// infix to postfix without stack
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10
char infix[SIZE], postfix[SIZE];

int isp(char op){
	switch(op){
                case '+':return 2;
                case '-':return 2;
                case '*':return 4;
                case '/':return 4;
                case '^':return 5;
                case '(': return 0;
		default: return -2;
        }
}

int icp(char op){
        switch(op){
                case '+':return 1;
                case '-':return 1;
                case '*':return 3;
                case '/':return 3;
                case '^':return 6;
                case '(': return 7;
		case ')':return 0;
                default: return -2;
        }
}

void infix_postfix(char *infix, char *postfix, int start,int end, int *index){
	if(start>end){return;}
	int minp=8;
	int mainp=-1;
	int o_brac=0;
	for(int i=start;i<=end;i++){
		if(infix[i]=='('){o_brac++;}
		else if(infix[i]==')'){o_brac--;}
		else if(o_brac==0 && icp(infix[i])>0 && icp(infix[i])<=minp){
			minp=isp(infix[i]);
			mainp=i;
		}
	}
	if(mainp==-1 ){
		if(infix[start]=='(' && infix[end]==')'){
			infix_postfix(infix,postfix,start+1,end-1,index);
		}
		else{
			for(int i=start; i<=end;i++){
				postfix[(*index)++]=infix[i];
			}
		}
	}
	else{
		infix_postfix(infix,postfix,start,mainp-1,index);
		infix_postfix(infix,postfix,mainp+1,end,index);
		postfix[(*index)++]=infix[mainp];
	}	
}

int main(){
	int index=0;
	printf("Enter infix expression:");
	scanf("%s",infix);
	infix_postfix(infix,postfix,0,strlen(infix)-1,&index);
	postfix[index]='\0';
	printf("Postfix expression:%s\n",postfix);
	return 0;
}
