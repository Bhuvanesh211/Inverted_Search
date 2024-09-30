/*
Name : Pavithra C R
Date : 04/06/2024
Description : Inverted Indexing Project
*/

#include "inverted_search.h"

int main(int argc, char *argv[])
{
    system("clear");
    Wlist *head[27] = {NULL};

    // Validate CLA
    if (argc <= 1)
    {
        printf("Enter the valid number of arguments\n");
        printf("./Slist.exe file1.txt file2.txt.......\n");
        return 0;
    }

    // Declare a head pointer for file linked list
    Flist *f_head = NULL;

    // Validate the files and create file linked list
    file_validation_n_file_list(&f_head, argv);

    if (f_head == NULL)
    {
        printf("No files are available in the file linked list\n");
        printf("Hence the process is terminated\n");
        return 0;
    }

    int y = 1;
    while (y)
    {
        printf("Select your choice among the following options:\n");
        printf("1. Create DATABASE\n");
        printf("2. Display Database\n");
        printf("3. Update DATABASE\n");
        printf("4. Search\n");
        printf("5. Save Database\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            create_database(f_head, head);
            printf("\nSuccessfully database is created\n\n");
            break;
        case 2:
            display_database(head);
            printf("\n");
            break;
        case 3:
            update_database(head, &f_head);
            break;
        case 4:
        {
            char word[WORD_SIZE];
            printf("\nEnter the word to search: ");
            scanf(" %[^\n]", word);
            search_database(head[tolower(word[0]) % 97], word);
        }
        break;
        case 5:
            save_database(head);
            break;
        case 6:
            printf("Exiting...\n");
            y = 0; // Set y to 0 to exit the loop
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
            break;
        }
    }

    return 0;
}
