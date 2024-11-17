#include <stdio.h>
#define SIZE 20
int mat1[10][10], mat2[10][10];
struct tuple{
	int row;
	int col;
	int val;
};
struct tuple t1[SIZE],t2[SIZE],res[SIZE],tt1[SIZE],tt2[SIZE];
int no=1;
//tt refers to transpose tuple

void display(struct tuple t[],int k){
	for(int i=0;i<k;i++){
		printf("%d\t%d\t%d\n",t[i].row,t[i].col,t[i].val);
	}
	printf("\n");		
}

void tuple_conversion(int m[][10],int r,int c, struct tuple t[],int num){
	int i,j,k=1;
	printf("\nTuple representation of matrix %d:\n",num);
        t[0].row=r;
        t[0].col=c;
        for(i=0;i<r;i++){
                for(j=0;j<c;j++){
                        if(m[i][j]==0){continue;}
                        t[k].row=i;
                        t[k].col=j;
                        t[k].val=m[i][j];
                        k++;
                }
        }
        t[0].val=(k-1);
        display(t,k);
}

void tuple_transpose(struct tuple t[],struct tuple tt[]){
	tt[0].row=t[0].row;
	tt[0].col=t[0].col;
	tt[0].val=t[0].val;
	int k=1;
	for(int i=0;i<t[0].col;i++){
		for(int j=1;j<=t[0].val;j++){
			if(t[j].col==i){
				tt[k].row=t[j].col;
				tt[k].col=t[j].row;
				tt[k].val=t[j].val;
				k++;
			}
		}
	}
	printf("Tuple Transpose of matrix %d:\n",no++);
	display(tt,k);
}

void tuple_sum(){
	if((t1[0].row!=t2[0].row)||(t1[0].col!=t2[0].col)){
		printf("Sum not possible\n");
		return;
	}
	else{
		res[0].row=t1[0].row;
		res[0].col=t1[0].col;
		int i=1,j=1,k=1;
		int rr1,cc1,rr2,cc2;
		while(i<=t1[0].val && j<=t2[0].val){
			rr1=t1[i].row;
			cc1=t1[i].col;
			rr2=t2[j].row;
			cc2=t2[j].col;
			if(rr1<rr2 ||(rr1==rr2 && cc1<cc2)){
				res[k].row=rr1;
				res[k].col=cc1;
				res[k].val=t1[i].val;
				i++;
				k++;
			}
			else if(rr1>rr2 ||(rr1==rr2 && cc1>cc2)){
				res[k].row=rr2;
				res[k].col=cc2;
				res[k].val=t2[j].val;
				j++;
				k++;
			}
			else{
				res[k].row=rr1;
				res[k].col=cc1;
				res[k].val=t1[i].val+t2[j].val;
				i++;
				j++;
				k++;
			}
		}	
		while(i<=t1[0].val){
			res[k].row=t1[i].row;
                        res[k].col=t1[i].col;
                        res[k].val=t1[i].val;
                        i++;
			k++;
		}
		while(j<=t2[0].val){
			res[k].row=t2[j].row;
                        res[k].col=t2[j].col;
                        res[k].val=t2[j].val;          
                        j++;
			k++;
		}
		res[0].val=(k-1);
		printf("\nTuple Sum:\n");
		display(res,k);
	}
}

int main(){
	int r1,r2,c1,c2,i,j;
	printf("Enter total number of rows and columns in matrix 1:");
	scanf("%d%d",&r1,&c1);
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			printf("Enter element %d%d:",i+1,j+1);
			scanf("%d",&mat1[i][j]);
		}
	}

	printf("Enter total number of rows and columns in matrix 2:");
        scanf("%d%d",&r2,&c2);
        for(i=0;i<r2;i++){
                for(j=0;j<c2;j++){
                        printf("Enter element %d%d:",i+1,j+1);
                        scanf("%d",&mat2[i][j]);
                }
        }

	tuple_conversion(mat1,r1,c1,t1,1);
	tuple_conversion(mat2,r2,c2,t2,2);
	tuple_transpose(t1,tt1);
	tuple_transpose(t2,tt2);
	tuple_sum();
	return 0;
}

