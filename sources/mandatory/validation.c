/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:48:43 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/31 01:06:51 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

int	is_allnums(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (argc == 2)
					ps_free_str(argv);
				error();
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_nodup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoin(argv[i]) == ft_atoin(argv[j]))
			{
				if (argc == 2)
					ps_free_str(argv);
				error();
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted_arr(int argc, char **argv)
{
	int	i;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	while (argv[i + 1])
	{
		if (ft_atoin(argv[i]) < ft_atoin(argv[i + 1]))
			i++;
		else
			return (0);
	}
	if (argc == 2)
		ps_free_str(argv);
	exit(0);
}

void	validation(int argc, char **argv)
{
	char	**tmp;

	if (argc == 2)
		tmp = ft_split(argv[1], ' ');
	else
		tmp = argv;
	is_allnums(argc, tmp);
	is_nodup(argc, tmp);
	is_sorted_arr(argc, tmp);
	if (argc == 2)
		ps_free_str(tmp);
}
