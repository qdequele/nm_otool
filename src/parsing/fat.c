/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:24:30 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/12 14:42:13 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	search_fat_32(void *ptr)
{
	int					i;
	struct fat_header	*header;
	struct fat_arch		*arch;

	if (DEBUG) ft_putendl("search_fat_32");
	header = (struct fat_header *)ptr;
	i = 0;
	while (i < convert_endian_32(header->nfat_arch))
	{
		arch = (struct fat_arch*)((void*)ptr + sizeof(struct fat_header));
		match_header((void *)header + convert_endian_32(arch->offset));
		arch += sizeof(struct fat_arch);
		i++;
	}
}

void	search_fat_64(void *ptr)
{
	int					i;
	struct fat_header	*header;
	struct fat_arch_64	*arch;

	if (DEBUG) ft_putendl("search_fat_64");
	header = (struct fat_header *)ptr;
	i = 0;
	while (i < convert_endian_64(header->nfat_arch))
	{
		arch = (struct fat_arch_64*)((void*)ptr + sizeof(struct fat_header));
		match_header((void *)header + convert_endian_64(arch->offset));
		arch += sizeof(struct fat_arch_64);
		i++;
	}
}
