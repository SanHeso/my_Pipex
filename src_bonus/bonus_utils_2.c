#include "../includes/pipex.h"

int	find_lvl(char **envp, char *find)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], find, ft_strlen(find)))
		i++;
	return (i);
}

void	ft_error(void)
{
	perror("Error");
	exit(0);
}

int	ft_access(char *path)
{
	if (access(path, F_OK) < 0)
		ft_error();
	else if (access(path, R_OK) < 0)
		ft_error();
	else if (access(path, W_OK) < 0)
		ft_error();
	else
		return (1);
	return (0);
}

void	free_all(char **arr)
{
	int	i;

	i = -1;
	if (!arr)
		ft_error();
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	wait_func(t_ppx *p, int size)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		waitpid(p->pid[i], NULL, 0);
		i++;
	}
	free(p->pid);
}
