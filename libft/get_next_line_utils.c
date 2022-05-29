/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlyubick <vlyubick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 00:08:36 by vlyubick          #+#    #+#             */
/*   Updated: 2022/05/12 15:31:26 by vlyubick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gl_strlen(const char *s)
{
	int	l;

	if (s == NULL)
		return (0);
	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

int	findn(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*gl_strjoin(char *s1, char *s2)
{
	int		li[3];
	char	*str;

	if (s2 == NULL || s2[0] == '\0')
		return (NULL);
	li[0] = ft_strlen(s1);
	li[1] = ft_strlen(s2);
	li[2] = 0;
	str = (char *)malloc(sizeof(char) * (li[0] + li[1] + 1));
	if (!str)
		return (NULL);
	while (li[2] < li[0] + li[1] + 1)
	{
		if (li[2] < li[0])
			str[li[2]] = s1[li[2]];
		if (li[2] >= li[0])
			str[li[2]] = s2[li[2] - li[0]];
		li[2]++;
	}
	str[li[0] + li[1]] = '\0';
	if (s1 != NULL)
		free(s1);
	s1 = NULL;
	return (str);
}
