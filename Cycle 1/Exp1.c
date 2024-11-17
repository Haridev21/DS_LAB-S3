//merge and asc sort two asc sorted arrays
#include <stdio.h>
int main(){
        int a[20];
        int b[20];
	int c[20];
        int i=0,n,m,j=0,k=0;

        printf("Enter number of elements of first array:");
        scanf("%d",&n);
	printf("\n");
        printf("Enter elements of first array in ascending order:\n");
        for (i=0;i<n;i++){
                printf("Enter element %d:",i+1);
                scanf("%d",&a[i]);}
	printf("\n");
        printf("Enter number of elements of second  array:");
        scanf("%d",&m);
        printf("\n");

        printf("Enter elements of second array in ascending order:\n");
        for (i=0;i<m;i++){
                printf("Enter element %d:",i+1);
                scanf("%d",&b[i]);}
	i=0;

	while(i<n && j<m){
		if(a[i]<b[j]){
			c[k]=a[i];
			i++;
			k++;}
		else{ c[k]=b[j];
			j++;
			k++;}}
	if(i>=n){
		while (j<m){
			c[k]=b[j];
			k++;
			j++;}}
	else{
		while (i<n){
			c[k]=a[i];
			k++;
			i++;}}
	for(i=0;i<k;i++){
                printf("%d \t",c[i]);}
        printf("\n");

return 0;}
