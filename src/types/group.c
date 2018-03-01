/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:35:06 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/28 20:59:13 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void			create_group(char *name)
{
	t_group		*group;
	t_list		*lst;

	if ((group = (t_group *)malloc(sizeof(t_group))) == NULL)
		return ;
	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return ;
	group->name = name;
	group->sym_list = NULL;
	group->sec_list = NULL;
	lst->content = (void *)group;
	lst->content_size = sizeof(group);
	lst->next = NULL;
	g_env->current_group = group;
	ft_lstaddend(&(g_env->group_list), lst);
}

void			group_description(t_list *node)
{
	t_group		*group;

	group = (t_group *)node->content;
	if (group->name)
	{
		ft_putstr("\n");
		ft_putendl(group->name);
	}
	if ((g_env->options & OPT_P) == OPT_P)
		return (ft_lstiter(group->sym_list, symbol_description));
	else if ((g_env->options & OPT_N) == OPT_N)
		ft_lst_bubble_sort(group->sym_list, sort_numerically);
	else
		ft_lst_bubble_sort(group->sym_list, sort_alphabetically);
	if ((g_env->options & OPT_R) == OPT_R)
		sort_reverse(&(group->sym_list));
	ft_lstiter(group->sym_list, symbol_description);
}
