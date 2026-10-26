#include"inverted_search.h"
int save_database( Wlist *head[])
{
    char file_name[FNAME_SIZE];
    printf("Enter the filename");
    scanf("%s",file_name);
    /*Open the file in w mode*/
    FILE *fptr = fopen(file_name,"w");
    if(fptr == NULL)
    {
        printf("Unable to open file\n");
        return FAILURE;
    }
    /*array of head*/
    for(int i=0;i<27;i++)
    {
        /*Check if any data is prent in the current index*/
        if(head[i] != NULL)
        {
            write_databasefile(head[i],fptr,i);
        }
    }
    fclose(fptr);
    printf("Database saved successfully\n");
    return SUCCESS;
}
void write_databasefile(Wlist *head,FILE *datafile,int index)
{
   while(head != NULL)
    {
        /*Print index*/
        fprintf(datafile, "#%d\n", index);
        /*Print word + file count*/
        fprintf(datafile, "Word: %s; FileCount:%d;", head->word, head->file_count);
        /*Traverse Ltable*/
        Ltable *temp = head->Tlink;

        while(temp != NULL)
        {
            fprintf(datafile, "%s Word Count:%d;", temp->file_name, temp->word_count);
            temp = temp->table_link;
        }
        fprintf(datafile, "\n");
        head = head->link;
    }
}