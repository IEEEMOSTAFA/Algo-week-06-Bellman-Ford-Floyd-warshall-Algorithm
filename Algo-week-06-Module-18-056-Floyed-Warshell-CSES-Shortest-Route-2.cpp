/*
There are n
 cities and m
 roads between them. Your task is to process q
 queries where you have to determine the length of the shortest route between two given cities.

Input

The first input line has three integers n
, m
 and q
: the number of cities, roads, and queries.

Then, there are m
 lines describing the roads. Each line has three integers a
, b
 and c
: there is a road between cities a
 and b
 whose length is c
. All roads are two-way roads.

Finally, there are q
 lines describing the queries. Each line has two integers a
 and b
: determine the length of the shortest route between cities a
 and b
.

Output

Print the length of the shortest route for each query. If there is no route, print −1
 instead.

Constraints
1≤n≤500

1≤m≤n2

1≤q≤105

1≤a,b≤n

1≤c≤109

Example

Input:
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2

Output:
5
5
8
-1
3
//query dara bojbo amra koita question korbo...
*/
#include<bits/stdc++.h>
using namespace std;
const int N  = 1e3 + 3;
const long long INF = 1e9;
long long d[N][N];


int main()
{
   int n,m,q;
   cin>>n>>m>>q;

   for(int i= 1;i<=n;i++)
   {
    for( int j=1;j<=n ;j++)
    {
        d[i][j] = INF;
    }
   }

   for(int i=0;i<m;i++)
   {
    int u,v;
    long long w;
    cin>>u>>v>>w;
    d[u][v] = min(d[u][v],w);

    d[v][u] = min(d[v][u],w);// jehoto graph ta bidirectional tai 2 tai likeci

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
for(int i=0;i<q;i++)
{
    int u,v;
    cin>>u>>v;
    if(d[u][v] ==INF)
    {
        cout<<-1<<endl;
    }
    else
    {

       cout<<d[u][v]<<endl;
    }
    
}
return 0;
}