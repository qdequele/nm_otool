/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   architecture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:00:46 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/09 14:46:47 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

// void	architecture_description(t_list *node)
// {
// 	t_architecture		*archi;

// 	archi = (t_architecture *)node->content;

// 	if (archi->sym_list == NULL)
// 		return;
// 	if (ft_strlen(archi->type) != 0)
// 		ft_putchar('\n');
// 	ft_putstr(archi->type);

// 	if ((g_env->options & OPT_P) == OPT_P)
// 		return ft_lstiter(archi->sym_list, symbol_description);
// 	else if ((g_env->options & OPT_N) == OPT_N)
// 		ft_lst_bubble_sort(archi->sym_list, sort_numerically);
// 	else
// 		ft_lst_bubble_sort(archi->sym_list, sort_alphabetically);
// 	if ((g_env->options & OPT_R) == OPT_R)
// 		sort_reverse(&(archi->sym_list));
// 	ft_lstiter(archi->sym_list, symbol_description);

// }
