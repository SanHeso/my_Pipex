#include "../includes/pipex.h"

char	*search(char **paths, char *find)
{
	int		i;
	char	*part;
	char	*path;

	i = 0;
	while (paths[i] && find[1] != '/')
	{
		part = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part, find);
		if (access(path, F_OK) == 0)
			return (path);
		free(part);
		free(path);
		i++;
	}
	if (find[0] == '/')
		return ("");
	if (access(find, F_OK) == 0)
		return (find);
	return (NULL);
}

char	*get_path(char **env, char **find)
{
	int		i;
	char	**paths;
	char	*path;

	i = find_lvl(env, "PATH=");
	paths = ft_split(env[i] + 5, ':');
	path = search(paths, *find);
	free_all(paths);
	return (path);
}
