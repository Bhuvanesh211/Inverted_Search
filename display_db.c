#include "inverted_search.h"

void display_database(Wlist *head[])
{
	printf("\n[index]    [word]     file_count file/s     File: File_name    word_count\n");

	for (int i = 0; i < 27; i++)
	{
		if (head[i] != NULL)
		{
			print_word_count(head[i]);
		}
	}
}

int print_word_count(Wlist *head)
{
	// traverse through the WList

	while (head != NULL)
	{
		
		 int index = tolower(head->word[0]) % 97;

        // Handle non-alphabetic characters
        if (!(index >= 0 && index <= 25))
            index = 26;

		printf("[%d]  \t [%s]   \t[%d] file/s : ", index, head->word, head->file_count);
		
		Ltable *Thead = head->Tlink;

		// traverse
		while (Thead)
		{
			printf("\tFile : %s  \t %d  ", Thead->file_name, Thead->word_count);
			Thead = Thead->table_link;
		}

		printf("\n");
		head = head->link;
	}

	return 0;
}
