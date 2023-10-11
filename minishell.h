/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:00:34 by bbach             #+#    #+#             */
/*   Updated: 2023/10/11 18:06:13 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
 #define MINISHELL_H

# include "./includes/libft_Bbach/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <dirent.h>
# include <sys/param.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <termcap.h>

typedef struct s_first
{
    char	*line;
    char	**args;
    char	**env;
    char	**path;
    char	**cmd;
    char	**cmd_path;
    char	**cmd_args;
}                t_first;

 # endif
