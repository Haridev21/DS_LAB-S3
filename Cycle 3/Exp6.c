//priority queue using 2d array
#include <stdio.h>
#define MAX_PRI 3
#define MAX_ELE 2
int pq[MAX_PRI][MAX_ELE]; //priority queue
int s[MAX_PRI]={0}; //array to track number of elements present

void display(){
	printf("Priority Queue:");
	for(int i=0;i<MAX_PRI;i++){
		for(int j=0;j<s[i];j++){
			printf("%d\t",pq[i][j]);
		}
	}
}

void enqueue(){
	int p,e;
	printf("Enter element and its priority(0-2):");
	scanf("%d%d",&e,&p);
	if(s[p]==MAX_ELE){
		printf("Queue for priority %d is full\n",p);
		return;
	}
	else{
		pq[p][s[p]]=e;
		s[p]++;
		display();
	}
}

void dequeue(){
	int i,j;
	for(i=0;i<MAX_PRI;i++){
		if(s[i]>0){
			int data=pq[i][0];
			for(j=0;j<s[i]-1;j++){
				pq[i][j]=pq[i][j+1];
			}
			s[i]--;
			printf("Deleted element:%d\n",data);
			display();
			return;
		}
	}
	printf("Empty Priority Queue\n");
}

int main(){
	int ch;
	while(1){
		printf("\n\nMENU:\n1.Enqueue\n2.Dequeue");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		if(ch==1){ enqueue();}
		else if(ch==2){ dequeue();}
		else{ break;}
	}
	return 0;
}
