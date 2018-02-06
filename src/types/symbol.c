/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:35:21 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/06 10:51:32 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

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

void	symbol_description(t_list *node)
{
	t_sym	*sym;

	sym = (t_sym *)node->content;
	if (((g_env->options & OPT_U) == OPT_U) && ft_strcmp(sym->type, "U") != 0)
		return;
	if (((g_env->options & OPT_U_MAJ) == OPT_U_MAJ) && ft_strcmp(sym->type, "U") == 0)
		return;
	if ((g_env->options & OPT_J) != OPT_J)
	{
		ft_putstr(sym->addr);
		ft_putstr(" ");
		ft_putstr(sym->type);
		ft_putstr(" ");
	}
	ft_putendl(sym->name);
}
