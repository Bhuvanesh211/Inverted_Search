#include "inverted_search.h"
void create_database(Flist *f_head, Wlist *head[])
{
    // Traverse through the file linked list
    while (f_head)
    {
        read_datafile(f_head, head, f_head->file_name);
        f_head = f_head->link;
    }
}

// Read content of file
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
    // Open the file in read mode
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        perror("Error opening file");
        return NULL;
    }

    // Declare an array to store words
    char word[WORD_SIZE];

    while (fscanf(fptr, "%s", word) != EOF)
    {
        // Index
        int index = tolower(word[0]) % 97;

        // Handle non-alphabetic characters
        if (!(index >= 0 && index <= 25))
            index = 26;

        // Check if words are repeated
        int flag = 1;
        if (head[index] != NULL)
        {
            Wlist *temp = head[index];
            // Compare the words at each node with the new word
            while (temp)
            {
                if (!strcmp(temp->word, word))
                {
                    update_word_count(&temp, filename);
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }
        }
        if (flag == 1)
        {
            // Words are not repeated
            insert_at_last(&head[index], word, filename);
        }
    }

    fclose(fptr);
    return NULL; // Return value is not used, so NULL is fine
}

int update_word_count(Wlist **head, char *file_name)
{
    // Check whether the filenames are the same or not
    // If filenames are the same, increment word_count
    // If filenames are different, increment file_count, create new Ltable node

    if (!strcmp(file_name, (*head)->Tlink->file_name))
    {
        (*head)->Tlink->word_count += 1;
    }
    else
    {
        (*head)->file_count += 1;

        Ltable *new = malloc(sizeof(Ltable));
        if (new == NULL)
        {
            return FAILURE;
        }

        strcpy(new->file_name, file_name);
        new->word_count = 1;
        new->table_link = NULL;

        Ltable *current = (*head)->Tlink;

        while (current->table_link != NULL)
        {
            current = current->table_link;
        }
        current->table_link = new;
    }
    return SUCCESS;
}
