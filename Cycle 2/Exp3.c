#include <stdio.h>
#define SIZE 5
int top=-1;

int s[SIZE];  //stack

void display(){
	int i;
	printf("\nStack:");
	for(i=0;i<=top;i++){
		printf("%d\t",s[i]);
	}
}

void push(int item){
	if(top==SIZE-1){
		printf("Stack Overflow\n");
	}
	else{
		top++;
		s[top]=item;
	}
	display();
}

void pop(){
	int it;
	if(top==-1){
		printf("Stack Underflow\n");
	}
	else{
		it=s[top];
		top--;
		printf("Deleted item:%d\n",it);
	}
	display();
}

int main(){
	int n,el;
	while(1){
		printf("\n\nMENU:\n1.Push\n2.Pop\n*.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&n);
		if(n==1){
			printf("Enter element to be pushed:");
			scanf("%d",&el);
			push(el);
		}
		else if(n==2){
			pop();
		}
		else{
			break;
		}
	}
	return 0;
}
