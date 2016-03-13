/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	if (students==NULL||len<0)
	  return NULL;
	int i, j,tscore,l,index;
	char tname;
	for (i = 0; i < len - 1;i++)
	{
		index = i;
		for (j = index + 1; j < len; j++)
		{
			if (students[index].score < students[j].score)
				index = j;
		}
		for (l = 0;l<10; l++)
			{
				tname = students[i].name[l];
				students[i].name[l] = students[index].name[l];
				students[index].name[l] = tname;
			}
			tscore = students[i].score;
			students[i].score = students[index].score;
			students[index].score = tscore;
	}
	return students;
}