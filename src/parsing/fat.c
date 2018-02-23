/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:24:30 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/23 14:49:59 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void search_fat_32(void *ptr)
{
	int i;
	struct fat_header *header;
	struct fat_arch *arch;
	int offset;

	header = (struct fat_header *)ptr;
	i = 0;
	arch = (struct fat_arch *)((void *)ptr + sizeof(struct fat_header));
	if (convert_endian_32(arch->cputype) == CPU_TYPE_POWERPC)
		arch = (void *)arch + sizeof(struct fat_arch);
	offset = convert_endian_32(arch->offset);
	g_env->nb_fat = convert_endian_32(header->nfat_arch);
	while (i < convert_endian_32(header->nfat_arch))
	{
		check_integrity(arch->offset + arch->offset);
		if (convert_endian_32(arch->cputype) == CPU_TYPE_X86_64)
		{
			offset = convert_endian_32(arch->offset);
			break;
		}
		arch = (void *)arch + sizeof(struct fat_arch);
		i++;
	}
	match_header((void *)header + offset);
}

void search_fat_64(void *ptr)
{
	int i;
	struct fat_header *header;
	struct fat_arch_64 *arch;
	int offset;

	header = (struct fat_header *)ptr;
	i = 0;
	arch = (struct fat_arch_64 *)((void *)ptr + sizeof(struct fat_header));
	if (convert_endian_64(arch->cputype) == CPU_TYPE_POWERPC)
		arch = (void *)arch + sizeof(struct fat_arch);
	offset = convert_endian_64(arch->offset);
	g_env->nb_fat = convert_endian_64(header->nfat_arch);
	while (i < convert_endian_64(header->nfat_arch))
	{
		check_integrity(arch->offset + arch->offset);
		if (convert_endian_64(arch->cputype) == CPU_TYPE_X86_64)
		{
			offset = convert_endian_64(arch->offset);
			break;
		}
		arch = (void *)arch + sizeof(struct fat_arch_64);
		i++;
	}
	match_header((void *)header + offset);
}
