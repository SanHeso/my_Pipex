#ifndef PIPEX_H
# define PIPEX_H
# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"
# include "string.h"
# include "fcntl.h"
# include "sys/wait.h"
# include "sys/types.h"

typedef struct s_ppx
{
	char	**cmd;
	int		fd[2];
	int		rem;
	int		in;
	int		out;
	int		*pid;
}				t_ppx;

int		ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		find_lvl(char **envp, char *find);
int		ft_access(char *path);
void	ft_error(void);
char	**ft_split(char const *s, char c);
void	free_all(char **arr);
char	*search(char **paths, char *find);
char	*get_path(char **env, char **find);
void	wait_func(t_ppx *p, int size);
void	ft_swap(int *a, int *b);
void	fd_close(int i, int *fd);

#endif