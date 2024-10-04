#include <ctype.h>
#include <stdio.h>
#include "inverted_search.h"

void display_database(Wlist *head[])
{
    printf("-----------------------------------------------------------------------\n");
    printf("[index]  [word]    file_count file/s  File:File_name    word_count\n");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            print_word_count(head[i]);
        }
    }
    printf("------------------------------------------------------------------------");
}

int print_word_count(Wlist *head)
{
    while (head != NULL)
    {
        int index = tolower(head->word[0]) - 'a';

        // Handle non-alphabetic characters
        if (!(index >= 0 && index <= 25))
            index = 26;

        printf(" [%2d]     %-10s   %d    file/s : ", index, head->word, head->file_count);

        Ltable *Thead = head->Tlink;

        while (Thead)
        {
            printf("\t%-10s \t   %d  ", Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
        }

        printf("\n");
        head = head->link;
        
    }
    return 0;
}
