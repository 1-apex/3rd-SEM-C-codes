#include<stdio.h>
#include<stdlib.h>

void main()
{
	FILE *fp;
	char name[10];
	char s[100];
	int prn;
	
	//------------------------------------------------
	// write
	
	
	fp = fopen("first_file.txt", "w");
	
	printf("Enter your name : ");
	scanf("%s", name);
	printf("Enter PRN : ");
	scanf("%d", &prn);
	
	fprintf(fp, "Name : %s PRN : %d \n", name, prn);
	
	//-------------------------------------------------
	// read
	
	/*
	fp = fopen("first_file.txt", "r");
	
	if(fp == NULL)
	{
		printf("Error while opening the file!!\n");
	}
	else
	{
		fgets(s, 50, fp);
		puts(s);
	}
	*/
	//--------------------------------------------------
	// append
	
	/*
	fp = fopen("first_file.txt", "a");
	
	printf("Enter your name : ");
	scanf("%s", name);
	printf("Enter PRN : ");
	scanf("%d", &prn);
	
	fprintf(fp, "Name : %s PRN : %d \n", name, prn);
	*/
	
	fclose(fp);
}
