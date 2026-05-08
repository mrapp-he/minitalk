/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:41:40 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/04/08 02:04:22 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "ft_printf/ft_printf.h"

typedef struct s_data
{
	int						size;
	int						index;
	int						ack;
	int						bit;
	int						bin;
	pid_t					pid;
	char					*str;
	struct sigaction		act;
}	t_data;

#endif
