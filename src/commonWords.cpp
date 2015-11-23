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
	int i, j, si = 0, sj = 0, f,co,count=-1,set=0,a;
	common = (char**)malloc(sizeof(char*) * SIZE);
	for (i = 0; i < SIZE; i++)
		common[i] = (char*)malloc(sizeof(char)*SIZE);
	if (str1 && str2){
		do{
			do{
				for (i = 0; str1[i] && str1[i] == ' '; i++);
				if (str1[i] == '\0')
				{
					si = i;
					break;
				}
				i = si; j = sj; set = 0;
				for (j = sj; str1[i] && str2[j] && str1[i] == str2[j] && str1[i] != ' '&&str2[j] != ' '; j++, i++);
				if (str1[i] && str2[j] && str1[i] != str2[j])
				{
					for (sj = j; str2[sj] && str2[sj] != ' '; sj++);
					j = sj;
					for (sj = j; str2[sj] && str2[sj] == ' '; sj++);
				}
				else{
					set = 1;
					for (co = i - 1; str1[co] != ' '&& co > 0; co--);
					if (co == 0)
						co = -1;
					for (f = co + 1,a=0, count = count + 1; str1[f] && str1[f] != ' '; f++,a++)
					{
						common[count][a] = str1[f];
					}
					common[count][a] = '\0';
					for (si = i; str1[si] && str1[si] == ' '; si++);
					sj = 0;
				}
			} while (str1[si] && str2[sj]);
			if (str1[si] == '\0')
				break;
			if (set==0){
				for (i = si; str1[i] && str1[i] != ' '; i++);
				for (si = i; str1[si] && str1[si] == ' '; si++);
				sj = 0;
			}
		} while (str1[si]);
		if (count == -1)
			return NULL;
		return common;
	}
	return NULL;
}