/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 06:24:12 by rallali           #+#    #+#             */
/*   Updated: 2024/04/22 18:28:45 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H



# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

char	**ft_split(char const *s, char c);
char	*path(char **str);
char	*ft_strjoin(char *s1, char *s2);
void	protect(int any);
char	*execute(char *cmd, char **ev);
void	child_process(char **av, char **ev, int *ld);
void	parents(char **av, char **ev, int *ld);

#endif