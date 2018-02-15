/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 11:35:21 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/14 15:12:42 by qdequele         ###   ########.fr       */
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
	t_sym	*next;

	sym = (t_sym *)node->content;
	next = NULL;
	if (node->next)
		next = (t_sym *)node->next->content;
	if ((next && ft_strcmp(sym->name, next->name) == 0
			&& ft_strcmp(sym->type, next->type) == 0
			&& ft_strcmp(sym->addr, next->addr) == 0)
		|| ft_strcmp(sym->type, "u") == 0 || ft_strcmp(sym->type, "p") == 0
		|| (((g_env->options & OPT_U) == OPT_U)
			&& ft_strcmp(sym->type, "U") != 0)
		|| (((g_env->options & OPT_U_MAJ) == OPT_U_MAJ)
			&& ft_strcmp(sym->type, "U") == 0))
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
