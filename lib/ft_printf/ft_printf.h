/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:43:50 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/01/18 20:50:56 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define HEX_U "0123456789ABCDEF"
# define HEX_L "0123456789abcdef"
# define DEX "0123456789"

typedef int	(*t_ftp)(va_list);

int		ft_printf(const char *str, ...);
int		flag_c(va_list args);
int		flag_s(va_list args);
int		flag_p(va_list args);
int		flag_di(va_list args);
int		flag_u(va_list args);
int		flag_xl(va_list args);
int		flag_xu(va_list args);
char	*ft_itoa_base(unsigned long long nbr, int bsize, char *base);
size_t	ft_strlen(char	*str);

#endif
