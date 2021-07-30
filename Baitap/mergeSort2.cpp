#include<iostream>
using namespace std;
void merge(int array[],int left,int mid,int right){
	int l=mid-left+1;
	int r=right-mid;
	int *leftarray=new int[l];
	int *rightarray=new int[r];
	for(int i=0;i<l;i++){
		leftarray[i]=array[left+i];
	}
	for(int j=0;j<r;j++){
		rightarray[j]=array[mid+1+j];
	}
	int left_idx=0;
	int right_idx=0;
	int merge_idx=left;

	/*
	Trộn:
	*/
	while(left_idx<l	&&	right_idx<r){
		if(leftarray[left_idx]<=rightarray[right_idx]){
			array[merge_idx++]=leftarray[left_idx++];
		}
		else{
			array[merge_idx++]=rightarray[right_idx++];
		}
	}
	while(left_idx<l){
		array[merge_idx++]=leftarray[left_idx++];
	}
	while(right_idx<r){
		array[merge_idx++]=rightarray[right_idx++];
	}
}

void mergeSort(int arr[],int begin,int end){
	if(begin>=end){
		return;
	}

		int mid=begin+(end-begin)/2;
		mergeSort(arr,begin,mid);
		mergeSort(arr,mid+1,end);
		merge(arr,begin,mid,end);
	}

int main(){
	int *a=new int[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}