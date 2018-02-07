/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:05:36 by quentindequ       #+#    #+#             */
/*   Updated: 2018/02/07 16:55:16 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	match_header(t_list *node)
{
	unsigned int	magic_number;
	t_architecture	*archi;

	archi = (t_architecture *)(node->content);
	magic_number = *(unsigned int *) archi->ptr;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		search_lc_64(archi);
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		search_lc_32(archi);
}

void	find_architecture(t_list *node)
{
	unsigned int	magic_number;
	t_file			*file;
	t_list			*archi;

	file = (t_file *)(node->content);
	magic_number = *(unsigned int *) file->ptr;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		match_header((archi = create_architecture("", file->ptr)));
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		match_header((archi = create_architecture("", file->ptr)));
	else if (magic_number == FAT_MAGIC)
		archi = search_fat_32(file);
	else if (magic_number == FAT_MAGIC_64)
		archi = search_fat_64(file);
	else if (magic_number == FAT_CIGAM)
		archi = search_fat_cigam_32(file);
	else if (magic_number == FAT_CIGAM_64)
		archi = search_fat_cigam_64(file);
	else if (ft_strncmp((char *)file->ptr, ARMAG, SARMAG) == 0)
	{
		archi = search_archives(file);
		ft_lstiter(archi, match_header);
	}
	else
		archi = create_architecture("", file->ptr);
	ft_lstaddend(&(file->archi_list), archi);
}
