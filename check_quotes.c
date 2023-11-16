/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:55:48 by bbach             #+#    #+#             */
/*   Updated: 2023/11/16 13:33:45 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *dequotation(char *input, t_minishell *minishell)
{
    int i = 0;
    int j = 0;

    minishell->input_dequoted = malloc(sizeof(char) * ft_strlen(input) + 1);
    if (!minishell->input_dequoted)
        return (NULL);
    while (input[i])
    {
        if ((input[i] == 34 && input[i + 1] == 34) || (input[i] == 39 && input[i + 1] == 39))
            i++;
        if ((input[i] == 34 && input[i - 1] == 34) || (input[i] == 39 && input[i - 1] == 39))
            i++;
        minishell->input_dequoted[j] = input[i];
        j++;
        i++;
    }
    minishell->input_dequoted[j] = '\0';
    return (minishell->input_dequoted);
}

int     count_double_quote(char *input, t_minishell *minishell)
{
    int i = 0;

    while (input[i])
    {
        if (input[i] == 34)
            minishell->nb_d_quote++;
        i++;
    }
    return (minishell->nb_d_quote);
}
int      how_many_str_to_malloc(char *input_dequoted, t_minishell *minishell)
{
    int nb_quote = 0;
    int nb_string = 0;

    while (*input_dequoted && minishell->nb_d_quote > 0)
    {
        if (*input_dequoted == 34)
        {
            minishell->nb_d_quote--;
            nb_quote++;
            while (*input_dequoted)
            {
                input_dequoted++;
                if (*input_dequoted == 34)
                {
                    minishell->nb_d_quote--;
                    nb_quote++;
                    if (nb_quote % 2 == 0 || minishell->nb_d_quote == 0)
                    {
                        nb_string++;
                        break;
                    } 
                }
            }
        }
        input_dequoted++;
    }
    return (nb_string);
}
char     **check_double_quote(int i, t_minishell *minishell, char *input)
{
    int j, k, f = 0;
    int nb_string = 0;

    i = 0;
    nb_string = how_many_str_to_malloc(minishell->input_dequoted, minishell);
    ft_printf("nb_string = %d\n", nb_string);
    minishell->str_in_d_quote = malloc(sizeof(char *) * nb_string + 1);
    //count_double_quote(minishell->input_dequoted, minishell);
    // if (minishell->nb_d_quote % 2 != 0)
    //     ft_printf("Error: quote not closed\n");
    if(!minishell->str_in_d_quote)
        return (NULL);
    while (input[i])
    {
        if (input[i] == 34)
        {
            j = i + 1;
            minishell->nb_d_quote--;
            while (input[i])
            {
                i++;
                if (input[i] == 34)
                {
                    k = i - 1;
                    minishell->nb_d_quote--;
                    if (minishell->nb_d_quote % 2 == 0 || minishell->nb_d_quote == 0)
                    {
                        if (nb_string-- > 0)
                        {
                            minishell->str_in_d_quote[f] = ft_strndup(input + j, k - j + 1);
                            ft_printf("str_in_d_quote[%d] = %s\n", f, minishell->str_in_d_quote[f]);
                            f++;
                            break;
                        }
                    }
                }
            }
        }
        i++;
    }
    return (NULL);
}

char	*ft_strndup(char *s, int n)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (dst == NULL)
		return (NULL);
	while (s[i] && i < n)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}