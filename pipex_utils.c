/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:28:08 by rallali           #+#    #+#             */
/*   Updated: 2024/04/22 18:18:34 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path(char **str)
{
	char	*c;
	int		i;
	int		j;
	int		l;

	i = -1;
	j = 0;
	l = 0;
	c = "PATH=";
	while (str[++i])
	{
		j = 0;
		while (str[i][j])
		{
			l = 0;
			while (str[i][j++] == c[l])
				l++;
			if (c[l] == '\0')
				return (str[i] + j);
			j++;
		}
	}
	return (NULL);
}

char	*ft_strjoin(char *str, char *str1)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!str)
		return (str1);
	if (!str1)
		return (str);
	while (str[i])
		i++;
	while (str1[j])
		j++;
	s = malloc((i + j + 1) * sizeof(char));
	if (!s)
		return (free(str), free(str1), str = NULL, NULL);
	i = -1;
	while (str[++i])
		s[i] = str[i];
	j = -1;
	while (str1[++j])
		s[i + j] = str1[j];
	s[i + j] = '\0';
	return (free(str), s);
}

void	protect(int any)
{
	if (any == -1)
	{
		perror("Error");
		exit(1);
	}
}

char	*execute(char *cmd, char **ev)
{
	char	**s;
	char	*n;
	char	*c;
	int		i;

	i = 0;
	c = path(ev);
	if (!c)
		return (NULL);
	s = ft_split(c, ':');
	if (!s)
		return (NULL);
	while (s[i])
	{
		n = ft_strjoin(s[i], "/");
		n = ft_strjoin(n, cmd);
		i++;
		if (access(n, X_OK) == 0)
		{
			return (n);
		}
	}
	return (NULL);
}
