//addition of polynomials with two variables (sll)
#include <stdio.h>
#include <stdlib.h>
struct node{
	int coeff;
	int expx;
	int expy;
	struct node* link;
};
struct node* head1=NULL;
struct node* head2=NULL;
struct node* heads=NULL;
void display(struct node* h){
	struct node* cur=h;
	while(cur!=NULL){
		if(cur->coeff!=0 && cur!=h){printf("+");}
		printf("%dx^%dy^%d",cur->coeff,cur->expx,cur->expy);
		cur=cur->link;
	}
	printf("\n");
}
void insert_sll(struct node** h,int c, int x,int y){
        struct node* newn=(struct node*)malloc(sizeof(struct node));
        newn->coeff=c;
        newn->expx=x;
	newn->expy=y;
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
        int n,c,x,y;
        scanf("%d",&n);
        printf("Enter the coefficient and exponent of:\n");
        for(int i=0;i<n;i++){
                printf("Term %d:",i+1);
                scanf("%d%d%d",&c,&x,&y);
                insert_sll(h,c,x,y);
        }
}
void sum_result(){
	struct node* h1=head1;
	struct node* h2=head2;
	while(h1!=NULL && h2!=NULL){
		int x1=h1->expx;
		int y1=h1->expy;
		int x2=h2->expx;
		int y2=h2->expy;
		if(x1>x2 || x1==x2 && y1>y2){
			insert_sll(&heads,h1->coeff,x1,y1);
			h1=h1->link;
		}
		else if(x1<x2 || x1==x2 && y1<y2){
			insert_sll(&heads,h2->coeff,x2,y2);
			h2=h2->link;
		}
		else{
			int sum=h1->coeff+h2->coeff;
			if(sum!=0){
				insert_sll(&heads,sum,x1,y1);
			}
			h1=h1->link;
			h2=h2->link;
		}
	}
	while(h1!=NULL){
		insert_sll(&heads,h1->coeff,h1->expx,h1->expy);
                h1=h1->link;
	}
	while(h2!=NULL){
                insert_sll(&heads,h2->coeff,h2->expx,h2->expy);
        	h2=h2->link;
        }
}
int main(){
	create_poly(&head1,1);
	create_poly(&head2,2);
	sum_result();
	printf("\n\n");
	printf("First polynomial:");
	display(head1);
	printf("Second polynomial:");
	display(head2);
	printf("Sum polynomial:");
	display(heads);
	return 0;
}
