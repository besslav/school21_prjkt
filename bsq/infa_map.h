/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infa_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymaragre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:08:43 by ymaragre          #+#    #+#             */
/*   Updated: 2021/08/10 19:09:32 by ymaragre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFA_MAP_H
# define INFA_MAP_H

typedef struct s_inf
{
	int		count_str;
	int		len_str;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
	int		**map_bi;
}	t_inf;

#endif
