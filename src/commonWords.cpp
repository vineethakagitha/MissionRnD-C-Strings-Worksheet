/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	char **common;
	common = (char**)malloc(sizeof(char) * SIZE);
	int i, j,st1=0,st2=0,flag;
	if (str1 && str2)
	{
		//i = 0; j = 0;
		while (str1[i] && str2[j])
		{
			flag = 0;
			for (i = st1,j=st2; str1[i] && str2[j] && str1[i] != ' ' && str2[j]!=' '; i++,j++)
			{
				if (str1[i] != str2[i])
				{
					break; flag = 1;
				}
			}
			if (flag)
			{
				for (st1 = i; str1[st1] != ' '; st1++);
			}
			else{

				for (st1 = i; str1[st1] != ' '; st1++);
				for (st2 = j; str2[st2] != ' '; st2++);
			}
			st1++;
		}

	}
	return NULL;
}