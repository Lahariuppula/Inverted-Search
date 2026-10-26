#include "inverted_search.h"
int search(Wlist *head,char *word)
{
    /*Check list is empty or not*/
    if(head == NULL)
    {
        printf("List is Empty\n");
        return 0;
    }
    /*Non empty list*/
    while(head)
    {
        /*Compare each word with the input word*/
        if(!(strcasecmp(head->word,word)))
        {
            printf("Word %s is present in %d files\n",word,head->file_count);
            Ltable *Thead = head -> Tlink;
            while(Thead)
            {
                printf("In file %s -> %d times\n",Thead->file_name,Thead->word_count);
                Thead = Thead -> table_link;
            }
            printf("\n");
            return SUCCESS;
        }
        head = head->link;
    }
    printf("Search word %s not found\n",word);
    return FAILURE;
}