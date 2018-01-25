/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:35:21 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/25 13:35:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"

t_list	*create_sym(char *addr, char *type, char *name)
{
	t_sym		*sym;
	t_list		*lst;

	if ((sym = (t_sym *)malloc(sizeof(t_sym))) == NULL)
		return (NULL);
	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	sym->addr = addr;
	sym->type = type;
	sym->name = name;
	lst->content = (void *)sym;
	lst->content_size = sizeof(sym);
	lst->next = NULL;
	return (lst);
}


char	*symbol_type(uint8_t type)
{
	if (type == 15)
	{
		return "T";
	}
	if (type == 1)
	{
		return "U";
	}
	return "X";
}
