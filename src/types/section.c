/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   section.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 11:29:17 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/09 15:32:03 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

t_list	*create_section(char *seg_name, char *sec_name, char *content)
{
	t_section	*sec;
	t_list		*lst;

	if ((sec = (t_section *)malloc(sizeof(t_section))) == NULL)
		return (NULL);
	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	sec->seg_name = seg_name;
	sec->sec_name = sec_name;
	sec->content = content;
	lst->content = (void *)sec;
	lst->content_size = sizeof(sec);
	lst->next = NULL;
	return (lst);
}
