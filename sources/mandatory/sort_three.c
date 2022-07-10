/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:37:35 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/10 06:36:41 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

static void	three_moves(t_node **stack)
{
	ra(stack, 1);
	sa(stack, 1);
	rra(stack, 1);
}

static void	one_move(t_node **stack, t_node *node, int min)
{
	if (node->next->index == min)
		sa(stack, 1);
	else
		rra(stack, 1);
}

void	sort_three(t_node **stack)
{
	int		min;
	int		min_next;
	t_node	*node;

	node = *stack;
	min = min_index(stack, -1);
	min_next = min_index(stack, min);
	if (is_sorted_stack(stack))
		return ;
	if (node->index == min && (node->next->index != min_next))
		three_moves(stack);
	else if (node->index == min_next)
		one_move(stack, node, min);
	else
	{
		if (node->next->index == min)
			ra(stack, 1);
		else
		{
			sa(stack, 1);
			rra(stack, 1);
		}
	}
}
