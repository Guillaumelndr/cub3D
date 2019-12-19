/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 13:46:32 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 11:34:00 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub.h"
#include "../includes/get_next_line.h"
#include "../includes/libft.h"
#include "../minilibix/mlx.h"

void	ft_print_map(t_cub *c)
{
	int		i;

	i = 0;
	while (c->texture[i])
		ft_putendl_fd(c->texture[i++], 1);
	i = 0;
	while (c->map[i])
		ft_putendl_fd(c->map[i++], 1);
}

void	run_game(t_cub *c)
{
	void	*mlx_id;
	void	*window_id;

	mlx_id = mlx_init();
	window_id = mlx_new_window(mlx_id, 500, 500, "test");
	mlx_loop(window_id);
	c->id = window_id;
}

int		main(int ac, char *av[])
{
	t_cub	*c;
	int		fd;

	if (ac != 2)
		put_error(1);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		put_error(2);
	if (!(c = malloc(sizeof(t_cub))))
		put_error(3);
	c->map = mapping(info_map(c, fd), av[1]);
	//ft_print_map(c);
	//run_game(c);
	free_struct(c);
	return (0);
}
