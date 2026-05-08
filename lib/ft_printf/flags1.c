/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:41:59 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/11/28 22:11:47 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_c(va_list args)
{
	char	chr;

	chr = va_arg(args, int);
	return (write(1, &chr, 1));
}

int	flag_s(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	flag_p(va_list args)
{
	unsigned long long	adrs;
	char				*str;

	adrs = va_arg(args, unsigned long);
	if (adrs == 0)
		return (write(1, "(nil)", 5));
	str = ft_itoa_base(adrs, 16, HEX_L);
	return (write(1, "0x", 2) + write(1, str, ft_strlen(str)));
}

int	flag_di(va_list args)
{
	long long	nbr;
	char		*str;
	int			cnt;

	nbr = va_arg(args, int);
	cnt = 0;
	if (nbr < 0)
	{
		cnt += write(1, "-", 1);
		nbr *= -1;
	}
	str = ft_itoa_base(nbr, 10, DEX);
	if (!str)
		return (write(1, "(null)", 6));
	return (cnt + write(1, str, ft_strlen(str)));
}

int	flag_u(va_list args)
{
	unsigned long long	nbr;
	char				*str;

	nbr = va_arg(args, unsigned int);
	str = ft_itoa_base(nbr, 10, DEX);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}
