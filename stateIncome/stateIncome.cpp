// stateIncome.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define NUM 51 // max number of states

void readFromFile();
void printLowestAllYears();
void printHighestAllYears();
void printLowestYear2004();
void printHighestYear2004();

struct income
{
	char state[40];
	int incomes[3];
};

//number of states
struct income states[NUM];


int main()
{
	readFromFile();
	printLowestAllYears();
	printHighestAllYears();
	printLowestYear2004();
	printHighestYear2004();
	return 0;
}


void readFromFile()
{
	FILE *fp;
	char strBuff[80];
	char temp[30];
	int i, j, nstate = 0;

	fp = fopen("C:\\Users\\sndri\\Documents\\Familyincome.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file!\n");
	}

	//sets file pointer at the start of the first state Alabama
	fseek(fp, 124, SEEK_SET);
	
	while (!feof(fp)) 
	{
		fgets(strBuff, 80, fp);

		i = 0;
		j = 0;
		while ((strBuff[i] != '\t') && (strBuff[i] != '\n'))
		{
			temp[j] = strBuff[i];
			i++;
			j++;
		}
		temp[j] = '\0';
		strcpy(states[nstate].state, temp);

		j = 0;
		i++;
		while ((strBuff[i] != '\t') && (strBuff[i] != '\n'))
		{
			temp[j] = strBuff[i];
			i++;
			j++;
		}
		temp[j] = '\0';
		states[nstate].incomes[0] = atoi(temp);

		j = 0;
		i++;
		while ((strBuff[i] != '\t') && (strBuff[i] != '\n'))
		{
			temp[j] = strBuff[i];
			i++;
			j++;
		}
		temp[j] = '\0';
		states[nstate].incomes[1] = atoi(temp);


		j = 0;
		i++;
		while ((strBuff[i] != '\t') && (strBuff[i] != '\n'))
		{
			temp[j] = strBuff[i];
			i++;
			j++;
		}
		temp[j] = '\0';
		states[nstate].incomes[2] = atoi(temp);

		nstate++;
	}
	fclose(fp);
}


void printLowestAllYears()
{
	int i = 0;
	int min03 = 0;
	int min04 = 0;
	int min05 = 0;
	for (i = 0; i < NUM; i++)
		{
			if (states[i].incomes[0] < states[i + 1].incomes[0])
			{
				if (states[i].incomes[0] < states[min03].incomes[0])
				{
					min03 = i;
				}
			}

			if (states[i].incomes[1] < states[i + 1].incomes[1])
			{
				if (states[i].incomes[1] < states[min04].incomes[1])
				{
					min04 = i;
				}
			}

			if (states[i].incomes[2] < states[i + 1].incomes[2])
			{
				if (states[i].incomes[2] < states[min05].incomes[2])
				{
					min05 = i;
				}
			}
		}
	if ((states[min03].incomes[0] < states[min04].incomes[1]) && (states[min03].incomes[0] < states[min05].incomes[2]))
	{
		printf("\nLowest Median Income was $%d in %s in 2003\n", states[min03].incomes[0], states[min03].state);
	}


	if ((states[min04].incomes[1] < states[min03].incomes[0]) && (states[min04].incomes[1] < states[min05].incomes[2]))
	{
		printf("\nLowest Median Income was $%d in %s in 2004\n", states[min04].incomes[1], states[min04].state);
	}


	if ((states[min05].incomes[2] < states[min04].incomes[1]) && (states[min05].incomes[2] < states[min03].incomes[0]))
	{
		printf("\nLowest Median Income was $%d in %s in 2005\n", states[min05].incomes[2], states[min05].state);
	}
}


void printHighestAllYears()
{
	int i = 0;
	int min03 = 0;
	int min04 = 0;
	int min05 = 0;
	for (i = 0; i < NUM; i++)
	{
		if (states[i].incomes[0] > states[i + 1].incomes[0])
		{
			if (states[i].incomes[0] > states[min03].incomes[0])
			{
				min03 = i;
			}
		}

		if (states[i].incomes[1] > states[i + 1].incomes[1])
		{
			if (states[i].incomes[1] > states[min04].incomes[1])
			{
				min04 = i;
			}
		}

		if (states[i].incomes[2] > states[i + 1].incomes[2])
		{
			if (states[i].incomes[2] > states[min05].incomes[2])
			{
				min05 = i;
			}
		}
	}
	if ((states[min03].incomes[0] > states[min04].incomes[1]) && (states[min03].incomes[0] > states[min05].incomes[2]))
	{
		printf("\nHighest Median Income was $%d in %s in 2003\n", states[min03].incomes[0], states[min03].state);
	}


	if ((states[min04].incomes[1] > states[min03].incomes[0]) && (states[min04].incomes[1] > states[min05].incomes[2]))
	{
		printf("\nHighest Median Income was $%d in %s in 2004\n", states[min04].incomes[1], states[min04].state);
	}


	if ((states[min05].incomes[2] > states[min04].incomes[1]) && (states[min05].incomes[2] > states[min03].incomes[0]))
	{
		printf("\nHighest Median Income was $%d in %s in 2005\n", states[min05].incomes[2], states[min05].state);
	}
}


void printLowestYear2004()
{
	int i = 0;
	int lowest = 0;
	for (i = 0; i < NUM; i++)
	{
		if (states[i].incomes[1] < states[i + 1].incomes[1])
		{
			if (states[i].incomes[1] < states[lowest].incomes[1])
			{
				lowest = i;
			}
		}
	}
	printf("\nLowest Median Income in 2004 was $%d in %s\n", states[lowest].incomes[1], states[lowest].state);
}


void printHighestYear2004()
{
	int i = 0;
	int highest = 0;
	for (i = 0; i < NUM; i++)
	{
		if (states[i].incomes[1] > states[i + 1].incomes[1])
		{
			if (states[i].incomes[1] > states[highest].incomes[1])
			{
				highest = i;
			}
		}
	}
	printf("\nHighest Median Income in 2004 was $%d in %s\n", states[highest].incomes[1], states[highest].state);
}