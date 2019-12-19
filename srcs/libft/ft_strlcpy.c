/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 08:17:04 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 09:42:58 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;

	i = 0;
	while (i != size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (!src[i])
		dst[i] = '\0';
	else
		dst[i - 1] = '\0';
	return (ft_strlen(src));
}
