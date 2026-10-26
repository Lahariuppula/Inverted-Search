#include "inverted_search.h"
extern char *fname;
int insert_at_last(Wlist **head,data_t *data)
{
    /*Create a Wlist node*/
    Wlist *new = malloc(sizeof(Wlist));
    if(new == NULL)
        return FAILURE;
    /*Update data*/
    new -> file_count = 1;
    strcpy(new->word,data);
    new -> Tlink = NULL;
    new -> link = NULL;
    update_link_table(&new);
    /*Check head is empty or not*/
    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    /*If non empty*/
    Wlist *temp = *head;
    Wlist *prev = NULL;
    // find correct position
    while(temp != NULL && strcmp(temp->word, data) < 0)
    {
        prev = temp;
        temp = temp->link;
    }
    // insert at beginning
    if(prev == NULL)
    {
        new->link = *head;
        *head = new;
    }
    else
    {
        new->link = temp;
        prev->link = new;
    }
    return SUCCESS;
}
int update_link_table(Wlist *head[])
{
    /*Create Ltable node*/
    Ltable *new = malloc(sizeof(Ltable));
    if(new == NULL)
        return FAILURE;
    new -> word_count = 1;
    strcpy(new->file_name,fname);
    new -> table_link = NULL;
    /*Link the Ltable node to word list node*/
    (*head)->Tlink = new;
    return SUCCESS;
}