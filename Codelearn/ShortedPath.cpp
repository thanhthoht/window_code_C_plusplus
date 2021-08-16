#include <bits/stdc++.h>
using namespace std;

int minDistance(int dist[],int n,bool visited[]){		//hàm tìm đỉnh có khoảng cách nhỏ nhất với đỉnh trước nó
	int min=INT_MAX;
	int minIndex;
	for(int i=1;i<=n;i++){
		if(!visited[i]&&dist[i]<=min){
			min=dist[i];
			minIndex=i;
		}
	}
	return minIndex;
}
void printpath(int graph[][100],int n,int p,int q,int path[]){	//hàm in đường đi
	for(int i=2;i<=n;i++){
		cout<<path[i]<<" ";		//in đỉnh trên đg đi
	}
	cout<<q;
}
void dijkstra(int graph[][100],int n,int p,int q){		//hàm thuật toán dij
	int dist[n];
	int path[n];
	bool visited[n];	//khởi tạo đánh dấu tất cả chưa thăm
	for(int i=1;i<=n;i++){
		visited[i]=false;
		path[i]=0;
		dist[i]=INT_MAX;
	}
	dist[p]=0;

	for(int i=1;i<=n;i++){
		int u=minDistance(dist,n,visited);	//tìm vetex gần nhất
		visited[u]=true;	//duyệt qua u

		for(int j=1;j<=n;j++){
			if(graph[u][j]>0  &&  !visited[j]	&& dist[u]!=INT_MAX  &&   (dist[u]+graph[u][j]<dist[j]))
			//gs graph[3][1]=1>0, visit[3]=true,visit[1]=false,dist[1]=o~o,dist[3]=0+1<o~o=1
			{
				dist[j]=dist[u]+graph[u][j];		//dist[1]=1, kc từ 3->1
				path[j]=u;							//path[1]=3, số liền trước 1 là 3
			}
		}		
	}
	if(dist[q]==INT_MAX){
		cout<<"Đức Anh đẹp zai k tìm đc liên kết"<<endl;
	}
	else{
		cout<<dist[q];
		printpath(graph,n,p,q,path);
	}
}

void floyd(int graph[][100],int n){			//hàm thuật toán floyd
	for(int p=1;p<=n;p++){
		for(int q=1;q<=n;q++){
		//gọi lại thuật toán dij
			int dist[n];
	    	int path[n];
	    	bool visited[n];	//khởi tạo đánh dấu tất cả chưa thăm
	    	for(int i=1;i<=n;i++){
	    		visited[i]=false;
	    		path[i]=0;
	    		dist[i]=INT_MAX;
	    	}
	    	dist[p]=0;

	    	for(int i=1;i<=n;i++){
	    		int u=minDistance(dist,n,visited);	//tìm vetex gần nhất
	    		visited[u]=true;	//duyệt qua u
	
	    		for(int j=1;j<=n;j++){
	    			if(graph[u][j]>0  &&  !visited[j]	&& dist[u]!=INT_MAX  &&   (dist[u]+graph[u][j]<dist[j]))
	    			//gs graph[3][1]=1>0, visit[3]=true,visit[1]=false,dist[1]=o~o,dist[3]=0+1<o~o=1
	    			{
	    				dist[j]=dist[u]+graph[u][j];		//dist[1]=1, kc từ 3->1
	    				path[j]=u;							//path[1]=3, số liền trước 1 là 3
	    			}
	    		}		
	    	}
	    	if(dist[q]==INT_MAX){
				cout<<"noEdge"<<" ";
			}
			else{
				cout<<dist[q]<<" ";
			}
	    }
		cout<<endl;
	}
}

int main(){
	int n,m;		//n là số đỉnh, m là số edge
	cin>>n>>m;
	int a[100][100];		//khởi tạo ma trận input
	for(int i=1;i<=m;i++){
		for(int j=0;j<=2;j++){
			cin>>a[i][j];
		}
	}
	  int p,q;		// 2 điểm cần tìm mindistance
	  cin>> p >>q;
	int edge[100][100];		// khởi tạo ma trận giá trị
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			edge[i][j]=-9999;	//giả sử -9999 nghĩa là 2 đỉnh không có edge
		}
	}
	for(int i=1;i<=m;i++){
		edge[a[i][0]][a[i][1]]=a[i][2];	//gán giá trị các cạnh có chiều từ input vào ma trận egde		
	}
	dijkstra(edge,n,p,q);
	cout<< endl;
	floyd(edge,n);
}