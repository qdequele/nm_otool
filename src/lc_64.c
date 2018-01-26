/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:31:16 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/26 15:51:43 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"

void	search_nlist_64(void *lc, t_archi *archi)
{
	struct symtab_command	*sym;
	int						i;
	char					*stringtable;
	struct nlist_64			*array;
	t_list					*symbol;

	sym = (struct symtab_command *) lc;
	array = archi->ptr + sym->symoff;
	stringtable = archi->ptr + sym->stroff;
	i = 0;
	while (i < (int)sym->nsyms)
	{
		if (ft_strlen((char *)(stringtable + array[i].n_un.n_strx)) != 0 && ft_strcmp(symbol_type_64(array[i].n_type, array[i].n_sect, archi), "X") != 0)
		{
			if (array[i].n_value == 0)
				symbol = create_sym(ft_padding_right(" ", 16, ' '),
									symbol_type_64(array[i].n_type, array[i].n_sect, archi),
									stringtable + array[i].n_un.n_strx);
			else
				symbol = create_sym(ft_padding_right(ft_ultohex(array[i].n_value), 16, '0'),
									symbol_type_64(array[i].n_type, array[i].n_sect, archi),
									stringtable + array[i].n_un.n_strx);
			ft_lstaddend(&(archi->sym_list), symbol);
		}
		i++;
	}
}

void	search_section_64(void *lc, t_archi *archi)
{
	struct segment_command_64	*seg;
	struct section_64			*sec;
	int							i;
	int							j;
	char						*content;

	seg = (struct segment_command_64 *)lc;
	sec = (struct section_64 *)((void *)seg + sizeof(struct segment_command_64));
	i = 0;
	while (i < (int)seg->nsects)
	{
		j = 0;
		content = ft_strnew(0);
		while (j < (int)sec->size)
		{
			if ((j % 16) == 0)
			{
				if (j != 0)
					content = ft_strfjoin(content, "\n");
				content = ft_strfjoin(ft_strfjoin(content, ft_padding_right(ft_ultohex(sec->addr + j), 16, '0')), "\t");
			}
			content = ft_strfjoin(ft_strfjoin(content, ft_padding_right(ft_uitohex(((char *)(archi->ptr + sec->offset))[j]), 2, '0')), " ");
			j++;
		}
		content = ft_strfjoin(content, "\n");
		ft_lstaddend(&(archi->sec_list), create_section(sec->segname, sec->sectname, content));
		sec = (struct section_64 *)((void *)sec + sizeof(struct section_64));
		i++;
	}
}

void	search_lc_64(t_archi *archi)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;


	header = (struct mach_header_64 *)archi->ptr;
	ncmds = header->ncmds;
	lc = archi->ptr + sizeof(*header);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			search_nlist_64(lc, archi);
		else if (lc->cmd == LC_SEGMENT_64)
			search_section_64(lc, archi);
		lc = (void*)lc + lc->cmdsize;
		i++;
	}

}
