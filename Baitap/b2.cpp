#include<iostream>
using namespace std;

int search(int array[],int b, int n,int y,int k){
	int x=y;
	for(int i=b;i<n;i++){
		x=x-array[i];
		if(x==0){
			cout<<"YES";
			i=n;
			break;		
		}
		else if(x<0){
			continue;
		}
		else {
			b=b+1;			
			search(array,b,n,x,k);
			if(b==n){
				cout<<"NO";
			}
		}
		x=k;
}
return 0;
}
int main(){
	int n,x;
	cin>>n>>x;
	int *array=new int[100];
	for(int i=0;i<n;i++){
		cin>>array[i];
	}
	int k=x;
	search(array,0,n,x,k);
}
//Em van chua bug dc code :((	