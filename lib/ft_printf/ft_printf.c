/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:41:57 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/01/18 20:50:37 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static void	init_arr(t_ftp *funcs)
{
	funcs['c'] = flag_c;
	funcs['s'] = flag_s;
	funcs['p'] = flag_p;
	funcs['d'] = flag_di;
	funcs['i'] = flag_di;
	funcs['u'] = flag_u;
	funcs['x'] = flag_xl;
	funcs['X'] = flag_xu;
}

int	ft_printf(const char *str, ...)
{
	static t_ftp	funcs[256];
	va_list			args;
	int				cnt;

	if (!str)
		return (-1);
	init_arr(funcs);
	cnt = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && ++str && funcs[(int)*str])
			cnt += funcs[(int)*str++](args);
		else
			cnt += write(1, str++, 1);
	}
	va_end(args);
	return (cnt);
}
