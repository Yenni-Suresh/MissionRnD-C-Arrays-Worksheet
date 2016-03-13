/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
    
	if (students == NULL || len < 0||K <= 0)
		return NULL;
	struct student *result, **p;
	int i, j, tscore, l, index;
	char tname;
	if (K > len)
		K = len;
	for (i = 0; i < K; i++)
	{
		index = i;
		if (index + 1 == len)
			break;
		for (j = index + 1; j < len; j++)
		{
			if (students[index].score < students[j].score)
				index = j;
		}
		/*for (l = 0; l<10; l++)
		{
		tname = students[i].name[l];
		students[i].name[l] = students[index].name[l];
		students[index].name[l] = tname;
		}*/
		tscore = students[i].score;
		students[i].score = students[index].score;
		students[index].score = tscore;
	}
	p = &students;
	//i = p[i]->score;
	students[0].score = 70;
	//p = (struct student*)realloc(students, sizeof(struct student)*K);
	//p = &students;
	//result = students;
	return &students;

}