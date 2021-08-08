#include<iostream>
using namespace std;

void input(int a[],int n){
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
void output(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
void bubble(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                int temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
	int *a=new int [100];
    input(a,n);
    bubble(a,n);
    output(a,n);
    delete[] a;
    return 0;
}