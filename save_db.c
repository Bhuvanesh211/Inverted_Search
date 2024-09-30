#include "inverted_search.h"

void save_database(Wlist *head[])
{
    // prompt the user for file

    int i;
    char file_name[FNAME_SIZE];

    printf("Enter the file name to save the database\n");
    scanf("%s", file_name);

    // open file
    FILE *fptr = fopen(file_name, "w");

    for (i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            write_databasefile(head[i], fptr,i);
        }
    }

    printf("\nDatabase saved\n\n");
}

void write_databasefile(Wlist *head, FILE *databasefile,int index)
{
    // #[index]  [word] :  [file_count]   :   file_name   :  [word_count]

    while (head)
    {
        fprintf(databasefile, "#[%d] \n word : [%s] \tfile count : [%d]", index, head->word, head->file_count);

        Ltable *Thead = head->Tlink;
        while (Thead)
        {
            fprintf(databasefile, "\tfilename :   %s \tword count :  [%d]\n\t\t\t\t\t\t\t\t", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
        }

        fprintf(databasefile, "\n\n");

        head = head->link;
    }
}