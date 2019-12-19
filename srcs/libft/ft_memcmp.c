/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 14:05:42 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 09:58:12 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*st1;
	char	*st2;

	st1 = (char *)s1;
	st2 = (char *)s2;
	if (n == 0)
		return (0);
	while (n - 1 > 0)
	{
		if (*st1 != *st2)
			return ((unsigned char)*st1 - (unsigned char)*st2);
		n--;
		st1++;
		st2++;
	}
	return ((unsigned char)*st1 - (unsigned char)*st2);
}
