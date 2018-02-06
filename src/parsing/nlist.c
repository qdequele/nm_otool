/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:44:47 by quentindequ       #+#    #+#             */
/*   Updated: 2018/02/06 10:46:10 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	search_nlist_32(void *lc, t_architecture *archi)
{
	struct symtab_command	*sym;
	int						i;
	char					*stringtable;
	struct nlist			*array;
	t_list					*symbol;

	sym = (struct symtab_command *) lc;
	array = archi->ptr + sym->symoff;
	stringtable = archi->ptr + sym->stroff;
	i = 0;
	while (i < (int)sym->nsyms)
	{
		if (ft_strlen((char *)(stringtable + array[i].n_un.n_strx)) != 0 && ft_strcmp(symbol_type_32(array[i].n_type, array[i].n_sect, archi), "X") != 0)
		{
			if (array[i].n_value == 0)
				symbol = create_sym(ft_padding_right(" ", 16, ' '),
									symbol_type_32(array[i].n_type, array[i].n_sect, archi),
									stringtable + array[i].n_un.n_strx);
			else
				symbol = create_sym(ft_padding_right(ft_ultohex(array[i].n_value), 8, '0'),
									symbol_type_32(array[i].n_type, array[i].n_sect, archi),
									stringtable + array[i].n_un.n_strx);
			ft_lstaddend(&(archi->sym_list), symbol);
		}
		i++;
	}
}

void	search_nlist_64(void *lc, t_architecture *archi)
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
