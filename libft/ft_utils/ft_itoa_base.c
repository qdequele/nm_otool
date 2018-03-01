/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qdequele <qdequele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:02:34 by qdequele          #+#    #+#             */
/*   Updated: 2018/02/28 20:57:00 by qdequele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa_base(int nb, int base)
{
	char			*str;
	size_t			len;
	size_t			neg;
	long long int	n;

	n = nb;
	len = ft_nbrlen_base(n, base);
	neg = ft_isnegative(n);
	str = (char *)malloc(sizeof(char) * (neg + len + 1));
	if (str == NULL)
		return (NULL);
	str[len + neg] = '\0';
	if (neg)
	{
		str[0] = '-';
		n = -n;
	}
	while ((len-- + neg) > neg)
	{
		str[len + neg] = (n % base) + ((n % base) > 9 ? 'A' - 10 : '0');
		n = n / base;
	}
	return (str);
}

char	*ft_uitoa_base(unsigned int nb, int base)
{
	char			*str;
	size_t			len;
	long long int	n;

	n = nb;
	len = ft_uilen_base(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (n % base) + ((n % base) > 9 ? 'A' - 10 : '0');
		n = n / base;
	}
	return (str);
}

char	*ft_itohex(int nb)
{
	char			*str;
	size_t			len;
	size_t			neg;
	long long int	n;

	n = nb;
	len = ft_nbrlen_base(n, 16);
	neg = ft_isnegative(n);
	str = (char *)malloc(sizeof(char) * (neg + len + 1));
	if (str == NULL)
		return (NULL);
	str[len + neg] = '\0';
	if (neg)
	{
		str[0] = '-';
		n = -n;
	}
	while ((len-- + neg) > neg)
	{
		str[len + neg] = (n % 16) + ((n % 16) > 9 ? 'A' - 10 : '0');
		n = n / 16;
	}
	return (str);
}

char	*ft_uitohex(unsigned int nb)
{
	char			*str;
	size_t			len;

	len = ft_uilen_base(nb, 16);
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (nb % 16) + ((nb % 16) > 9 ? 'a' - 10 : '0');
		nb = nb / 16;
	}
	return (str);
}

char	*ft_ultohex(unsigned long nb)
{
	char			*str;
	size_t			len;

	len = ft_ullen_base(nb, 16);
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (nb % 16) + ((nb % 16) > 9 ? 'a' - 10 : '0');
		nb = nb / 16;
	}
	return (str);
}
