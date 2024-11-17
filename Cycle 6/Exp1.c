//binary tree operations
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* l;//left child
	struct node* r;//right child
};
struct node* root=NULL;//root node
int flag=0;//flag to check whether element present in tree or not (1 means absent)
struct node* new_node(int ele){
	struct node* n=(struct node*)malloc(sizeof(struct node));
	n->data=ele;
	n->l=NULL;
	n->r=NULL;
	return n;
}
struct node* insertion(struct node* n){
	char ch;
	int ele;
	printf("Does %d have left child(y/n):",n->data);
	scanf(" %c",&ch);
	if(ch=='y'){
		printf("Enter element:");
		scanf("%d",&ele);
		n->l=new_node(ele);
		insertion(n->l);
	}
	printf("Does %d have right child(y/n):",n->data);
	scanf(" %c",&ch);
	if(ch=='y'){
		printf("Enter element:");
		scanf("%d",&ele);
		n->r=new_node(ele);
		insertion(n->r);
	}
}
struct node* inorder(struct node* d){
	if(d!=NULL){
		inorder(d->l);
		printf("%d\t",d->data);
		inorder(d->r);
	}
}
struct node* preorder(struct node* d){
	if(d!=NULL){
		printf("%d\t",d->data);
		preorder(d->l);
		preorder(d->r);
	}
}
struct node* postorder(struct node* d){
	if(d!=NULL){
		postorder(d->l);
		postorder(d->r);
		printf("%d\t",d->data);
	}
}
struct node* LeftMost(struct node* n){
	while(n && n->l!=NULL){
		n=n->l;
	}
	return n;
}
struct node* DelNode(struct node* n,int key){
	if(n==NULL){return NULL;}
	if(n->data==key){
		if(n->l==NULL && n->r==NULL){
			free(n);
			return NULL;
		}
		else if(n->l==NULL){
			struct node* temp=n->r;
			free(n);
			return temp;
		}
		else if(n->r==NULL){
			struct node* temp=n->l;
			free(n);
			return temp;
		}
		else{
			struct node* t=LeftMost(n->r);
			n->data=t->data;
			n->r=DelNode(n->r,t->data);
		}
	}
	else{
		n->l=DelNode(n->l,key);
		n->r=DelNode(n->r,key);
	}
	return n;
}
int main(){
	int ch,data,d;
	printf("Enter root node data:");
	scanf("%d",&d);
	root=new_node(d);
	insertion(root);
	while(1){
		printf("\n\nMENU\n1.Inorder Traversal");
		printf("\n2.Preorder traversal\n3.Postorder traversal");
		printf("\n4.Delete a node\n*.EXIT");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		if(ch==1){
			if(root==NULL){
				printf("Empty tree\n");
			}
			else{
				printf("Inorder:");
				inorder(root);
			}
		}
		else if(ch==2){
			if(root==NULL){
				printf("Empty Tree\n");
			}
			else{
				printf("Preorder:");
				preorder(root);
			}
		}
		else if(ch==3){
			if(root==NULL){
				printf("Empty Tree\n");
			}
			else{
				printf("Postorder:");
				postorder(root);
			}
		}
		else if(ch==4){
			if(root==NULL){
				printf("Empty tree\n");
			}
			else{
				printf("Enter element to be deleted:");
				scanf("%d",&data);
				root=DelNode(root,data);
				inorder(root);
			}
		}
		else{break;}
	}
	return 0;
}
