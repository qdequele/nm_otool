/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:24:30 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/14 10:53:30 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	search_fat_32(void *ptr)
{
	int					i;
	struct fat_header	*header;
	struct fat_arch		*arch;
	int					offset;

	if (DEBUG) ft_putendl("search_fat_32");
	header = (struct fat_header *)ptr;
	i = 0;
	arch = (struct fat_arch*)((void*)ptr + sizeof(struct fat_header));
	if (arch->cputype == 301989888)
		arch = (void *)arch + sizeof(struct fat_arch);
	offset = convert_endian_32(arch->offset);
	g_env->nb_fat = convert_endian_32(header->nfat_arch);
	while (i < convert_endian_32(header->nfat_arch))
	{
		if (arch->cputype == 117440513)
		{
			offset = convert_endian_32(arch->offset);
			break ;
		}
		arch = (void *)arch + sizeof(struct fat_arch);
		i++;
	}
	if (DEBUG) printf("offset : %d\n", offset);
	match_header((void *)header + offset);
}

void	search_fat_64(void *ptr)
{
	int					i;
	struct fat_header	*header;
	struct fat_arch_64	*arch;
	int					offset;

	if (DEBUG) ft_putendl("search_fat_64");
	header = (struct fat_header *)ptr;
	i = 0;
	arch = (struct fat_arch_64*)((void*)ptr + sizeof(struct fat_header));
	if (arch->cputype == 301989888)
		arch = (void *)arch + sizeof(struct fat_arch);
	offset = convert_endian_64(arch->offset);
	g_env->nb_fat = convert_endian_64(header->nfat_arch);
	while (i < convert_endian_64(header->nfat_arch))
	{
		if (arch->cputype == 117440513)
		{
			offset = convert_endian_64(arch->offset);
			break ;
		}
		arch = (void *)arch + sizeof(struct fat_arch_64);
		i++;
	}
	if (DEBUG) printf("offset : %d\n", offset);
	match_header((void *)header + offset);
}
