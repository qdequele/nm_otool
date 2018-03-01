/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:44:47 by quentindequ       #+#    #+#             */
/*   Updated: 2018/03/01 09:37:06 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

t_list	*sym_32_from(struct nlist array, char *type, char *stringtable)
{
	if (ft_strcmp(type, "U") == 0)
		return (create_sym(ft_padding_right(" ", 8, ' '), type,
		stringtable + array.n_un.n_strx));
	else
		return (create_sym(ft_padding_right(ft_ultohex(array.n_value), 8, '0'),
		type, stringtable + array.n_un.n_strx));
}

void	search_nlist_32(void *lc, void *ptr)
{
	int						i;
	char					*stringtable;
	struct nlist			*array;
	t_list					*symbol;
	char					*type;

	array = ptr + ((struct symtab_command *)lc)->symoff;
	stringtable = ptr + ((struct symtab_command *)lc)->stroff;
	i = 0;
	while (i < (int)((struct symtab_command *)lc)->nsyms)
	{
		type = symbol_type(array[i].n_type, array[i].n_sect);
		if (ft_strlen((char *)(stringtable + array[i].n_un.n_strx)) != 0
			&& ft_strcmp(type, "X") != 0)
		{
			symbol = sym_32_from(array[i], type, stringtable);
			ft_lstskip(&(g_env->current_group->sym_list), symbol, equatable);
		}
		i++;
	}
}

t_list	*sym_64_from(struct nlist_64 array, char *type, char *stringtable)
{
	if (ft_strcmp(type, "U") == 0)
		return (create_sym(ft_padding_right(" ", 16, ' '), type,
		stringtable + array.n_un.n_strx));
	else
		return (create_sym(ft_padding_right(ft_ultohex(array.n_value), 16, '0'),
		type, stringtable + array.n_un.n_strx));
}

void	search_nlist_64(void *lc, void *ptr)
{
	int						i;
	char					*stringtable;
	struct nlist_64			*array;
	t_list					*symbol;
	char					*type;

	array = ptr + ((struct symtab_command *)lc)->symoff;
	stringtable = ptr + ((struct symtab_command *)lc)->stroff;
	i = 0;
	while (i < (int)((struct symtab_command *)lc)->nsyms)
	{
		type = symbol_type(array[i].n_type, array[i].n_sect);
		if (ft_strlen((char *)(stringtable + array[i].n_un.n_strx)) != 0
			&& ft_strcmp(type, "X") != 0)
		{
			symbol = sym_64_from(array[i], type, stringtable);
			ft_lstreplace(&(g_env->current_group->sym_list), symbol, equatable);
		}
		i++;
	}
}
