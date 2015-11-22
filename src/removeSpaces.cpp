/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char removeSpaces(char *str) {
	int i,j,sh=0,l;
	if (str && str!="")
	{
		for (i = 0; str[i]; i++)
		{
			if (str[i] == ' ')
			{
				for (j = i; str[j] == ' ' && str[j]; j++);
				if (str[j] == '\0')
				{
					str[l] = '\0';
					break;
				}
				if (sh==0)
					l = i;
				for (sh = j; str[sh] != ' '&& str[sh]; sh++,l++)
				{
					str[l] = str[sh];
				}
				 i = sh - 1;
			}
		}
		return *str;
	}
	return '\0';
}