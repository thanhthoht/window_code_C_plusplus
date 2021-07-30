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
node *instead(node *t,int x,int y){
	node *p=t;
	while(p!=NULL){
		if(p->data==x){
			p->data=y;
		}
		p=p->next;
	}
	return t;
}
node *addLastNode(node *t,int x){
	node *p=t;
	while(p!=NULL){
		p=p->next;
		if(p->next==NULL){
			node *temp=new node;
			p->next=temp;
			temp->data=x;
			temp->next=NULL;
			break;
		}
	}
	return t;
}

node *getNode(node *t,int k){
	node *p=t;
	for(int i=1;i<k;i++){
		p=p->next;
	}
	return p;
}

node *NewList(node *t,int k){
	node *p=t;
	node *a=new node;
	while(p!=NULL){
		if(p->data<=k){
			a=createNode(p->data);
			p=p->next;
			break;
		}
		p=p->next;
	}
	node *q=a;
	while (p!=NULL)
	{
		if(p->data<=k){
			q=addNode(q,p->data);
		}
		p=p->next;
	}
	return a;
}

node *CreateCircleList(node *t,int x){
	node *p=t;
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	p->next=temp;
	return t;
}
node *AddTail(node *t,int x){
	node *p=t;
	while(t->next!=t){
		p=p->next;
	}
	node *temp=new node;
	temp->data=x;
	temp->next=t;
	p->next=temp;
	p=temp;
	return t;
}
int main(){
	int n,x;
	cin>>n;
	cin>>x;
	node *t=createNode(x);
	node *p=t;
	for(int i=1;i<n-1;i++){
		cin>>x;
		p=CreateCircleList(p,x);
	}
	cin>>x;
	t=AddTail(t,x);
}