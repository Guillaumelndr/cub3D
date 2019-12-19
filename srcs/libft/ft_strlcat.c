/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 08:17:17 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 09:58:12 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (dst[++i])
		len++;
	if ((int)size > i)
	{
		while (++i != (int)size && *src)
			dst[i - 1] = *src++;
		dst[i - 1] = '\0';
		return (ft_strlen(src) + ft_strlen(dst));
	}
	return (ft_strlen(src) + size);
}
