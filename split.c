/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:28:14 by rallali           #+#    #+#             */
/*   Updated: 2024/04/20 14:41:33 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_count_words(const char *s, char c, int *ptr)
{
	char	last;
	int		i;
	int		count;

	last = c;
	i = 0;
	*ptr = 0;
	count = 0;
	while (s[i])
	{
		if (last == c && s[i] != c)
			count++;
		last = s[i];
		i++;
	}
	return (count);
}

static void	ft_free(char **result, int count)
{
	while (count-- > 0)
		free(result[count]);
	free(result);
}

static char	*ft_next_word(const char *s, char c)
{
	char	*sub;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	sub = (char *)malloc((i + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	sub[i] = '\0';
	while (i--)
		sub[i] = s[i];
	return (sub);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**sub;
	int		i;

	if (s == NULL)
		return (NULL);
	word_count = ft_count_words(s, c, &i);
	sub = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!sub)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			sub[i] = ft_next_word(s, c);
			if (!sub[i])
				return (ft_free(sub, i), NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (sub[i] = NULL, sub);
}
