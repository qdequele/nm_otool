/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 10:25:40 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/14 15:10:08 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstinsert(t_list **lst, t_list *new, int (*c)(t_list *current, t_list *new))
{
	t_list	*tmp;
	int		ret;

	tmp = *lst;
	if (tmp == NULL || new == NULL)
		return ;
	while (tmp->next)
	{
		ret = c(tmp, new);
		if (ret == 1)
		{
			new->next = tmp->next;
			tmp->next = new;
			return ;
		} else if (ret == -1)
		{
			tmp->content = new->content;
			return ;
		}
		tmp = tmp->next;
	}
	tmp->next = new;
}
