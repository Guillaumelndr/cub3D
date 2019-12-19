/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 07:22:50 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 09:58:12 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t		i;
	int			j;
	char		*st2;

	i = ft_strlen(s1);
	j = 0;
	st2 = (char *)s2;
	while (st2[j])
	{
		s1[i + j] = st2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
