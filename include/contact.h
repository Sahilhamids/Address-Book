#ifndef CONTACT_H
#define MAX_CONTACTS 100

typedef struct
{
    char name[100];
    char phone[100];
    char email[100];
    char address[150];
} Contact;

extern Contact contacts[MAX_CONTACTS];
extern int contactsCount;

void addContact(void);
void displayContacts(void);
void displayContact(int index);
void searchContact(void);
void deleteContact(void);
void updateContact(void);
void sortContacts(void);

#endif

