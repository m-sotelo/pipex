/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:56:15 by msotelo-          #+#    #+#             */
/*   Updated: 2022/05/12 22:05:28 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex_bonus.h"
#include "libft.h"

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
	int		j;
	char	**cmd_exec;

	i = 0;
	j = 0;
	cmd_exec = ft_split(cmd, ' ');
	data->path = find_path(cmd_exec[0], envp);
	if (data->path == NULL)
	{
		perror("Command not found");
		exit(EXIT_FAILURE);
	}
	i = execve(data->path, cmd_exec, envp);
	while (cmd_exec[j])
	{
		free(cmd_exec[j]);
		j++;
	}
	free(cmd_exec);
	if (i == -1)
	{
		perror("Execution failed");
		exit(EXIT_FAILURE);
	}
	return ;
}
