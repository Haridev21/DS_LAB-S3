#include <stdio.h>
#define SIZE 4
struct poly{
	int coeff;
	int exp;
};
struct poly p1[SIZE],p2[SIZE],res[SIZE];
void display(struct poly p[], int t ){
	for(int i=0;i<t;i++){
		if(i!=0 && p[i].coeff>0){
			printf(" + ");
		}
		printf("%dx^%d",p[i].coeff,p[i].exp);
	}
	printf("\n");
}
int sum_poly(int n, int m){
	int i=0,j=0,k=0;
	while(i<n && j<m){
		if(p1[i].exp>p2[j].exp){
			res[k].coeff=p1[i].coeff;
			res[k].exp=p1[i].exp;
			k++;
			i++;
		}
		else if(p1[i].exp<p2[j].exp){
			res[k].coeff=p2[j].coeff;
			res[k].exp=p2[j].exp;
			k++;
			j++;
		}
		else if(p1[i].exp==p2[j].exp){
			int a=p1[i].coeff+p2[j].coeff;
			if(a==0){
				i++;
				j++;
			}
			else{
				res[k].coeff=a;
				res[k].exp=p1[i].exp;
				k++;
				i++;
				j++;
			}
		}
	}
	while(i<n){
		res[k].coeff=p1[i].coeff;
		res[k].exp=p1[i].exp;
		k++;
		i++;
	}
	while(j<m){
		res[k].coeff=p2[j].coeff;
                res[k].exp=p2[j].exp;
                k++;
                j++;
	}
	return k;
}
void display_all(int n, int m, int k){
	printf("First polynomial:");
	display(p1,n);
	printf("Second polynomial:");
	display(p2,m);
	printf("Sum polynomial:");
	display(res,k);
}

int main(){
	int n,m,i;
	printf("Enter total number of terms in first polynomial:");
	scanf("%d",&n);
	printf("Enter coefficient and exponent:\n");
	for(i=0;i<n;i++){
		int c,e;
		printf("Term %d:",i+1);
		scanf("%d%d",&c,&e);
		p1[i].coeff=c;
		p1[i].exp=e;
	}
	printf("\nEnter total number of terms in second polynomial:");
        scanf("%d",&m);
        printf("Enter coefficient and exponent:\n");
        for(i=0;i<m;i++){
                int c,e;
                printf("Term %d:",i+1);
                scanf("%d%d",&c,&e);
                p2[i].coeff=c;
                p2[i].exp=e;
        }
	int k=sum_poly(n,m);
	display_all(n,m,k);
	return 0;
}
