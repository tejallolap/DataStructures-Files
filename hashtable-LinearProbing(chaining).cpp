
/*Assignment 9 - Implement all the functions of a dictionary (ADT) using hashing. Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique Standard Operations: Insert(key, value), Find(key), Delete(key) (use linear probing with chaining) */



#include<iostream>

#include<string>

using namespace std;


class hashing

{

typedef struct node

{

string word;

string meaning;

struct node* next;

}node;

node *New,*temp;

int i;

node *arr[10];

public:

hashing()

{

i=0;

New=temp=NULL;

for(int i=0;i<10;i++)

{

arr[i]=NULL;

}



}


void input()

{

char ans;

do

{

New=new node;

New->next=NULL;

cout<<"\nEnter word :";

cin>>New->word;

cout<<"\nEnter meaning :";

cin>>New->meaning;


int x=hash(New->word);


if(arr[x]==NULL)

arr[x]=New;

else

{

temp=arr[x];

while(temp->next!=NULL)

temp=temp->next;

temp->next=New;

}


cout<<"\nContinue?";

cin>>ans;

}while(ans=='y');
}

void deletefunc()

{

string delword;

int flag=0;

cout<<"\nEnter the word to be deleted :"; cin>>delword;

int x=hash(delword);

temp=arr[x];


while(temp!=NULL && temp->word!=delword)

{

temp=temp->next;


}


if(temp==NULL)

cout<<"\nWord not present in dictionary.\n"; else

{

node *p;

if(flag==0)

{

p=temp;

temp=temp->next;

arr[x]=temp;

delete(p);

display();

}

else

{


p=temp->next;

temp->next=(temp->next)->next;

delete(p);

display();

}

}


}


int hash(string word)

{

int i=0,sum=0,x=0;


while(i<word.length())

{

x=word[i];

sum+=x;

i++;

}

sum=sum%10;

return sum;

}





void search()

{

string person;

cout<<"\nEnter the word to find it's meaning :"; cin>>person;
 

int x=hash(person);

temp=arr[x];


while(temp!=NULL && temp->word!=person)

temp=temp->next;


if(temp==NULL)

cout<<"\nWord not present in dictionary.\n"; else

cout<<"Required meaning is :"<<temp->meaning;


}





void display()

{


int j=0;

while(j<10)

{

temp=arr[j];

if(temp==NULL)

{

j++;

continue;

}

else

{

while(temp!=NULL)

{

cout<<temp->word<<"\t";
 

cout<<temp->meaning<<endl;

temp=temp->next;

}

}

j++;

}

}

};

int main()

{

hashing s;

s.input();

s.display();

s.deletefunc();

s.search();

return 0;

}


