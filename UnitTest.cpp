#define _CRT_SECURE_NO_WARNINGS

#include "DZ1.h"
#include "UnitTest.h"

using namespace std;
FILE* fin = fopen("file.txt", "r");

void Test_ReadString_NullPointer()
{
	printf("ReadString_NullPointer\n");
	int* Even = NULL;
	char LettersAndOdd[1][100];
	int numberEven = 0;
	int numberWordsAndOdd = 0;

	int expected = ERR_NULL;
	int result = ReadStringToArrays(Even, LettersAndOdd, &numberEven, &numberWordsAndOdd, fin);
	
	if (result == expected)
		printf("Passed\n");
	else
		printf("Failed");
	printf("__________\n");
}

void Test_ReadString_NullPointerSecondArg()
{
	printf("ReadString_NullPointerSecondArg\n");
	char LettersAndOdd[1][100] = { NULL };
	int* Even = NULL;
	int numberEven = 0;
	int numberWordsAndOdd = 0;

	int expected = ERR_NULL;
	int result = ReadStringToArrays(Even, LettersAndOdd, &numberEven, &numberWordsAndOdd, fin);

	if (result == expected)
		printf("Passed\n");
	else
		printf("Failed");
	printf("__________\n");
}

void Test_ReadString_NegativeCounter()
{
	printf("ReadString_NegativeCounter\n");
	int* Even = NULL;
	char LettersAndOdd[1][100];
	int numberEven = -100;
	int numberWordsAndOdd = 0;

	int expected = ERR_NEGATIVE_COUNTER;
	int result = ReadStringToArrays(Even, LettersAndOdd, &numberEven, &numberWordsAndOdd, fin);

	if (result == expected)
		printf("Passed\n");
	else
		printf("Failed");
	printf("__________\n");
}

void Test_ReadString_NegativeCounterSecondArg()
{
	printf("ReadString_NegativeCounterSecondArg\n");
	int* Even = NULL;
	char LettersAndOdd[1][100];
	int numberEven = 0;
	int numberWordsAndOdd = -100;

	int expected = ERR_NEGATIVE_COUNTER;
	int result = ReadStringToArrays(Even, LettersAndOdd, &numberEven, &numberWordsAndOdd, fin);

	if (result == expected)
		printf("Passed\n");
	else
		printf("Failed");
	printf("__________\n");
}

void Test_WriteToFile_NullPointer()
{
	printf("WriteToFile_NullPointer\n");
	int* Even = NULL;
	char LettersAndOdd[1][100];
	int numberEven = 0;
	int numberWordsAndOdd = 0;

	int expected = ERR_NULL;
	int result = ReadStringToArrays(Even, LettersAndOdd, &numberEven, &numberWordsAndOdd, fin);

	if (result == expected)
		printf("Passed\n");
	else
		printf("Failed");
	printf("__________\n");
}

void Test_WriteToFile_NullPointerSecondArg()
{
	printf("WriteToFile_NullPointerSecondArg\n");
	char LettersAndOdd[1][100] = { NULL };
	int* Even = NULL;
	int numberEven = 0;
	int numberWordsAndOdd = 0;

	int expected = ERR_NULL;
	int result = ReadStringToArrays(Even, LettersAndOdd, &numberEven, &numberWordsAndOdd, fin);

	if (result == expected)
		printf("Passed\n");
	else
		printf("Failed");
	printf("__________\n");
}

void Test_WriteToFile_NegativeCounter()
{
	printf("WriteToFile_NegativeCounter\n");
	int* Even = NULL;
	char LettersAndOdd[1][100];
	int numberEven = -100;
	int numberWordsAndOdd = 0;

	int expected = ERR_NEGATIVE_COUNTER;
	int result = ReadStringToArrays(Even, LettersAndOdd, &numberEven, &numberWordsAndOdd, fin);

	if (result == expected)
		printf("Passed\n");
	else
		printf("Failed");
	printf("__________\n");
}

void Test_WriteToFile_NegativeCounterSecondArg()
{
	printf("WriteToFile_NegativeCounterSecondArg\n");
	int* Even = NULL;
	char LettersAndOdd[1][100];
	int numberEven = 0;
	int numberWordsAndOdd = -100;

	int expected = ERR_NEGATIVE_COUNTER;
	int result = ReadStringToArrays(Even, LettersAndOdd, &numberEven, &numberWordsAndOdd, fin);

	if (result == expected)
		printf("Passed\n");
	else
		printf("Failed");
	printf("__________\n");
}




void run_all_tests()
{
	Test_ReadString_NullPointer();
	Test_ReadString_NullPointerSecondArg();
	Test_ReadString_NegativeCounter();
	Test_ReadString_NegativeCounterSecondArg();
	Test_WriteToFile_NullPointer();
	Test_WriteToFile_NullPointerSecondArg();
	Test_WriteToFile_NegativeCounter();
	Test_WriteToFile_NegativeCounterSecondArg();



}