#include "inverted_search.h" 
int insert_at_last(Wlist **head, data_t *data, char *filename)
{
    //create a node 
    Wlist *new = malloc(sizeof(Wlist));

    //error check
    if(new == NULL)
    {
        return FAILURE;
    }
    //update the fields
    new->file_count = 1;
    strcpy(new->word ,data);
    new->Tlink = NULL;
    new->link = NULL;

    //call fun() to create Ltable node
    update_link_table(&new, filename);

    //check Wlist is empty or not
    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    //list is not empty

    Wlist *temp = *head;
    //traverse through Wlist

    while(temp->link)
    {
        temp = temp->link;
    }

    temp->link = new;
    return SUCCESS;

}

int update_link_table(Wlist **head, char *filename)
{
    //create a node
    Ltable *new = malloc(sizeof(Ltable));

    //error check
    if(new == NULL)
    {
        return FAILURE;
    }

    new->word_count = 1;
    strcpy(new->file_name, filename);
    new->table_link = NULL;

    (*head)->Tlink = new;

    return SUCCESS;
}