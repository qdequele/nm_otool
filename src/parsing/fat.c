/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:24:30 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/07 17:15:12 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

t_list	*search_fat_32(t_file *file)
{
	unsigned int		i;
	struct fat_header	*header;
	struct fat_arch		*arch;
	t_list				*archi;
	t_list				*archi_list;

	header = (struct fat_header *)file->ptr;
	i = 0;
	archi_list = NULL;
	arch = (struct fat_arch*)((void*)file->ptr + sizeof(struct fat_header));
	while (i < header->nfat_arch)
	{
		archi = create_architecture("", (void *)header + arch->offset);
		match_header(archi);
		ft_lstaddend(&archi_list, archi);
		arch += sizeof(struct fat_arch);
		i++;
	}
	return (archi_list);
}

t_list	*search_fat_cigam_32(t_file *file)
{
	unsigned int		i;
	struct fat_header	*header;
	struct fat_arch		*arch;
	t_list				*archi;
	t_list				*archi_list;

	header = (struct fat_header *)file->ptr;
	i = 0;
	archi_list = NULL;
	arch = (struct fat_arch*)((void*)file->ptr + sizeof(struct fat_header));
	while (i < ENDIAN(header->nfat_arch))
	{
		archi = create_architecture("", (void *)header + ENDIAN(arch->offset));
		match_header(archi);
		ft_lstaddend(&archi_list, archi);
		arch += sizeof(struct fat_arch);
		i++;
	}
	return (archi_list);
}

t_list	*search_fat_64(t_file *file)
{
	unsigned int			i;
	struct fat_header		*header;
	struct fat_arch_64		*arch;
	t_list					*archi;
	t_list					*archi_list;

	header = (struct fat_header *)file->ptr;
	i = 0;
	archi_list = NULL;
	arch = (struct fat_arch_64*)((void*)header + sizeof(struct fat_header));
	while (i < header->nfat_arch)
	{
		archi = create_architecture("", (void *)header + arch->offset);
		match_header(archi);
		ft_lstaddend(&archi_list, archi);
		arch += sizeof(struct fat_arch_64);
		i++;
	}
	return (archi_list);
}

t_list	*search_fat_cigam_64(t_file *file)
{
	unsigned int			i;
	struct fat_header		*header;
	struct fat_arch_64		*arch;
	t_list					*archi;
	t_list					*archi_list;

	header = (struct fat_header *)file->ptr;
	i = 0;
	archi_list = NULL;
	arch = (struct fat_arch_64*)((void*)header + sizeof(struct fat_header));
	while (i < ENDIAN(header->nfat_arch))
	{
		archi = create_architecture("", (void *)header + ENDIAN(arch->offset));
		match_header(archi);
		ft_lstaddend(&archi_list, archi);
		arch += sizeof(struct fat_arch_64);
		i++;
	}
	return (archi_list);
}
