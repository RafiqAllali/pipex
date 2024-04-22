/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rallali <rallali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 10:27:58 by rallali           #+#    #+#             */
/*   Updated: 2024/04/22 18:42:38 by rallali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**which_one(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '\'' || av[i] == '"')
			return (ft_split(av, av[i]));
		i++;
	}
	return (ft_split(av, ' '));
}

void	child_process(char **av, char **ev, int *ld)
{
	char	*path;
	char	**flag;
	int		infile;

	infile = open(av[1], O_RDONLY);
	protect(infile);
	flag = which_one(av[2]);
	path = execute(flag[0], ev);
	if (!path)
	{
		write(1,"command not found\n", 17);
		exit(1);
	}
	protect (close(ld[0]));
	protect (dup2(ld[1], 1));
	protect (dup2(infile, 0));
	protect (execve(path, flag, ev));
}

void	second_child(char **av, char **ev, int *ld)
{
	char	*path;
	char	**flag;
	int		outfile;

	flag = which_one(av[3]);
	path = execute(flag[0], ev);
	outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC , 0644);
	if (!path)
	{
		write(1,"command not found", 17);
		exit (1);
	}
	protect (outfile);
	protect (close(ld[1]));
	protect (dup2(ld[0], 0));
	protect (dup2(outfile, 1));
	protect (execve(path, flag, ev));
} 

int	main(int ac, char **av, char **ev)
{
	int	id;
	int	ld[2];
	int	k;


	if (ac != 5)
	{
		write(1, "Error: wrong number of arguments\n", 33);
		exit(EXIT_FAILURE);
	}
	protect(pipe(ld));
	id = fork();
	protect(id);
	if (id == 0)
		child_process(av, ev, ld);
	else
	{
		k = fork();
		if (k == 0)
			second_child(av, ev, ld);
	}
	close(ld[0]);
	close(ld[1]);
	wait(NULL);
	wait(NULL);
}
