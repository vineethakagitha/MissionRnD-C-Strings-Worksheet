/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
#include<stdlib.h>
void str_words_in_rev(char *input, int len){
	int i, j,n,sh=0,l;
	char *temp;
	temp = (char*)malloc(sizeof(char)*len);
	n = len;
	j = len - 1;
	for (i = 0; i < len; i++)
		temp[i] = input[i];
	while (j > 0)
	{
		for (j = n - 1,l=0; input[j] != ' ' &&  j>0; j--);
		if (j == 0)
			l = -1;
		for (i = j +l+1; input[i] != ' ' && input[i]; i++,sh++)
		{
			temp[sh] = input[i];
		}
		for (n = j; input[n] == ' ' && n>0; n--)
		{
			temp[sh] = ' ';
			sh++;
		}
		n = n+1;
	}
		for (i = 0; i < len; i++)
			input[i] = temp[i];
}
