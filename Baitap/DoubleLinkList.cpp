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
DoubleList *Insert(DoubleList *t,int v,int x){
	node *p=t->head;
	for(int i=0;i<v-1;i++){
		p=p->next;
	}
	node *temp=new node;
	temp->data=x;
	temp->pre=p;
	temp->next=p->next;
	p->next->pre=temp;
	p->next=temp;
	return t;
}
int main(){
	int k,x;
	cin>>k>>x;
	DoubleList *t=create(x);
	for(int i=1;i<k;i++){
		cin>>x;
		t=addTail(t,x);
	}
	int vitri,giatri;
	cin>>vitri>>giatri;
	if(vitri==0){
        addHead(t,giatri);
    }
    else if(vitri==k-1){
        addTail(t,giatri);
    }
    else if(vitri>0&&vitri<k-1){
        Insert(t,vitri,giatri);
    }
	printList(t);
}
