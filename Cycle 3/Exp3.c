//infix to prefix
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 10
char infix[SIZE], prefix[SIZE], s[SIZE];
int top=-1;

void reverse(char *s){
	char t;
	int start=0, end=strlen(s)-1;
	while(start<end){
		t=s[start];
		s[start]=s[end];
		s[end]=t;
		start++;
		end--;
	}
}

int precedence(int m){
        switch(m){
                case '+':return 1;
                case '-':return 1;
                case '*':return 2;
                case '/':return 2;
                case '%':return 2;
		case '^':return 3;
                default:return -1;
        }
}

void infix_to_prefix(){

	reverse(infix);
	int i=0, j=0;
	while(infix[i]!='\0'){
		if(infix[i]=='('){infix[i]=')';}
		else if(infix[i]==')'){infix[i]='(';}
		i++;
	}

	i=0;
	while(infix[i]!='\0'){
		char n=infix[i];
		if(isalnum(n)){
			prefix[j]=n;
			j++;
		}
		else if(n=='('){
			top++;
			s[top]=n;
		}
		else if(n==')'){
			while(top!=-1 && s[top]!='('){
				prefix[j]=s[top];
				j++;
				top--;
			}

			if(top!=-1){top--;}
		}
		else{
			if(n=='^' && s[top]=='^'){
				top++;
				s[top]=n;
			}
			else{
				while(top!=-1 && precedence(n)<=precedence(s[top])){
					prefix[j]=s[top];
					j++;
					top--;
				}
				top++;
				s[top]=n;	
			}
		}
		i++;
	}
	while(top!=-1){
		prefix[j]=s[top];
		j++;
		top--;
	}
	reverse(prefix);
	printf("Prefix expression:%s\n",prefix);
}
int main(){
	printf("Enter infix expression:");
	scanf("%s",infix);
	infix_to_prefix();
	return 0;
}

