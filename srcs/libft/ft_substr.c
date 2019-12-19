/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 13:17:49 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 09:58:12 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;
	int		i;

	i = -1;
	if (!s)
		return (0);
	size = ft_strlen(s);
	if (start > size)
		return (ft_calloc(1, 1));
	if (start + len > size)
		if (!(str = ft_calloc(size - start, 1)))
			return (0);
	if (start + len <= size)
		if (!(str = ft_calloc(len + 1, 1)))
			return (0);
	while (s[start + ++i] && (unsigned long)i != len)
		str[i] = s[start + i];
	str[start + i] = '\0';
	return (str);
}
