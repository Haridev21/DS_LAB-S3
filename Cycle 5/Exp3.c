//singly linked list
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node* header=NULL;

void display(){
	if(header==NULL){printf("Empty List\n"); return;}
	struct node* temp=header;
	printf("Linked List:");
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp=temp->link;
	}
	printf("NULL\n");
}

void insert_beginning(){
	int ele;
	printf("Enter element to be inserted:");
	scanf("%d",&ele);
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=ele;
	newnode->link=header;
	header=newnode;
	display();
}

void insert_end(){
	int ele;
        printf("Enter element to be inserted:");
        scanf("%d",&ele);	
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=ele;
	newnode->link=NULL;

	//if there is only header
	if(header==NULL){
		header=newnode;
	}
	else{
		//there are other elements in ll
		struct node* temp=header;
		while(temp->link!=NULL){
			temp=temp->link;
		}
		temp->link=newnode;
	}
	display();
}

void insert_position(){
	//insert after specified data value
	int ele,key;
	printf("Enter element to be inserted and element after which to insert it:");
	scanf("%d%d",&ele,&key);
	struct node* newn=(struct node*)malloc(sizeof(struct node));
	newn->data=ele;
	struct node* temp=header;
	while(temp!=NULL && temp->data!=key){
		temp=temp->link;
	}
	if(temp!=NULL){
		newn->link=temp->link;
		temp->link=newn;
		printf("Inserted\n");
		display();
	}
	else{ printf("Element not present\n");}
}
void delete_beginning(){
	if(header==NULL){printf("Linked List is empty\n");}
	else{
		struct node* temp=header;
		header=header->link;
		printf("Deleted:%d\n",temp->data);
		free(temp);  
	}
	display();
}

void delete_end(){
	if(header==NULL){printf("Linked list is empty\n");return;}
	if(header->link==NULL){
		printf("Deleted:%d\n",header->data);
		free(header);
		header=NULL;
		return;
	}
	struct node* ptr=header;
	while(ptr->link->link!=NULL){
		ptr=ptr->link;
	}
	printf("Deleted:%d\n",ptr->link->data);
	free(ptr->link);
	ptr->link=NULL;
	display();
}

void delete_position(){
	//delete specified data element
	int ele;
	printf("Enter data element to be deleted:");
	scanf("%d",&ele);
	if(header==NULL){
		printf("Empty list. Element thus is not present\n");
	}
	else if(header->data==ele){
		struct node* temp=header;
		header=header->link;
		free(temp);
		printf("Deleted\n");
		display();
	}
	else{
		struct node* prev=header;
		struct node* ptr=header->link;
		while(ptr!=NULL && ptr->data!=ele){
			prev=prev->link;
			ptr=ptr->link;
		}
		if(ptr!=NULL){
			prev->link=ptr->link;
			free(ptr);
		}
		else{ printf("Element not present\n");}
		display();
	}
}

int main(){
	int ch;
	while(1){
		printf("\n\nMENU:\n1.insert at beginning");
		printf("\n2.insert at end\n3.insert at specified position");
		printf("\n4.delete from beginning\n5.Delete from end");
		printf("\n6.Delete from specified position\n*.END");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1: insert_beginning(); break;
			case 2: insert_end(); break;
			case 3:insert_position(); break;
			case 4:delete_beginning(); break;
			case 5:delete_end(); break;
			case 6:delete_position(); break;
			default: exit(0);
		}
	}
	return 0;
}
