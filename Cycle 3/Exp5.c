#include<stdio.h>
#include<stdlib.h>
int MAX= 5;
int Q[5],R=-1,F=-1;

void insertion();
void delection();
void traversal();
int main()
{
   int op;
   printf("Menu\n1.Insertion\n2.Delection\n3.Traversal\n4.Exit\n");
   do
   {
      printf("Enter the choice:");
      scanf("%d",&op);
      switch(op)
      {
         case 1:
            insertion();
            break;
         case 2:
           delection();
           break;
        case 3:
           traversal();
           break;
        case 4:
           printf("Exited\n");
           exit(0);
        default:
         printf("invaid choice.");
     }

   }while(1);
 return 0;
}
void insertion()
{
   int val;
   if((R+1)%MAX==F)
   {
      printf("Queue OverFlow!\n");
   }
   else
   {
      printf("Enter the element to be inserted:\n");
      scanf("%d",&val);
      R=(R+1)%MAX;
      Q[R]=val;
      if(F==-1)
      {
         F=0;
      }
   }
}


void delection()
{
   int val;
   if(F==-1)
   {
      printf("Queue underflow!\n");
   }
   else
   {
      val=Q[F];
      if(F==R)
      {
         F=-1;
         R=-1;
      }
      else
      {
         F=(F+1)%MAX;
      }
      printf("The delected element is %d\n",val);
   }
}


void traversal()
{
   int i;
   if(F==-1)
   {
      printf("Queue is empty!\n");
   }
   else
   {
      printf("The element are:\n");
      i=F;
      while(1)
      {
         printf("%d\t",Q[i]);
         if(i==R)
            break;
         i=(i+1)%MAX; // MOVE BACKWARD AND WRAP AROUND IF NECCESSARY
      }
      printf("\n");
   }
}













