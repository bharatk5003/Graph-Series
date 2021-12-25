
#include<bits/stdc++.h>
using namespace std;
static int edges[101][101];

void BFS(int v,bool *visited,int sv)
{
   queue<int>q;
   q.push(sv);
   visited[sv]=true;

   while(!q.empty())
   {
       int front=q.front();
       q.pop();
       cout<<front<<endl;

       for(int i=0;i<v;i++)
       {
           if(edges[front][i]==1&&visited[i]==false)
           {
               q.push(i);
               visited[i]=true;

           }

       }

   }

}


int main()
{
   int v,e;
   cin>>v>>e;

  // int edges[v+1][v+1];
  memset(edges,0,sizeof(edges));

   for(int i=0;i<e;i++)
   {

       int u,v;
       cin>>u>>v;
       edges[u][v]=1;
       edges[v][u]=1;
   }

   bool visited[v];
   for(int i=0;i<v;i++)
    visited[i]=false;

   for(int i=0;i<v;i++)
   {
      if(visited[i]==false)
      {

          BFS(v,visited,i);
      }

   }


}

