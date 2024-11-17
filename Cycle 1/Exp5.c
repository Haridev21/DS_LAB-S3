//bubble sort using pointers
#include <stdio.h>
#include <stdlib.h>
int main(){
   int n,i,j,t;
   printf("Enter the total number of array elements:");
   scanf("%d",&n);
   int *p=malloc(n*sizeof(int));
   for(i=0;i<n;i++){
      printf("Enter element %d:",i+1);
      scanf("%d",&p[i]);
   }
  for(i=1;i<=n-1;i++)
  {
      for(j=0;j<=n-i-1;j++)
      {
         if(*(p+j)>*(p+j+1))
         {
            t=*(p+j);
            *(p+j)=*(p+j+1);
            *(p+j+1)=t;
         }
      }
  }
  for(i=0;i<n;i++)
  {
     printf("%d ",p[i]);
  }
  printf("\n");
  free(p);
  return 0;
}

