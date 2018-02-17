/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 15:45:28 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/17 15:55:29 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
**
** Insertion sort is a simple sorting algorithm that works the way 
** we sort playing cards in our hands.
**
** 12, 11, 13, 5, 6
**
** Let us loop for i = 1 (second element of the array) to 5 (Size of input array)
**
** i = 1. Since 11 is smaller than 12, move 12 and insert 11 before 12
** 11, 12, 13, 5, 6
**
** i = 2. 13 will remain at its position as all elements in A[0..I-1] are smaller than 13
** 11, 12, 13, 5, 6
**
** i = 3. 5 will move to the beginning and all other elements from 11 to 13 will move one position ahead of their current position.
** 5, 11, 12, 13, 6
** 
** i = 4. 6 will move to position after 5, and elements from 11 to 13 will move one position ahead of their current position.
** 5, 6, 11, 12, 13
*/

void	insertion_sort(int arr[], int n)
{
	int i;
	int j;
	int key;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are greater than key,
		to one position ahead of their current position. */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
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
	int arr[] = {43, 65, 11, 16, 1, 5, 9};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	printf("Given array is: \n");
	print_array(arr, arr_size);

	insertion_sort(arr, arr_size);

	printf("Sorted array: \n");
	print_array(arr, arr_size);

	return (0);
}
