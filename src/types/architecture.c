/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   architecture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:00:46 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/06 12:37:31 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

t_list	*create_architecture(char *type, void *ptr)
{
	t_architecture		*archi;
	t_list		*lst;

	if ((archi = (t_architecture *)malloc(sizeof(t_architecture))) == NULL)
		return (NULL);
	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	archi->type = type;
	archi->ptr = ptr;
	archi->nb_sym = 0;
	archi->sym_list = NULL;
	archi->nb_sec = 0;
	archi->sec_list = NULL;
	lst->content = (void *)archi;
	lst->content_size = sizeof(archi);
	lst->next = NULL;
	return (lst);
}

void	architecture_description(t_list *node)
{
	t_architecture		*archi;

	archi = (t_architecture *)node->content;

	ft_putstr(archi->type);

	if ((g_env->options & OPT_P) == OPT_P)
		return ft_lstiter(archi->sym_list, symbol_description);
	else if ((g_env->options & OPT_N) == OPT_N)
		ft_lst_bubble_sort(archi->sym_list, sort_numerically);
	else
		ft_lst_bubble_sort(archi->sym_list, sort_alphabetically);
	if ((g_env->options & OPT_R) == OPT_R)
		sort_reverse(&(archi->sym_list));
	ft_lstiter(archi->sym_list, symbol_description);
	ft_putchar('\n');
}
