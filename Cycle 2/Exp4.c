#include <stdio.h>
#include <string.h>
#define SIZE 5
int top=-1;
int s[SIZE];  //stack

int main(){
	char str[20];
	int len,i=0,flag=0;

	printf("Enter a string:");
	scanf("%s",str);
	len= strlen(str);

	//inserting into stack
	while(str[i]!='\0'){
		top++;
		s[top]=str[i];
		i++;
	}
	
	//checking for palindrome
	for(i=0;i<len;i++){
		if(str[i]!=s[top]){
			printf("It is not a palindrome\n");
			flag=1;
			break;
		}
		top--;
	}
	if(flag==0){printf("It is a palindrome\n");}
	
	return 0;
}
