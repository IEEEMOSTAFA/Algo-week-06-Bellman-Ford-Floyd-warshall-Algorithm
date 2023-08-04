/*
Input-> A weighted graph as an adjacency matrix 
Output-> All  pair Shortest distance.

Time Complexity: O(v^3)
Space Complexity: O(v^2)

-Create a distance_matrix "d" where there is a direct from node " i" to node "j" and cost is "X"

-for all node " i" d[i][i] = 0;
-for all node "i" & "j" where there isn't any direct edge from "i" to "j"   d[i][j] = INF
-for all node "k" ->O(1)
 -for all node " U"  ->O(1)
   -for all node "V" ->O(1)

     d[U][V] = min(d[U][V],d[u][k]+ d[k][v])     => O(1)

-Output all pair shortest distance "d"


>>>>For all pair shortest :we use Floyed Warshell Algorithm

*/
#include<bits/stdc++.h>
using namespace std;
const int N  = 1e3 + 3;
const int INF = 1e9;
int d[N][N];


int main()
{
   int n,m;
   cin>>n>>m;

   for(int i= 1;i<=n;i++)
   {
    for( int j=1;j<=n ;j++)
    {
        d[i][j] = INF;
    }
   }
   for(int i=0;i<m;i++)
   {
    int u,v,w;
    cin>>u>>v>>w;
    d[u][v] = w;
   }

   for (int  i = 1; i <=n; i++)
   {
    d[i][i] = 0;

   }
   
for(int k=1 ;k<=n;k++)
{
    for(int u = 1;u<=n;u++)  // u and v er node ta all pair node er junno
    {
        for(int v =1;v<=n;v++)
        {
            d[u][v] = min(d[u][v],d[u][k]+ d[k][v]);
        }
    }
}
for (int  i = 1; i<=n; i++)
{
    for (int j = 1; j <=n; j++)
    {
      cout<<d[i][j]<<" ";
    }
    cout<<endl;
    
}
return 0;
}