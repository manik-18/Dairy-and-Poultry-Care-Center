/*
DAIRY & POULTRY CARE CENTRE
BY:- MANIK GUPTA
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char day[20], date[20], category[10], name[20], oname[20], problem[100], mob[20];
	struct node *next;
};

struct node *start = NULL;
int i;

void add();     // This function is used to add new Record
void modify();	// This function is used to modify any particular Record
void delete();	// This function is used to delete any Record
void search();	// This function is used to find or search any Record
void display();	// This function is used to display all the Record

void main()
{
	int option;
	char p[10], un[10], c;
	start = NULL;
	system("cls");

//  login code starts

	printf("\n\n\n\n\t\t\t\tLogin\n");
	printf("\t\t\t*********************\n");
	printf("\n\tEnter User ID: ");
	scanf("%s", un);
	printf("\n\tEnter your password : ");
	scanf("%s", p);
	if (strcmp(un, "Manik") == 0)
	{
		if (strcmp(p, "123") == 0)
		{
			printf("\n\t!!! LOGIN SUCCESSFUL !!!\n\n\tPress Enter to continue... ");
		}
		else
		{
			printf("\n\n\t\t!!! WRONG PASSWORD !!!");
		}
	}
	else
	{
		printf("\n\n\t\t!!! INVALID USERNAME !!!");
	}
	getch();
	if (strcmp(un, "Manik") == 0 && strcmp(p, "123") == 0)
	
	// login code ends

	{
		system("cls");
		printf("\t\t\t---------------------------\n");
		printf("\t\t\t\tWELCOME\n");
		printf("\t\t\t---------------------------\n");
		printf("\t\t\tDAIRY & POULTRY CARE CENTRE\n");
		printf("\t\t\t---------------------------\n");

		do
		{
			system("cls");
			printf("\n\t\t\t\tMENU\n\t\t1. Enter new pet details\n\t\t2. Find pet details\n\t\t");
			printf("3. Delete pet details\n\t\t4. Modify pet details\n\t\t5. Display all pets with their details\n\t\t6. Exit\n");
			printf("\nChoose an option: ");
			scanf("%d", &option);
			switch (option)
			{
			case 1:
				add();
				break;
			case 2:
				search();
				break;
			case 3:
				delete ();
				break;
			case 4:
				modify();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("!!! Enter a valid number !!!");
				break;
			}
			printf("\nDo you want to continue ?(y/n)");
			c = getche();
		} while (c == 'y');
	}
	getch();
}

void add()
{
	struct node *temp, *newnode;
	system("cls");
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\nEnter the date in (DD/MM/YY):  ");
	scanf("%s", newnode->date);
	printf("Enter the day: ");
	scanf("%s", newnode->day);
	printf("Is the pet is dairy or poultry:  ");
	scanf("%s", newnode->category);
	printf("Enter the name of pet:  ");
	fflush(stdin);
	scanf("%[^\n]s", newnode->name);
	printf("Enter the pet's owner name:  ");
	fflush(stdin);
	scanf("%[^\n]s", newnode->oname);
	printf("Enter the problem which pet has:  ");
	fflush(stdin);
	scanf("%[^\n]s", newnode->problem);
	printf("Enter the correct contact of owner:  ");
	scanf("%s", newnode->mob);
	newnode->next = NULL;
	if (start == NULL)
	{
		start = newnode;
	}
	else
	{
		temp = start;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}

	printf("\n!!! Record added successfully !!!\n");
}

void modify()
{
	struct node *temp;
	char item1[20], item2[20];
	temp = start;
	system("cls");

	if (start == NULL)
	{
		printf("\n!!! Add Record first !!!\n");
	}
	else
	{
		printf("Enter the name of the pet whose record you want to update: ");
		fflush(stdin);
		scanf("%[^\n]s", item1);
		printf("Enter the date on which the pet is admitted:               ");
		scanf("%s", item2);
		while (strcmpi(temp->date, item2) != 0 && temp->next != NULL && strcmpi(temp->name, item1) != 0)
		{
			temp = temp->next;
		}
		if ((strcmpi(temp->date, item2) == 0) && (strcmpi(temp->name, item1) == 0))
		{
			printf("\nRecord with name %s and date %s is found\n", item1, item2);
			printf("\nPlease enter the new record\n");
			printf("\nEnter the date: ");
			scanf("%s", temp->date);
			printf("Enter the day: ");
			scanf("%s", temp->day);
			printf("Is the pet is dairy or poultry: ");
			scanf("%s", temp->category);
			printf("Enter the name of pet: ");
			fflush(stdin);
			scanf("%[^\n]s", temp->name);
			printf("Enter the pet's owner name: ");
			fflush(stdin);
			scanf("%[^\n]s", temp->oname);
			printf("Enter the problem which pet has: ");
			fflush(stdin);
			scanf("%[^\n]s", temp->problem);
			printf("Enter the correct contact of owner: ");
			scanf("%s", temp->mob);

			printf("\n!!! Record Updated Successful !!!\n");
		}
		else
		{
			printf("\n!!! Record is not found !!!\n");
		}
	}
}

void delete ()
{
	struct node *temp = start;
	struct node *q;
	char item1[20], item2[20];
	system("cls");
	if (start == NULL)
	{
		printf("\n!!! First add Record to delete !!!\n");
	}
	else
	{
		printf("Enter the name of the pet whose record you want to delete: ");
		fflush(stdin);
		scanf("%[^\n]s", item1);
		printf("Enter the date on which the pet is admitted: ");
		scanf("%s", item2);
		if (strcmp(temp->date, item2) == 0 && strcmp(temp->name, item1) == 0)
		{
			start = start->next;
			printf("\n!!! Record deleted !!!\n");
		}
		else
		{
			while (strcmp(temp->date, item2) != 0 && strcmp(temp->name, item1) != 0 && temp != NULL)
			{
				q = temp;
				temp = temp->next;
			}
			if (strcmp(temp->date, item2) == 0 && strcmp(temp->name, item1) == 0)
			{
				q->next = temp->next;
				printf("\n!!! Record deleted !!!\n");
			}
			else
			{
				printf("\n!!! Record not found !!!\n");
			}
		}
	}
}

void search()
{
	struct node *temp = start;
	char item1[20], item2[20];
	system("cls");

	if (start == NULL)
	{
		printf("\n!!! Add record first !!!\n");
	}
	else
	{
		printf("Enter the name of the animal whose record you want to search: \n");
		fflush(stdin);
		scanf("%[^\n]s", item1);
		printf("Enter the date on which the pet is admitted: \n");
		scanf("%s", item2);
		while (strcmpi(temp->date, item2) != 0 && temp->next != 0 && strcmpi(temp->name, item1) != 0)
		{
			temp = temp->next;
		}
		if ((strcmpi(temp->date, item2) == 0) && (strcmpi(temp->name, item1) == 0))
		{
			printf("\n!!! Record Found !!!\n");
			printf("\nDate: %s\n", temp->date);
			printf("Day: %s\n", temp->day);
			printf("Category: %s\n", temp->category);
			printf("Name of pet: %s\n", temp->name);
			printf("Owner's name: %s\n", temp->oname);
			printf("Problem of pet: ");
			printf("%s", temp->problem);
			printf("\nContact of owner: %s\n", temp->mob);
		}
		else
		{
			printf("\n!!! Record is not found !!!\n");
		}
	}
}

void display()
{
	struct node *temp;
	system("cls");
	temp = start;
	if (start == NULL)
	{
		printf("\n!!! Nothing to display !!!\n");
	}
	else
	{
		while (temp != NULL)
		{
			printf("\nThe record is given below:\n");
			printf("\nDate: %s\n", temp->date);
			printf("Day: %s\n", temp->day);
			printf("Category: %s\n", temp->category);
			printf("Name of pet: %s\n", temp->name);
			printf("Owner's name: %s\n", temp->oname);
			printf("Problem of pet: ");
			printf("%s", temp->problem);
			printf("\nContact of owner: %s\n", temp->mob);
			temp = temp->next;
		}
	}
}

