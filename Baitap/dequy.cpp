#include<iostream>

using namespace std;

int UCLN(int a,int b){
	if(b==0) {return a;}
	if(a%b==0) {return b;}
	return UCLN(b,a%b);
}
int main(){
	int m,n;
	cin >>m>> n;
	cout << UCLN(max(m,n),min(m,n));
	return 0;
}