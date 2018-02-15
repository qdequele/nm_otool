/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 11:05:36 by quentindequ       #+#    #+#             */
/*   Updated: 2018/02/14 15:10:33 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	match_header(void *ptr)
{
	unsigned int	magic_number;

	magic_number = *(unsigned int *)ptr;
	if (magic_number == MH_MAGIC_64 || magic_number == MH_CIGAM_64)
		search_lc_64(ptr);
	else if (magic_number == MH_MAGIC || magic_number == MH_CIGAM)
		search_lc_32(ptr);
	else if (magic_number == FAT_MAGIC || magic_number == FAT_CIGAM)
		search_fat_32(ptr);
	else if (magic_number == FAT_MAGIC_64 || magic_number == FAT_CIGAM_64)
		search_fat_64(ptr);
	else if (ft_strncmp((char *)ptr, ARMAG, SARMAG) == 0)
		search_archives(ptr);
	else
		return ;
}
