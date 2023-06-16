/*
LIVESTOCK LEDGER
BY:- MANIK GUPTA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Record
{
    char day[20], date[20], category[10], petName[20], ownerName[20], problem[100], contactNumber[11];
    struct Record *next;
};

struct Record *start = NULL;

void addRecord(const char *date, const char *day, const char *category, const char *petName, const char *ownerName, const char *problem, const char *contactNumber);
void modifyRecord(const char *petName);
void deleteRecord(const char *petName);
void searchRecord(const char *petName);
void displayRecords();

int isValidDate(const char *date);
int isValidContactNumber(const char *number);

void takeInputAndAddRecord();

int main()
{
    int option;
    char password[10], username[10], choice;

    start = NULL;
    system("cls");

    printf("\n\n\n\n\t\t\t\tLogin\n");
    printf("\t\t\t*********************\n");
    printf("\n\tEnter User ID: ");
    scanf("%s", username);
    printf("\n\tEnter your password: ");
    scanf("%s", password);

    if (strcmp(username, "Manik") == 0 && strcmp(password, "123") == 0)
    {
        printf("\n\t!!! LOGIN SUCCESSFUL !!!\n\n\tPress Enter to continue... ");
        getch();
        system("cls");
        printf("\t\t\t---------------------------\n");
        printf("\t\t\t\tWELCOME\n");
        printf("\t\t\t---------------------------\n");
        printf("\t\t\tLIVESTOCK LEDGER\n");
        printf("\t\t\t---------------------------\n");

        do
        {
            system("cls");
            printf("\n\t\t\t\tMENU\n\t\t1. Enter new pet details\n\t\t2. Find pet details\n\t\t3. Delete pet details\n\t\t4. Modify pet details\n\t\t5. Display all pets with their details\n\t\t6. Exit\n");
            printf("\nChoose an option: ");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                system("cls");
                takeInputAndAddRecord();
                break;
            case 2:
            {
                system("cls");
                char petName[20];
                printf("\nEnter the pet's name to search: ");
                scanf(" %[^\n]s", petName);
                searchRecord(petName);
                break;
            }
            case 3:
            {
                system("cls");
                char petName[20];
                printf("\nEnter the pet's name to delete: ");
                scanf(" %[^\n]s", petName);
                deleteRecord(petName);
                break;
            }
            case 4:
            {
                system("cls");
                char petName[20];
                printf("\nEnter the pet's name to modify: ");
                scanf(" %[^\n]s", petName);
                modifyRecord(petName);
                break;
            }
            case 5:
                system("cls");
                displayRecords();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("!!! Enter a valid number !!!");
                break;
            }
            printf("\n\nDo you want to continue? (y/n)");
            scanf(" %c", &choice);
        } while (choice == 'y' || choice == 'Y');
    }
    else
    {
        printf("\n\t!!! WRONG CREDENTIALS !!!\n\n\tPress Enter to continue... ");
    }
    getch();
}

void takeInputAndAddRecord()
{
    char date[20], day[20], category[10], petName[20], ownerName[20], problem[100], contactNumber[11];

    printf("Enter the date (DD/MM/YY):  ");
    scanf("%s", date);
    while (!isValidDate(date))
    {
        printf("\nInvalid date format.\n\nPlease enter a valid date (DD/MM/YY): ");
        scanf("%s", date);
    }

    printf("Enter the day: ");
    scanf("%s", day);

    printf("Is the pet dairy or poultry?  ");
    scanf("%s", category);

    printf("Enter the pet's name:  ");
    scanf(" %[^\n]s", petName);

    printf("Enter the owner's name:  ");
    scanf(" %[^\n]s", ownerName);

    printf("Enter the problem the pet has:  ");
    scanf(" %[^\n]s", problem);

    printf("Enter the contact number of the owner (10 digits):  ");
    scanf("%s", contactNumber);
    while (!isValidContactNumber(contactNumber))
    {
        printf("\nInvalid contact number.\n\nPlease enter a 10-digit number: ");
        scanf("%s", contactNumber);
    }

    addRecord(date, day, category, petName, ownerName, problem, contactNumber);
}

void addRecord(const char *date, const char *day, const char *category, const char *petName, const char *ownerName, const char *problem, const char *contactNumber)
{
    struct Record *temp, *newRecord;

    newRecord = (struct Record *)malloc(sizeof(struct Record));
    strcpy(newRecord->date, date);
    strcpy(newRecord->day, day);
    strcpy(newRecord->category, category);
    strcpy(newRecord->petName, petName);
    strcpy(newRecord->ownerName, ownerName);
    strcpy(newRecord->problem, problem);
    strcpy(newRecord->contactNumber, contactNumber);

    newRecord->next = NULL;

    if (start == NULL)
    {
        start = newRecord;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newRecord;
    }

    printf("\nRecord added successfully!");
}

void modifyRecord(const char *petName)
{
    struct Record *temp = start;

    if (temp == NULL)
    {
        printf("\nNo records found.");
        return;
    }

    while (temp != NULL)
    {
        if (strcmp(temp->petName, petName) == 0)
        {
            char date[20], day[20], category[10], ownerName[20], problem[100], contactNumber[11];

            printf("Enter the new date (DD/MM/YY): ");
            scanf("%s", date);
            while (!isValidDate(date))
            {
                printf("\nInvalid date format.\n\nPlease enter a valid date (DD/MM/YY): ");
                scanf("%s", date);
            }

            printf("Enter the new day: ");
            scanf("%s", day);

            printf("Enter the new category (dairy or poultry): ");
            scanf("%s", category);

            printf("Enter the new pet's name: ");
            scanf(" %[^\n]s", petName);

            printf("Enter the new owner's name: ");
            scanf(" %[^\n]s", ownerName);

            printf("Enter the new problem the pet has: ");
            scanf(" %[^\n]s", problem);

            printf("Enter the new contact number of the owner (10 digits): ");
            scanf("%s", contactNumber);
            while (!isValidContactNumber(contactNumber))
            {
                printf("\nInvalid contact number.\n\nPlease enter a 10-digit number: ");
                scanf("%s", contactNumber);
            }

            strcpy(temp->date, date);
            strcpy(temp->day, day);
            strcpy(temp->category, category);
            strcpy(temp->petName, petName);
            strcpy(temp->ownerName, ownerName);
            strcpy(temp->problem, problem);
            strcpy(temp->contactNumber, contactNumber);

            printf("\nRecord modified successfully!");
            return;
        }
        temp = temp->next;
    }

    printf("\nPet's name not found in records.");
}

void deleteRecord(const char *petName)
{
    struct Record *temp = start;
    struct Record *prev = NULL;

    if (temp == NULL)
    {
        printf("\nNo records found.");
        return;
    }

    while (temp != NULL)
    {
        if (strcmp(temp->petName, petName) == 0)
        {
            if (prev == NULL)
            {
                start = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            free(temp);
            printf("\nRecord deleted successfully!");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("\nPet's name not found in records.");
}

void searchRecord(const char *petName)
{
    struct Record *temp = start;

    if (temp == NULL)
    {
        printf("\nNo records found.");
        return;
    }

    while (temp != NULL)
    {
        if (strcmp(temp->petName, petName) == 0)
        {
            printf("\nRecord found!\n");
            printf("Date: %s\n", temp->date);
            printf("Day: %s\n", temp->day);
            printf("Category: %s\n", temp->category);
            printf("Pet's Name: %s\n", temp->petName);
            printf("Owner's Name: %s\n", temp->ownerName);
            printf("Problem: %s\n", temp->problem);
            printf("Contact Number: %s\n", temp->contactNumber);
            return;
        }
        temp = temp->next;
    }

    printf("\nPet's name not found in records.");
}

void displayRecords()
{
    struct Record *temp = start;

    if (temp == NULL)
    {
        printf("\nNo records found.");
        return;
    }

    printf("\nRecords:");
    printf("\n---------------------------\n");
    while (temp != NULL)
    {
        printf("\nDate: %s\n", temp->date);
        printf("Day: %s\n", temp->day);
        printf("Category: %s\n", temp->category);
        printf("Pet's Name: %s\n", temp->petName);
        printf("Owner's Name: %s\n", temp->ownerName);
        printf("Problem: %s\n", temp->problem);
        printf("Contact Number: %s\n", temp->contactNumber);
        printf("---------------------------\n");

        temp = temp->next;
    }
}

int isValidDate(const char *date)
{
    // Check if the date is in DD/MM/YY format
    if (strlen(date) != 8)
        return 0;

    int day = (date[0] - '0') * 10 + (date[1] - '0');
    int month = (date[3] - '0') * 10 + (date[4] - '0');
    int year = (date[6] - '0') * 10 + (date[7] - '0');

    // Check if the day, month, and year are valid
    if (day <= 0 || day > 31 || month <= 0 || month > 12 || year < 0)
        return 0;

    return 1;
}

int isValidContactNumber(const char *number)
{
    // Check if the contact number is 10 digits
    if (strlen(number) != 10)
        return 0;

    // Check if all characters are digits
    for (int i = 0; i < 10; i++)
    {
        if (number[i] < '0' || number[i] > '9')
            return 0;
    }

    return 1;
}
