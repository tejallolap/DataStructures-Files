/* Name- Tejal Lolap
Batch: B1
Roll. No. : 222008
Gr. No. : 17u620 
*/

/* Assignment 6 - Read the marks obtained by students of second year in an online examination of particular subject. Find out
maximum and minimum marks obtained in that subject using heap data structure. */

#include<iostream>
using namespace std;
class heap
{
    int *arr,size;
public:
    heap(int x)
    {
        arr=new int(x);
        size=x;
    }
    void create();
    void heapify(int,int);
    void heap_s();
};

void heap::create()
{
    int i;
    cout<<"Enter the heap members\n";
    for(i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<"Entered heap is:\n";
     for(i=0;i<size;i++)
    {
        cout<<""<<arr[i]<<"\t";
    }
}

void heap::heapify(int size,int i)
{
    int l,r,largest;
    largest=i;
    l=2*i+1;
    r=2*i+2;
    if(l<size && arr[l]>arr[largest])
        largest=l;
    if(r<size && arr[r]>arr[largest])
        largest=r;

    if(largest!=i)
    {
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(size,largest);
    }
}

void heap::heap_s()
{
    int i;
    for(i=size/2;i>=0;i--)
    {
        heapify(size,i);
    }
    cout<<"\nAfter heapifying to a max heap:\n";
    for(i=0;i<size;i++)
    {
        cout<<""<<arr[i]<<"\t";
    }
    for(i=size-1;i>=0;i--)
    {
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(i,0);
    }
    cout<<"\nAfter using a heap sort:\n";
    for(i=0;i<size;i++)
    {
        cout<<""<<arr[i]<<"\t";
    }
}

int main()
{
    int n;
    cout<<"Enter the heap's size\n";
    cin>>n;
    heap h(n);
    h.create();
    h.heap_s();
    return 0;
}

