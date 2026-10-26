#include "inverted_search.h"
int main(int argc,char *argv[])
{
    /*Clears the screen from previous execution*/
    system("clear");
    /*Validation of CLA*/
    if(argc <= 1)
    {
        printf("Enter the valid number of arguments\n");
        printf("./Slist.exe file1.txt file2.txt...\n");
        return -1;
    }
    /*Create file linked list*/
    Flist *f_head = NULL;
    Wlist *head[27] = {NULL};
    /*File Validation*/
    file_validation_n_file_list(&f_head,argv);
    if(f_head == NULL)
    {
        printf("No files are added to the database\n");
        printf("Hence process is terminated\n");
        return 1;
    }
    int option;
    /*Prompt user to enter the menu*/
    printf("1. Create Database\n2. Display Database\n3. Update Database\n4. Search Database\n5. Save Database\n6. Exit\n");
     /*Select choice*/
     printf("Enter the option: ");
     while(1)
     {
        scanf("%d", &option);
        switch(option)
        {
            case 1:
            create_database(f_head, head);
            break;

            case 2:
            display_database(head);
            break;

            case 3:
            update_database(head, &f_head);
            break;

            case 4:
            {
                char word[WORD_SIZE];
                printf("Enter word to search: ");
                scanf("%s", word);
                int index = tolower(word[0])%97;
                search(head[index], word);
                break;
            }

            case 5:
            save_database(head);
            break;

            case 6:
            return 0;

            default:
            printf("Invalid option\n");
        }
     }
    return 0;
}