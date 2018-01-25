/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_32.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:31:20 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/25 13:39:02 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/ft_nm.h"

void	search_nlist_32(void *lc, void *ptr)
{
	struct symtab_command	*sym;
	int						i;
	char					*stringtable;
	struct nlist			*array;

	sym = (struct symtab_command *) lc;
	array = ptr + sym->symoff;
	stringtable = ptr + sym->stroff;
	i = 0;
	while (i < (int)sym->nsyms)
	{
		if (ft_strlen((char *)(stringtable + array[i].n_un.n_strx)) != 0 && array[i].n_type < 100 && array[i].n_type != 36)
		{
			if (array[i].n_value == 0)
				printf("%s %s %s\n", ft_padding_right(" ", 8, ' '), symbol_type(array[i].n_type), stringtable + array[i].n_un.n_strx);
			else
				printf("%s %s %s\n", ft_padding_right(ft_ultohex(array[i].n_value), 8, '0'), symbol_type(array[i].n_type), stringtable + array[i].n_un.n_strx);
		}
		i++;
	}
}

void	search_lc_32(void *ptr)
{
	int						ncmds;
	int						i;
	struct mach_header	*header;
	struct load_command		*lc;

	header = (struct mach_header *)ptr;
	ncmds = header->ncmds;
	lc = ptr + sizeof(*header);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			search_nlist_32(lc, ptr);
			break;
		}
		lc = (void*)lc + lc->cmdsize;
		i++;
	}

}

