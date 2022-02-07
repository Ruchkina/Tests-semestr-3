#define _CRT_SECURE_NO_WARNINGS
#include "DZ1.h"
#include "UnitTest.h"

using namespace std;


int main()
{
	int* Even = (int*)malloc(100 * sizeof(int));
	char LettersAndOdd[100][100];

	int numberEven = 0;
	int numberWordsAndOdd = 0;
	int rc;

	/*
	FILE* ptr = fopen("file.txt", "r+");	
	FILE* ptrNew = fopen("file_new.txt", "w+");
	*/
	char path_in[250];
	char path_out[250] = "file_new.txt";
	gets_s(path_in);
	FILE* fin = fopen(path_in, "r");
	FILE* fout = fopen(path_out, "w");

	if (fin == NULL)
	{
		fprintf(fout, "no such file.\n");
		printf("no such file");
		fclose(fout);
		return ERR_NO_FILE;
	}
	else
	{
		fseek(fin, 0, SEEK_END);
		unsigned int size = ftell(fin);
		if (size == 0)
		{
			fprintf(fout, "file is empty.\n");
			printf("file is empty.\n");
			fclose(fout);
			return ERR_FILE_EMPTY;
		}
		fseek(fin, 0, SEEK_SET);
	}

	while (!feof(fin))
	{
		rc = ReadStringToArrays(Even, LettersAndOdd, &numberEven, &numberWordsAndOdd, fin);
		if (rc == ERR_DATA)
		{
			fclose(fout);
			fopen("file_new.txt", "w");
			fprintf(fout, "%s", "Incorrect data.\n");
			printf("Incorrect data.\n");
			fclose(fout);
			return rc;
		}
		else if (rc == ERR_NULL)
		{
			fclose(fout);
			fopen("file_new.txt", "w");
			fprintf(fout, "%s", "NULL.\n");
			printf("NULL.\n");
			fclose(fout);
			return rc;
		}
		else if (rc == ERR_NEGATIVE_COUNTER)
		{
			fclose(fout);
			fopen("file_new.txt", "w");
			fprintf(fout, "%s", "NEGATIVE_COUNTER.\n");
			printf("NEGATIVE_COUNTER.\n");
			fclose(fout);
			return rc;
		}
		WriteToFile(numberWordsAndOdd, numberEven, Even, LettersAndOdd, fout);
		memset(Even, 0, numberEven);
		memset(LettersAndOdd, ' ', numberWordsAndOdd);
		numberWordsAndOdd = 0;
		numberEven = 0;
	}

	run_all_tests();
	fclose(fin);
	fclose(fout);
	free(Even);

	system("pause");

}

int ReadStringToArrays(int* Even, char(*LettersAndOdd)[100], int* numberEven, int* numberWordsAndOdd, FILE* ptr)
{
	char o;
	int num;
	int rc = OK;
	char d;
	if (*(numberEven) < 0 || *(numberWordsAndOdd) < 0)
		return ERR_NEGATIVE_COUNTER;
	if (Even == NULL || LettersAndOdd == NULL)
		return ERR_NULL;


	while ((fscanf(ptr, "%c", &o) && (o != '\n')) && (!feof(ptr)))
	{
		fseek(ptr, -1, SEEK_CUR);

		if (fscanf(ptr, "%d", &num) != 0)
		{
			if (num % 2 == 0)
			{
				(Even[*(numberEven)]) = num;
				*(numberEven) = *(numberEven) + 1;
			}
			else
			{
				_itoa(num, LettersAndOdd[*(numberWordsAndOdd)], 10);
				*(numberWordsAndOdd) = *(numberWordsAndOdd)+1;
			}
				
		}
		else
		{
			fscanf(ptr, "%c", &d);
			fseek(ptr, -1, SEEK_CUR);
			if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
			{
				//fscanf(ptr, "%c", LettersAndOdd[*(numberWordsAndOdd)]);
				(fscanf(ptr, "%s", LettersAndOdd[*(numberWordsAndOdd)]));
				*(numberWordsAndOdd) = *(numberWordsAndOdd)+1;
			}
				
			else
				return ERR_DATA;	
		}
	}
	return rc;
}

int WriteToFile(int numberWordsAndOdd, int numberEven, int* Even, char(*LettersAndOdd)[100], FILE* ptrNew)
{
	if (&(numberEven) < 0 || &(numberWordsAndOdd) < 0)
		return ERR_NEGATIVE_COUNTER;
	if (Even == NULL || LettersAndOdd == NULL)
		return ERR_NULL;

	for (int j = 0; j < numberWordsAndOdd; j++)
		fprintf(ptrNew, "%s ", LettersAndOdd[j]);

	for (int i = 0; i < numberEven; i++)
		fprintf(ptrNew, "%d ", Even[i]);
	fprintf(ptrNew, "%c", '\n');

}
//qwe



