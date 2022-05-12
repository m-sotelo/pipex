/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:04:22 by msotelo-          #+#    #+#             */
/*   Updated: 2022/05/12 22:05:23 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	int		check;
	int		pid;
	int		status;
	int		cmds;
	int		count;
	int		files[2];
	char	*path;
}			t_data;

void	fork_pipe_check(int check, int pid);
int		**check_entry(int argc, t_data *data);
void	child_process(char **argv, t_data *data, char **envp, int **fd);
void	father_process(char **argv, t_data *data, char **envp, int **fd);
void	free_data(t_data *data, int i);
void	close_data(t_data *data, int i);
void	execute(char *argv, char **envp, t_data *data);
char	*find_path(char *cmd, char **envp);
#endif
