#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
int h[10001],nxt[130001],v[130001],n,m;
float p[130001],w[130001],d[130001],low,high,mid;
bool in[130001],flag;
void dfs(int now)
{
    in[now]=1;
    for(int i=h[now];i;i=nxt[i])
      if(d[now]+p[i]*mid-w[i]<=d[v[i]])
      {
        if(in[v[i]]){flag=0;return;}
        d[v[i]]=d[now]+p[i]*mid-w[i];
        dfs(v[i]);
        if(!flag)return;
      }
    in[now]=0;
}
void init()
{
    scanf("%d%d",&n,&m);
    int i,j,k;
    for(j=1;j<=m;j++)
    {
        scanf("%d%d%f%f",&i,v+j,w+j,p+j);
        if(i!=v[m])
        {
          nxt[j]=h[i];
          h[i]=j;
        }
    }
    for(i=1;i<=n;i++)
    {
        v[i+m]=i;
        nxt[i+m]=h[0];
        h[0]=i+m;
    }
}
int main()
{
    init();
    low=0;
    high=200;
    while(low+0.01<high)
    {
        mid=(low+high)/2;
        flag=1;
        memset(in,0,sizeof(in));
        memset(d,127,sizeof(d));
        d[0]=0;
        dfs(0);
        if(!flag)low=mid;
        else high=mid;
    }
    if(low==0)printf("-1");
    else printf("%.5f",high);
    return 0;
}