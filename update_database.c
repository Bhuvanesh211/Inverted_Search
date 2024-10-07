#include "inverted_search.h"

int update_database(Wlist *head[], Flist **f_head)
{
    char file_name[FNAME_SIZE];
    printf("Enter the file name to update the data : ");
    scanf("%s", file_name);

    // validation
    //......TODO......
    int empty = isFileEmpty(file_name);

    if (empty == FILE_NOTAVAILABLE)
    {
        printf("\nFile : %s is not available\n", file_name);
        printf("Hence we are not adding that file\n\n");
        return 0;
    }
    else if (empty == FILE_EMPTY)
    {
        printf("\nFile : %s is not having any content \n", file_name);
        printf("Hence we are not adding that file\n\n");
        return 0;
    }
    else
    {
        // add files to file LL
        int ret_val = to_create_list_of_files(f_head, file_name);

        if (ret_val == SUCCESS)
        {
            printf("\nSuccessfull : Inserting the file : %s into file Linked list\n", file_name);
            printf("Successful : creation of database for file : %s\n\n",file_name);
            *f_head = (*f_head)->link;
        }
        else if (ret_val == REPEATATION)
        {
            printf("\nThis file name : %s is repeated. Hence we are not adding that file\n\n", file_name);
            return 0;
        }
        else
        {
            printf("Failure\n");
            return 0;
        }
    }

    while (*f_head)
    {
        if (!strcmp((*f_head)->file_name, file_name))
        {
            create_database(*f_head, head);
        }
        *f_head = (*f_head)->link;
    }
}