/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:07:51 by msotelo-          #+#    #+#             */
/*   Updated: 2022/05/24 23:22:26 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "libft.h"

void	check_entry(int argc)
{
	if (argc < 5)
	{
		perror("Not enough arguments");
		exit(EXIT_FAILURE);
	}
	else if (argc > 5)
	{
		perror("Too many arguments");
		exit(EXIT_FAILURE);
	}
}

void	child_process(char **argv, t_data *data, char **envp)
{
	close(data->fd[0]);
	dup2(data->fd[1], 1);
	data->files[0] = open(argv[1], O_RDONLY);
	if (data->files[0] == -1)
	{
		perror("File not found");
		exit(EXIT_FAILURE);
	}
	dup2(data->files[0], 0);
	execute(argv[2], envp, data);
	close(data->fd[1]);
	close(data->files[0]);
	return ;
}

void	father_process(char **argv, t_data *data, char **envp)
{
	close(data->fd[1]);
	dup2(data->fd[0], 0);
	close(data->fd[0]);
	data->files[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
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

	i = 0;
	check_entry(argc);
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
		child_process (argv, &data, envp);
	else
	{
		waitpid (data.pid, &data.status, 0);
		father_process (argv, &data, envp);
	}
}
