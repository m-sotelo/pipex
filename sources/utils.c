/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:56:15 by msotelo-          #+#    #+#             */
/*   Updated: 2022/05/24 23:21:27 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "libft.h"

void	check_envp(char *cmd, char **envp)
{
	char	**cmd_exec;
	int		j;

	j = 0;
	cmd_exec = ft_split(cmd, ' ');
	if (access(cmd_exec[0], F_OK) == 0)
	{
		execve(cmd_exec[0], cmd_exec, envp);
	}
	while (cmd_exec[j])
	{
		free(cmd_exec[j]);
		j++;
	}
	free(cmd_exec);
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
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (posible_paths[i++])
		free(posible_paths[i]);
	free(posible_paths);
	return (NULL);
}

void	execute(char *cmd, char **envp, t_data *data)
{
	int		i;
	char	**cmd_exec;

	i = 0;
	check_envp(cmd, envp);
	cmd_exec = ft_split(cmd, ' ');
	data->path = find_path(cmd_exec[0], envp);
	if (data->path == NULL)
	{
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	i = execve(data->path, cmd_exec, envp);
	while (cmd_exec[i])
	{
		free(cmd_exec[i]);
	}
	free(cmd_exec);
	if (i == -1)
	{
		perror("Execution failed");
		exit(EXIT_FAILURE);
	}
}
