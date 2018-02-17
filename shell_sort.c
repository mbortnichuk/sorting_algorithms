/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 17:33:06 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/17 17:33:08 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
** ShellSort is mainly a variation of Insertion Sort. 
** In insertion sort, we move elements only one position ahead. 
** When an element has to be moved far ahead, many movements are involved. 
** The idea of shellSort is to allow exchange of far items. 
** In shellSort, we make the array h-sorted for a large value of h. 
** We keep reducing the value of h until it becomes 1. 
** An array is said to be h-sorted if all sublists of every h’th element is sorted.
*/

void	shell_sort(int arr[], int n)
{
	int i;
	int j;
	int k;
	int temp;

	for (i = n / 2; i > 0; i = i / 2)
	{
		for (j = i; j < n; j++)
		{
			for (k = j - i; k >= 0; k -= i)
			{
				if (arr[k + i] >= arr[k])
					break ;
				else
				{
					temp = arr[k];
					arr[k] = arr[k + i];
					arr[k + i] = temp;
				}
			}
		}
	}
}

/* 
** To print an array.
*/

void	print_array(int arr[], int size)
{
	int i = 0;

	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

/* Driver program to test above functions. */
int main(void)
{
	int arr[] = {54, 1, 34, 3, 8, 666, 12};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	printf("Given array is: \n");
	print_array(arr, arr_size);

	shell_sort(arr, arr_size);

	printf("Sorted array: \n");
	print_array(arr, arr_size);

	return (0);
}