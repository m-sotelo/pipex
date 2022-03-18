/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:07:51 by msotelo-          #+#    #+#             */
/*   Updated: 2022/03/18 17:59:04 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"
#include "libft.h"

void	check_entry(int argc)
{
	if (argc < 5)
	{
		perror("Not enough arguments");
		exit(EXIT_FAILURE);
	}
}

void	child_process(char **argv, t_data *data, char **envp, int i)
{
	if (pipe(data->fd) == -1)
	{
		perror("Error pipe");
		exit(EXIT_FAILURE);
	}
	close(data->fd[0]);
	dup2(data->fd[1], 1);
	close(data->fd[1]);
	data->files[0] = open(argv[1], O_RDONLY);
	if (data->files[0] == -1)
	{
		perror("File not found");
		exit(EXIT_FAILURE);
	}
	dup2(data->files[0], 0);
	execute(argv[i], envp, data);
	close(data->files[0]);
	return ;
}

void	father_process(char **argv, t_data *data, char **envp)
{
	close(data->fd[1]);
	dup2(data->fd[0], 0);
	close(data->fd[0]);
	data->files[1] = open(argv[data->cmd_num], O_RDWR | O_CREAT | O_TRUNC, 0777);
	dup2(data->files[1], 1);
	execute(argv[3], envp, data);
	close(data->files[1]);
	return ;
}

/*void	leaks( void ){
	system( "leaks pipex" );
}*/

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		i;

	i = 1;
	data.cmd_num = argc - 1;
	check_entry(argc);
	data.pid = fork();
	if (data.pid == -1)
	{
		perror("Error fork");
		exit(EXIT_FAILURE);
	}
	else if (data.pid == 0)
		while(i++ < (data.cmd_num - 1))
			child_process (argv, &data, envp, i);
	else
	{
		waitpid (data.pid, &data.status, 0);
		father_process (argv, &data, envp);
	}
}
