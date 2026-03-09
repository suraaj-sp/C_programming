#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Contact;

void addContact(Contact contacts[], int *count) {
    if (*count < MAX_CONTACTS) {
        printf("Enter name: ");
        scanf("%s", contacts[*count].name);
        printf("Enter phone: ");
        scanf("%s", contacts[*count].phone);
        (*count)++;
        printf("Contact added.\n");
    } else {
        printf("Address book is full.\n");
    }
}

void viewContacts(Contact contacts[], int count) {
    printf("Contacts:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
    }
}

void deleteContact(Contact contacts[], int *count) {
    char name[NAME_LENGTH];
    printf("Enter name to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            contacts[i] = contacts[*count - 1]; // Replace with last contact
            (*count)--;
            printf("Contact deleted.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

void saveContacts(Contact contacts[], int count) {
    FILE *file = fopen("contacts.txt", "w");
    if (file) {
        for (int i = 0; i < count; i++) {
            fprintf(file, "%s %s\n", contacts[i].name, contacts[i].phone);
        }
        fclose(file);
        printf("Contacts saved to file.\n");
    } else {
        printf("Error opening file.\n");
    }
}

void loadContacts(Contact contacts[], int *count) {
    FILE *file = fopen("contacts.txt", "r");
    if (file) {
        while (fscanf(file, "%s %s", contacts[*count].name, contacts[*count].phone) != EOF) {
            (*count)++;
        }
        fclose(file);
        printf("Contacts loaded from file.\n");
    } else {
        printf("No existing contacts found.\n");
    }
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int count = 0;
    loadContacts(contacts, &count);
    
    int choice;
    do {
        printf("\n1. Add Contact\n2. View Contacts\n3. Delete Contact\n4. Save Contacts\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addContact(contacts, &count); break;
            case 2: viewContacts(contacts, count); break;
            case 3: deleteContact(contacts, &count); break;
            case 4: saveContacts(contacts, count); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}
