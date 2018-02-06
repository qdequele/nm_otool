/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archives.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quentindequelen <quentindequelen@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:54:31 by quentindequ       #+#    #+#             */
/*   Updated: 2018/02/06 12:19:11 by quentindequ      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

t_list	*search_archives(t_file *file)
{
	struct ar_hdr	*header;
	int				i;
	t_list			*archi;
	t_list			*archi_list;
	char			*name;

	i = 0;
	archi_list = NULL;
	header = (struct ar_hdr *)(void*)(file->ptr + SARMAG);
	while ((header = (struct ar_hdr *)((void*)header + sizeof(struct ar_hdr) + ft_atoi(header->ar_size)))
			&& ((char *)header)[0])
	{
		name = ft_strjoin(file->name, ft_strjoin("(", ft_strjoin(ft_strsub((char *)((void *)header + sizeof(struct ar_hdr)), 0, 60), "):\n")));
		archi = create_architecture(name, (void *)header + sizeof(struct ar_hdr) + ft_atoi(ft_strsub(header->ar_name, 3, 5)));
		ft_lstaddend(&archi_list, archi);
	}

	return (archi_list);
}
