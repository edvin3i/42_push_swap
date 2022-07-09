/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:31:18 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/30 20:17:11 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	mv_cnt;

	if (is_sorted_stack(stack_a))
		return ;
	mv_cnt = ps_movescount(stack_a, min_index(stack_a, -1));
	if (mv_cnt == 1)
		ra(stack_a);
	else if (mv_cnt == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (mv_cnt == 3)
		rra(stack_a);
	if (is_sorted_stack(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	mv_cnt;

	mv_cnt = ps_movescount(stack_a, min_index(stack_a, -1));
	if (mv_cnt == 1)
		ra(stack_a);
	else if (mv_cnt == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (mv_cnt == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (mv_cnt == 4)
		rra(stack_a);
	if (is_sorted_stack(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	small_sel(t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = ps_lstsize(*stack_a);
	if (is_sorted_stack(stack_a) || !len || len == 1)
		return ;
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 4)
		sort_four(stack_a, stack_b);
	else if (len == 5)
		sort_five(stack_a, stack_b);
}
