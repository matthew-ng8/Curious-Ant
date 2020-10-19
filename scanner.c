#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

FILE *f;
long nr_rows, nr_columns;

int maze_reader()
{
	char identifier[LEN];
	char equal;
	char comma;
	char underscore;
	int i = 0 , j = 0;
	char c;
	
	if((f = fopen("Maze2.txt","r")) == NULL)
	{
		printf("This file can't be opened.");
	}
	
	fscanf(f,"%s %c %d %c %d", identifier, &equal, &currentPos.x, &comma, &currentPos.y);
	printf("%s %c %d%c%d", identifier, equal, currentPos.x, comma, currentPos.y);
	
	identifier == '\0';
	printf("\n");
	
	fscanf(f,"%s %c %d %c %d", identifier, &equal, &exitPos.x, &comma, &exitPos.y);
	printf("%s %c %d%c%d", identifier, equal, exitPos.x, comma, exitPos.y);
	
	printf("\n");
	
	fscanf(f,"%s %c %s", identifier, &equal, numofcolumns);
	printf("%s %c %s", identifier, equal, numofcolumns);
	
	printf("\n");
	
	fscanf(f,"%s %c %s", identifier, &equal, numofrows);
	printf("%s %c %s", identifier, equal, numofrows);
	
	c = fgetc(f);
	nr_rows = atoi(numofrows);
	nr_columns = atoi(numofcolumns);
	
	while (c == ' ' || c == '\n' || c == '|' || c == '-')
	    {
	    	if(c != '\n')
			{
				mazestorer[i][j] = c;
				j++;
					if(j > nr_columns - 1)
						{
							i++;
							j = 0;
						}
			}
			c = fgetc(f);
			printf("%c",c);
		}
	printf("\n");
	for(i = 0; i < nr_rows ; i++)
	{
		for(j = 0; j < nr_columns ; j++)
		{
			printf("%c",mazestorer[i][j]);
		}
		printf("\n");
	}
	
}

void readIntelligence(){
	printf("Hello world");
	t = 0;
	n = 0;
	int i;
	char word[10];
	FILE *fint;

	if((fint = fopen("intelligence.txt","r")) == NULL)
	{//Input_File_Directional_Words
		printf("This file can't be opened.");
	}
	 fscanf(fint,"%s", word);
	 printf("%s", word);
	 //if((strcmp(word, "RP")) ==0)
	 //{
	 	fscanf(fint, "%d", &n);
	 	fscanf(fint, "%d", &t);
	 	//intelligence[n];
	//}
	 
	i = 0;
	 while(!feof(fint))
	 {
	 	fscanf(fint, "%s", word);
		printf("\n%s", word);
	 	
		if(strcmp(word,"MVF")==0)
		{
			intelligence[i] = MVF;	
		}
		else if(strcmp(word,"MVB")==0)
		{
			intelligence[i] = MVB;
		}
		else if(strcmp(word,"MVL")==0)
		{
			intelligence[i] = MVL;
		}	
		
		else if(strcmp(word, "CWL")==0)
		{
			intelligence[i] = CWL;
		}
		else if(strcmp(word,"MWR")==0)
		{
			intelligence[i] = MWR;
		}
		else if(strcmp(word,"CWR")==0)
		{
			intelligence[i] = CWR;
		}	
		else if(strcmp(word,"CWF")==0)
		{
			intelligence[i] = CWF;
		}
		else if(strcmp(word,"CWB")==0)
		{
			intelligence[i] = CWB;
		}
		else if(strcmp(word, "PUSH")==0)
		{
			intelligence[i] = PUSH;
		}
		else if(strcmp(word, "POP")==0)
		{
			intelligence[i] = POP;
		}
		else if(strcmp(word, "PEEK")==0)
		{
			intelligence[i] = PEEK;
		}
		else if(strcmp(word,"CLEAR")==0)
		{
			intelligence[i] = CLEAR;
		}
		else if(strcmp(word, "BJPI")==0)
		{
			intelligence[i] = BJPI;
		}
		else if(strcmp(word, "CJPI")==0)
		{
			intelligence[i] = CJPI;
		}
		
		
		i++;
	}
	//p = intelligence;
}


