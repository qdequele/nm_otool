/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:00:46 by qdequele          #+#    #+#             */
/*   Updated: 2018/01/25 15:29:39 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_nm.h"

t_list	*create_archi(char *type, void *ptr)
{
	t_archi		*archi;
	t_list		*lst;

	if ((archi = (t_archi *)malloc(sizeof(t_archi))) == NULL)
		return (NULL);
	if ((lst = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	archi->type = type;
	archi->ptr = ptr;
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
	t_list			*archi;

	file = (t_file *)(node->content);
	magic_number = *(unsigned int *) file->ptr;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		search_lc_64((t_archi *)((archi = create_archi("64Bits", file->ptr))->content));
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		search_lc_32((t_archi *)((archi = create_archi("32Bits", file->ptr))->content));
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		archi = create_archi("FAT32", file->ptr);
	else if (magic_number == FAT_MAGIC_64 || magic_number == FAT_CIGAM_64)
		archi = create_archi("FAT64", file->ptr);
	else if (ft_strncmp((char *)file->ptr, ARMAG, SARMAG) == 0)
		archi = create_archi("ARCH", file->ptr);
	else
		archi = create_archi("UNDEFINED", file->ptr);
	ft_lstaddend(&(file->archi_list), archi);
}

void	archi_description(t_list *node)
{
	t_archi		*archi;

	archi = (t_archi *)node->content;
	ft_putstr("arch: ");
	ft_putendl(archi->type);
	ft_lstiter(archi->sym_list, symbol_description);
}
