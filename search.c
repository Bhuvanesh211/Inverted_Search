#include "inverted_search.h"

int search_database( Wlist *head, char *word)
{
    if(head == NULL)
    {
        printf("List is empty , search not possible\n");
        return 0;
    }

    //traverse the list
    while(head)
    {
        //compare each node word with the search word
        if(!strcmp(head->word , word))
        {
            printf("Word %s is present in %d file/s \n", word , head->file_count);

            Ltable *Thead = head->Tlink;
            while(Thead)
            {
                printf("In file : %s  %d time/s \n" , Thead->file_name , Thead->word_count);
                Thead = Thead->table_link;
            }
            printf("\n");
            return 0;
        }
        head = head->link;
    }

    printf("Search word not found\n");

}