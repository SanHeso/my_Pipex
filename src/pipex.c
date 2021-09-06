#include "../includes/pipex.h"

int	ppx_open(char *file, char **env, int flag, int mod)
{
	int		t;
	char	*pwd;
	char	*path;
	char	*part;

	t = find_lvl(env, "PWD=");
	pwd = env[t] + 4;
	part = ft_strjoin(pwd, "/");
	path = ft_strjoin(part, file);
	if (flag == (O_RDWR | O_CREAT) || ft_access(path))
	{
		if (mod)
			t = open(path, flag, mod);
		else
			t = open(path, flag);
		free(path);
		return (t);
	}
	free(path);
	return (-1);
}

void	child(t_ppx *p, char **argv, char **env, int i)
{
	if (i == 0)
	{
		p->in = ppx_open(argv[1], env, O_RDONLY, 0);
		if (p->in == -1 || (read(p->in, 0, 0)) < 0)
			ft_error();
		if (dup2(p->in, 0) < 0)
			ft_error();
		close(p->in);
	}
	else
		if (dup2(p->fd[0], 0) < 0)
			ft_error();
	if (dup2(p->fd[1], 1) < 0)
		ft_error();
	close(p->fd[1]);
	close(p->fd[0]);
	p->cmd = ft_split(argv[i + 2], ' ');
	if (execve(get_path(env, p->cmd), p->cmd, env) == -1)
		ft_error();
}

void	last_child(t_ppx *p, char **argv, char **env, int s)
{
	p->pid[s] = fork();
	if (!p->pid[s])
	{
		p->out = ppx_open(argv[s + 3], env, O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if (p->out == -1)
			ft_error();
		if (dup2(p->rem, 0) < 0)
			ft_error();
		close(p->rem);
		if (dup2(p->out, 1) < 0)
			ft_error();
		close(p->out);
		p->cmd = ft_split(argv[s + 2], ' ');
		if (execve(get_path(env, p->cmd), p->cmd, env) == -1)
			ft_error();
	}
}

void	parser(t_ppx *p, char **env, char **argv, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pipe(p->fd) == -1)
			ft_error();
		p->pid[i] = fork();
		if (p->pid[i] < 0)
			ft_error();
		if (i != 0)
			ft_swap(&p->fd[0], &p->rem);
		else
			p->rem = p->fd[0];
		if (p->pid[i] == 0)
			child(p, argv, env, i);
		fd_close(i, p->fd);
		i++;
	}
	last_child(p, argv, env, size);
	close(p->fd[0]);
	wait_func(p, size + 1);
}

int	main(int argc, char **argv, char **env)
{
	t_ppx	p;

	if (argc < 5)
	{
		perror("Error");
		return (1);
	}
	p.pid = malloc(sizeof(pid_t) * argc - 3);
	parser(&p, env, argv, argc - 4);
	return (0);
}
