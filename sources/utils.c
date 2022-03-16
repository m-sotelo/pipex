/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:56:15 by msotelo-          #+#    #+#             */
/*   Updated: 2022/03/16 18:14:24 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "libft.h"

void	free_data(t_data *data, int	i)
{
	if (i == 0)
	{
		free(data->res);
		free(data->buf);
	}
	return ;
}

void	close_data(t_data *data, int i)
{
	if (i == 0)
	{
		close(data->files[0]);
		close(data->fd[1]);
	}
	else if (i == 1)
	{
		close(data->files[1]);
		close(data->fd[0]);
	}
	return ;
}

char	*find_path(char *cmd, char **envp)
{
	char	**posible_paths;
	char	*path;
	int		i;

	i = 0;
	while(ft_strnstr(envp[i],"PATH",4) == 0)
		i++;
	posible_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (posible_paths[i])
	{	
		path = ft_strjoin(posible_paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = 0;
	while(posible_paths[i])
	{
		free(posible_paths[i]);
		i++;
	}
	free(posible_paths);
	return (NULL);
}

void	execute(char *cmd, char **envp, t_data *data)
{
	int		i;
	char	**cmd_exec;

	cmd_exec = ft_split(cmd, ' ');
	data->path = find_path(cmd_exec[0], envp);
	if (data->path == NULL)
		exit(0);
	i = execve(data->path, cmd_exec, envp);
	if (i == -1)
		exit(0);
}
