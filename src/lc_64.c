/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lc_64.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:31:16 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/25 15:33:48 by qdequele         ###   ########.fr       */
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
		if (ft_strlen((char *)(stringtable + array[i].n_un.n_strx)) != 0)
		{
			if (array[i].n_value == 0)
				symbol = create_sym(ft_padding_right(" ", 16, ' '),
									symbol_type(array[i].n_type),
									stringtable + array[i].n_un.n_strx);
			else
				symbol = create_sym(ft_padding_right(ft_ultohex(array[i].n_value), 16, '0'),
									symbol_type(array[i].n_type),
									stringtable + array[i].n_un.n_strx);
			ft_lstaddend(&(archi->sym_list), symbol);
		}
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
		{
			search_nlist_64(lc, archi);
			break;
		}
		lc = (void*)lc + lc->cmdsize;
		i++;
	}

}
