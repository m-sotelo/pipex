/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msotelo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:07:51 by msotelo-          #+#    #+#             */
/*   Updated: 2022/03/16 18:14:48 by msotelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"
#include "libft.h"

int	check_entry(int argc)
{
	if (argc != 5)
		return (0);
	return (1);
}

void	child_process(char **argv, t_data *data, char **envp)
{
//	int		i;
//	int		k;

//	data->buf = (char *)malloc(sizeof(char));
//	data->res = (char *)malloc(sizeof(char));
	close(data->fd[0]);
	dup2(data->fd[1], 1);
	close(data->fd[1]);
	data->files[0] = open(argv[1], O_RDONLY);
	dup2(data->files[0], 0);
	execute(argv[2], envp, data);
	close(data->files[0]);
//	i = read(data->files[0], data->res, 1);
//	k = 0;
//	while (i != 0)
//	{
//		i = read(data->files[0], data->buf, 1);
//		data->res = ft_strjoin(data->res, data->buf);
//		k++;
//	}	
//	write(data->fd[1], data->res, k);
//	free_data(data, 0);
//	close_data(data, 0);
	return ;
}

void	father_process(char **argv, t_data *data, char **envp)
{
//	int		i;
//	int		k;

//	data->buf = (char *)malloc(sizeof(char));
//	data->res = (char *)malloc(sizeof(char));
	close(data->fd[1]);
	dup2(data->fd[0], 0);
	close(data->fd[0]);
	data->files[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	dup2(data->files[1], 1);
	execute(argv[3], envp, data);
	close(data->files[1]);
//	i = read(data->fd[0], data->res, 1);
//	k = 0;
//	while (i != 0)
//	{
//		i = read(data->fd[0], data->buf, 1);
//		data->res = ft_strjoin(data->res, data->buf);
//		k++;
//	}
//	write(data->files[1], data->res, k);
//	free_data(data, 0);
//	close_data(data, 1);
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
	data.check = check_entry(argc);
	pipe(data.fd);
	data.pid = fork();
	if (data.pid == 0)  //hijo
	{
		printf("\nSoy hijo, mi pid es: %d\n",getpid());
 		printf("\nMi padre tiene el pid: %d\n",getppid());
		child_process(argv, &data, envp);
	}
	else //padre
	{
		waitpid(data.pid, &data.status, 0);
		father_process(argv, &data, envp);
	}
//	atexit( leaks );
}
