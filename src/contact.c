#include<stdio.h>
#include <string.h>   // For strcmp
#include <strings.h>  // For strcasecmp
#include "../include/contact.h"
#include "../include/file.h"

//helper functions for sorting
int isUpper(int ch);
int lowerToUpper(int ch);

// array of Contact user defined data type
Contact contacts[MAX_CONTACTS];
int contactsCount =0;
int c;
//define functions 





void addContact(void)
{   
    int run = 1;
    char choice; // 1 is temp 
    //Get name
    while (run)
    {
        printf("Enter Name: ");
        scanf("%[^\n]",contacts[contactsCount].name);
        while ((c = getchar()) != '\n' && c != EOF);
        //Get phone
        printf("Enter Phone Number: ");
        scanf("%[^\n]",contacts[contactsCount].phone);
        //Get email
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Enter Email ID: ");
        scanf("%[^\n]",contacts[contactsCount].email);
        while ((c = getchar()) != '\n' && c != EOF);
        //Get address
        printf("Enter Address: ");
        scanf("%[^\n]",contacts[contactsCount].address);
        while ((c = getchar()) != '\n' && c != EOF);
        contactsCount++;

        printf("---> Contact added successfully\n");

        //ask to add more
        printf("Want to add more, Press y/n: ");
        scanf("%c",&choice);
        while ((c = getchar()) != '\n' && c != EOF);
        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
        {
            printf("Error: Invalid input, try again..\n");
            printf("Want to add more, Press y/n: ");
            scanf("%c",&choice);
            while ((c = getchar()) != '\n' && c != EOF);
        }
        switch(choice)
        {
            case 'y':
            case 'Y': break;
            case 'n':
            case 'N': 
            run=0;
            break;
        }   

    }
}

void deleteContact(void)
{
    int choice;
    char contact[30];
    int index;

    printf("======= DELETE CONTACT =======\n");
    printf(
        "\t1. Delete contact\n"
        "\t2. Delete all contacts\n"
        "\t3. Cancle\n");

    printf("Enter choice number: ");
    scanf("%d",&choice);
    while ((c = getchar()) != '\n' && c != EOF);
    switch (choice)
    {
        case 1: printf("Enter NAme/ Phone/ Email of the contact: ");
                scanf("%[^\n]",contact);
                while ((c = getchar()) != '\n' && c != EOF);
                //linear search
                int found=0;
                for (int i=0; i< contactsCount; i++)
                {
                    if ( 
                    (strcasecmp(contacts[i].name , contact) == 0) 
                    || 
                    (strcmp(contacts[i].phone , contact) == 0) 
                    ||
                    (strcasecmp(contacts[i].email , contact) == 0))
                    {
                        index = i;
                        found = 1;
                        break;
                    }
                }
                //check if contact exists or not
                if (found)
                {   
                    char option; // Confirmation yes or no y/n
                    //Confirm delete
                    printf("Contact Found\n"
                        "Please Confirm to delete this contact->\n");

                    // display contact
                    displayContact(index);

                    printf("Press 'y' for Yes 'n' for No: ");
                    scanf(" %c",&option);
                    while ((c = getchar()) != '\n' && c != EOF);
    
                    switch(option)
                    {
                        case 'y':
                        case 'Y':
                            //delete
                            
                            for (int i = index; i < contactsCount-1; i++)
                            {
                                contacts[i] = contacts[i+1];
                            }
                            contactsCount--;
                            printf("\n--> Contact deleted successfully.\n");
                            break;
                        case 'n':
                        case 'N': break;
                    }
                    
                }else
                {
                    printf("--> Contact does not exist\n");
                }
        break;
        case 2: int pass;
                printf("PLEASE ENTER PASSWORD TO DELETE ALL CONTACTS: ");
                scanf("%d",&pass);
                while ((c = getchar()) != '\n' && c != EOF);
                short i=1;
                while (i <= 3 && pass != 1234)
                {   
                    printf("\nWrong password, try again\nPassword: ");
                    scanf("%d",&pass);
                    while ((c = getchar()) != '\n' && c != EOF);
                    i++;
                }
                if (pass != 1234)
                {
                    printf("\nAttempts Exausted!\n");
                    break;
                }
                contactsCount=0;
                saveContacts();
                printf("\n--> ALL CONTACTS DELETED SUCCESSFULLY\n");
                break;
        case 3: printf("--> Delete Operatation Cancelled\n");
        break;            

    }
}

void displayContact(int index)
{   
    printf("\tName    : %s\n",contacts[index].name);
    printf("\tPhone   : %s\n",contacts[index].phone);
    printf("\tEmail   : %s\n",contacts[index].email);
    printf("\tAddress : %s\n\n",contacts[index].address);
}

void displayContacts(void)
{   
    sortContacts();
    if (contactsCount == 0)
    {
        printf("--> No contacts found, Address book is empty\n");
        return;
    }
    printf("\n============= CONTACTS LIST ==============\n\n");
    for (int i=0; i< contactsCount; i++)
    {   printf("Contact %d\n",i+1);
        printf("\tName      : %s\n",contacts[i].name);
        printf("\tPhone     : %s\n",contacts[i].phone);
        printf("\tEmail     : %s\n",contacts[i].email);
        printf("\tAddress   : %s\n",contacts[i].address);
        printf("\n");
    }
    
}

void searchContact(void)
{   printf("\n============    SEARCH    =============\n\n");
    char contact[40];
    printf("Enter name/phone/email of the contact: ");
    scanf("%[^\n]",contact);
    int n = strlen(contact);
    while ((c = getchar()) != '\n' && c != EOF);
    //linear search
    int found=0;
    int index;
    printf("\nSearched contacts:\n") ; 
    int count=1;
    for (int i=0; i< contactsCount; i++)
    {
        if ( 
            (strncasecmp(contacts[i].name , contact,n) == 0) 
            ||
            (strncmp(contacts[i].phone , contact,n) == 0) 
            ||                
            (strncasecmp(contacts[i].email , contact,n) == 0))
        {
            // display contact   
            printf("\nContact %d\n",count);
            displayContact(i);
            found = 1;
            count++;
        }
    }
    if (!found)
    {  
        printf("--> Searched contact does not exist");
    }
    
}

void updateContact(void)
{   printf("============== UPDATE CONTACT ==============\n");
    char contact[30];
    printf("Enter name/phone/email of the contact: ");
    scanf("%[^\n]",contact);
    while ((c = getchar()) != '\n' && c != EOF);
    //linear search
    int found=0;
    int index;
    for (int i=0; i< contactsCount; i++)
    {
        if ( 
            (strcasecmp(contacts[i].name , contact) == 0) 
            || 
            (strcmp(contacts[i].phone , contact) == 0) 
            ||                
            (strcasecmp(contacts[i].email , contact) == 0))
        {
            index = i;
            found = 1;
            break;
        }
    }
    if (found)
    {  
        // display contact  
        printf("Contact to update->\n");    
        displayContact(index);
        
        
            printf("\nEnter new Name    : ");
            scanf("%[^\n]",contacts[index].name);
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Enter new Phone   : ");
            scanf("%[^\n]",contacts[index].phone);
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Enter new Email   : ");
            scanf("%[^\n]",contacts[index].email);
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Enter new Address : ");
            scanf("%[^\n]",contacts[index].address);
            while ((c = getchar()) != '\n' && c != EOF);
            printf("\n--> Updated successfully");

    }
    else 
    {
        printf("--> Contact not found");
    }
}

void sortContacts(void)
{   
    //loop for running bubble sort
    for(int i=0; i<contactsCount-1; i++)
    {
        for (int j=0; j < contactsCount-1; j++)
        {
            char *curContact  = contacts[j].name;
            char *nextContact = contacts[j+1].name;
            int shouldSwap =0;

            while( *curContact != '\0' &&  *nextContact != '\0')
            {   
                int ch1 = *curContact;
                int ch2 = *nextContact;
                // convert to upper 
                ch1 = lowerToUpper(ch1);
                ch2 = lowerToUpper(ch2);
                if (ch1 > ch2)
                {
                    //swap strings and break
                    shouldSwap = 1;
                    break;
                }
                if(ch1<ch2)
                {
                    //no swap needed
                    break;
                }
                curContact++;
                nextContact++;
            }
            // if curr str is remaining and next is finished then swap
            if (shouldSwap==0 && *nextContact == '\0' && *curContact != '\0')
                {
                    //swap strings and break
                   shouldSwap=1;
                }

            if (shouldSwap)
            {
                Contact  temp = contacts[j];
                contacts[j] = contacts[j+1];
                contacts[j+1] = temp;
            }
        }
    }
}

int isUpper(int ch)
{
    //asci value of A is 65 and of a is 97 
    //check if both are uppercase
    if (ch >= 'A' && ch <= 'Z' )
    {
        return 1;
    }
    return 0;

}
int lowerToUpper(int ch)
{   
    //check if alnum
    if (!((ch >= 'A' && ch <= 'Z') ||
          (ch >= 'a' && ch <= 'z') ||
          (ch >= '0' && ch <= '9')))
    {
        return ch;
    }
    if(  ! isUpper(ch) )
    {   
        //convert to upper  a=97 , A=65 so 97-32 = 65 =A
        ch = ch-32;  
    }
    return ch;
}
