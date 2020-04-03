#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
//some helpful constants
const int Villagers = 50000;
int LineOfPeople[Villagers];
const int Max_Len = 10000;
char code[Max_Len];

int asciiPlus = 43;
int asciiMinus = 45;
int asciiStar = 42;
int asciiLCarrot = 60;
int asciiRCarrot = 62;
int asciiOpenParenthese = 40;
int asciiClosedParenthese = 41;

//Our functions
int slideToTheRight(int pointerLocation);
int slideToTheLeft(int pointerLocation);
void addPebble(int pointerLocation);
void minusPebble(int pointerLocation);
int OpenParenthese(int pointerLocation, int codeLength);
int ClosedParenthese(int pointerLocation, int codeLength);

int main(int argc,char **argv) 
{
	for (int i = 0; i <= Villagers; i++)
	{
		LineOfPeople[i] = 0;
	}
	FILE* BrazilianFumaroleCode = fopen(argv[1], "r");
	if (BrazilianFumaroleCode == NULL)
	{
		printf("cannot open file");
		exit(1);
	}
	char rune;
	int i = 0;
	while ((rune = fgetc(BrazilianFumaroleCode)) != EOF)
	{
		//printf("%c", rune);
		code[i] = rune;
		i++;
		//printf("%c", code[0]);
	}
	//our code array is now loaded with all the code
	//printf("\n%c\n", code[0]);
	bool counting = false;
	int count = 0;
	int paranthesesCount = 0;
	int pointerLocation = 0;
	int NumberOfOpensPassed = 0;
	int NumberOfClosedPassed = 0;
	int codeIndex = 0;
	while (codeIndex <= Max_Len)
	{
		//printf("%c", code[codeIndex]);
		if ((int)code[codeIndex] == asciiPlus)
		{
			if (LineOfPeople[pointerLocation] == 255)
			{
				LineOfPeople[pointerLocation] = 0;
			}
			else
			{
				addPebble(pointerLocation);
			}
		}	
		else if ((int)code[codeIndex] == asciiMinus)
		{
			if (LineOfPeople[pointerLocation] == 0)
			{
				LineOfPeople[pointerLocation] = 255;
			}
			else
			{
				minusPebble(pointerLocation);
			}
		}
		else if ((int)code[codeIndex] == asciiStar)
		{
			//printf("%d-", (char)LineOfPeople[pointerLocation]);
			printf("%c", (char)LineOfPeople[pointerLocation]);
		}
		else if ((int)code[codeIndex] == asciiLCarrot)
		{
			if (pointerLocation >= 0)
			{
				pointerLocation--;
			}
			else
			{
				printf("The compilier was not given a valid command...<");
				exit(1);
			}
		}
		else if ((int)code[codeIndex]==asciiRCarrot)
		{
			if (pointerLocation < Villagers)
			{
				pointerLocation++;
			}
			else
			{
				printf("The compilier was not given a valid command...>");
				exit(1);
			}				
		}
		else if ((int)code[codeIndex] == asciiOpenParenthese)
		{
			//printf("%d ", codeIndex);
			codeIndex = OpenParenthese(pointerLocation, codeIndex);
			//printf("%d\n", codeIndex);
		}
		else if ((int)code[codeIndex] == asciiClosedParenthese)
		{
			codeIndex = ClosedParenthese(pointerLocation, codeIndex);
			//printf("\n%d\n", codeIndex)
		}
	codeIndex++;
	}
}
void addPebble(int pointerLocation)
{
	LineOfPeople[pointerLocation]++;
}
void minusPebble(int pointerLocation)
{
	LineOfPeople[pointerLocation]--;
}
int OpenParenthese(int pointerLocation, int codeIndex)
{
	if (LineOfPeople[pointerLocation]==0)
	{
		int numOpensCheck = 0;
		while(numOpensCheck >= 0)
		{
			codeIndex++;
			//printf("%c", codeIndex);
			if ((int)code[codeIndex] == asciiOpenParenthese)
			{
				numOpensCheck++;
			}
			else if ((int)code[codeIndex ] == asciiClosedParenthese)
			{
				numOpensCheck--;
			}
		}
	}
return codeIndex;
}
int ClosedParenthese(int pointerLocation, int codeIndex)
{
	if (LineOfPeople[pointerLocation]!=0)
	{
		int numClosedCheck = 0;
		while(numClosedCheck >= 0)
		{
			codeIndex--;
			if ((int)code[codeIndex] == asciiClosedParenthese)
			{
				numClosedCheck++;
			}
			else if ((int)code[codeIndex ] == asciiOpenParenthese)
			{
				numClosedCheck--;
			}
		}
			
	}
	return codeIndex;
}


