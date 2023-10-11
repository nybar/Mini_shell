/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:00:41 by bbach             #+#    #+#             */
/*   Updated: 2023/10/11 19:03:50 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"

int	main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    (void)env;
    
    t_first first;
    char    *input;

    while (1)
    {
        input = readline("minishell>$ ");
        if (!input)
            break;
        if (input)
            add_history(input);
        first.line = input;
        ft_printf("%s\n", first.line);
        free(input);
    }
}

char    *parse_input(char *input, char **env)
{
    char    **cmd;
    char    *path_line;
    int     i;

    i = -1;
    while (env[++i])
    {
        if (ft_strncmp("PATH=", env[i], 5) == 0)
                path_line = ft_strdup(env[i] + 5);
}
