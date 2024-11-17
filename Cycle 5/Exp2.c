//palindrome checking using doubly linked list
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
	char data;
	struct node* next;
	struct node* prev;
};
struct node* head=NULL;
char str[50];

void display(){
	struct node* ptr=head;
	while(ptr!=NULL){
		printf("%c",ptr->data);
	}
	printf("\n");
}

void new_node(int ele){
	struct node* newn=(struct node*)malloc(sizeof(struct node));
	newn->data=ele;
	newn->next=NULL;
	newn->prev=NULL;
	if(head==NULL){
		head=newn;
	}
	else{
		//insert at end
		struct node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newn;
		newn->prev=temp;
	}
}

bool palindrome(){
	struct node* ptr=head;
	struct node* tail=head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	while(ptr!=tail && ptr->prev!=tail){
		if(ptr->data != tail->data){return false;}
		ptr=ptr->next;
		tail=tail->prev;
	}
	return true;
}

int main(){
	printf("Enter a string:");
	scanf("%s",str);
	int i=0;
	while(str[i]!='\0'){
		new_node(str[i]);
		i++;
	}
	int p=palindrome();
	if(p){printf("It is a palindrome\n");}
	else{printf("It is not a palindrome\n");}
	return 0;
}
