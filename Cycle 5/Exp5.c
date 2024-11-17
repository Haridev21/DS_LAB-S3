//reverse queue using stack (both singly linked lists)
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node* headq=NULL;
struct node* f=NULL;
struct node* r=NULL;
struct node* heads=NULL;
struct node* top=NULL;

void push(int n);
void pop();
void enqueue(int n);
void dequeue();

void displayq(){
	struct node* ptr=headq;
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr=ptr->link;
	}
	printf("\n");
}

void displays(){
        struct node* ptr=heads;
        while(ptr!=NULL){
                printf("%d\t",ptr->data);
                ptr=ptr->link;
        }
        printf("\n");
}

void push(int e){
	struct node* newn=(struct node*)malloc(sizeof(struct node));
	newn->data=e;
	newn->link=NULL;
	if(heads==NULL){
		heads=newn;
		top=newn;
	}
	else{
		newn->link=top;
		top=newn;
		heads=newn;
	}
}

void pop(){
	if(top!=NULL){
		struct node* temp=top;
		top=top->link;
		heads=top;
		int item=temp->data;
		free(temp);
		enqueue(item);
	}
}

void enqueue(int e){
	struct node* newn=(struct node*)malloc(sizeof(struct node));
	newn->data=e;
	if(headq==NULL){
		headq=newn;
		f=newn;
		r=newn;
	}
	else{
		r->link=newn;
		r=newn;
		newn->link=NULL;
	}
}

void dequeue(){
	if(f==NULL){return;}
	struct node* temp=f;
	int item=temp->data;
	f=f->link;
	headq=f;
	free(temp);
	push(item);
}

int main(){
	int n,ele;
	printf("Enter total number of queue elements:");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter queue elements:");	
		scanf("%d",&ele);
		enqueue(ele);
	}
	printf("Original queue:\t");
	displayq();
	while(f!=NULL){
		dequeue();
	}
	while(top!=NULL){
		pop();
	}
	printf("Reversed queue:\t");
	displayq();
	return 0;
}

