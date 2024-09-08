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
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	node*first=new node;
	cin>>first->data;
	first->day=1;
	int num=1;
	for(int i=1;i<l;i++){
		node*p=first;
		node*q=p;
		node* m=new node;
		cin>>m->data;
		m->day=i+1;
		if(p->data>=m->data){
			m->next=p;
			first=m;
		}
		if(m->data>p->data){
			p=p->next;
			while(m->data>p->data){
				p=p->next;
				q=q->next;
			}
			m=q->next;
			m->next=p;
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
		day* m=new day;
		m->day=p->day;
		p=p->next;
		if(p1->day>=m->day){
			m->next=p1;
			f1=m;
		}
		if(m->day>p1->day){
			p1=p1->next;
			while(m->day>p1->day){
				p1=p1->next;
				q1=q1->next;
			}
			m=q1->next;
			m->next=p1;
		}
	}
	p=f1;
	whiel(p->next!=NULL){
		result-=d*(p->next->day-p->day);
		p=p->next;
	}
}