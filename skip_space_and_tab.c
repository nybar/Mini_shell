/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space_and_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbach <bbach@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:35:36 by bbach             #+#    #+#             */
/*   Updated: 2023/11/14 15:51:52 by bbach            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     valid_input(char *input)
{
    int     i;

    if (!input)
        return (1);
    i = 0;
    if (input[i] == '\0')
        return (1);
    return (0);
}