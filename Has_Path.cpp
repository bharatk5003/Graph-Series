

#include<bits/stdc++.h>
using namespace std;
static int edges[101][101];

bool Has_Path(int v,int sv,int ev,bool *visited)
{
    visited[sv]=true;
   if(sv==ev)
    return true;

    bool ans=false;

    for(int i=0;i<v;i++)
    {
        if(edges[sv][i]==1 && visited[i]==false)
        {
            ans=Has_Path(v,i,ev,visited);

            if(ans==true)
                return ans;
        }

    }
    return ans;


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


   bool ans=Has_Path(v,0,5,visited)


}
