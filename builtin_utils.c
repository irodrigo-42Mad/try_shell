# include "minishell.h"

/*
** Notes to int	is_builtin(char *arg)
**
** we check if our arg is a builtin
**
*/
int	is_builtin(char *arg)
{
	if (precise_cmp(arg, "pwd", 3))
		return (1);
	else if (precise_cmp(arg,"cd", 2))
		return (1);
	else if (precise_cmp(arg, "echo", 4))
		return (1);
	else if (precise_cmp(arg, "env", 3))
		return (1);
	else if (precise_cmp(arg, "export", 6))
		return (1);
	else if (precise_cmp(arg,"unset", 5))
		return (1);
	else if (precise_cmp(arg, "exit", 4))
		return (1);
	else
		return (0);
}

/*
** Notes to void exec_builtin(char **arg, int type)
**
** we execute our builtin and exit if child
**
*/

void	exec_builtin(char **arg, int type)
{
	if (precise_cmp(arg[0], "pwd", 3))
		ft_pwd();
	else if (precise_cmp(arg[0],"cd", 2))
		ft_cd(arg[1]);
	else if (precise_cmp(arg[0], "echo", 4))
		ft_echo(arg);
	else if (precise_cmp(arg[0], "env", 3))
		ft_env();
	//else if (precise_cmp(arg[0], "export", 6))
	//	ft_export();
	//else if (precise_cmp(arg[0],"unset", 5))
	//	ft_unset();
	else if (precise_cmp(arg[0], "exit", 4))
		ft_exit(arg, type); 
	if (type == 0) //0 means child
		exit (0);
}

int precise_cmp(char *s1,char *s2, size_t size) // a strncmp that takes the lenght into account
{
	if (ft_strlen(s1) == size && ft_strlen(s2) == size && !ft_strncmp(s1, s2, size))
		return (1);
	return(0);
}