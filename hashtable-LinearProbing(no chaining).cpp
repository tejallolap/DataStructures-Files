
/*Assignment 8 - A node consist of <Key, Value> pair ,where nodes are compared and inserted on basis of key . Build a structure such that it should provide a facility of adding a new key ,update meaning of a key ,delete a key(linear probing without chaining) */


#include<iostream>
#include<string.h>
using namespace std;
struct hashtable
{
int key;
string value;
};
void insert(int size, hashtable h[])
{
int k;
string s;
cout<<"\n Enter the Key ";
cin>>k;
cout<<"\n Enter the Name";
cin>>s;
int index=(k%size);
for(int i=0;i<size;i++)
{
int in=((k+i)%size);
if(h[in].key==-1 || h[index].key==-2)
{
h[in].key=k;
h[in].value=s;
break;
}

}

}
void display(int size,hashtable h[])
{
for(int i=0;i<size;i++)
{
cout<<i<<"  "<<h[i].key<<"  "<<h[i].value<<endl;

}




}
int search(int size,hashtable h[],int r)
{

for(int i=0;i<size;i++)
{
int in=(r+i)%size;
if(h[in].key==r)
{
cout<<"\n Found";
cout<<h[in].key<<"  "<<h[in].value<<endl;
return(in);
}

else if(h[in].key==-1)
{
cout<<"\n Not Found!! \n";
return(-1);
}



}




}

void delete_(int size,hashtable h[],int r)
{
int pos=(search(size,h,r));
if(pos==-1)
{
cout<<"\n Element not present";

}
else
{
h[pos].key=-2;
h[pos].value=" ";
cout<<"\n Deleted the Key";

}


}
int main()
{
int s;
cout<<"\n Enter the size of the Hash Table";
cin>>s;
hashtable h[s];
for(int i=0;i<s;i++)
{
h[i].key=-1;

}
int ch;
do
{
cout<<"\n 1.Insert ";
cout<<"\n 2.Display ";
cout<<"\n 3.Search ";
cout<<"\n 4.Delete";
cout<<"\n 5.Exit";
cout<<"\n Enter the choice";
cin>>ch;
switch(ch)
{
case 1:insert(s,h);break;
case 2:display(s,h);break;
case 3:{
int r;
cout<<"\n Enter the key to be searched";
cin>>r;
int pos=search(s,h,r);break;}
case 4:{
int r;
cout<<"\n Enter the key to be deleted";
cin>>r;
delete_(s,h,r);break;}
case 5:break;

}

}while(ch!=5);

}

