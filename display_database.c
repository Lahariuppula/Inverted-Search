#include "inverted_search.h"
void display_database(Wlist *head[])
{
    /*Display output in table format*/
    printf("Index\tWord\tFileCount\tFileName\tWordCount\n");
    for(int i=0;i<27;i++)
    {
        /*Print alphabetically - iterate through the head*/
        if(head[i] != NULL)
        {
            print_word_count(head[i]);
        }
    }
}
/*Print the details*/
int print_word_count(Wlist *head)
{
    /*Traverse through Wlist*/
    while(head != NULL)
    {
        printf("%d\t%-10s\t%d\t",tolower(head->word[0])%97,head->word,head->file_count);
        /*Get the Tlink table details*/
        Ltable *temp = head->Tlink;
        // First file
        if(temp)
        {
            printf("%-15s\t%d\n", temp->file_name, temp->word_count);
            temp = temp->table_link;
        }
        // Remaining files
        while(temp)
        {
            printf("\t\t\t\t%-15s\t%d\n", temp->file_name, temp->word_count);
            temp = temp->table_link;
        }
        head = head->link;
    }
    return SUCCESS;
}