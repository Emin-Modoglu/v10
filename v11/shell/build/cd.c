// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   cd.c                                               :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/03/15 19:48:33 by emmodogl          #+#    #+#             */
// /*   Updated: 2024/03/17 22:02:56 by emmodogl         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../include/minishell.h"
// #include <stdlib.h>
// #include <stdio.h>
// #include <errno.h>
// #include <string.h>

// void	exec_cd1(char *str, t_parse *data, t_mini *m_mini)
// {
// 	change_old(str, m_mini);
// 	chdir(get_home(m_mini));
// 	change_pwd(data, m_mini);
// 	m_mini->exec_status = 0;
// }

// void	exec_cd(t_parse *data, t_mini *m_mini)
// {
// 	char	*str;
// 	char	*str1;

// 	str = getcwd(NULL, 0);
// 	if (data->text && data->text[0])
// 	{
// 		if (chdir(data->text[0]) == 0)
// 		{
// 			change_old(str, m_mini);
// 			change_pwd(data, m_mini);
// 			m_mini->exec_status = 0;
// 		}
// 		else
// 		{
// 			str1 = strerror(errno);
// 		 	printf("%s",str);
// 			m_mini->exec_status = 1;
// 		}
// 	}
// 	else
// 		exec_cd1(str, data, m_mini);
// 	free(str);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmodogl <rootkalixox@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:48:33 by emmodogl          #+#    #+#             */
/*   Updated: 2024/03/17 20:24:21 by emmodogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void	exec_cd1(char *str, t_parse *data, t_mini *m_mini)
{
	change_old(str, m_mini);
	chdir(get_home(m_mini));
	change_pwd(data, m_mini);
	m_mini->exec_status = 0;
}

void	exec_cd(t_parse *data, t_mini *m_mini)
{
	char	*str;
	char	*str2;

	str = getcwd(NULL, 0);
	if (data->text && data->text[0])
	{
		if (chdir(data->text[0]) == 0)
		{
			change_old(str, m_mini);
			change_pwd(data, m_mini);
			m_mini->exec_status = 0;
		}
		else
		{
			str2 = strerror(errno);
		 	printf("minishell: %s\n",str2);
			m_mini->exec_status = 1;
		}
	}
	else
		exec_cd1(str, data, m_mini);
	free(str);
}
