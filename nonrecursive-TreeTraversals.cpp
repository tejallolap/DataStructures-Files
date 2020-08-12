
/* Assignment 2: Construct an expression tree from postfix expression and perform non-recursive Inorder and
Preorder traversals */

#include<iostream>
#include<string.h>
using namespace std;
class treenode
{
    friend class stacknode;
public:
    char exp;
    treenode *lptr;
    treenode *rptr;
public:
    /*treenode()
    {
        exp='0';
        lptr=rptr=NULL;
    }*/
    treenode* create(char x)
    {
        treenode *a;
        a=new treenode;
        a->exp=x;
        a->lptr=NULL;
        a->rptr=NULL;
        return(a);
    }

};

class node
{
    friend class stacknode;
private:
    treenode *data;
    node *link;

};

class stacknode
{
    node *top;
public:
    stacknode()
    {
        top=NULL;
    }
    void push(treenode *a)
    {
        node *stackptr=new node;
        stackptr->data=a;
        //cout<<"\n Pushed"<<(stackptr->data)->exp;
        //cout<<"\n Left and Right Child"<<((stackptr->data)->lptr)->exp;
        stackptr->link=NULL;
        if(top==NULL)
        {
            top=stackptr;
        }
        else
        {
            stackptr->link=top;
            top=stackptr;
        }


    }
    treenode* pop()
    {

        node *temp=top;
        top=top->link;
        //cout<<"\n Popped"<<(temp->data)->exp;
        treenode *a=temp->data;
        delete(temp);
        return (a);
    }
    
    void traversal()
    {   treenode *temp=top->data;
        cout<<"\n The Infix Expression is:";
        inorder(temp);
        cout<<"\n The PreFix Expression is:";
        preorder(temp);
       }
       
    void inorder(treenode *a)
    {   top=NULL;
        while(1)
        {
            while(a)
            {
                push(a);
                a=a->lptr;
            }
            if(top==NULL)
                break;
            a=pop();
            cout<<" "<<a->exp;
            a=a->rptr;


        }

    }
    void preorder(treenode *a)
    {
        top=NULL;
        while(1)
        {
            while(a)
            {
                push(a);
                cout<<" "<<a->exp;
                a=a->lptr;
            }
            if(top==NULL)
                break;
            a=pop();
            a=a->rptr;

        }
    }



};
int main()
{   stacknode sn;
    char s[50];
    cout<<"\n Enter the Postfix Expression: "<<endl;
    cin>>s;
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(s[i]=='+' || s[i]=='-'  || s[i]=='*'  || s[i]=='/')
        {
            treenode *a;
            treenode *r,*l;
            treenode tn;
            a=tn.create(s[i]);
            r=sn.pop();
            l=sn.pop();
            a->rptr=r;
            a->lptr=l;
            sn.push(a);

        }
        else
        {
            treenode tn;
            treenode *a;

            a=tn.create(s[i]);
            sn.push(a);
        }
    }
    sn.traversal();

}

/* Output - Enter the Postfix Expression ab+cd*-

 The Infix Expression is: a + b - c * d
 The PreFix Expression is: - + a b * c d
 */
