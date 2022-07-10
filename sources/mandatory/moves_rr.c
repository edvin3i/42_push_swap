/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:17:31 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/10 06:41:37 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

int	move_rev(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (ps_lstsize(*stack) < 2)
		return (-1);
	first = *stack;
	last = ps_lstlast(first);
	while (first)
	{
		if (!first->next->next)
		{
			first->next = NULL;
			break ;
		}
		first = first->next;
	}
	last->next = *stack;
	*stack = last;
	return (0);
}

int	rra(t_node **stack, int p)
{
	if (move_rev(stack) < 0)
		return (-1);
	if (p)
		ft_printf("rra\n");
	return (0);
}

int	rrb(t_node **stack, int p)
{
	if (move_rev(stack) < 0)
		return (-1);
	if (p)
		ft_printf("rrb\n");
	return (0);
}

int	rrr(t_node **stack_a, t_node **stack_b, int p)
{
	if ((ps_lstsize(*stack_a) < 2) \
	|| (ps_lstsize(*stack_b) < 2))
		return (-1);
	move_rev(stack_a);
	move_rev(stack_b);
	if (p)
		ft_printf("rrr\n");
	return (0);
}
