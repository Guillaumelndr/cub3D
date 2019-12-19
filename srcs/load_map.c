/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   load_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 15:05:35 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 09:25:38 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub.h"

size_t	ft_strlen_map(const char *line)
{
	size_t	i;

	i = 0;
	while (*line && *line == ' ')
		line++;
	while (line[i])
		i++;
	return (i);
}

char	*add_map_line(size_t len, char *line)
{
	char	*map_line;
	int		i;

	i = 0;
	if (!(map_line = malloc(sizeof(char) * len + 1)))
		put_error(3);
	while (*line && *line == ' ')
		line++;
	while (*line)
		map_line[i++] = *line++;
	map_line[len] = '\0';
	return (map_line);
}

int		check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i])
	{
		if (line[i] == 'R' || line[i] == 'N' || line[i] == 'S' || line[i] == 'O'
		|| line[i] == 'C' || line[i] == 'F' || line[i] == 'W' || line[i] == 'E')
			return (1);
		i++;
	}
	return (0);
}

int		info_map(t_cub *c, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**info;
	int		ret;

	i = 0;
	j = 0;
	ret = 1;
	line = NULL;
	if (!(info = malloc(sizeof(char *) * 9)))
		put_error(3);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (*line && *line == '1')
			i++;
		else if (check_line(line))
			info[j++] = add_map_line(ft_strlen_map(line), line);
		free(line);
	}
	info[8] = NULL;
	pars_info(c, info);
	close(fd);
	return (i);
}

char	**mapping(int size, char *path)
{
	char	*line;
	int		fd;
	char	**map;
	int		ret;
	int		i;

	ret = 1;
	i = -1;
	line = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
		put_error(2);
	if (!(map = malloc(sizeof(char *) * (size + 1))))
		put_error(3);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (*line && *line == '1')
			map[++i] = add_map_line(ft_strlen(line), line);
		free(line);
	}
	map[size] = NULL;
	close(fd);
	return (map);
}
