//binary search
#include <stdio.h>
#define SIZE 10
int main(){
	int arr[SIZE];
	int n, i, key,l,h,mid,flag=0;
	printf("Enter the total number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter element %d:",i+1);
		scanf("%d",&arr[i]);
	}
	printf("Enter element to be searched:");
	scanf("%d",&key);
	l=0;
	h=n-1;
	while(l<=h){
		mid=(l+h)/2;
		if(key==arr[mid]){
			printf("%d found at position %d\n",key,mid);
			flag=1;
			break;
		}
		else if(key>arr[mid]){
			l=mid+1;
		}
		else{
			h=mid-1;
		}
	}
	if(flag==0){printf("%d not found\n",key);}
	return 0;
}
