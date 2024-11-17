#include <stdio.h>
#include <string.h>
void Long(char *s)
{
   int len,k,i=0,j;
   int prev_index, cur_len=1,maxl=1,start=0;
   int visited[256];
   for(i=0;i<256;i++){
      visited[i]=-1;}
   len=strlen(s);

   visited[s[0]]=0;
   for(i=1;i<len;i++){
      prev_index=visited[s[i]];
      if(prev_index==-1 || i-cur_len>prev_index){
         cur_len++;}
      else{
         if(cur_len>maxl){maxl=cur_len; start=i-cur_len;}
         cur_len=i-prev_index;}
   visited[s[i]]=i;
   }
   if(cur_len>maxl){maxl=cur_len; start=len-cur_len;}
   printf("\nMaximum length of substring:%d",maxl);
   printf("\nLongest substring is ");
   for(i=start;i<start+maxl;i++){
      printf("%c",s[i]);}
   printf("\n");
}
int main()
{
   char s[20];
   printf("Enter a string:");
   scanf("%s",s);
   Long(s);
   return 0;
}
