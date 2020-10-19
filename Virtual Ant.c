#include "Virtual_Ant.h"

int MAX_ENERGY = INT_MAX; //if you want, do MAX_ENERGY = LEN for a smaller energy size
//Global variables

int itchR, itchL, itchF, itchB;
long nr_rows, nr_columns;
FILE *f2;

void fillInX(int p1, int p2, int y){
	//fills in the matrix from p1 to p2 along the x positions
	int max = p2;
	int min = p1;
	int i;
	if(p1 > p2){
		max = p1;
		min = p2;
	}
	
	for(i = min;i < max;i++){
		mazestorer[i][y] = 'v';
	}
		
}

void fillInY(int p1, int p2, int x){
	int max = p2;
	int min = p1;
	int i;
	if(p1 > p2){
		max = p1;
		min = p2;
	}
	
	for(i = min;i < max;i++){
		mazestorer[x][i] = 'v';
	}
}

void resetItches(){//0 means that there are no itches
	itchR = 0;
	itchL = 0;
	itchF = 0;
	itchB = 0;
}

void Virtual_Ant()
{
	FILE *f3; //output file
	
	if((f3 = fopen("Output_File.txt","w")) == NULL)
	{
		printf("This file can't be opened.");
	}
	
	maze_reader();
	char word[10];
	act action;
	int counter = 0;

	printf("Start Position X = %d", currentPos.x);
	printf("\n Start Position Y = %d", currentPos.y);
	printf("\n Exit Position X = %d", exitPos.x);
	printf("\n Exit Position Y = %d\n", exitPos.y);
	int distance = 0;//distance can move in direction of the twitch
	int i = 0, j =0, d= 0;
	int twitch = 0;// 1 = yes, 0 = no
	int moved = 0;
	int energy = MAX_ENERGY;
	
	readIntelligence();
	
	printf("\nThis is t = %d\n", t);
	printf("This is n = %d", n);
	
	i = 0; j = 0;
	while (((currentPos.x != exitPos.x) || (currentPos.y != exitPos.y)) && (energy > 0 ) && j < t) //change back later
	{
		printf("\nPOSITION X = %d", currentPos.x);
		printf("\nPosition Y = %d\n", currentPos.y);
		action = intelligence[i]; 
		switch(action)
		{
			case MVF: 
				if(itchF && energy >= 3)
				{				
					printf("FORWARD\n");
					fprintf(f3,"MVF\n");
					mazestorer[currentPos.x][currentPos.y] = 'v';
					currentPos.x +=1;
					energy-=3;
					printf("%d", energy);
					resetItches();
					moved = 1;
					counter++;
				}
				break;
						
			case MVB: 
				if(itchB && energy >= 3)
				{
					printf("BACK\n");
					fprintf(f3,"MVF\n");
					mazestorer[currentPos.x][currentPos.y] = 'v';
					currentPos.x -=1;
					energy-= 3;
					resetItches();
					moved = 1;
					counter++;
				}
				break;
			case MVL: 
				if(itchL && energy >= 3)
				{
					printf("LEFT\n");
					fprintf(f3,"MVL\n");
					mazestorer[currentPos.x][currentPos.y] = 'v';
					currentPos.y -=1;
					energy-=3;
					resetItches();
					moved = 1;
					counter++;
				}
				break;
			case MWR: 
				if(itchR && energy >= 3)
				{
					printf("RIGHT\n");
					fprintf(f3,"MWR\n");
					mazestorer[currentPos.x][currentPos.y] = 'v';
					currentPos.y +=1;
					energy-=3;
					resetItches();
					moved = 1;
					counter++;
				}
				break;
			case CWL: 
			if(energy >= 1)
			{
				printf("CHECK LEFT\n");
				fprintf(f3,"CWL\n");
				d = currentPos.y - 1;//checks the first space to the left
				distance = 0;//IDK if we should set it to zero, to count. Depending on when we call other functions
				while(mazestorer[currentPos.x][d] == ' ')
				{
					d--;
					distance++;
					itchL = 1;//yes there is an available space
				}
				moved = 0;
				energy--;
				counter++;
				break;
			}
			case CWR: 
			if(energy >= 1)
			{
				printf("CHECK RIGHT\n");
				fprintf(f3,"CWR\n");
				d = currentPos.y + 1;//checks the first space to the right
				distance = 0;//IDK if we should set it to zero, to count. Depending on when we call other functions
				while(mazestorer[currentPos.x][d] == ' ')
				{
					d++;
					distance++;
					itchR = 1;//yes there is an available space
				}
				moved = 0;
				energy--;
				counter++;
				break;
			}
			case CWF: 
			if(energy >= 1)
			{
				printf("CHECK FORWARD\n");
				fprintf(f3,"CWF\n");
				d = currentPos.x +1;//checks the space in front of it
				distance = 0;
				while(mazestorer[d][currentPos.y] == ' ')
				{
					d++;
					distance++;
					itchF = 1;
				}
				moved = 0;
				energy--;
				counter++;
				break;	
			}
			case CWB: 
			if(energy >= 1)
			{
				printf("CHECK BACK\n");
				fprintf(f3,"CWB\n");
				d = currentPos.x -1;//checks the space behind it
				distance = 0;
				while(mazestorer[d][currentPos.y] == ' ')
				{
					d--;
					distance++;
					itchB = 1;
				}
				moved = 0;
				energy--;
				counter++;
				break;
			}
			case PUSH: 
			if(energy >= 4)
			{
				
				if(itchR + itchL + itchB + itchF >1)
				{
					push(currentPos);
					energy-=4;
					counter++;
					fprintf(f3,"PUSH\n");
					printf("PUSH\n");
				}
					break;
			}
			case POP: 
			if(energy >= 4)
			{
				if(moved == 0){
					printf("POP\n");
					fprintf(f3,"POP\n");
					currentPos = pop();
					energy-=4;
					counter++;
				}
				break;
			}
			case PEEK: 
			if(energy >= 2)
			{
				printf("PEEK\n");
				fprintf(f3,"PEEK\n");
				energy-=2;
				counter++;
				break;
			}
			case CLEAR: 
			if(energy >= 2)
			{
				printf("CLEAR\n");
				fprintf(f3,"CLEAR\n");
				energy-=2;
				counter++;
				break;
			}
			case BJPI: 
			if(energy >= 5)
			{
				
				if(itchR ==1){
					currentPos.y += distance;
					energy-=5;
					counter++;
					printf("BOLD JUMP\n");
					fprintf(f3,"BOLD JUMP\n");
					
				}else if(itchL ==1){
					currentPos.y -= distance;
					energy-=5;
					counter++;
					printf("BOLD JUMP\n");
					fprintf(f3,"BOLD JUMP\n");
					
				}else if(itchB ==1){
					currentPos.x -= distance;
					energy-=5;
					counter++;
					printf("BOLD JUMP\n");
					fprintf(f3,"BOLD JUMP\n");
				}else if(itchF ==1){
					currentPos.x +=distance;
					energy-=5;
					counter++;
					printf("BOLD JUMP\n");
					fprintf(f3,"BOLD JUMP\n");
				}
				break;
			}
			case CJPI: 
			if(energy >= 3)
			{
				
				if(itchR ==1 && distance >=2){
					currentPos.y += 2;
					energy-=3;
					counter++;
					printf("CAUTIOUS JUMP\n");
				fprintf(f3,"CAUTIOUS JUMP\n");
				}else if(itchL ==1 && distance >=2){
					currentPos.y -= 2;
					energy-=3;
					counter++;
					printf("CAUTIOUS JUMP\n");
					fprintf(f3,"CAUTIOUS JUMP\n");
				}else if(itchB ==1 && distance >=2){
					currentPos.x -= distance;
					energy-=3;
					counter++;
					printf("CAUTIOUS JUMP\n");
					fprintf(f3,"CAUTIOUS JUMP\n");
				}else if(itchF ==1 && distance >=2){
					currentPos.x +=distance;
					energy-=3;
					counter++;
					printf("CAUTIOUS JUMP\n");
					fprintf(f3,"CAUTIOUS JUMP\n");
				}
				break;
			}
			}
		
		i++;
		if(i == n)
		{
			i = 0;
			j++;
		}
		printf("i = %d", i);
		printf("\nj = %d", j);
		printf("\nEnergy right now equals to %d",energy);
	}
	
	if(energy <= 0)
	{	
		printf("\nMichael ran out of energy and died, we are sorry");
		fprintf(f3,"\nMichael ran out of energy and died, we are sorry");
	}
	if(currentPos.x == exitPos.x && currentPos.y == exitPos.y)
	{
		printf("\n\nMichael made it out! Final Position = %d %d", currentPos.x, currentPos.y);
		printf("\nExit Position X = %d",exitPos.x);
		fprintf(f3,"\nExit Position X = %d",exitPos.x);
		printf("\nExit Position Y = %d",exitPos.y);
		fprintf(f3,"\nExit Position Y = %d",exitPos.y);
		fprintf(f3,"\n\nMichael made it out! Final Position = %d %d", currentPos.x, currentPos.y);
	}
	
	distance = 0;
	for(i = 0; i < nr_rows;i++)
	{
		for(j =0; j < nr_columns;j++)
		{
			if(mazestorer[i][j] == 'v')
				distance++;
		}
	}
	
	printf("\n\nThe distance travelled is %d", distance);
	fprintf(f3,"\n\nThe distance travelled is %d", distance);
	printf("\nEnergy spent is %d",MAX_ENERGY - energy);	
	fprintf(f3,"\nEnergy spent is %d",MAX_ENERGY - energy);
	printf("\nThe amount of moves made was %d",counter);
	fprintf(f3,"\nThe amount of moves made was %d",counter);
}
