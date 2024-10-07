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
    // Check if the word node is NULL
    if (*head == NULL)
    {
        return FAILURE;
    }

    // Traverse the link table to find if the file name exists
    Ltable *temp = (*head)->Tlink;

    while (temp != NULL)
    {
        // If the file names match, increment the word count
        if (strcmp(temp->file_name, file_name) == 0)
        {
            temp->word_count++; // Increment word count for this file
            return SUCCESS;
        }

        temp = temp->table_link; // Move to the next file node
    }

    // If the file name doesn't match any existing file, create a new link table node for the new file
    Ltable *new_node = (Ltable *)malloc(sizeof(Ltable));
    if (new_node == NULL)
    {
        perror("Failed to allocate memory");
        return FAILURE;
    }

    // Initialize the new link table node
    strcpy(new_node->file_name, file_name);
    new_node->word_count = 1; // Word occurs once in this new file
    new_node->table_link = (*head)->Tlink;

    // Update the word node's link to point to the new node
    (*head)->Tlink = new_node;

    // Increment the file count for the word node
    (*head)->file_count++;

    return SUCCESS;
}
