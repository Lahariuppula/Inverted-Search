#include"inverted_search.h"
char *fname;
void create_database(Flist *f_head,Wlist *head[])
{
    while(f_head)
    {
        /*Read each file one after another untill the condition is true*/
        read_datafile(f_head,head,f_head->file_name);
        /*Move the file link to node*/
        f_head = f_head->link;
    }
}
/*Function to read the content of the file and create Wlist*/
Wlist *read_datafile(Flist *file,Wlist *head[],char *filename)
{
    /*Open the file in read mode*/
    FILE *fptr = fopen(filename,"r");
    if(fptr == NULL)
        return NULL;
    fname = filename;
    /*Validate the file is open or not*/
    char word[WORD_SIZE];
    while(fscanf(fptr,"%s",word)!=EOF)
    {
        for(int i = 0; word[i]; i++)
        {
            word[i] = tolower(word[i]);
        }
        int len = strlen(word);
        if(len > 0 && ispunct(word[len - 1]))
        {
            word[len - 1] = '\0';
        }
        int flag = 1;
        /*Find the index of the word*/
        int index = tolower(word[0])%97;
        if(!(index >= 0 && index <= 25))
        {
            index = 26;
        }
        if(head[index] != NULL)
        {
            /*Traverse in the list to find the repeated word*/
            Wlist *temp = head[index];
            /*Compare new node with each node word*/
            while(temp)
            {
                if(!strcmp(temp->word,word))//word is same
                {
                    /*Update the word count or file count*/
                    update_word_count(&temp,filename);//current word,filename
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }
        }
        /*If word is not repeated or head is empty*/
        if(flag == 1)
        {
            insert_at_last(&head[index],word);
        }
    }
    fclose(fptr);
    return NULL;
}
int update_word_count(Wlist **head,char *filename)
{
    if(*head == NULL)
        return FAILURE;
    Ltable *temp = (*head)->Tlink;
    /*Check if file already exists*/
    while(temp != NULL)
    {
        if(strcmp(temp->file_name, filename) == 0)
        {
            /*If filename is same then increment the word count*/
            temp->word_count++; 
            return SUCCESS;
        }
        temp = temp->table_link;
    }
    /*File not found then create new node*/
    Ltable *new = malloc(sizeof(Ltable));
    if(new == NULL)
        return FAILURE;
    strcpy(new->file_name, filename);
    new->word_count = 1;
    new->table_link = NULL;
    /*Insert at last*/
    temp = (*head)->Tlink;
    if(temp == NULL)
    {
        (*head)->Tlink = new;
    }
    else
    {
        while(temp->table_link != NULL)
        {
            temp = temp->table_link;
        }
        temp->table_link = new;
    }
    /*If filename is different then increment the file count*/
    (*head)->file_count++;
    return SUCCESS;
}