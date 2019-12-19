/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gulandre <gulandre@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 08:15:58 by gulandre     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 09:58:12 by gulandre    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int		len_nbr(long n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static char		*fillnbr(char *res, int len, long nb)
{
	if (nb < 0)
		nb *= -1;
	while (nb >= 0 && len - 1 != -1)
	{
		if (res[len - 1] != '-')
			res[len - 1] = '0' + (nb % 10);
		len--;
		nb /= 10;
	}
	return (res);
}

static char		*alloc_nbr(int len, long nb)
{
	char *nbr;

	if (!(nbr = ft_calloc(len + 1, sizeof(char))))
		return (0);
	if (nb < 0)
		nbr[0] = '-';
	nbr[len] = '\0';
	return (nbr);
}

char			*ft_itoa(int n)
{
	long	nb;
	char	*res;
	int		len;

	nb = (long)n;
	len = len_nbr(nb);
	if (!(res = alloc_nbr(len, nb)))
		return (0);
	res = fillnbr(res, len, nb);
	return (res);
}
