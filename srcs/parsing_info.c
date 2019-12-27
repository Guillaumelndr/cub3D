/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_info.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 09:20:36 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 12:15:24 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub.h"

void	free_info(char **inf)
{
	int		i;

	i = 0;
	while (inf[i])
	{
		free(inf[i]);
		i++;
	}
	free(inf);
}

int		size_texture(char *line_inf)
{
	int		i;

	i = 0;
	while (*line_inf && *line_inf == ' ')
		line_inf++;
	while (*line_inf && *line_inf != ' ')
	{
		line_inf++;
		i++;
	}
	line_inf++;
	while (*line_inf && *line_inf != ' ')
	{
		line_inf++;
		i++;
	}
	return (i + 1);
}

char	*add_texture_info(char **info)
{
	int			j;
	int			x;
	static int	y = 0;
	char		*tmp;

	x = 0;
	j = 0;
	tmp = NULL;
	while (!tmp)
	{
		while (ft_isalpha(info[y][j]))
			j++;
		j = (j == 2) ? size_texture(info[y]) : 0;
		if (j)
		{
			if(!(tmp = malloc(sizeof(char) * j)))
				put_error(3);
			j = 0;
			while (info[y][j] && ft_isalpha(info[y][j]))
				tmp[x++] = info[y][j++];
			while (info[y][j] && info[y][j] == ' ')
				j++;
			while (info[y][j] && info[y][j] != ' ')
				tmp[x++] = info[y][j++];
			tmp[x] = '\0';
			j = 0;
		}
		y++;
	}
	return (tmp);
}

void	pars_info(t_cub *c, char **info)
{
	int		i;

	i = -1;
	if(!(c->texture = malloc(sizeof(char *) * 5)))
		put_error(3);
	while (++i != 4)
		c->texture[i] = add_texture_info(info);
	c->texture[4] = NULL;
	free_info(info);
}