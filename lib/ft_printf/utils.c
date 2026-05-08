/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:35:55 by mrapp-he          #+#    #+#             */
/*   Updated: 2024/12/01 17:21:40 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_itoa_base(unsigned long long nbr, int bsize, char *base)
{
	static char	arr[20];
	int			i;

	i = 20;
	if (nbr == 0)
	{
		arr[--i] = '0';
		return (&arr[i]);
	}
	while (nbr > 0)
	{
		arr[--i] = base[(nbr % bsize)];
		nbr /= bsize;
	}
	return (&arr[i]);
}
