/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:38:24 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/24 18:09:09 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"


char	*get_n_type(uint8_t type)
{
	if (type == N_UNDF)
	{
		return "U";
	}
	if (type == N_ABS)
	{
		return "A";
	}
	if (type == N_SECT)
	{
		return "S";
	}
	if (type == N_PBUD)
	{
		return "P";
	}
	if (type == N_INDR)
	{
		return "I";
	}
	return "X";
}

// char	*get_n_type(uint8_t type)
// {
// 	if (type == N_TYPE)
// 	{
// 		return "T";
// 	}
// 	if (type == N_STAB)
// 	{
// 		return "S";
// 	}
// 	if (type == N_PEXT)
// 	{
// 		return "P";
// 	}
// 	if (type == N_EXT)
// 	{
// 		return "E";
// 	}
// 	return "X";
// }

void	handle_nlist_64(void *lc, void *ptr)
{
	struct symtab_command	*sym;
	int						i;
	char					*stringtable;
	struct nlist_64			*array;

	sym = (struct symtab_command *) lc;
	array = ptr + sym->symoff;
	stringtable = ptr + sym->stroff;
	i = 0;
	while (i < (int)sym->nsyms)
	{
		if (ft_strlen((char *)(stringtable + array[i].n_un.n_strx)) != 0)
		{
			printf("%s\t - %hhu: %hhu\t - %s\n", ft_itoa_base((int)array[i].n_value, 16), array[i].n_type, array[i].n_sect, stringtable + array[i].n_un.n_strx);
		}
		i++;
	}
}

void	handle_64(void *ptr)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;

	header = (struct mach_header_64 *)ptr;
	ncmds = header->ncmds;
	lc = ptr + sizeof(*header);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			handle_nlist_64(lc, ptr);
			break;
		}
		lc = (void*)lc + lc->cmdsize;
		i++;
	}

}

void	nm(void *ptr)
{
	unsigned int	magic_number;

	magic_number = *(unsigned int *) ptr;
	if (magic_number == MH_MAGIC_64)
	{
		handle_64(ptr);
	}
}

void	readFile(char * filename, void (*next)(void *))
{
	int			fd;
	char		*ptr;
	struct stat	buff;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (fstat(fd, &buff) < 0)
	{
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	if ((ptr = mmap(0, buff.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	next(ptr);
	if (munmap(ptr, buff.st_size) < 0)
	{
		perror("munmap");
		exit(EXIT_FAILURE);
	}
}

int		main(int ac, char ** av)
{
	if (ac != 2)
	{
		fprintf(stderr, "Please give me an arg\n");
		return (EXIT_FAILURE);
	}
	readFile(av[1], nm);
	return (0);
}
