/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:49:09 by ademarti          #+#    #+#             */
/*   Updated: 2024/06/06 14:43:01 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchar_fd_(char c, int fd)
{
	int	count;

	count = 0;
	write(fd, &c, 1);
	count++;
	return (count);
}

void	ft_putstr_fd_(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd_("(null)", 1);
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_putchar_fd_(str[i], 1);
		i++;
	}
	return (i);
}
