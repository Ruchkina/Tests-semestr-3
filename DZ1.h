#ifndef DZ1_H
#define DZ1_H

#define OK						 0
#define ERR_NO_FILE				-1
#define ERR_FILE_EMPTY			-2
#define ERR_DATA				-3
#define ERR_NULL				-4
#define ERR_NEGATIVE_COUNTER	-5

using namespace std;

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

int ReadStringToArrays(int*, char(*LettersAndOdd)[100], int*, int*, FILE*);
int WriteToFile(int numberWordsAndOdd, int numberEven, int* Even, char(*LettersAndOdd)[100], FILE* ptrNew);

#endif