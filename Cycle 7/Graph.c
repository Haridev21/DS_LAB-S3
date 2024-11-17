//graph BFS and DFS
#include <stdio.h>
#include <stdbool.h>
void createMatrix(int m[][50],int v,int e){
	int src,dest;
	for(int i=0;i<e;i++){
		printf("Enter vertices of edge %d:",i+1);
		scanf("%d%d",&src,&dest);
		m[src][dest]=1;
		m[dest][src]=1;
	}
}
void dfs(int m[][50],int v, int start){
	bool visited[50];
	for(int i=0;i<50;i++){
		visited[i]=false;
	}
	int s[50],top=-1;
	top++;
	s[top]=start;
	while(top!=-1){
		int node=s[top];
		top--;
		if(!visited[node]){
			visited[node]=true;
			printf("%d\t",node);
			for(int i=v;i>=0;i--){
				if(m[node][i]==1 && !visited[i]){
					top++;
					s[top]=i;
				}
			}
		}
	}
}	
void bfs(int m[][50], int v, int start){
	bool visited[50];
	for(int i=0;i<50;i++){
		visited[i]=false;
	}
	int q[50],f=0,r=0;
	q[r]=start;
	r++;
	visited[start]=true;
	while(f<r){
		int node=q[f];
		f++;
		printf("%d\t",node);
		for(int i=0;i<=v;i++){
			if(m[node][i]==1 && !visited[i]){
				q[r]=i;
				r++;
				visited[i]=true;
			}
		}
	}
}
int main(){
	int v,e,start,ch;
	printf("Enter the total number of vertices and edges:");
	scanf("%d%d",&v,&e);
	printf("Number of vertices:%d\nNumber of edges:%d\n",v,e);
	int adjMatrix[50][50];
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			adjMatrix[i][j]=0;
		}
	}
	createMatrix(adjMatrix,v,e);
	while(1){
		printf("\n\nMENU:\n1.DFS\n2.BFS\n*.EXIT");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		if(ch==1){
			printf("Enter the starting node for traversal:");
			scanf("%d",&start);
			printf("DFS:");
			dfs(adjMatrix,v,start);
			printf("\n");
		}
		else if(ch==2){
			printf("Enter the starting node for traversal:");
                        scanf("%d",&start);
                        printf("BFS:");
                        bfs(adjMatrix,v,start);
                        printf("\n");
		}
		else{break;}
	}
	return 0;
}
		
