
#include<bits/stdc++.h>
using namespace std;
static int edges[101][101];

void DFS(int v,bool *visited,int sv)
{
    cout<<sv<<endl;
    visited[sv]=true;

    for(int i=0;i<v;i++)
    {

        if(edges[sv][i]==1 && visited[i]==false){
            DFS(v,visited,i);
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

          DFS(v,visited,i);
      }

   }


}
