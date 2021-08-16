#include <bits/stdc++.h>
using namespace std;
int main(){
	char a[100];
	cout<<"nhập chuỗi:";
	gets(a);
	int len=0;
	while (a[len] != '\0'){
        len++;
	}
	for(int i=0;i<len;i++){
		if(a[i]>='A'&&a[i]<'Z'){
			a[i]+=32;
		}
	}
	cout<< "nhap ký tự cần tìm:";
	char c;
	cin>>c;
	int count=0;
	for(int i=0;i<len;i++){
		if(a[i]==c){
			count++;
		}
	}
	cout<< count;
}