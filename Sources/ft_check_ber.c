/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:30:11 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/24 16:45:25 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Checks the file name
*/

#include "soulong.h"

void	ft_check_ber(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] != 'r' || str[len - 2] != 'e' || \
		str[len - 3] != 'b' || str[len - 4] != '.')
		ft_exit(4);
}
