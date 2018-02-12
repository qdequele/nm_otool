/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:08:28 by quentindequ       #+#    #+#             */
/*   Updated: 2018/02/12 13:58:51 by qdequele         ###   ########.fr       */
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
