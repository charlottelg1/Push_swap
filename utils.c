/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-gran <cle-gran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:37:47 by cle-gran          #+#    #+#             */
/*   Updated: 2022/01/09 15:32:20 by cle-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkoverflow(char *str)
{
	int	i;

	i = 0;
	while (*str >= '0' && *str <= '9')
	{
		i++;
		str++;
	}
	if (i > 11)
		return (0);
	return (1);
}

void	error_atoi(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_atoi(char *str)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!checkoverflow(str))
		error_atoi();
	while (*str)
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	if (res * sign >= 2147483648 || res * sign < -2147483648)
		error_atoi();
	return (res * sign);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
