#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    queue<int> q;
    bool b[100];
    int  a[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<100;i++){
        b[i]=false;
    }
	int k;
    cin>>k;
    for(int i=0;i<n;i++){
        if(!b[a[i]]){
            if(q.size()<k){
                b[a[i]]=true;
                q.push(a[i]);
            }else{
                b[q.front()]=false;
                b[a[i]]=true;
                q.push(a[i]);
                q.pop();
            }
        }
    }
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}