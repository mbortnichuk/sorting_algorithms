/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 14:20:06 by mbortnic          #+#    #+#             */
/*   Updated: 2018/02/17 14:51:37 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* 
** Merges two subarray to arr[].
** First subarray is arr[one..two].
** Second subarray is arr[two+1..three].
*/

void	merge_arrays(int arr[], int one, int two, int three)
{
	int i = 0;
	int j = 0;
	int k = 0;

	int n1 = two - one + 1;
	int n2 = three - two;

	/* Create temporary arrays. */
	int left[n1];
	int right[n2];

	/* Copy data to temporary arrays left[] and rigth[]. */
	for (i = 0; i < n1; i++)
		left[i] = arr[one + i];
	for (j = 0; j < n2; j++)
		right[j] = arr[two + 1 + j];

	/* Merge the temporary arrays back into arr[one...three]. */
	i = 0; /* initial index of first subarray; */
	j = 0; /* initial index of second subarray; */
	k = one; /* initial index of merged subarray; */

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	/* Copy the remainig elements of left[], if there are any. */
	while (i < n1)
	{
		arr[k] = left[i];
		k++;
		i++;
	}
	while (j < n2)
	{
		arr[k] = right[j];
		j++;
		k++;
	}
}

/*
** Left is for left index and Right is right index of the subarray of 
** arr to be sorted.
*/

void	merge_sort(int arr[], int left, int right)
{
	int m;

	if (left < right)
	{
		/* Same as (left + right), but avoids overflow for large left and right. */
		m = left + (right - left) / 2;

		/* Sort first and second halves. */
		merge_sort(arr, left, m);
		merge_sort(arr, m + 1, right);

		merge_arrays(arr, left, m, right);
	}
}

/* 
** To print an array.
*/

void	print_array(int arr[], int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	int arr[] = {5, 8, 3, 1, 25, 55, 13, 98};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is: \n");
	print_array(arr, arr_size);

	merge_sort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	print_array(arr, arr_size);

	return (0);
}
