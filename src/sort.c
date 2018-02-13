/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:08:28 by quentindequ       #+#    #+#             */
/*   Updated: 2018/02/13 10:20:47 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

int		sort_alphabetically(t_list *node)
{
	t_sym	*elem;
	t_sym	*n_elem;

	elem = node->content;
	n_elem = node->next->content;
	if (n_elem &&ft_strcmp(elem->name, n_elem->name) > 0)
		return (1);
	return (0);
}

int		sort_numerically(t_list *node)
{
	t_sym	*elem;
	t_sym	*n_elem;

	elem = node->content;
	n_elem = node->next->content;
	if (n_elem && ft_strcmp(elem->addr, n_elem->addr) > 0)
		return (1);
	return (0);
}

int		sort_reverse(t_list **node)
{
	*node = ft_lst_reverse(*node);
	return (1);
}

int		equatable(t_list *f, t_list *b)
{
	t_sym	*from;
	t_sym	*by;
	char	*from_name;
	char	*by_name;

	from = (t_sym *)f->content;
	by = (t_sym *)b->content;
	from_name = ft_strcut_before(&from->name, '$');
	by_name = ft_strcut_before(&by->name, '$');

	if (from_name[ft_strlen(from_name) - 1] == '_')
	{
		if (ft_strcmp(from->name, by->name) == 0)
			return (1);
		return (0);
	}
	if (ft_strcmp(from_name, by_name) == 0)
		return (1);
	return (0);
}
