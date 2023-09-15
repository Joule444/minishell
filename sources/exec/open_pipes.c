/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:02:44 by jthuysba          #+#    #+#             */
/*   Updated: 2023/07/05 17:27:14 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Ouvre toutes les pipes de la ligne de comande */
int	open_pipes(t_minishell *data)
{
	int	i;

	data->x->nb_cmd = nb_cmd(*(data->token));
	i = 0;
	if (data->x->nb_cmd <= 1)
		return (0);
	data->x->pipe = malloc(sizeof(int *) * data->x->nb_cmd - 1);
	while (i < data->x->nb_cmd - 1)
	{
		data->x->pipe[i] = malloc(sizeof(int) * 2);
		if (pipe(data->x->pipe[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}
