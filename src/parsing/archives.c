/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archives.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:54:31 by quentindequ       #+#    #+#             */
/*   Updated: 2018/02/07 13:12:19 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_nm.h>

t_list	*search_archives(t_file *file)
{
	struct ar_hdr	*header;
	int				i;
	t_list			*archi_list;
	char			*name;

	i = 0;
	archi_list = NULL;
	header = (struct ar_hdr *)(void*)(file->ptr + SARMAG);
	while ((header = (struct ar_hdr *)((void*)header + sizeof(struct ar_hdr)
			+ ft_atoi(header->ar_size))) && ((char *)header)[0])
	{
		name = ft_strjoin(file->name, ft_strjoin("(", ft_strjoin(ft_strsub(
			(char *)((void *)header + sizeof(struct ar_hdr)), 0, 60), "):\n")));
		ft_lstaddend(&archi_list, create_architecture(name, (void *)header +
			sizeof(struct ar_hdr) + ft_atoi(ft_strsub(header->ar_name, 3, 5))));
	}
	return (archi_list);
}
