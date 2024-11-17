#include <stdio.h>
int main(){
	int arr[10];
	int key, i,n;
	printf("Enter the total number of array elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter element %d:",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter element to be searched:");
	scanf("%d",&key);
	for(i=0;i<n;i++){
		if(arr[i]==key){
			printf("%d found at position %d\n",key,i+1);
			break;
		}
	}
	if(i==n){ printf("%d not found\n",key);}

	return 0;

}
