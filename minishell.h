/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:00:34 by bbach             #+#    #+#             */
/*   Updated: 2023/11/15 15:04:26 by bbach            ###   ########.fr       */
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
    char    *input;
    char	**env;
    char	**path;
    char	**cmd;
    char	**cmd_path;
    char	**split_args;
}                t_first;

typedef struct s_token
{
    char    *content;
    int     type;
}               t_token;

typedef struct s_minishell
{
    int     nb_s_quote;
    int     nb_d_quote;
    char    **str_in_d_quote;
    char    *input_dequoted;
}           t_minishell;

//--------------Minishell.c---------------------//

void    initialize(t_minishell *minishell);

//----------------Analyser.c--------------------//

char    **split_input(t_first first, char *input);

//--------------Skip_space_n_tab----------------//

int     valid_input(char *input);

//--------------Check_quotes.c------------------//

char     **check_double_quote(int i, t_minishell *minishell, char *input);
char	*ft_strndup(char *s, int n);
int     count_double_quote(char *input, t_minishell *minishell);
char    *dequotation(char *input, t_minishell *minishell);
int     how_many_str_to_malloc(char *input_dequoted, t_minishell *minishell);



# endif
