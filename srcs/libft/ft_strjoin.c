/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 14:37:02 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 09:58:12 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	int		j;

	if (!s1 && !s2)
		return (ft_calloc(1, 1));
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	j = -1;
	if (!(str = (char *)malloc(sizeof(char) * i)))
		return (0);
	while (s1[++j])
		str[j] = s1[j];
	i = 0;
	while (s2[i])
	{
		str[j + i] = s2[i];
		i++;
	}
	str[j + i] = '\0';
	return (str);
}
