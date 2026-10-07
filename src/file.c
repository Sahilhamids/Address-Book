#include<stdio.h>
#include "../include/contact.h"
#include "../include/file.h"
#define DATA_FILE "data/contacts.dat"



void loadContacts(void)
{
    FILE *fp;
    fp = fopen(DATA_FILE,"rb");
    //File doesn't exist
    if (fp == NULL)
    {   
        printf("File does not exist\n");
        contactsCount=0;
        return;
    }

    //Read contacts from the file into array
    contactsCount = fread(
        contacts,
        sizeof(Contact),
        MAX_CONTACTS,
        fp);
    fclose(fp);
}

void saveContacts(void)
{
    FILE *fp;
    fp = fopen(DATA_FILE,"wb");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        contactsCount=0;
        return;
    }
    fwrite(contacts,sizeof(Contact),contactsCount,fp);
    fclose(fp);
}