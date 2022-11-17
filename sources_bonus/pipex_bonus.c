/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:07:51 by msotelo-          #+#    #+#             */
/*   Updated: 2022/11/03 08:04:00 by msotelo-         ###   ########.fr       */
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

void	check_entry(int argc, t_data *data)
{
	int	i;

	i = 0;
	if (argc < 5)
	{
		perror("Not enough arguments");
		exit(EXIT_FAILURE);
	}
	data->cmds = argc - 3;
}

void	aux_wait(t_data *data, int *pid)
{
	int	i;

	i = 0;
	while (i < data->cmds)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		i;
	int		*pid;

	i = 0;
	check_entry(argc, &data);
	data.count = 0;
	data.files[0] = open(argv[1], O_RDONLY);
	if (data.files[0] == -1)
	{
		perror("File not found");
		exit(EXIT_FAILURE);
	}
	data.files[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0777);
	pid = (int *)malloc(sizeof(int) * (argc - 3));
	if (pid == NULL)
		free(pid);
	while (i < data.cmds)
	{
		pid[i] = child_process(argv, &data, envp, i);
		i++;
	}
	aux_wait(&data, pid);
	return (0);
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
