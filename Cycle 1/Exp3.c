#include <stdio.h>
int main(){
	int a[20];
	int *p;
	int smallest,n,i;
	
	printf("Enter total number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter element %d:",i+1);
		scanf("%d",&a[i]);}

	printf("\n");
	p=a;
	
	smallest= *p;
	
	for(i=0;i<n;i++){
		if (*p < smallest){
			smallest=*p;}
		p++;}
	printf("Smallest number: %d\n",smallest);
	return 0;}

