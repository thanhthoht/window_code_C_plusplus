#include<iostream>
using namespace std;
int k,q,z;
void SelectionSort(int a[],int n){
    for(int i=0;i<n;i++){
		int indexMin=i;
		for(int j=i+1;j<n;j++){
			if(a[indexMin]>a[j]){
				indexMin=j;
			}
		}
		if(indexMin!=i){
			int temp=a[i];
			a[i]=a[indexMin];
			a[indexMin]=temp;
		}
	}
}
int main(){
    int n;
    cin>>n;
    int *a=new int[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    SelectionSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}