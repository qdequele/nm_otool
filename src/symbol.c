/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:35:21 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/26 15:50:47 by qdequele         ###   ########.fr       */
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

char	*symbol_type_64(uint8_t type, uint8_t sect, t_archi *archi)
{
	char		*ret;
	t_section	*sec;

	if ((type & N_TYPE) == N_UNDF)
		ret = "U";
	else if ((type & N_TYPE) == N_ABS)
		ret = "A";
	else if ((type & N_TYPE) == N_SECT)
	{
		sec = (t_section *)(ft_lstget_at(archi->sec_list, (int)sect - 1)->content);
		if (ft_strcmp(sec->sec_name, SECT_TEXT) == 0)
			ret = "T";
		else if (ft_strcmp(sec->sec_name, SECT_DATA) == 0)
			ret = "D";
		else if (ft_strcmp(sec->sec_name, SECT_BSS) == 0)
			ret = "B";
		else
			ret = "S";
	}
	else if ((type & N_TYPE) == N_PBUD)
		ret = "P";
	else if ((type & N_TYPE) == N_INDR)
		ret = "I";
	else
		ret = "X";

	if ((type & N_EXT) == 0 && ft_strcmp(ret, "X") != 0)
		ret += 32;
	return (ret);
}

char	*symbol_type_32(uint8_t type, uint8_t sect, t_archi *archi)
{
	char		*ret;
	t_section	*sec;

	if ((type & N_TYPE) == N_UNDF)
		ret = "U";
	else if ((type & N_TYPE) == N_ABS)
		ret = "A";
	else if ((type & N_TYPE) == N_SECT)
	{
		sec = (t_section *)(ft_lstget_at(archi->sec_list, (int)sect - 1)->content);
		if (ft_strcmp(sec->sec_name, SECT_TEXT) == 0)
			ret = "T";
		else if (ft_strcmp(sec->sec_name, SECT_DATA) == 0)
			ret = "D";
		else if (ft_strcmp(sec->sec_name, SECT_COMMON) == 0)
			ret = "B";
		else
			ret = "S";
	}
	else if ((type & N_TYPE) == N_PBUD)
		ret = "P";
	else if ((type & N_TYPE) == N_INDR)
		ret = "I";
	else
		ret = "X";

	if ((type & N_EXT) == 0 && ft_strcmp(ret, "X") != 0)
		ret += 32;
	return (ret);
}

void	symbol_description(t_list *node)
{
	t_sym	*sym;

	sym = (t_sym *)node->content;
	ft_putstr(sym->addr);
	ft_putstr(" ");
	ft_putstr(sym->type);
	ft_putstr(" ");
	ft_putendl(sym->name);
}
