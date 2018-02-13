/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 09:37:56 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/13 10:15:26 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstreplace(t_list **alst, t_list *n, int (*f)(t_list *f, t_list *b))
{
	t_list	*list;

	list = *alst;
	if ((*alst == NULL || (*alst)->content == NULL || f == NULL) && n)
		*alst = n;
	else
	{
		while (list->next)
		{
			if (f(list, n) == 1)
			{
				free(list->content);
				list->content = n->content;
				return ;
			}
			list = list->next;
		}
		list->next = n;
	}
}

void	ft_lstskip(t_list **alst, t_list *n, int (*f)(t_list *f, t_list *b))
{
	t_list	*list;

	list = *alst;
	if ((*alst == NULL || (*alst)->content == NULL || f == NULL) && n)
		*alst = n;
	else
	{
		while (list->next)
		{
			if (f(list, n) == 1)
				return ;
			list = list->next;
		}
		list->next = n;
	}
}
