/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:08:28 by quentindequ       #+#    #+#             */
/*   Updated: 2018/02/09 16:07:22 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

int		sort_alphabetically(t_list *node)
{
	t_sym	*elem;
	t_sym	*n_elem;

	elem = node->content;
	n_elem = node->next->content;
	if (n_elem && ft_strcmp(elem->group, n_elem->group) > 0)
		return (1);
	if (n_elem && ft_strcmp(elem->group, n_elem->group) < 0)
		return (0);
	if (n_elem && ft_strcmp(elem->group, n_elem->group) == 0
		&& ft_strcmp(elem->name, n_elem->name) > 0)
		return (1);
	return (0);
}

int		sort_numerically(t_list *node)
{
	t_sym	*elem;
	t_sym	*n_elem;

	elem = node->content;
	n_elem = node->next->content;
	if (n_elem && ft_strcmp(elem->group, n_elem->group) > 0)
		return (1);
	if (n_elem && ft_strcmp(elem->group, n_elem->group) < 0)
		return (0);
	if (n_elem && ft_strcmp(elem->group, n_elem->group) == 0
		&& ft_strcmp(elem->addr, n_elem->addr) > 0)
		return (1);
	return (0);
}

int		sort_reverse(t_list **node)
{
	*node = ft_lst_reverse(*node);
	return (1);
}
