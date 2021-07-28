#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<string> a;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		cout << a[i];
	}
}