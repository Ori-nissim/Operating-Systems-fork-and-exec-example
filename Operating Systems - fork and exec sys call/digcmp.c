#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int digcmp(const char* str1, const char* str2);
int countDigits(const char* string);

int main(int argc, char *argv[])
{

	if (argc != 3)
		return -1;

	return digcmp(argv[1], argv[2]);
}
int digcmp(const char* str1, const char* str2)
{
	int sum1 = countDigits(str1);
	int sum2 = countDigits(str2);

	if (sum1 > sum2) return 1;
	else if (sum2 > sum1) return 2;
	else return 0;
}

int countDigits(const char* string)
{
	int sum = 0;

	for (int i = 0; i < strlen(string); i++)
		if (isdigit(string[i])) sum++;

	return sum;
}

