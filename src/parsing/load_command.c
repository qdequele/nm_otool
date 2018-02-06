/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:31:16 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/06 10:46:58 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

void	search_lc_32(t_architecture *archi)
{
	int						ncmds;
	int						i;
	struct mach_header		*header;
	struct load_command		*lc;


	header = (struct mach_header *)archi->ptr;
	ncmds = header->ncmds;
	lc = archi->ptr + sizeof(*header);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			search_nlist_32(lc, archi);
		else if (lc->cmd == LC_SEGMENT_64)
			search_section_32(lc, archi);
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
}

void	search_lc_64(t_architecture *archi)
{
	int						ncmds;
	int						i;
	struct mach_header_64	*header;
	struct load_command		*lc;


	header = (struct mach_header_64 *)archi->ptr;
	ncmds = header->ncmds;
	lc = archi->ptr + sizeof(*header);
	i = 0;
	while (i < ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			search_nlist_64(lc, archi);
		else if (lc->cmd == LC_SEGMENT_64)
			search_section_64(lc, archi);
		lc = (void*)lc + lc->cmdsize;
		i++;
	}
}
