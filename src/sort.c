/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:08:28 by quentindequ       #+#    #+#             */
/*   Updated: 2018/02/14 13:20:41 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

int		sort_alphabetically(t_list *node)
{
	t_sym	*elem;
	t_sym	*n_elem;

	elem = node->content;
	n_elem = node->next->content;
	if (elem == NULL || n_elem == NULL)
		return (0);
	if (ft_strcmp(elem->name, n_elem->name) == 0)
	{
		if (ft_strcmp(elem->addr, n_elem->addr) > 0)
			return (1);
		return (0);
	}
	if (ft_strcmp(elem->name, n_elem->name) > 0)
		return (1);
	return (0);
}

int		sort_alpha(t_list *node, t_list *new)
{
	t_sym	*elem;
	t_sym	*next_elem;
	t_sym	*new_elem;

	elem = node->content;
	next_elem = node->next->content;
	new_elem = new->content;
	if (elem == NULL || next_elem == NULL)
		return (0);
	if (ft_strcmp(elem->name, new_elem->name) == 0)
	{
		if (ft_strcmp(elem->addr, new_elem->addr) > 0)
			return (-1);
		return (1);
	}
	if (ft_strcmp(elem->name, new_elem->name) > 0)
		return (1);
	return (0);
}

int		sort_numerically(t_list *node)
{
	t_sym	*elem;
	t_sym	*n_elem;

	elem = node->content;
	n_elem = node->next->content;
	if (elem == NULL || n_elem == NULL)
		return (0);
	if (ft_strcmp(elem->addr, n_elem->addr) > 0)
		return (1);
	return (0);
}

int		sort_num(t_list *node, t_list *new)
{
	t_sym	*elem;
	t_sym	*n_elem;
	t_sym	*new_elem;

	elem = node->content;
	n_elem = node->next->content;
	new_elem = new->content;
	if (elem == NULL || n_elem == NULL)
		return (0);
	if (ft_strcmp(elem->addr, new_elem->addr) == 0)
	{
		if (ft_strcmp(elem->name, new_elem->name) > 0)
			return (-1);
		return (1);
	}
	if (ft_strcmp(elem->addr, new_elem->addr) > 0)
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

	from = (t_sym *)f->content;
	by = (t_sym *)b->content;
	if (ft_strcmp(from->name, by->name) == 0
		&& ft_strcmp(from->addr, by->addr) == 0)
		return (1);
	return (0);
}
