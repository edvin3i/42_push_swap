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
	char		**cln_input;
	int			i;

	i = 0;
	while (cln_input[i])
	{
		ft_printf("%d ", ft_atoi(cln_input[i]));
		i++;
	}
	return (0);
}
