/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:39:37 by msotelo-          #+#    #+#             */
/*   Updated: 2022/11/03 07:45:04 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"

void	child_process2(char **argv, t_data *data, char **envp, int i)
{
	if (i == data->cmds - 1)
	{
		close(data->fd[0]);
		dup2(data->files[1], 1);
		close(data->files[1]);
	}
	else if (i == 0)
	{
		close(data->fd[0]);
		dup2(data->files[0], 0);
		dup2(data->fd[1], 1);
		close(data->files[0]);
		close(data->fd[1]);
	}
	else
	{
		close(data->fd[0]);
		dup2(data->fd[1], 1);
		close(data->fd[1]);
	}
	execute(argv[i + 2], envp, data);
	return ;
}

void	father_process(t_data *data)
{
	close(data->fd[1]);
	dup2(data->fd[0], 0);
	close(data->fd[0]);
	return ;
}

int	child_process(char **argv, t_data *data, char **envp, int i)
{
	int	pid;
	int	j;

	j = pipe(data->fd);
	if (j == -1)
	{
		perror("error pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("error fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		child_process2(argv, data, envp, i);
		return (pid);
	}
	else
		father_process(data);
	return (pid);
}

/*void	child_process(char **argv, t_data *data, char **envp, int **fd)
{
	int	i;

	i = data->count;
	if (i == 0)
	{
		close(fd[i][0]);
		data->files[0] = open(argv[1], O_RDONLY);
		if (data->files[0] == -1)
		{
			perror("File not found");
			exit(EXIT_FAILURE);
		}
		dup2(data->files[0], 0);
		dup2(fd[i][1], 1);
		execute(argv[i + 2], envp, data);
		close(data->files[0]);
		close(fd[i][1]);
		data->count++;
		return ;
	}
	else if (i < data->cmds - 1)
	{
		data->check = pipe(fd[i]);
		close(fd[i - 1][1]);
		close(fd[i][0]);
		dup2(fd[i - 1][0], 0);
		dup2(fd[i][1], 1);
		execute(argv[i + 2], envp, data);
		close(fd[i - 1][0]);
		close(fd[i][1]);
		data->count++;
		return ;
	}
	else if (i == data->cmds - 1)
	{
		write(1, "HOLA1\n", 6);
		data->files[1] = open(argv[i + 3], O_RDWR | O_CREAT | O_TRUNC, 0777);
		close(fd[i - 1][1]);
		dup2(fd[i - 1][0], 0);
		dup2(data->files[1], 1);
		execute(argv[i + 2], envp, data);
		close(fd[i - 1][0]);
		close(data->files[1]);
		return;
	}
}

void	father_process(char **argv, t_data *data, char **envp, int **fd)
{
	int	i;

	i = data->count + 1;
	if (i < data->cmds - 1)
	{	
		data->check = pipe(fd[i]);
		close(fd[i - 1][1]);
		close(fd[i][0]);
		dup2(fd[i - 1][0], 0);
		//dup2(fd[i][1], 1);
		execute(argv[i + 2], envp, data);
		close(fd[i - 1][0]);
		close(fd[i][1]);
		data->count++;
		data->pid = fork();
		printf("esto es el pid:%i\n", data->pid);
		fork_pipe_check(data->check, data->pid);
		if (data->pid == 0)
		{
			child_process(argv, data, envp, fd);
		}
		else if (data->count < data->cmds - 1)
		{
			waitpid (data->pid, &data->status, 0);
			father_process (argv, data, envp, fd);
		}
		return ;
	}
	else if (i == data->cmds - 1)
	{	
		data->files[1] = open(argv[i + 3], O_RDWR | O_CREAT | O_TRUNC, 0777);
		close(fd[i - 1][1]);
		dup2(fd[i - 1][0], 0);
		dup2(data->files[1], 1);
		execute(argv[i + 2], envp, data);
		close(fd[i - 1][0]);
		close(data->files[1]);
		return;
	}
}*/
