/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 10:06:27 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 09:58:12 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!(dst) && !(src))
		return (NULL);
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	i = -1;
	if (str1 == str2)
		return (dst);
	if (str1 < str2)
		while (++i != (int)len)
			str1[i] = str2[i];
	else
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			str1[i] = str2[i];
			i--;
		}
	}
	dst = str1;
	return (dst);
}
