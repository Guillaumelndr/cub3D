/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/17 14:02:49 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 09:25:50 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>

#include "../minilibix/mlx.h"
#include "./libft.h"
#include "./get_next_line.h"

typedef struct s_cub
{
    char **map;
    char **texture;
    void *id;
}   t_cub;

// ERROR & MEMORY

void    free_struct(t_cub *c);
void    put_error(int num);

/////////////////

// LOAD MAPP

int     info_map(t_cub *c, int fd);
char    **mapping(int size, char *path);
void    pars_info(t_cub *c, char **info);

/////////////////
#endif