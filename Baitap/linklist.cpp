#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *createNode(int x){
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	return temp;
}
node *addNode(node *p,int x){
	node *temp=createNode(x);
	p->next=temp;
	return temp;
}
void printList(node *t){
	node *p=t;
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
}

int main(){
	int n,x;
	cin>>n;
	cin>>x;
	node *t=createNode(x);
	node *p=t;
	for(int i=1;i<n;i++){
		cin>>x;
		p=addNode(p,x);
	}
	printList(t);
}
