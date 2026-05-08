/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrapp-he <mrapp-he@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:49:56 by mrapp-he          #+#    #+#             */
/*   Updated: 2025/04/08 21:53:20 by mrapp-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk.h"

static t_data	*db(void)
{
	static t_data	db;

	return (&db);
}

static void	sig_receiver(int sig)
{
	if (sig == SIGUSR1)
		db()->ack = 1;
	else if (sig == SIGUSR2)
	{
		db()->ack = 1;
		ft_printf("Message Received!\n");
	}
}

static void	send_size(void)
{
	db()->bit = 0;
	while (db()->bit < 32)
	{
		if (db()->size & (1 << db()->bit))
			db()->bin = kill(db()->pid, SIGUSR1);
		else
			db()->bin = kill(db()->pid, SIGUSR2);
		if (db()->bin == -1)
			exit(ft_printf("Invalid PID\n"));
		while (!db()->ack)
			usleep(100);
		db()->bit++;
		db()->ack = 0;
	}
}

static void	send_str(void)
{
	db()->size = ft_strlen(db()->str);
	send_size();
	while (db()->index <= db()->size)
	{
		db()->bit = 0;
		while (db()->bit < 8)
		{
			if (db()->str[db()->index] & (1 << db()->bit))
				kill(db()->pid, SIGUSR1);
			else
				kill(db()->pid, SIGUSR2);
			while (!db()->ack)
				usleep(100);
			db()->bit++;
			db()->ack = 0;
		}
		db()->index++;
	}
	db()->size = 0;
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (*av[1] && *av[1] == '+')
			av[1]++;
		while (*av[1] >= '0' && *av[1] <= '9')
			db()->pid = (db()->pid * 10) + (*av[1]++ - '0');
		if (db()->pid == 0)
			exit(ft_printf("Invalid PID\n"));
		db()->str = av[2];
		signal(SIGUSR2, sig_receiver);
		signal(SIGUSR1, sig_receiver);
		send_str();
	}
	else
		exit(ft_printf("Error\n"));
	return (0);
}
