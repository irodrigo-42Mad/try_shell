#include "minishell.h"

/*
** function creating for freeing matrixes
*/
void	free_matrix(char **matrix)
{
	int	i;
	int ln;

	i = 0;
	if (!matrix)
		return ;
	else
	{
		while (matrix[i])
		{
			ln = 0;
			while (matrix[i][ln])
			{
				matrix[i][ln] = '\0';
				ln++;
			}
			free(matrix[i]);
			i++;
		}
		free(matrix);
		matrix = NULL;
	}
}

void free_vars (t_sh_var *elm)
{
	t_sh_var *aux;

	if (!elm)
		return ;
	else
	{
		aux = elm;
		while (aux)
		{
			ft_bzero(elm->v_name, ft_strlen(elm->v_name));
			ft_bzero(elm->v_val, ft_strlen(elm->v_val));
			free(elm->v_name);
			free(elm->v_val);
			aux = elm->next;
			elm->next = NULL;
			free(elm);
			elm = NULL;
		}
		free(aux);
		aux = NULL;
	}
}

void free_nodes (t_lst *elm)
{
	t_lst *aux;

	if (!elm)
		return ;
	else
	{
		aux = elm;
		while (aux)
		{
			if(!elm->herename)
				ft_bzero(elm->herename, ft_strlen(elm->herename));
			if(!elm->str_cmd)
				ft_bzero(elm->str_cmd, ft_strlen(elm->str_cmd));
			if(!elm->str_line)
				ft_bzero(elm->str_line, ft_strlen(elm->str_line));
			if(!elm->str_aux)
				ft_bzero(elm->str_aux, ft_strlen(elm->str_aux));
			if(!elm->str_save)
				ft_bzero(elm->str_save, ft_strlen(elm->str_save));
			if(!elm->str_aux_save)
				ft_bzero(elm->str_aux_save, ft_strlen(elm->str_aux_save));
			elm->next = NULL;
			free(elm);
			elm = NULL;
		}
		free(aux);
		aux = NULL;
	}
}