#include<stdio.h>
#include "../include/contact.h"
#include "../include/file.h"
int main()
{   
    int c;
    loadContacts();
    int choice = -1;
    do
    {   printf("===================================================\n"
            "================   ADDRESS BOOK   =================\n"
            "===================================================\n");
        printf("\n**************** MENU ********************\n");
        printf("\n"
            "1. Add contacts\n"
            "2. Display contacts\n"
            "3. Search contact\n"
            "4. Delete contacts\n"
            "5. Update contact\n"
            "6. Exit Menu\n\n");

        printf("Enter choice: ");
        scanf("%d",&choice);
        while ((c = getchar()) != '\n' && c != EOF);//clear buffer

        while ( !(choice > 0 && choice <=6) )
        {
            printf("Error: Invalid input, try again\n");
            printf("Enter choice: ");
            scanf("%d",&choice);
            while ((c = getchar()) != '\n' && c != EOF);
        }
        switch(choice)
        {
            case 1:
            addContact();
            saveContacts();
            printf("Press ENTER for MENU: ");
            getchar();
            break;
            case 2:
            displayContacts();
            printf("Press ENTER for MENU: ");
            getchar();
            break;
            case 3: 
            searchContact();
            printf("Press ENTER for MENU: ");
            getchar(); 
            break;
            case 4: 
            deleteContact(); 
            saveContacts();
            printf("Press ENTER for MENU: ");
            getchar();
            break;
            case 5:
            updateContact(); 
            saveContacts();
            printf("Press ENTER for MENU: ");
            getchar();
            break;
            case 6:
            printf("\n............. End: Good by! .............\n\n");
            saveContacts();
            break;
        }

    }while(choice != 6);
    saveContacts();
    return 0;
}