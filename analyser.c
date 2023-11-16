/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:38:56 by bbach             #+#    #+#             */
/*   Updated: 2023/10/14 17:47:55 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    **split_input(t_first first, char *input)
{
    (void)input;
    char    *tmp;
    char    **analysing;

tmp = first.input;
analysing = ft_split(tmp, ' ');
free (tmp);
return (analysing);
}
