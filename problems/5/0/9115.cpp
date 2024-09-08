#include<iostream>
#include<cstdlib>
using namespace std;
struct node{
	int day;
	int data;
	node* next=NULL;
};
struct day{
	int day;
	node* next=NULL;
};
int main(){
	int n;
	int m;
	int d;
	cin>>n;
	cin>>m;
	cin>>d;
	node*first=new node;
	cin>>first->data;
	first->day=1;
	int num=1;
	for(int i=1;i<n;i++){
		node*p=first;
		node*q=p;
		node* m1=new node;
		cin>>m1->data;
		m->day=i+1;
		if(p->data>=m1->data){
			m1->next=p;
			first=m1;
		}
		if(m1->data>p->data){
			p=p->next;
			while(m1->data>p->data){
				p=p->next;
				q=q->next;
			}
			m1=q->next;
			m1->next=p;
		}
		if(num>=m){
			p=first;
			first=first->next;
			delete p;
		}
	}
	int result;
	p=first;
	while(p->next!=NULL){
		result+=p->data;
	}
	day*f1=new day;
   f1->day=first->day;
	p=first->next;
	for(int i=1;i<m;i++){
		day*p1=f1;
		day*q1=p1;
		day* m2=new day;
		m->day=p->day;
		p=p->next;
		if(p1->day>=m2->day){
			m2->next=p1;
			f1=m2;
		}
		if(m2->day>p1->day){
			p1=p1->next;
			while(m2->day>p1->day){
				p1=p1->next;
				q1=q1->next;
			}
			m2=q1->next;
			m2->next=p1;
		}
	}
	p=f1;
	whiel(p->next!=NULL){
		result-=d*(p->next->day-p->day);
		p=p->next;
	}
}