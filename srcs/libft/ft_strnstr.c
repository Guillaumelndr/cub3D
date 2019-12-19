/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 11:37:02 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 09:58:12 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		sim;
	size_t		index;

	sim = 0;
	index = 0;
	if (!(needle[0]))
		return ((char *)haystack);
	while (haystack[index] && index != len)
	{
		while (haystack[index] == needle[sim] && index != len)
		{
			sim++;
			index++;
			if (sim == ft_strlen(needle))
				return ((char *)haystack + (index - sim));
		}
		index = index - sim + 1;
		sim = 0;
	}
	return (NULL);
}
