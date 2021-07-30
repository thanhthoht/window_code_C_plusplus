#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
	node *pre;
};
struct DoubleList
{
	node *head;
	node *tail;
};
DoubleList *create(int x){
	DoubleList *t=new DoubleList;
	t->head=new node;
	t->head->data=x;
	t->head->pre=NULL;
	t->head->next=NULL;
	t->tail=t->head;
	return t;
}
DoubleList *addHead(DoubleList *t,int x){
	node *temp=new node;
	temp->data=x;
	temp->pre=NULL;
	temp->next=t->head;
	t->head->pre=temp;
	t->head=temp;
	return t;
}
DoubleList *addTail(DoubleList *t,int x){
	node *temp=new node;
	temp->data=x;
	temp->next=NULL;
	temp->pre=t->tail;
	t->tail->next=temp;
	t->tail=temp;
	return t;
}

void printList(DoubleList *t){
	node *p= t->head;
	while(p!=NULL){
		cout << p->data<<" ";
		p=p->next;
	}
}
int main(){
	int k;
	cin>>k;
	DoubleList *t=create(1);
	for(int i=2;i<=k;i++){
		t=addHead(t,i);
		t=addTail(t,i);
	}
	printList(t);
}
