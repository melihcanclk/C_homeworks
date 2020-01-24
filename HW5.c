#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record
{
	char ID[50];
	char name[40];
	char surname[50];
	char email[60];

} record;

int line_counter();
void readDataFromFile(record *p, int counter);
void sorting_ID(record *p, int counter);
void sorting_name(record *p, int counter);
void sorting_surname(record *p, int counter);
void sorting_email(record *p, int counter);
void writeDataToFile(record *p, int counter);

int main()
{
	record *p;
	char selection;
	int counter = line_counter();					//Line Counter Function
	p = (record *)malloc(sizeof(record) * counter); //Dividing Space For Every Line

	readDataFromFile(p, counter);
	printf("%s", "Select your Order Type(I=ID , N=NAME , S=SURNAME , M=MAIL , Q=EXIT):");
	selection = getchar();
	if (selection == 'I')
	{
		sorting_ID(p, counter);
		printf("%s\n", "Your File Ordered According To ID");
	}
	else if (selection == 'N')
	{ //Read Function
		sorting_name(p, counter);
		printf("%s\n", "Your File Ordered According To Name");
	}
	else if (selection == 'S')
	{
		sorting_surname(p, counter);
		printf("%s\n", "Your File Ordered According To Surname");
	}
	else if (selection == 'M')
	{
		sorting_email(p, counter);
		printf("%s\n", "Your File Ordered According To E-Mail");
	}
	writeDataToFile(p, counter); //Write Function

	free(p); //Freeing 'p' Pointer

	return 0;
}

int line_counter()
{

	FILE *fileopen = NULL;

	char single_character;
	int counter = 0;

	fileopen = fopen("hw4_disordered_people.txt", "r"); //Opening File

	if (fileopen == NULL)
	{ //Control Section
		printf("Error!");
		exit(1);
	}
	for (single_character = getc(fileopen); single_character != EOF; single_character = getc(fileopen))
	{

		if (single_character == '\n')
		{ //Actual Line Counter
			counter++;
		}
	}

	fclose(fileopen); //Closing File
	return counter;
}

void readDataFromFile(record *p, int counter)
{

	int i, j = 0, k = 0, a = 0, x, email_flag;

	char scan_character[60];

	FILE *fileopen_read = NULL;

	fileopen_read = fopen("hw4_disordered_people.txt", "r"); //Opening File
	if (fileopen_read == NULL)
	{
		printf("Error!"); //Control Section
		exit(1);
	}

	while (k < counter)
	{
		for (i = 0; i < 4; i++)
		{

			char scan_character[60] = {};
			fscanf(fileopen_read, "%s", scan_character); //Scanning Only One Word
			int lenght = strlen(scan_character);		 //Finding Length Of The Word

			if (scan_character[0] >= '0' && scan_character[0] <= '9')
			{ //Filtering For Detecting ID Numbers To Temporary Array

				strcpy(p[k].ID, scan_character); //Copying Temporary Detected ID Number To Pointer
			}
			else if (scan_character[lenght - 4] == '.' || scan_character[lenght - 3] == '.')
			{ //Filtering For Detecting E-Mail To Temporary Array

				strcpy(p[k].email, scan_character); //Copying Temporary Detected E-Mail To Pointer
			}
			else if (scan_character[0] >= 'A' && scan_character[0] <= 'Z' && scan_character[1] >= 'A' && scan_character[1] <= 'Z')
			{ //Filtering For Detecting Surname To Temporary Array

				strcpy(p[k].surname, scan_character); //Copying Temporary Detected Surname To Pointer
													  //printf("%s\n",p[k].surname);
			}
			else if (scan_character[0] >= 'A' && scan_character[0] <= 'Z' && scan_character[1] >= 'a' && scan_character[1] <= 'z')
			{ //Filtering For Detecting Name To Temporary Array
				x = 0;
				while (scan_character[x] != '\0')
				{ //Counting How Many Words Are There In The Scanned Word
					x++;
				}
				strcpy(p[k].name, scan_character);			 //Copying Temporary Detected E-Mail To Pointer
				fscanf(fileopen_read, "%s", scan_character); //Scanning If Next Word Is Again Number or Not
				int lenght = strlen(scan_character);		 //Counting How Many Words Are There In The Scanned Word

				if (scan_character[0] >= 'A' && scan_character[0] <= 'Z' && scan_character[1] >= 'a' && scan_character[1] <= 'z')
				{ //Again Filtering For Detecting Name To Temporary Array

					p[k].name[x] = ' ';
					p[k].name[x + 1] = '\0';		   //Ascending Space End Of The First Number
					strcat(p[k].name, scan_character); //Adding Two Word Together
				}
				else if (scan_character[0] >= '0' && scan_character[0] <= '9')
				{ //Filtering For Detecting ID Numbers To Temporary Array

					strcpy(p[k].ID, scan_character); //Copying Temporary Detected ID Number To Pointer

					i++;
				}
				else if (scan_character[lenght - 4] == '.' || scan_character[lenght - 3] == '.')
				{ //Filtering For Detecting E-Mail To Temporary Array

					strcpy(p[k].email, scan_character); //Copying Temporary Detected E-Mail To Pointer

					i++;
				}
				else if (scan_character[0] >= 'A' && scan_character[0] <= 'Z' && scan_character[1] >= 'A' && scan_character[1] <= 'Z')
				{ //Filtering For Detecting Surname To Temporary Array

					strcpy(p[k].surname, scan_character); //Copying Temporary Detected Surname To Pointer

					i++; //The Reason I Added Every Step To Add "i++" Every Line Is That
				}		 //Not To Shift Words. If I Didn't Write,There Will Be A Shifting
			}
		}
		k++; //Passing Next Line
	}
	fclose(fileopen_read); //Closing File For This Function
}

void sorting_ID(record *p, int counter)
{

	int a, b, j, i, x;
	char temp_ID[50], temp_name[50], temp_surname[50], temp_email[50];

	for (i = 0; i < counter + 1; i++)
	{
		for (j = i + 1; j < counter; j++)
		{

			a = strlen((p + i)->ID);
			b = strlen((p + j)->ID);

			if (a > b)
			{ //If Lenght Of First ID Of Array is Bigger Than Second ID Of Array,Reverse Them.

				strcpy(temp_ID, (p + i)->ID);
				strcpy((p + i)->ID, (p + j)->ID);
				strcpy((p + j)->ID, temp_ID);

				strcpy(temp_name, (p + i)->name);
				strcpy((p + i)->name, (p + j)->name);
				strcpy((p + j)->name, temp_name);

				strcpy(temp_surname, (p + i)->surname);
				strcpy((p + i)->surname, (p + j)->surname);
				strcpy((p + j)->surname, temp_surname);

				strcpy(temp_email, (p + i)->email);
				strcpy((p + i)->email, (p + j)->email);
				strcpy((p + j)->email, temp_email);
			}
			if (a == b)
			{ //If They Are Equal, Look At The Numbers Of ID's
				char *ptr;
				int count = 0;

				for (ptr = (p + j)->ID; ptr < (char *)(p + j)->ID + 1; ptr++)
				{ //ID's Character Numbers
					count++;
				}
				for (x = 0; x < count; x++)
				{
					if ((p + j)->ID[x] <= (p + i)->ID[x])
					{ //If Lenght Of First Number Of ID is Bigger Than Second Number Of ID,Reverse Them.

						strcpy(temp_ID, (p + i)->ID);
						strcpy((p + i)->ID, (p + j)->ID);
						strcpy((p + j)->ID, temp_ID);

						strcpy(temp_name, (p + i)->name);
						strcpy((p + i)->name, (p + j)->name);
						strcpy((p + j)->name, temp_name);

						strcpy(temp_surname, (p + i)->surname);
						strcpy((p + i)->surname, (p + j)->surname);
						strcpy((p + j)->surname, temp_surname);

						strcpy(temp_email, (p + i)->email);
						strcpy((p + i)->email, (p + j)->email);
						strcpy((p + j)->email, temp_email);
					}
				}
			}
		}
	}
}

void sorting_name(record *p, int counter)
{

	int comparison, j, i;
	char temp_ID[50], temp_name[50], temp_surname[50], temp_email[50];

	for (i = 0; i < counter + 1; i++)
	{
		for (j = i + 1; j < counter; j++)
		{ //i=1. j=2.

			comparison = strcmp((p + i)->name, (p + j)->name);
			if (comparison > 0)
			{

				strcpy(temp_ID, (p + i)->ID);
				strcpy((p + i)->ID, (p + j)->ID);
				strcpy((p + j)->ID, temp_ID);

				strcpy(temp_name, (p + i)->name);
				strcpy((p + i)->name, (p + j)->name); //Comparison of two strings
				strcpy((p + j)->name, temp_name);

				strcpy(temp_surname, (p + i)->surname);
				strcpy((p + i)->surname, (p + j)->surname);
				strcpy((p + j)->surname, temp_surname);

				strcpy(temp_email, (p + i)->email);
				strcpy((p + i)->email, (p + j)->email);
				strcpy((p + j)->email, temp_email);
			}
		}
	}
}

void sorting_surname(record *p, int counter)
{

	int comparison, j, i;
	char temp_ID[50], temp_name[50], temp_surname[50], temp_email[50];

	for (i = 0; i < counter + 1; i++)
	{
		for (j = i + 1; j < counter; j++)
		{ //i=1. j=2.

			comparison = strcmp((p + i)->surname, (p + j)->surname);
			if (comparison > 0)
			{

				strcpy(temp_ID, (p + i)->ID);
				strcpy((p + i)->ID, (p + j)->ID);
				strcpy((p + j)->ID, temp_ID);

				strcpy(temp_name, (p + i)->name);
				strcpy((p + i)->name, (p + j)->name); //Comparison of two strings
				strcpy((p + j)->name, temp_name);

				strcpy(temp_surname, (p + i)->surname);
				strcpy((p + i)->surname, (p + j)->surname);
				strcpy((p + j)->surname, temp_surname);

				strcpy(temp_email, (p + i)->email);
				strcpy((p + i)->email, (p + j)->email);
				strcpy((p + j)->email, temp_email);
			}
		}
	}
}

void sorting_email(record *p, int counter)
{

	int comparison, j, i;
	char temp_ID[50], temp_name[50], temp_surname[50], temp_email[50];

	for (i = 0; i < counter + 1; i++)
	{
		for (j = i + 1; j < counter; j++)
		{ //i=1. j=2.

			comparison = strcmp((p + i)->email, (p + j)->email);
			if (comparison > 0)
			{

				strcpy(temp_ID, (p + i)->ID);
				strcpy((p + i)->ID, (p + j)->ID);
				strcpy((p + j)->ID, temp_ID);

				strcpy(temp_name, (p + i)->name);
				strcpy((p + i)->name, (p + j)->name); //Comparison of two strings
				strcpy((p + j)->name, temp_name);

				strcpy(temp_surname, (p + i)->surname);
				strcpy((p + i)->surname, (p + j)->surname);
				strcpy((p + j)->surname, temp_surname);

				strcpy(temp_email, (p + i)->email);
				strcpy((p + i)->email, (p + j)->email);
				strcpy((p + j)->email, temp_email);
			}
		}
	}
}

void writeDataToFile(record *p, int counter)
{

	int i, c = 0;
	char input_char, a;
	FILE *fileopen_write = NULL;
	fileopen_write = fopen("ordered_file.txt", "w"); //Opening Write File

	if (fileopen_write == NULL)
	{
		printf("Error!"); //Control Step
		exit(1);
	}

	while (c < 1)
	{

		input_char = getchar();

		switch (input_char)
		{
		case 'I':
			fprintf(fileopen_write, "%s					", "ID");
			fprintf(fileopen_write, "%s				", "Name"); //Printing Titles To Top
			fprintf(fileopen_write, "%s				", "Surname");
			fprintf(fileopen_write, "%s", "E-Mail");
			fprintf(fileopen_write, "\n");

			for (i = 0; i < counter; i++)
			{ //Line Increaser Loop
				int lenght_ID = strlen((p + i)->ID);
				int lenght_name = strlen((p + i)->name);
				int lenght_surname = strlen((p + i)->surname); //Looking Lenght of Every Word Thar Will Be Ordered
				int lenght_email = strlen((p + i)->email);

				if (lenght_ID < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].ID);
				}
				else if (lenght_ID < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].ID); //Printinf Regularly. I Could Use '->' Instead Of '.'
				}
				else if (lenght_ID < 12)
				{
					fprintf(fileopen_write, "%s			", p[i].ID);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].ID);
				}
				if (lenght_name < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].name);
				}
				else if (lenght_name < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].name); //Printinf Regularly. I Could Use '->' Instead Of '.'
				}
				else if (lenght_name < 12)
				{
					fprintf(fileopen_write, "%s			", p[i].name);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].name);
				}
				if (lenght_surname < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].surname);
				}
				else if (lenght_surname < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].surname);
				}
				else if (lenght_surname < 12)
				{ //Printinf Regularly. I Could Use '->' Instead Of '.'
					fprintf(fileopen_write, "%s			", p[i].surname);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].surname);
				}
				if (lenght_email < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].email);
				}
				else if (lenght_email < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].email);
				}
				else if (lenght_email < 12)
				{ //Printinf Regularly. I Could Use '->' Instead Of '.'
					fprintf(fileopen_write, "%s			", p[i].email);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].email);
				}

				fprintf(fileopen_write, "\n"); //Passing Next Line
			}

			printf("%s\n", "Your File's  First Column Set As ID");
			c++;
			break;

		case 'M':
			fprintf(fileopen_write, "%s								", "E-Mail");
			fprintf(fileopen_write, "%s					", "ID"); //Printing Titles To Top
			fprintf(fileopen_write, "%s				", "Name");
			fprintf(fileopen_write, "%s", "Surname");
			fprintf(fileopen_write, "\n");

			for (i = 0; i < counter; i++)
			{ //Line Increaser Loop
				int lenght_ID = strlen((p + i)->ID);
				int lenght_name = strlen((p + i)->name);
				int lenght_surname = strlen((p + i)->surname); //Looking Lenght of Every Word Thar Will Be Ordered
				int lenght_email = strlen((p + i)->email);

				if (lenght_email < 8)
				{
					fprintf(fileopen_write, "%s							", p[i].email);
				}
				else if (lenght_email < 16)
				{
					fprintf(fileopen_write, "%s						", p[i].email);
				}
				else if (lenght_email < 24)
				{ //Printinf Regularly. I Could Use '->' Instead Of '.'
					fprintf(fileopen_write, "%s				", p[i].email);
				}
				else
				{
					fprintf(fileopen_write, "%s			", p[i].email);
				}
				if (lenght_ID < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].ID);
				}
				else if (lenght_ID < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].ID); //Printinf Regularly. I Could Use '->' Instead Of '.'
				}
				else if (lenght_ID < 12)
				{
					fprintf(fileopen_write, "%s			", p[i].ID);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].ID);
				}
				if (lenght_name < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].name);
				}
				else if (lenght_name < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].name); //Printinf Regularly. I Could Use '->' Instead Of '.'
				}
				else if (lenght_name < 12)
				{
					fprintf(fileopen_write, "%s			", p[i].name);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].name);
				}
				if (lenght_surname < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].surname);
				}
				else if (lenght_surname < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].surname);
				}
				else if (lenght_surname < 12)
				{ //Printinf Regularly. I Could Use '->' Instead Of '.'
					fprintf(fileopen_write, "%s			", p[i].surname);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].surname);
				}

				fprintf(fileopen_write, "\n"); //Passing Next Line
			}

			printf("%s\n", "Your File's  First Column Set As E-Mail");
			c++;
			break;

		case 'N':
			fprintf(fileopen_write, "%s				", "Name");
			fprintf(fileopen_write, "%s					", "ID"); //Printing Titles To Top
			fprintf(fileopen_write, "%s				", "Surname");
			fprintf(fileopen_write, "%s", "E-Mail");
			fprintf(fileopen_write, "\n");

			for (i = 0; i < counter; i++)
			{
				//Line Increaser Loop
				int lenght_ID = strlen((p + i)->ID);
				int lenght_name = strlen((p + i)->name);
				int lenght_surname = strlen((p + i)->surname); //Looking Lenght of Every Word Thar Will Be Ordered
				int lenght_email = strlen((p + i)->email);

				if (lenght_name < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].name);
				}
				else if (lenght_name < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].name); //Printinf Regularly. I Could Use '->' Instead Of '.'
				}
				else if (lenght_name < 12)
				{
					fprintf(fileopen_write, "%s			", p[i].name);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].name);
				}
				if (lenght_ID < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].ID);
				}
				else if (lenght_ID < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].ID); //Printinf Regularly. I Could Use '->' Instead Of '.'
				}
				else if (lenght_ID < 12)
				{
					fprintf(fileopen_write, "%s			", p[i].ID);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].ID);
				}

				if (lenght_surname < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].surname);
				}
				else if (lenght_surname < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].surname);
				}
				else if (lenght_surname < 12)
				{ //Printinf Regularly. I Could Use '->' Instead Of '.'
					fprintf(fileopen_write, "%s			", p[i].surname);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].surname);
				}
				if (lenght_email < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].email);
				}
				else if (lenght_email < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].email);
				}
				else if (lenght_email < 12)
				{ //Printinf Regularly. I Could Use '->' Instead Of '.'
					fprintf(fileopen_write, "%s			", p[i].email);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].email);
				}

				fprintf(fileopen_write, "\n"); //Passing Next Line
			}

			printf("%s\n", "Your File's  First Column Set As Name");
			c++;
			break;

		case 'S':
			fprintf(fileopen_write, "%s				", "Surname");
			fprintf(fileopen_write, "%s					", "ID"); //Printing Titles To Top
			fprintf(fileopen_write, "%s				", "Name");
			fprintf(fileopen_write, "%s", "E-Mail");
			fprintf(fileopen_write, "\n");

			for (i = 0; i < counter; i++)
			{ //Line Increaser Loop
				int lenght_ID = strlen((p + i)->ID);
				int lenght_name = strlen((p + i)->name);
				int lenght_surname = strlen((p + i)->surname); //Looking Lenght of Every Word Thar Will Be Ordered
				int lenght_email = strlen((p + i)->email);

				if (lenght_surname < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].surname);
				}
				else if (lenght_surname < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].surname);
				}
				else if (lenght_surname < 12)
				{ //Printinf Regularly. I Could Use '->' Instead Of '.'
					fprintf(fileopen_write, "%s			", p[i].surname);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].surname);
				}
				if (lenght_ID < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].ID);
				}
				else if (lenght_ID < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].ID); //Printinf Regularly. I Could Use '->' Instead Of '.'
				}
				else if (lenght_ID < 12)
				{
					fprintf(fileopen_write, "%s			", p[i].ID);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].ID);
				}
				if (lenght_name < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].name);
				}
				else if (lenght_name < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].name); //Printinf Regularly. I Could Use '->' Instead Of '.'
				}
				else if (lenght_name < 12)
				{
					fprintf(fileopen_write, "%s			", p[i].name);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].name);
				}

				if (lenght_email < 4)
				{
					fprintf(fileopen_write, "%s					", p[i].email);
				}
				else if (lenght_email < 8)
				{
					fprintf(fileopen_write, "%s				", p[i].email);
				}
				else if (lenght_email < 12)
				{ //Printinf Regularly. I Could Use '->' Instead Of '.'
					fprintf(fileopen_write, "%s			", p[i].email);
				}
				else
				{
					fprintf(fileopen_write, "%s		", p[i].email);
				}

				fprintf(fileopen_write, "\n"); //Passing Next Line
			}

			printf("%s\n", "Your File's  First Column Set As Surname");
			c++;
			break;

		case 'Q':
			exit(1);
			break;

		default:

			printf("%s", "Give A Sort Metric(I=ID , N=NAME , S=SURNAME , M=MAIL , Q=EXIT):");
		}
	}

	fclose(fileopen_write);
}
