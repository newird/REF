#include<iostream>
using namespace std;
template<class T>
class LinkList;
template<class T>
ostream& operator<<(ostream& out,const LinkList<T>& l);
template<class T>
istream& operator>>(istream& in,LinkList<T>& list);
template<class T>
struct LinkNode{
    T data;
    LinkNode<T> *next;
    LinkNode(T value=0);
};
template<class T1,class T2>
struct headNode{
    T1 data;
    LinkNode<T2> *next;
    headNode(T1 value);
};
template<class T>
LinkNode<T>::LinkNode(T value){
    data=value;
    next=NULL;
}
template<class T>
class LinkList{
    private:
    LinkNode<T>* first;
    public:
    LinkList(T n);
    friend istream& operator >><T>(istream&,LinkList<T>&);
    template<class T1>
    friend void operator+(LinkList<T1>&,LinkList<T1>&);
    friend ostream& operator<<<T>(ostream&,const LinkList<T>&);
};
template<class T>
LinkList<T>::LinkList(T n){
    first=new LinkNode<T>(n);
};
template<class T>
istream& operator >>(istream& in,LinkList<T>& list){
    LinkNode<long long>* current=list.first;
    for(long long i=0;i<list.first->data;i++){
        LinkNode<T>* p=new LinkNode<T>;
        in>>p->data;
        current->next=p;
        current=p;
    }
    return in;
}

template<class T>
void operator+(LinkList<T>& List1,LinkList<T>& List2){
    // long long result=0;
    // LinkNode<T> *l1=List1.first->next,*l2=List2.first->next;
    // int upp=0;
    // int exp=1;
    // if(List1.first->data<List2.first->data){
    //     for(long long i=0;i<List1.first->data;i++){
    //         int add=l1->data+l2->data;
    //         result+=(add%10+upp)*exp;
    //         exp=exp*10;
    //         upp=add/10;
    //         l1=l1->next;l2=l2->next;
    //     }
    //     while(l2!=NULL){
    //         result+=l2->data*exp;
    //         exp=exp*10;
    //         l2=l2->next;
    //     }
    // }else{
    //     for(long long i=0;i<List2.first->data;i++){
    //         int add=l1->data+l2->data;
    //         result+=(add%10+upp)*exp;
    //         exp=exp*10;
    //         upp=add/10;
    //         l1=l1->next;l2=l2->next;
    //     }
    //     while(l1!=NULL){
    //         result+=l1->data*exp;
    //         exp=exp*10;
    //         l1=l1->next;
    //     }
    // }
    // return result;
    int result=0;
    string a("");
    LinkNode<T> *l1=List1.first->next,*l2=List2.first->next;
    int upp=0;
    int exp=1;
    if(List1.first->data<List2.first->data){
        for(long long i=0;i<List1.first->data;i++){
            int add=l1->data+l2->data;
            string str=to_string(add%10+upp);
            a=str+a;
            upp=add/10;
            l1=l1->next;l2=l2->next;
        }
        
        while(l2!=NULL){
            int add=upp+l2->data;
            a=to_string(add%10)+a;
            upp=add/10;
            l2=l2->next;
        }
        if(l1==NULL && l2==NULL && upp!=0)
        a=to_string(upp)+a;
    }else{
        for(long long i=0;i<List2.first->data;i++){
            int add=l1->data+l2->data;
            string str=to_string(add%10+upp);
            a=str+a;
            upp=add/10;
            l1=l1->next;l2=l2->next;
        }
        
        while(l1!=NULL){
            int add=upp+l1->data;
            a=to_string(add%10)+a;
            upp=add/10;
            l1=l1->next;
        }
        if(l1==NULL && l2==NULL && upp!=0)
        a=to_string(upp)+a;
    }
    cout<<a;
}
template<class T>
ostream& operator<<(ostream& out,const LinkList<T>& l){
    LinkNode<T>* current=l.first->next;
    while(current!=NULL){
        out<<current->data<<" ";
        current=current->next;
    }
    return out;
};

int main(){
    long long n,m;
    cin>>n>>m;
    LinkList<long long> l1=LinkList<long long>(n),l2=LinkList<long long>(m);
    cin>>l1>>l2;
    l1+l2;
}