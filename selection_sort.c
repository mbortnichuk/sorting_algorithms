/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:01:32 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/17 16:01:35 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
** The selection sort algorithm sorts an array by repeatedly finding the minimum 
** element (considering ascending order) from unsorted part and putting it 
** at the beginning. The algorithm maintains two subarrays in a given array.
**
** 1) The subarray which is already sorted.
** 2) Remaining subarray which is unsorted.
** 
** In every iteration of selection sort, the minimum element 
** (considering ascending order) from the unsorted subarray 
** is picked and moved to the sorted subarray.
*/

void	my_swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void	selection_sort(int arr[], int n)
{
	int i;
	int j;
	int min_id;

	i = 0;
	/* One by one move boundary of unsorted subarray. */
	while (i < n - 1)
	{
		j = 0;
		min_id = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_id])
				min_id = j;
		my_swap(&arr[min_id], &arr[i]);
		i++;
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
	int arr[] = {2, 5, 999, 65, 11, 54, 287, 132, 3};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	printf("Given array is: \n");
	print_array(arr, arr_size);

	selection_sort(arr, arr_size);

	printf("Sorted array: \n");
	print_array(arr, arr_size);

	return (0);
}