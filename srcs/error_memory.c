/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error_memory.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 13:51:38 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 10:45:51 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub.h"

void	free_struct(t_cub *c)
{
	int		i;

	i = 0;
	if (c->map)
	{
		while (c->map[i])
			free(c->map[i++]);
		free(c->map);
	}
	i = 0;
	if (c->texture)
	{
		while (c->texture[i])
			free(c->texture[i++]);
		free(c->texture);
	}
	free(c);
}

void	put_error(int num)
{
	if (num == 1)
		ft_putendl_fd("invalid numbers of arguments!", 1);
	if (num == 2)
		ft_putendl_fd("invalid path!", 1);
	if (num == 3)
		ft_putendl_fd("error malloc!", 1);
	exit(-1);
}
