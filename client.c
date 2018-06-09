/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:43:26 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/19 23:29:20 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char		*make_binary(int nbr)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * 9);
	result[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		result[i] = nbr % 2 + 48;
		nbr = nbr / 2;
		i--;
	}
	return (result);
}

int			push_letter(char *binary_letter, pid_t pid)
{
	int		j;

	j = 0;
	while (binary_letter[j])
	{
		if (binary_letter[j] == 48)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("killing error\n");
				return (1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("killing error\n");
				return (1);
			}
		}
		j++;
		usleep(50);
	}
	return (0);
}

int			main(int ac, char **av)
{
	pid_t	pid;
	int		i;
	char	*binary_letter;

	i = 0;
	if (ac != 3)
	{
		ft_printf("./client [server PID] [string to deliver]\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		binary_letter = make_binary((unsigned char)av[2][i++]);
		if (push_letter(binary_letter, pid))
			return (0);
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
	}
	free(binary_letter);
	return (0);
}
