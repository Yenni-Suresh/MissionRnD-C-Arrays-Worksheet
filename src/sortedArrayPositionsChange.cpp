/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr==NULL||len<0)
	  return NULL;
	int temp,i,x,y,flag=0;
	if (len == 2)
	{
		temp = Arr[0];
		Arr[0] = Arr[1];
		Arr[1] = temp;
		return Arr;
	}
	for (i = 0; i < len - 1; i++)
	{
		if (flag == 0 && Arr[i] > Arr[i + 1])
		{
			x = i;
			flag = 1;
		}
		else if (Arr[i] > Arr[i + 1])
		{
			y = i + 1;
			temp = Arr[x];
			Arr[x] = Arr[y];
			Arr[y] = temp;
			break;
		}
	}
	return Arr;
}