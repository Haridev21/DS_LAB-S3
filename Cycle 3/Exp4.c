#include <stdio.h>
int f=-1, r=-1,SIZE;
void display(int q[], int f, int r){
	int i;
	printf("Queue:");
	for(i=f;i<=r;i++){
		printf("%d\t",q[i]);
	}
}
void enqueue(int q[], int item){
	if(r==SIZE-1){
		printf("Queue Overflow\n");
	}
	else{
		r++;
		q[r]=item;
		if(f==-1){ f=0;}
	}
	display(q,f,r);
}
void dequeue(int q[]){
	int it;
	if((f>r)||(f==-1 && r==-1)){
		printf("Queue underflow\n");
	}
	else{
		it=q[f];
		f++;
		printf("Deleted item:%d\n",it);
		display(q,f,r);
		
	}
}
int main(){
	printf("Enter size of queue:");
	scanf("%d",&SIZE);
	int n, q[SIZE],el;
	while(1){
		printf("\n\nMENU:\n1.Enqueue\n2.Dequeue\n*.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&n);
		if (n==1){
			printf("Enter element to be inserted:");
			scanf("%d",&el);
			enqueue(q,el);			
		}
		else if(n==2){
			dequeue(q);
		}
		else{
			break;
		}
	}
	return 0;
}
