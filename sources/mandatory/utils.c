/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:17:53 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/30 15:19:27 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

int	is_sorted_stack(t_node **stack)
{
	t_node	*node;

	node = *stack;
	while (node && node->next)
	{
		if (node->num > node->next->num)
			return (0);
		node = node->next;
	}
	return (1);
}

int	min_index(t_node **stack, int num)
{
	int		min_index;
	t_node	*node;

	node = *stack;
	min_index = node->index;
	while (node->next)
	{
		node = node->next;
		if ((node->index < min_index) && (node->index != num))
			min_index = node->index;
	}
	return (min_index);
}

int	ps_index_bmax(t_node **stack)
{
	int		max;
	int		curr_max;
	t_node	*node;

	node = *stack;
	max = 0;
	curr_max = node->index;
	while (node)
	{
		if (node->index > curr_max)
			curr_max = node->index;
		node = node->next;
	}
	while ((curr_max >> max) != 0)
		max++;
	return (max);
}
