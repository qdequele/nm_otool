/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:44:47 by quentindequ       #+#    #+#             */
/*   Updated: 2018/02/07 15:27:20 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	search_nlist_32(void *lc, t_architecture *archi)
{
	int						i;
	char					*stringtable;
	struct nlist			*array;
	t_list					*symbol;
	char					*type;

	array = archi->ptr + ((struct symtab_command *) lc)->symoff;
	stringtable = archi->ptr + ((struct symtab_command *) lc)->stroff;
	i = 0;
	while (i < (int)((struct symtab_command *) lc)->nsyms)
	{
		type = symbol_type_32(array[i].n_type, array[i].n_sect, archi);
		if (ft_strlen((char *)(stringtable + array[i].n_un.n_strx)) != 0
			&& ft_strcmp(type, "X") != 0)
		{
			if (ft_strcmp(type, "U") == 0)
				symbol = create_sym(ft_padding_right(" ", 16, ' '), type,
									stringtable + array[i].n_un.n_strx);
			else
				symbol = create_sym(ft_padding_right(ft_ultohex(array[i].n_value
				), 8, '0'), type, stringtable + array[i].n_un.n_strx);
			ft_lstaddend(&(archi->sym_list), symbol);
		}
		i++;
	}
}

void	search_nlist_64(void *lc, t_architecture *archi)
{
	int						i;
	char					*stringtable;
	struct nlist_64			*array;
	t_list					*symbol;
	char					*type;

	array = archi->ptr + ((struct symtab_command *) lc)->symoff;
	stringtable = archi->ptr + ((struct symtab_command *) lc)->stroff;
	i = 0;
	while (i < (int)((struct symtab_command *) lc)->nsyms)
	{
		type = symbol_type_64(array[i].n_type, array[i].n_sect, archi);
		if (ft_strlen((char *)(stringtable + array[i].n_un.n_strx)) != 0 && ft_strcmp(type, "X") != 0)
		{
			if (ft_strcmp(type, "U") == 0)
				symbol = create_sym(ft_padding_right(" ", 16, ' '), type,
									stringtable + array[i].n_un.n_strx);
			else
				symbol = create_sym(ft_padding_right(ft_ultohex(array[i].n_value), 16, '0'), type,
									stringtable + array[i].n_un.n_strx);
			ft_lstaddend(&(archi->sym_list), symbol);
		}
		i++;
	}
}
