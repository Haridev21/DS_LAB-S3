//polynomial addition using singly linked list
#include <stdio.h>
#include <stdlib.h>
struct node{
	int coeff;
	int exp;
	struct node* link;
};
struct node* head1=NULL;//head of first polynomial
struct node* head2=NULL;//head of second polynomial
struct node* headr=NULL; //head of resultant sum polynomial
void display(struct node* h){
	struct node* temp=h;
	while(temp!=NULL){
		if(temp->coeff!=0 && temp!=h){printf("+");}
		printf("%dx^%d\t",temp->coeff,temp->exp);
		temp=temp->link;
	}
	printf("\n");
}
void insert_sll(struct node** h,int c,int e){
	struct node* newn=(struct node*)malloc(sizeof(struct node));
        newn->coeff=c;
        newn->exp=e;
        newn->link=NULL;
        if(*h==NULL){
		*h=newn;
        }
        else{
                //insert at end
                struct node* temp=*h;
                while(temp->link!=NULL){
                	temp=temp->link;
                }
                temp->link=newn;
        }

}

void create_poly(struct node** h,int num){
	printf("Enter total number of terms in polynomial %d:",num);
	int n,c,e;
	scanf("%d",&n);
	printf("Enter the coefficients and exponents of:\n");
	for(int i=0;i<n;i++){
		printf("Term %d:",i+1);
		scanf("%d%d",&c,&e);
		insert_sll(h,c,e);
	}
}

void sum_result(){
	struct node* h1=head1;
	struct node* h2=head2;
	while(h1!=NULL && h2!=NULL){
		if(h1->exp>h2->exp){
			insert_sll(&headr,h1->coeff,h1->exp);
			h1=h1->link;
		}
		else if(h1->exp<h2->exp){
			insert_sll(&headr,h2->coeff,h2->exp);
			h2=h2->link;
		}
		else{
			int sum=h1->coeff+h2->coeff;
			if(sum!=0){
				insert_sll(&headr,sum,h1->exp);
			}
			h1=h1->link;
			h2=h2->link;
		}
	}
	while(h1!=NULL){
		insert_sll(&headr,h1->coeff,h1->exp);
		h1=h1->link;
	}
	while(h2!=NULL){
		insert_sll(&headr,h2->coeff,h2->exp);
		h2=h2->link;
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
	sum_result();
	printf("Sum polynomial:");
        display(headr);
	return 0;
}

