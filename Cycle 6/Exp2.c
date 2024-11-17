//binary search tree operations
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node* l;
	struct node* r;
};
struct node* root=NULL;
int flag=0;
struct node* new_node(int ele){
	struct node* n=(struct node*)malloc(sizeof(struct node));
	n->data=ele;
	n->l=NULL;
	n->r=NULL;
	return n;
}
struct node* insertion(struct node* d,int ele){
	if(d==NULL){return new_node(ele);}
	if(ele<d->data){
		d->l=insertion(d->l,ele);
	}
	else if(ele>d->data){
		d->r=insertion(d->r,ele);
	}
	return d;
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
struct node* min_val(struct node* t){
        struct node* cur=t;
        while(cur && cur->l!=NULL){
                cur=cur->l;
        }       
        return cur;
}
struct node* deletion(struct node* d,int key){
        if(d==NULL){flag=1; return d;}
        if(key<d->data){
                d->l=deletion(d->l,key);
        }
        else if(key>d->data){
                d->r=deletion(d->r,key);
        }
        else{
                if(d->l==NULL){
                        struct node* temp=d->r;
                        free(d);
                        return temp;
                }
                else if(d->r==NULL){
                        struct node* temp=d->l;
                        free(d);
                        return temp;
                }
                struct node* temp=min_val(d->r);
                d->data=temp->data;
                d->r=deletion(d->r,temp->data);
        }
        return d;
}
int leaf_node_count(struct node* d){
	if(d==NULL){ return 0;}
	if(d->l==NULL && d->r==NULL){return 1;}
	return leaf_node_count(d->l)+leaf_node_count(d->r);
}
void sort(){
	printf("Sorted numbers:");
	inorder(root);
}
int main(){
int ch,data;
        while(1){
                printf("\n\nMENU\n1.Insert node\n2.Inorder Traversal");
                printf("\n3.Preorder traversal\n4.Postorder traversal");
                printf("\n5.Delete a node\n6.Number of leaf nodes\n7.Sort\n*.EXIT");
                printf("\nEnter your choice:");
                scanf("%d",&ch);
                if(ch==1){
                        printf("Enter element to be inserted:");
                        scanf("%d",&data);
                        printf("Inserted!\n");
                        root=insertion(root,data);
                }
		else if(ch==2){
                        if(root==NULL){
                                printf("Empty tree\n");
                        }
                        else{
                                printf("Inorder:");
                                inorder(root);
                        }
                }
                else if(ch==3){
                        if(root==NULL){
                                printf("Empty Tree\n");
                        }
                        else{
                                printf("Preorder:");
                                preorder(root);
                        }
                }
		else if(ch==4){
                        if(root==NULL){
                                printf("Empty Tree\n");
                        }
                        else{
                                printf("Postorder:");
                                postorder(root);
                        }
                }
		else if(ch==5){
                        if(root==NULL){
                                printf("Empty tree\n");
                        }
                        else{
                                printf("Enter element to be deleted:");
                                scanf("%d",&data);
                                deletion(root,data);
                                if(flag==0){
                                        printf("Deleted:%d\n",data);
                                }
                                else{
                                        printf("Element not present\n");
                                        flag=0;
                                }
                        }
                }
		else if(ch==6){
			int count=leaf_node_count(root);
			printf("Number of leaf nodes:%d\n",count);
		}
		else if(ch==7){
			sort();
		}
		else{break;}
	}
	return 0;
}
