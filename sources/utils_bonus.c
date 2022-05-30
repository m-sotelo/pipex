/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:56:15 by msotelo-          #+#    #+#             */
/*   Updated: 2022/05/30 14:31:05 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"
#include "libft.h"

void	free_path(char **posible_paths)
{
	int	i;

	i = 0;
	while (posible_paths[i])
	{
		free(posible_paths[i]);
		i++;
	}
	free(posible_paths);
	return ;
}

void	free_cmd(t_data *data)
{
	int	i;

	i = 0;
	while (data->cmd_exec[i])
	{
		free(data->cmd_exec[i]);
		i++;
	}
	free(data->cmd_exec);
	free(data->path);
	return ;
}

void	check_envp(char *cmd, char **envp, t_data *data)
{
	int		j;

	j = 0;
	data->cmd_exec = ft_split(cmd, ' ');
	if (access(data->cmd_exec[0], F_OK) == 0)
	{
		execve(data->cmd_exec[0], data->cmd_exec, envp);
	}
	while (data->cmd_exec[j])
	{
		free(data->cmd_exec[j]);
		j++;
	}
	free(data->cmd_exec);
	return ;
}

char	*find_path(char *cmd, char **envp)
{
	char	**posible_paths;
	char	*path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	posible_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (posible_paths[i])
	{	
		path = ft_strjoin(posible_paths[i], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, F_OK) == 0)
		{
			free_path(posible_paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_path(posible_paths);
	return (NULL);
}

void	execute(char *cmd, char **envp, t_data *data)
{
	int		j;

	j = 0;
	check_envp(cmd, envp, data);
	data->cmd_exec = ft_split(cmd, ' ');
	data->path = find_path(data->cmd_exec[0], envp);
	if (data->path == NULL)
	{
		free_cmd(data);
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	if (execve(data->path, data->cmd_exec, envp) == -1)
	{
		free_cmd(data);
		perror("Execution failed");
		exit(EXIT_FAILURE);
	}
	return ;
}
