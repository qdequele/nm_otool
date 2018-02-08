/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:31:16 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/08 14:32:32 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	search_lc_32(void *ptr)
{
	int						i;
	struct mach_header		*header;
	struct load_command		*lc;

	header = (struct mach_header *)ptr;
	lc = ptr + sizeof(struct mach_header_64);
	i = 0;
	while (i < convert_endian_32(header->ncmds))
	{
		if (lc->cmd == LC_SYMTAB)
			search_nlist_32(lc, ptr);
		else if (lc->cmd == LC_SEGMENT_64)
			search_section_32(lc, ptr);
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
}

void	search_lc_64(void *ptr)
{
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;

	header = (struct mach_header_64 *)ptr;
	lc = ptr + sizeof(struct mach_header_64);
	i = 0;
	while (i < convert_endian_32(header->ncmds))
	{
		if (lc->cmd == LC_SYMTAB)
			search_nlist_64(lc, ptr);
		else if (lc->cmd == LC_SEGMENT_64)
			search_section_64(lc, ptr);
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
}
