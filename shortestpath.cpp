
/* Assignment 7 : A Customer wants to travel from source A to destination B , he books a cab from source A to reach destination B 
calculate a shortest path by avoiding real time traffic to reach destination B*/

#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
int min(int dis[],int n,int vis[])
{
int m,i,j;
m=32767;
for(i=0;i<n;i++)
{
if(dis[i]<=m && vis[i]==0)
{
m=dis[i];
j=i;
}
}
return j;
}

int main()
{

vector <int>v;
vector<int>::iterator it;

int n,i,j,u;
char ch;
cout<<"Enter the number of vertices\n";
cin>>n;
int arr[n][n],dest,source=0;

cout<<"Enter the destination\n";
cin>>dest;

do
{
cout<<"Source:"<<source<<"\n";
v.clear();
cout<<"Enter the adjecancy matrix w.r.t time\n";
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
  cin>>arr[i][j];
 }
}

cout<<"Entered matrix is:\n";
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 {
  cout<<""<<arr[i][j]<<"\t";
 }
cout<<"\n";
}

int count=1;

int vis[n],dis[n],parent[n];

for(i=0;i<n;i++)
{
vis[i]=0;
dis[i]=32767;
parent[i]=0;
}
dis[source]=0;
parent[source]=-1;
cout<<"Parent of source:"<<parent[source]<<"\n";

cout<<"\n";
while(count<=n)
{
u=min(dis,n,vis);
vis[u]=1;


for(j=0;j<n;j++)
{
  if(arr[u][j]!=0 && dis[j]> dis[u]+arr[u][j])
  {
    dis[j]=dis[u]+arr[u][j];
    parent[j]=u;
  }
}




//cout<<"u:"<<u<<"\n";
if(u==dest)
{
while(parent[u]!=-1)
{
    v.push_back(u);
    u=parent[u];
}
v.push_back(source);
it=v.end();
it--;
while(it!=(v.begin()--))
{
    cout<<""<<*it<<" -\t";
    it--;
}
cout<<""<<*it<<"\n";
}

count++;
}

//cout<<"After using Dijkstra's algorithm:\n";
if(u==dest)
{
    cout<<""<<u<<" : "<<dis[u]<<"\n";
}


it=v.end();
it--;
while(it!=(v.begin()-1))
{
cout<<"Has the traffic conditions changed?\n";
cin>>ch;
if(ch=='y' || ch=='Y')
{
   
 source=*it;
 //cout<<"Source:"<<source<<"\n";
 break;
}
else
{
    if(*it==dest)
    {
        cout<<"You have reached your destintion\n";
        exit(1);
    }
    it--;
    cout<<""<<*it<<"\n";
    continue;
}
}
}while(1);

return 0;
}

