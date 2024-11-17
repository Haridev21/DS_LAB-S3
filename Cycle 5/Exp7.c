//product of two polynomials (sll rep)
#include <stdio.h>
#include <stdlib.h>
struct node{
	int coeff;
	int exp;
	struct node* link;
};
struct node* head1=NULL;
struct node* head2=NULL;
struct node* heads=NULL; //final pdt
struct node* headp=NULL; //initial pdt
int arr[10]={0}; //index is exp
void display(struct node* h){
	struct node* cur=h;
	while(cur!=NULL){
		if(cur->coeff!=0 && cur!=h){printf("+");}
		printf("%dx^%d",cur->coeff,cur->exp);
		cur=cur->link;
	}
	printf("\n");
}
void insert_sll(struct node** h,int c, int e){
	struct node* newn=(struct node*)malloc(sizeof(struct node));
	newn->coeff=c;
	newn->exp=e;
	newn->link=NULL;
	//insert at end
	if(*h==NULL){
		*h=newn;
	}
	else{
		struct node* temp=*h;
		while(temp->link!=NULL){
			temp=temp->link;
		}
		temp->link=newn;
	}
}
void create_poly(struct node **h, int num){
	printf("Enter the total number of terms in polynomial %d:",num);
	int n,c,e;
	scanf("%d",&n);
	printf("Enter the coefficient and exponent of:\n");
	for(int i=0;i<n;i++){
		printf("Term %d:",i+1);
		scanf("%d%d",&c,&e);
		insert_sll(h,c,e);
	}
}
struct node* inorder(struct node* h, int c, int e){
	struct node* newn=(struct node*)malloc(sizeof(struct node));
	newn->coeff=c;
	newn->exp=e;
	newn->link=NULL;
	if(h==NULL || h->exp<e){
		newn->link=h;
		return newn;
	}
	struct node* temp=h;
	struct node* prev=NULL;
	while(temp!=NULL && temp->exp>=e){
		if(temp->exp==e){
			temp->coeff+=c;
			free(newn);
			return h;
		}
		prev=temp;
		temp=temp->link;
	}
	newn->link=temp;
	prev->link=newn;
	return h;
}
struct node* simplify(){
	if(headp==NULL){
		printf("Empty\n");
		return NULL;
	}
	struct node* result=NULL;
	struct node* cur=headp;
	while(cur!=NULL){
		result=inorder(result,cur->coeff,cur->exp);
		cur=cur->link;
	}
	return result;
}
void pdt_result(){
	struct node* h1=head1;
	struct node* h2=head2;
	while(h1!=NULL){
		while(h2!=NULL){
			int c= h1->coeff*h2->coeff;
			int e=h1->exp+h2->exp;
			insert_sll(&headp,c,e);
			h2=h2->link;
		}
		h2=head2;
		h1=h1->link;
	}
}
int main(){
	create_poly(&head1,1);
	create_poly(&head2,2);
	printf("\n\n");
	printf("First polynomial:");
        display(head1);
        printf("Second polynomial:");
        display(head2);
	printf("Product polynomial:");
	pdt_result();
	struct node* s;
	s=simplify();
	display(s);
	return 0;
}
