/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:54:51 by irodrigo          #+#    #+#             */
/*   Updated: 2022/03/09 12:52:27 by irodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_heredoc(void)
{
 	t_lst	*lst;
 	char	*tmp;
 	int		x;

 	x = g_ms->prcs_n;
 	lst = g_ms->instr;
 	while (x-- > 0)
 	{
 		ft_set_hdoc(lst);
// 		rebuild_aux_strings(node);
 		lst = lst->next;
		//i--;
 	}
 	tmp = set_hdocfname(NOT_EXIST);
 	free(tmp);
}

char	*set_hdocfname(int exist)
{
	static int	x;
	char		*f_name;
	char		*tmp;

	if (!x)
		x = 0;
	tmp = NULL;
	f_name = NULL;
	if (exist == 0)
		x = 0;
	else
	{
		tmp = ft_itoa(x);
		f_name = ft_strjoin(".here_doc", ft_itoa(x));
		free(tmp);
		x++;
	}
	return (f_name);
}