/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 15:14:55 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/17 15:15:00 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
** Bubble Sort is the simplest sorting algorithm that 
** works by repeatedly swapping the adjacent elements 
** if they are in wrong order.
** Example:
** First Pass:
** ( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
** ( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
** ( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
** ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), 
** algorithm does not swap them.
**
** Second Pass:
** ( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
** ( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
** ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
** ( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
** Now, the array is already sorted, but our algorithm does not know 
** if it is completed. The algorithm needs one whole pass 
** without any swap to know it is sorted.
**
** Third Pass:
** ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
** ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
** ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
** ( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
*/

void	my_swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void	bubble_sort(int arr[], int n)
{
	int i;
	int j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		/* Last i elements are already in place. */
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				my_swap(&arr[j], &arr[j + 1]);
			j++;
		}
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
	int arr[] = {43, 54, 12, 78, 321, 98, 1, 3};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	printf("Given array is: \n");
	print_array(arr, arr_size);

	bubble_sort(arr, arr_size);

	printf("Sorted array: \n");
	print_array(arr, arr_size);

	return (0);
}