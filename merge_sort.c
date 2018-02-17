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
** Merge Sort is a Divide and Conquer algorithm. 
** It divides input array in two halves, calls itself for the two halves 
** and then merges the two sorted halves.
**
** MergeSort(arr[], l,  r)
** If r > l
**     1. Find the middle point to divide the array into two halves:  
**             middle m = (l+r)/2
**     2. Call mergeSort for first half:   
**             Call mergeSort(arr, l, m)
**     3. Call mergeSort for second half:
**             Call mergeSort(arr, m+1, r)
**     4. Merge the two halves sorted in step 2 and 3:
**             Call merge(arr, l, m, r)
*/

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
	while (i < n1)
	{
		left[i] = arr[one + i];
		i++;
	}
	while (j < n2)
	{
		right[j] = arr[two + 1 + j];
		j++;
	}

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

	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
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
