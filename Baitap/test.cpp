#include<iostream>
#include<math.h>

using namespace std;

struct Selection
{
	int W;
	int V;
};
Selection a[100];
int k[100][100];
int res=0;
int knap(int n,int m){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0&&j==0){
				k[i][j]=0;
			}else if(j<a[i].W){
				k[i][j]=k[i-1][j];
			}
			else{
				k[i][j]=max(k[i-1][j],k[i-1][j-a[i].W]+a[i].V);
				res=max(res,k[i][j]);
			}
		}
	}
	return res;
}
int main(){
	int n, W;
	cin>>n>>W;
	for(int i=0;i<n;i++){
		cin>>a[i].W>>a[i].V;
	}
	cout << knap(n,W);
}
