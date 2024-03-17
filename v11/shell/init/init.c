/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 05:24:46 by atasyure          #+#    #+#             */
/*   Updated: 2024/03/17 21:44:43 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdlib.h>
#include <stdio.h>

int	init(t_mini **mini)
{
	*mini = ft_calloc(1,sizeof(t_mini));
	if (!(*mini))
		return (1);
	(*mini)->lex_list = ft_calloc(1,sizeof(t_lexer));
	if (!(*mini)->lex_list)
		return (free(*mini),printf(A_ERR), 1); //changed
	g_heredoc_sig = 0;
	return (0);
}

void	proper_free(t_list **node)
{
	t_list *curr_node;
	t_list *temp;

	curr_node = *node;

	while(curr_node != NULL)
	{
		free(curr_node->content);
		curr_node->content = NULL;
		temp = curr_node;
		curr_node = curr_node->next;
		free(temp);
		temp = NULL;
	}
}


