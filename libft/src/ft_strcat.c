/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 08:20:16 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/03/24 08:20:17 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char *temp;

	temp = s1;
	while (*temp)
		temp++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (s1);
}