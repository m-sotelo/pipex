/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:07:51 by msotelo-          #+#    #+#             */
/*   Updated: 2022/05/12 22:05:31 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"
#include "libft.h"

void	fork_pipe_check(int check, int pid)
{
	if (check == -1)
	{
		perror("Error pipe");
		exit(EXIT_FAILURE);
	}
	else if (pid == -1)
	{
		perror("Error fork");
		exit(EXIT_FAILURE);
	}
	return ;
}

int	**check_entry(int argc, t_data *data)
{
	int	**fd;
	int	i;

	i = 0;
	if (argc < 5)
	{
		perror("Not enough arguments");
		exit(EXIT_FAILURE);
	}
	data->cmds = argc - 3;
	fd = (int **)malloc(sizeof(int *) * (argc - 4));
	while (i < argc - 4)
	{
		fd[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	return (fd);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		i;	
	int		**fd;

	i = 0;
	fd = check_entry(argc, &data);
	data.count = 0;
	data.check = pipe(fd[0]);
	data.pid = fork();
	fork_pipe_check(data.check, data.pid);
	if (data.pid == 0)
	{
		child_process (argv, &data, envp, fd);
	}
	else
	{
		waitpid(data.pid, &data.status, 0);
		father_process (argv, &data, envp, fd);
	}
}

/*void	leaks( void ){
	system( "leaks pipex" );
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		i;
	int		cmds;

	i = 0;
	cmds = check_entry(argc);
	if (pipe(data.fd) == -1)
	{
		perror("Error pipe");
		exit(EXIT_FAILURE);
	}
	data.pid = fork();
	if (data.pid == -1)
	{
		perror("Error fork");
		exit(EXIT_FAILURE);
	}
	else if (data.pid == 0)
		child_process (argv, &data, envp, cmds);
	else
	{
		waitpid (data.pid, &data.status, 0);
		father_process (argv, &data, envp, cmds);
	}
}*/
