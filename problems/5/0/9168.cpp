#include<iostream>
#include<cstdlib>
using namespace std;
struct day_{
	int day;
	day_*next1=NULL;
};
struct node{
	int nday;
	int data;
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
	first->nday=1;
	int num=1;
	node*p=first;
	node*q=p;
	for(int i=1;i<n;i++){
		node*p=first;
		node*q=p;
		node* m1=new node;
		cin>>m1->data;
		m1->nday=i+1;
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
	day_*f1=new day_;
   f1->day=first->nday;
	p=first->next;
	int temp;
	day_*p1;
	day_*q1;
	for(int i=1;i<m;i++){
		p1=f1;
		q1=f1;
		day_* m2=new day_;
		temp=p->nday;
		m2->day=temp;
		p=p->next;
		if(p1->day>=m2->day){
			m2->next1=p1;
			f1=m2;
		}
		if(m2->day>p1->day){
			p1=p1->next1;
			while(m2->day>p1->day){
				p1=p1->next1;
				q1=q1->next1;
			}
			m2=q1->next1;
			m2->next1=p1;
		}
	}
	p1=f1;
	while(p1->next1!=NULL){
		result-=d*(p1->next1->day-p1->day);
		p1=p1->next1;
	}
}