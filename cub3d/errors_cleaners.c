/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_cleaners.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskip <pskip@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:41:22 by pskip             #+#    #+#             */
/*   Updated: 2022/07/24 18:31:21 by pskip            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	error(char *err)
{
	write(2, err, ft_strlen(err));
	exit(1);
}

void	cleaner(char **spl)
{
	int	i;

	i = 0;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}
