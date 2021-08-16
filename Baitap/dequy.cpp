#include<iostream>
using namespace std;
int Bool[100];
int array[100];
void allHoanVi(int k,int n){
	for(int i=1;i<=n;i++){
		if(Bool[i]==1){
			array[k]=i;		// nhập a[1],[2],[3]
			if(k==n){
				for(int j=1;j<=n;j++){
					cout<<array[j];
				}					
				cout<<" ";		//in a[1][2][3]
			}
			else{
				Bool[i]=0;
				allHoanVi(k+1,n);
				Bool[i]=1;
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		Bool[i]=1;
	}
	allHoanVi(1,n);
}
