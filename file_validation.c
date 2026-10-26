#include "inverted_search.h"
void file_validation_n_file_list(Flist **f_head,char *argv[])
{
    int i=1,empty;//a.out is not considered
    while(argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);
        if(empty == FILE_NOTAVAILABLE)
        {
            printf("File: %s is not available in the list", argv[i]);
            printf("Hence we are not adding that file into database\n");
            i++;
            continue;
        }
        else if(empty == FILE_EMPTY)
        {
            printf("File: %s is not having any content", argv[i]);
            printf("Hence we are not adding that file into database\n");
            i++;
            continue;
        }
        else
        {
            /*add the file to the database*/
            int ret_val = to_create_list_of_files(f_head,argv[i]);
            if(ret_val == SUCCESS)
            {
                printf("Successfully inserted %s file into database\n",argv[i]);
            }
            else if(ret_val == REPEATATION)
            {
                printf("The %s file is already present in the database\n",argv[i]);
            }
            else
            {
                printf("Unable to add the file\n");
            }
            i++;
        }
    }
}
int isFileEmpty(char *filename)
{
    errno = 0;
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL) 
    { 
        if(errno == ENOENT) 
         
            return FILE_NOTAVAILABLE; 
        return FILE_NOTAVAILABLE; 
    } 
    fseek(fptr,0,SEEK_END); 
    if(ftell(fptr) == 0)
    { 
        fclose(fptr);
        return FILE_EMPTY;
    }
    fclose(fptr);
    return SUCCESS;
}
int to_create_list_of_files(Flist **f_head,char *filename)
{
    /*Create a linked list of all the input files passed by the user*/
    /*Check duplicate*/
    Flist *temp = *f_head;
    while(temp != NULL)
    {
        if(strcmp(temp->file_name, filename) == 0)
        {
            return REPEATATION;
        }
        temp = temp->link;
    }
    /*Create new node*/
    Flist *new = malloc(sizeof(Flist));
    if(new == NULL)
        return FAILURE;
    strcpy(new->file_name, filename);
    new->link = NULL;

    /*Insert node*/
    if(*f_head == NULL)
    {
        *f_head = new;
    }
    else
    {
        temp = *f_head;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;
    }
    return SUCCESS;
}