#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
	int i = 1, empty;
	while (argv[i] != NULL)
	{
		empty = isFileEmpty(argv[i]);
		if (empty == FILE_NOTAVAILABLE)
		{
			printf("File : %s is not available\n", argv[i]);
			printf("Hence we are not adding this file into file linked list\n");
			i++;
			continue;
		}
		else if (empty == FILE_EMPTY)
		{
			printf("File : %s is empty\n", argv[i]);
			printf("Hence we are not adding this file into file linked list\n");
			i++;
			continue;
		}
		else
		{
			int ret_val = to_create_list_of_files(f_head, argv[i]);
			if (ret_val == SUCCESS)
			{
				printf("Successfull : inserting the file name %s into file linked list\n", argv[i]);
			}
			else if (ret_val == REPEATATION)
			{
				printf("This file name : %s is repeated. Do not add into file linked list\n", argv[i]);
			}
			else
			{
				printf("Failure\n");
			}

			i++;
			continue;
		}
	}
}

// fun() is used to check whether file is available or not
//  it checks for file empty or not

int isFileEmpty(char *filename)
{
	FILE *fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		if (errno == ENOENT)
		{
			return FILE_NOTAVAILABLE;
		}
	}

	fseek(fptr, 0, SEEK_END);
	if (ftell(fptr) == 0)
	{
		return FILE_EMPTY;
	}
}

int to_create_list_of_files(Flist **f_head, char *name)
{
	//...........TODO.........
	// check file name , duplicate or not
	// create a file linked list
	Flist *new = malloc(sizeof(Flist));
	if (new == NULL)
	{
		return -1;
	}

	strcpy(new->file_name, name);
	new->link = NULL;

	if (*f_head == NULL)
	{
		*f_head = new;
		return 0;
	}
	else
	{
		Flist *temp = *f_head;

		while (temp->link != NULL)
		{
			if (strcmp(temp->file_name, name) == 0)
			{
				free(new);
				return REPEATATION;
			}
			temp = temp->link;
		}

		if (strcmp(temp->file_name, name) == 0)
		{
			free(new);
			return REPEATATION;
		}
		temp->link = new;
	}

	return SUCCESS;
}
