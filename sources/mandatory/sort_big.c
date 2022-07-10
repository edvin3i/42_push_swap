/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:40:09 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/10 06:32:25 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	mv_down(t_params *params)
{
	params->stack_a->flag = -1;
	ra(params->stack_a);
}

int	min_b_a(t_params *p)
{
	int	min;

	min = p->stack_a->prev->index + 1;
	if (p->stack_b->index == min)
	{
		pa(p->stack_a, p->stack_b);
		mv_down(p);
		return (1);
	}
	else if (p->stack_a->index == min)
		mv_down(p);
	else if (p->stack_a->next->index == min)
	{
		sa(p->stack_a);
		mv_down(p);
	}
}
