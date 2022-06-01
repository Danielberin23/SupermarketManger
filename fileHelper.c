#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Macros.h"

#include "fileHelper.h"
#include "General.h"


int	 writeStringToFile(const char* str, FILE* fp,const char* msg)
{
	int length = (int)strlen(str);
	length++;
	if (!writeIntToFile(length, fp,msg))
		return 0;

	if (!writeCharsToFile(str, length, fp, msg))
		return 0;


	return 1;
}

int	 writeCharsToFile(const char* arr, int size, FILE* fp, const char* msg)
{
	if (fwrite(arr, sizeof(char), size, fp) != size)
	{
		puts(msg);
		return 0;
	}
	return 1;

}

int	 writeIntToFile(int val, FILE* fp, const char* msg)
{
	if (fwrite(&val, sizeof(int), 1, fp) != 1)
	{
		puts(msg);
		return 0;
	}
	return 1;
}

char* readStringFromFile(FILE* fp, const char* msg)
{
	char* str;
	int length;
	if (!readIntFromFile(&length, fp,msg))
		return NULL;
	str = (char*)malloc((length) * sizeof(char));

	CHECK_MSG_RETURN_NULL(str, msg);

	if (fread(str, sizeof(char), length, fp) != length)
	{
		free(str);
		puts(msg);
		return NULL;
	}
	return str;
}

int readFixSizeStrFromFile(char* arr,FILE* fp, const char* msg)
{
	int len;
	if (!readIntFromFile(&len, fp, msg))
		return 0;
	
	if (!readCharsFromFile(arr, len, fp, msg))
		return 0;

	return 1;
}

int	 readCharsFromFile(char* arr, int length, FILE* fp, const char* msg)
{
	if (fread(arr, sizeof(char), length, fp) != length)
	{
		puts(msg);
		return 0;
	}
	return 1;
}

int	  readIntFromFile(int* pVal, FILE* fp, const char* msg)
{
	if (fread(pVal, sizeof(int), 1, fp) != 1)
	{
		puts(msg);
		return 0;
	}
	return 1;

}


char* readDynStringFromTextFile(FILE* fp)
{
	char temp[MAX_STR_LEN];
	myGets(temp, sizeof(temp), fp);
	return getDynStr(temp);
}
char DecimalandLettersfromI(char decodethis)
{
	char a=0;
	if (decodethis < 10)
	{
		a = decodethis + '0';
	}
	if (decodethis >= 10)
	{
		a = (decodethis-10) + 'A';
	}
	return a;
}
int ctoi(char encode)
{
	int a = 0;

	if (isdigit(encode))
	{
		a = encode - '0';
	}
	if(isupper(encode))
	{
		a = (encode + 10) - 'A';
	}
	return a;
}