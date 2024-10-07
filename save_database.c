#include "inverted_search.h"

void save_database(Wlist *head[])
{
    char file_name[FNAME_SIZE];
    printf("Enter the file name : ");
    scanf("%s", file_name);
    int i;

    // open file

    FILE *fptr = fopen(file_name, "w");

    for (i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            write_databasefile(head[i], fptr,i);
        }
    }
}

void write_databasefile(Wlist *head, FILE *databasefile, int index)
{
    //.......TODO.........
    // #[index]  word is [word] : file count is file_count : file/s  : file name is file_name : word count is word_count

    while (head)
    {
        fprintf(databasefile, "#[%d] \nword is [%s]: file count is : [%d]:", index, head->word, head->file_count);

        Ltable *Thead = head->Tlink;
        while (Thead)
        {
            fprintf(databasefile, "file/s: file is %s: word count is %d.", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
        }

        fprintf(databasefile, "\n");

        head = head->link;
    }
}