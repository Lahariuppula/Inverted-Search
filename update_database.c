#include "inverted_search.h"
int update_database(Wlist *head[],Flist **f_head)
{
    /*Prompt the user to enter the filename*/
    char filename[FNAME_SIZE];
    printf("Enter the filename\n");
    scanf("%s",filename);
    /*Validate file*/
    int empty = isFileEmpty(filename);
    if(empty == FILE_NOTAVAILABLE)
    {
        printf("File: %s is not available\n", filename);
        return FAILURE;
    }
    else if(empty == FILE_EMPTY)
    {
        printf("File: %s is empty\n", filename);
        return FAILURE;
    }
    /*Add file to file linked list*/
    int ret_val = to_create_list_of_files(f_head, filename);
    if(ret_val == REPEATATION)
    {
        printf("The %s file is already present in database\n", filename);
        return FAILURE;
    }
    else if(ret_val == FAILURE)
    {
        printf("Unable to add file\n");
        return FAILURE;
    }
    else
    {
        printf("Successfully inserted %s file into database\n", filename);
    }
    /*Bring f_head to last node (new file)*/
    Flist *temp = *f_head;
    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    create_database(temp, head);
    return SUCCESS;
}