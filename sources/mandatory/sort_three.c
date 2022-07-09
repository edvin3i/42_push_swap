/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:37:35 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/30 16:31:48 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

static void	three_moves(t_node **stack)
{
	ra(stack);
	sa(stack);
	rra(stack);
}

static void	one_move(t_node **stack, t_node *node, int min)
{
	if (node->next->index == min)
		sa(stack);
	else
		rra(stack);
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
			ra(stack);
		else
		{
			sa(stack);
			rra(stack);
		}
	}
}
