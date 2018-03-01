/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 12:28:23 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/28 20:55:42 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_match(char *s1, char *s2)
{
	if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0' && *s1 != '*')
		return (ft_match(s1 + 1, s2 + 1));
	else if (*s1 != '\0' && *s2 == '*' && *(s2 + 1) == '*')
		return (ft_match(s1, s2 + 1));
	else if (*s1 != '\0' && *s2 == '*' && *s1 == *(s2 + 1))
		return (ft_match(s1, s2 + 1));
	else if (*s1 != '\0' && *s2 == '*')
		return (ft_match(s1 + 1, s2) || (ft_match(s1, s2 + 1)));
	else if (*s1 == '\0' && *s2 == '*')
		return (ft_match(s1, s2 + 1));
	if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
		return (1);
	else
		return (0);
}

int	ft_match_str(char *s1, char *s2, unsigned int size_s1, unsigned int size_s2)
{
	if (s1 == '\0' || s2 == '\0' || size_s1 < size_s2)
		return (0);
	if (ft_strcmp(ft_strsub(s1, 0, size_s2), s2) == 0)
		return (1);
	else
		return (ft_match_str(s1 + 1, s2, size_s1 - 1, size_s2));
}
