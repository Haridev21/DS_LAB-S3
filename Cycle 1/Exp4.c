#include <stdio.h>
int StringLength(char *s)
{
   int l=0;
   while(*s != '\0')
   {
      l++;
      s++;
   }
   return l;
}
void StringCopy(char *s1, char *s2)
{
   int i=0,j=0;
   while(*(s1+i)!='\0')
   {
      *(s2+j)=*(s1+i);
      j++;
      i++;
   }
   printf("Copied string is: %s",s2);
}
int StringCompare(char *s1, char *s2)
{
   int i=0,j=0,k=0,m=0,n=0;
   int l1,l2;
   l1=StringLength(s1);
   l2=StringLength(s2);
   if(l1==l2){
      while(m<l1){
         if(*(s1+i)==*(s2+i)){n++;}
         else if(*(s1+i)>*(s2+i)){return 1;}
         else if(*(s1+i)<*(s2+i)){return -1;}
         m++;
      }
      if(n==l1){return 0;}
   }
   else if(l1>l2){
      while(k<l2){
         if(*(s1+i)>*(s2+i)){return 1;}
         else if(*(s1+i)<*(s2+i)){return -1;}
         k++;}
      return 1;}
   else if (l1<l2){
      while(k<l1){
         if(*(s1+i)>*(s2+i)){return 1;}
         else if(*(s1+i)<*(s2+i)){return -1;}
         k++;} 
      return -1;}

   
}
void StringConcat(char *s1, char *s2)
{
   int i=0,l1;
   l1=StringLength(s1);
   while(*(s2+i)!='\0'){
      *(s1+l1)=*(s2+i);
      l1++;
      i++;
   }
   printf("Concatenated string is %s\n",s1);
}
int main()
{
   char str1[20],str2[20],str3[20];
   int l,p;

   printf("Enter a string:");
   scanf("%s",str1);
   printf("\n\nString Length:\n");
   l=StringLength(str1);
   printf("Length of string: %d",l);
   printf("\n\nString Copy:\n");
   StringCopy(str1,str2);
   printf("\n\nString Compare:\n");
   printf("Enter another string:");
   scanf("%s",str3);
   p=StringCompare(str1,str3);
   if (p>0){printf("%s is greater than %s",str1,str3);}
   else if (p==0){printf("Both the strings are equal");}
   else if(p<0){printf("%s is lesser than %s",str1,str3);}
   printf("\n\nString Concatenation:\n");
   StringConcat(str1,str3);

  return 0;
}
