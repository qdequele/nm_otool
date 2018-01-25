/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:00:46 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/25 13:37:30 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"

t_list	*create_archi(char *type, char *name)
{
	t_archi		*archi;
	t_list		*lst;

	if ((archi = (t_archi *)malloc(sizeof(t_archi))) == NULL)
		return (NULL);
	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	archi->type = type;
	archi->name = name;
	archi->nb_sym = 0;
	archi->sym_list = NULL;
	lst->content = (void *)archi;
	lst->content_size = sizeof(archi);
	lst->next = NULL;
	return (lst);
}

void	find_arch(t_list *node)
{
	unsigned int	magic_number;
	t_file			*file;

	file = (t_file *)(node->content);
	magic_number = *(unsigned int *) file->ptr;
	if (magic_number == MH_MAGIC_64)
		search_lc_64(file->ptr);
	else if (magic_number == MH_MAGIC)
		search_lc_32(file->ptr);
}
