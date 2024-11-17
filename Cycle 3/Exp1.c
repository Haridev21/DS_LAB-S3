#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define SIZE 10
char infix[SIZE], postfix[SIZE],s[SIZE];
int top=-1;

int precedence(int m){
	switch(m){
		case '+':return 1;
		case '-':return 1;
		case '*':return 2;
		case '/':return 2;
		case '%':return 2;
		case '^':return 3;
		default:return 0;
	}
}
void infix_to_postfix(){
	int i=0, j=0;
	while(infix[i]!='\0'){
		char n=infix[i];
		if(isalnum(n)){
			postfix[j]=n;
			j++;
		}
		else if(n=='('){
			top++;
			s[top]=n;
		}
		else if(n==')'){
			while(top!=-1 && s[top]!='('){
				postfix[j]=s[top];
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
					postfix[j]=s[top];
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
		postfix[j]=s[top];
		j++;
		top--;
	}
	postfix[j]='\0';
}

void evaluate(){
	int j=0;
	while(postfix[j]!='\0'){
		char n=postfix[j];
		if(isdigit(n)){
			top++;
			s[top]=n-'0';
		}
		else{
			float b=s[top];
			float c=s[--top];
			switch(n){
		                case '+':s[top]=c+b; break;
                		case '-':s[top]=c-b; break;
		                case '*':s[top]=((int)c)*((int)b); break;
                		case '/':s[top]=(float)c/b; break;
		                case '%':s[top]=((int)c)%((int)b); break;
				case '^':s[top]=pow(c,b); break;
			}
		}			
		j++;
	}
	printf("\nResult:%d\n",s[top]);
}

int main(){
	printf("Enter infix expression:");
	scanf("%s",infix);
	infix_to_postfix();
	printf("Postfix expression:%s\n",postfix);
	evaluate();
	return 0;
}

