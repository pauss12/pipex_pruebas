/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:51:48 by pmendez-          #+#    #+#             */
/*   Updated: 2024/07/29 19:51:59 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

# include "../libft/libft.h"

# define RED "\033[0;31m"
# define END "\033[0m"
# define WRITE 1
# define READ 0

typedef struct s_pipex
{
	char	**path;
	char	**envp;
	int		pipe_fd[2];
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;
}	t_pipex;

//utils.c
char	**get_path(char **envp);
void	free_double_str(char **str);
void	print_error(char *error_message, char *cmd);
char	*search_path(t_pipex *pipex, char **cmd_splitted);
void	error_no_cmd(char *error_message, int code, t_pipex *pipex);

// execution.c
void	first_command(t_pipex *pipex, char *cmd, char *file_name);
void	execute(t_pipex *pipex, char *command_argv);
void	check_if_accesible(char **str, t_pipex *pipex, char *cmd);
void	second_command(t_pipex *pipex, char *cmd, char *file_name);

//pipex.c
void	end_process(t_pipex *pipex);
void	close_fd(int *fd, char *name);

#endif
