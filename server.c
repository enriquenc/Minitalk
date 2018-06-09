/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obamzuro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:54:27 by obamzuro          #+#    #+#             */
/*   Updated: 2018/05/19 23:28:29 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_input;

void	signal_handler(int signo)
{
	if (signo == SIGUSR1)
		g_input = 0;
	else if (signo == SIGUSR2)
		g_input = 1;
}

int		main(void)
{
	pid_t	serverpid;
	int		i;
	char	inputcharacter;

	i = 0;
	inputcharacter = 0;
	serverpid = getpid();
	ft_printf("%d\n", serverpid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
		inputcharacter += g_input << (7 - i);
		++i;
		if (i == 8)
		{
			write(1, &inputcharacter, 1);
			if (!inputcharacter)
				write(1, "\n", 1);
			inputcharacter = 0;
			i = 0;
		}
	}
}
