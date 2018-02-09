/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:35:21 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/09 16:14:14 by quentindequ      ###   ########.fr       */
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
	if (g_env->current_group)
		sym->group = g_env->current_group;
	else
		sym->group = NULL;
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
	t_sym	*next;

	sym = (t_sym *)node->content;
	if (node->next)
		next = (t_sym *)node->next->content;
	if (ft_strcmp(sym->type, "u") == 0 || ft_strcmp(sym->type, "p") == 0)
		return;
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
	if (next && ft_strcmp(sym->group, next->group) != 0)
	{
		ft_putstr("\n");
		ft_putstr(next->group);
	}
}
