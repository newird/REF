#include <iostream>
using namespace std;
const int MaxSize=100;  
template <class DataType>           //模板类
class SeqList
{
 public:  
     SeqList( ) ;                                 //构造函数
     SeqList(DataType a[ ], int n);       
     ~SeqList( ) { }; 
	 void PrintList();                              //析构函数
	 friend SeqList<int> Add(SeqList <int> A,SeqList <int> B);  
     DataType data[MaxSize]; 
     int length;
};
template <class DataType>  
SeqList<DataType> ::SeqList( )
{  
    length = 0; 
}
template <class DataType>  
SeqList<DataType> ::SeqList(DataType a[ ], int n)
{  
       if (n > MaxSize) throw "参数非法";
       for (int i = 0; i < n; i++)  
             data[i] = a[i];
       length = n; 
 }
template <class DataType>
void SeqList<DataType> ::  PrintList()
{
	for(int i=0; i<length; i++)
	cout<<data[i];
 } 
SeqList<int> Add(SeqList <int> A,SeqList <int> B)
{
	SeqList<int> C;
	int flag=0;int i=0;
	int n=A.length;int m=B.length;
	while (i<n && i<m)
	{
		C.data[i]=(A.data[i]+B.data[i]+flag)%10;
		flag=(A.data[i]+B.data[i]+flag)/10;
		i++;
	}
	for(; i<n; i++)
	{
		C.data[i]=(A.data[i]+flag)%10;
		flag=(A.data[i]+flag)/10;
	}
	for(; i<m; i++)
	{
		C.data[i]=(B.data[i]+flag)%10;
		flag=(B.data[i]+flag)/10;
	}
	C.length=max(m,n)+flag;
	if(flag==1) C.data[C.length-1]=1;
	return C;
}
int main()
{
	int a[5]={1,2,3,4,5},b[5]={1,2,3,4,5};
	SeqList <int>A(a,5);
	cout<<"大整数A：";A.PrintList();cout<<endl; 
	SeqList <int>B(b,5);
	cout<<"大整数B：";B.PrintList();cout<<endl; 
	SeqList <int>C;
	C=Add(A,B);
	cout<<"A+B=";C.PrintList();cout<<endl; 
	return 0;
}