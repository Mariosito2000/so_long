/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ber_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:30:11 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/28 16:06:48 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Checks the file name
*/

#include "soulong_bonus.h"

void	ft_check_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] != 'r' || str[len - 2] != 'e' || \
		str[len - 3] != 'b' || str[len - 4] != '.')
		ft_exit(4);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
