/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:59:32 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/24 13:59:39 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	err_handler(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	main(int argc, char **argv)
{
	char	**cln_nums;
	t_input	input;
	int		i;

	cln_nums = NULL;
	if (argc < 2)
		err_handler();
	else
	{
		input.argc = argc;
		input.argv = argv;
		cln_nums = ft_parser(input);
	}
	i = 0;
	is_allnums(cln_nums);
	is_nodup(cln_nums);
	while (cln_nums[i])
	{
		ft_printf("%d ", ft_atoi(cln_nums[i]));
		i++;
	}
	return (0);
}
