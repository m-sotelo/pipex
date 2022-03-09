/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:07:29 by msotelo-          #+#    #+#             */
/*   Updated: 2022/03/09 14:44:42 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


typedef struct s_data
{
	int		check;
	int		fd[2];
	int		files[2];
	int		pid;
	int		status;
	char	*res;
	char	*buf;
	char	*path;
}			t_data;

int	check_entry(int argc);
void	child_process(char **argv, t_data *data, char **envp);
void	father_process(char **argv,  t_data *data, char **envp);
void	free_data(t_data *data, int i);
void	close_data(t_data *data, int i);
void	execute(char *argv, char **envp, t_data *data);
char	*find_path(char *cmd, char **envp);
