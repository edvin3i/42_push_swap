/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 08:09:12 by gbreana           #+#    #+#             */
/*   Updated: 2022/07/10 07:07:32 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	if (argc < 2)
		exit(0);
	validation(argc, argv, 0);
	stack_a = ps_lstcreate();
	stack_b = ps_lstcreate();
	ps_init_stack(stack_a, argc, argv);
	push_swap(stack_a, stack_b);
	ps_free_stack(stack_a);
	ps_free_stack(stack_b);
	return (0);
}
