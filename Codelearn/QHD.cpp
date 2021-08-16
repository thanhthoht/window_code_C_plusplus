#include<iostream>
#include<vector>
using namespace std;
int main(){
	int count=1;
	int n;
	cin>>n;
	int a[100001];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int value=a[0];
	int max_v=a[0];
	for(int i=0;i<n;i++){
		if(a[i]<value){
			value=a[i];
			count++;
		}
	}
	int j=1;
	while(j<n&&a[j]>max_v){
		
	}
	cout<<count;
}