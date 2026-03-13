#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct Email{
	char sender[MAX];
	char reciever[MAX];
	char subject[MAX];
	char body[500];
};

void sendEmail(){
	struct Email e;
	FILE *fptr;

	fptr = fopen("Mails.txt","a");
	if (fptr==NULL){
		printf("Error opening file..\n");
		return;
	}

	printf("\nCompose new email\n");
	printf("From:"); scanf("%s",e.sender);
	printf("TO:"); scanf("%s",e.reciever);
	getchar();

	printf("Subject:"); fgets(e.subject,MAX,stdin);
	printf("Body:"); fgets(e.body,500,stdin);

	fprintf(fptr, "From:%s | To:%s | Subject:%s | Body:%s",e.sender,e.reciever,e.subject,e.body);

	fclose(fptr);
	printf("Email sent successfully.\n");

}
void viewInbox(){
	char buffer[10000];
	char searchUser[MAX];
	FILE *fptr = fopen("Mails.txt","r");

	if (fptr == NULL){
		printf("NO emails found in storge\n");
		return;
	}

	printf("Enter username to search:");
	scanf("%s", searchUser);
	
	printf("Details:\n");
	while(fgets(buffer,10000,fptr)){
		if(strstr(buffer,searchUser) != NULL){
			printf("%s",buffer);
		}
	}
	fclose(fptr);
}

int main(){
	int choice;
	while(1){
		printf("\nMail simulator\n");
		printf("1.send email\n");
		printf("2.view inbox\n");
		printf("3.exit\n");
		printf("Choice:\n");
		scanf("%d",&choice);

		switch(choice){
			case 1: sendEmail(); break;
			case 2: viewInbox(); break;
			case 3: exit(0);
			default: printf("Invalid choice\n");
		}
	}
	return 0;
}
