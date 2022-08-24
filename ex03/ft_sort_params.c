/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantonio <aantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 11:31:58 by aantonio          #+#    #+#             */
/*   Updated: 2022/08/24 22:25:56 by aantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	swap_contents(char *str_array[], int index1, int index2)
{
	char	*temp;

	temp = str_array[index1];
	str_array[index1] = str_array[index2];
	str_array[index2] = temp;
}

int	check_if_ordered(char *str_array[], int array_length)
{
	int	i;
	int	j;

	i = 0;
	while (i < array_length - 1)
	{
		j = 0;
		while (str_array[i][j] == str_array[i + 1][j])
		{
			if (str_array[i][j] == 0 && str_array[i + 1][j] != 0)
				break ;
			if (str_array[i][j] != 0 && str_array[i + 1][j] == 0)
				return (0);
			j++;
		}
		if (str_array[i][j] > str_array[i + 1][j])
			return (0);
		i++;
	}
	return (1);
}

void	order_array(char *str_array[], int array_length)
{
	int	i;
	int	j;

	i = 0;
	while (!check_if_ordered(str_array, array_length))
	{
		j = 0;
		while (str_array[i][j] == str_array[i + 1][j])
		{
			if (str_array[i][j] == 0 || str_array[i + 1][j] == 0)
				break ;
			j++;
		}

		i = 0;
		while (i < (array_length - 1) && str_array[i][j] <= str_array[i + 1][j])
		{
			i++;
		}
		if (i < array_length - 1)
			swap_contents(str_array, i, i + 1);
	}
}

int	main(int argc, char *argv[])
{
	int		arguments;
	int		c;
	char	**start;

	if (argc == 1)
		return (0);
	start = argv + 1;
	write(1,"before Orderin\n",16);
	order_array(start, argc - 1);
	write(1,"after Orderin\n",15);
	arguments = 1;
	while (arguments < argc)
	{
		c = 0;
			int test = arguments + '0';
			write(1,"printing argument ",19);
			write(1, &test,1);
			write(1, "\n ",1);
		while (argv[arguments][c])
		{
			write(1, argv[arguments] + c, 1);
			c++;
		}
		write(1, "\n", 1);
		arguments++;
	}
	return (0);
}
