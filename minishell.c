/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:00:41 by bbach             #+#    #+#             */
/*   Updated: 2023/11/16 14:14:23 by bbach            ###   ########.fr       */
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
    //t_token token;
    t_minishell minishell;
    //int i = 0;
    initialize(&minishell);
    while (1)
    {   
        initialize(&minishell);
        first.input = readline("minishell>$ ");
        if (valid_input(first.input) == 0)
        {
            add_history(first.input);
            dequotation(first.input, &minishell);
            printf("input_dequoted = %s\n", minishell.input_dequoted);
            count_double_quote(minishell.input_dequoted, &minishell);
            printf("nb_d_quote = %d\n", minishell.nb_d_quote);
            check_double_quote(0, &minishell, minishell.input_dequoted);
            // if (minishell.nb_d_quote < 2)
            //     ft_printf("Error: quote not closed\n");
            //printf("str_in_d_quote = %s\n", minishell.str_in_d_quote[0]);
            free(first.input);
        }
        else
            free(first.input);
    }
     return (0);   
}
void    initialize(t_minishell *minishell)
{
    //minishell->str_in_d_quote = NULL;
    minishell->nb_s_quote = 0;
    minishell->nb_d_quote = 0;
    //minishell->input_dequoted = NULL;
}
