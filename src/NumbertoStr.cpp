/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>

void number_to_str(float number, char *str,int afterdecimal){
	int i, d, j, p = 0, inte = 1,num;
	char temp;
	if (number < 0)
	{
		number = -number; p = 1; str[0] = '-';
	}
	for (i = 0; i < afterdecimal; i++)
	{
		inte = inte * 10;
	}
	number = number*inte;
	num = number;
	for (i = p; num!=0; i++)
	{
		d = num % 10;
		if (afterdecimal && (afterdecimal+p)== (i))
		{
			str[i] = '.';
			continue;
		}
		str[i] = d+'0';
		num = num / 10;
	}
	str[i] = '\0';
	if (p)
	{
		for (j = p; j <= i / 2; j++)
		{
			temp = str[j];
			str[j] = str[i - j];
			str[i - j] = temp;
		}
	}
	else{
		for (j = 0; j < i / 2; j++)
		{
			temp = str[j];
			str[j] = str[i - (j)-1];
			str[i - (j)-1] = temp;
		}
	}
}

