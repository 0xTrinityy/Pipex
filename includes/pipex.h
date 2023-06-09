/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:24:22 by tbelleng          #+#    #+#             */
/*   Updated: 2023/04/03 17:12:27 by tbelleng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ERR_INFILE "Infile error\n"
# define ERR_OUTFILE "Outfile error\n"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe error \n"
# define ERR_CMD "Command not found\n"
# define NO_PATH "Path not found\n"

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipe[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;

}			t_pipe;

char		*find_path(char **envp);
void		close_pipes(t_pipe *data);
int			msg(char *err);
void		msg_error(char *err, t_pipe *data);
void		close_all(t_pipe *data);
void		parent_free(t_pipe *data);
void		child_free(t_pipe *data);
char		*get_cmd(char **paths, char *cmd);
void		first_child(t_pipe pipex, char **argv, char **envp);
void		second_child(t_pipe pipex, char **argv, char **envp);
void		error_free(t_pipe *data);

#endif