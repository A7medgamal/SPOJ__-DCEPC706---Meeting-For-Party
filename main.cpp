
/*the trick is to find where they can meet outside the grid So I put two columns and two rows to the grid and run bfs
The storage time of arrival of each person in each cell and the choice of cell shall be found the 3 persons and the least time*/

#include <bits/stdc++.h>
using namespace std;
typedef int  ll;
typedef bitset<15>mask;
#define F first
#define S second
ll n,m,x,y,z,k,sol,sum,ans,l,r,xx,yy,a[1000000],b[1000000],t;
vector<pair<ll,ll>>v1;
vector<ll>v2;
pair<ll,pair<ll,ll> >pp[1000000];
pair<ll,ll>p[1000000];
map<ll,ll>ma;
string s1,s2,s;
ll vis[500][500][5];
char c[500][500];
bool valid(int x,int y)
{
    return (x<=n+1&&x>=0&&y<=m+1&&y>=0&&c[x][y]!='#');
}
void bfs(int x,int y,int h)
{
    queue<pair<ll,ll>>q;
    q.push({x,y});
    int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
    while(!q.empty())
    {
        int fx=q.front().F,fy=q.front().S;
        q.pop();
        for(int i=0;i<=3;i++)
        {
            xx=fx+dx[i];
            yy=fy+dy[i];
            if(!vis[xx][yy][h]&&valid(xx,yy))
            {
               vis[xx][yy][h]=vis[fx][fy][h]+1;
              q.push({xx,yy});
            }
        }
    }
}
int main()
{
//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>t;
    while(t--)
    {
        sol=1e9;
    cin>>n>>m;
    for(int i=0;i<=n+1;i++)
    {
        for(int q=0;q<=m+1;q++)
            c[i][q]='.';
    }
    for(int i=1;i<=n;i++)
    {
        for(int q=1;q<=m;q++)
        {
            cin>>c[i][q];
            if(c[i][q]!='.'&&c[i][q]!='#')
            v1.push_back({i,q});
        }
    }
    for(int i=0;i<v1.size();i++)
        bfs(v1[i].F,v1[i].S,i+1);
   for(int i=0;i<=n+1;i++)
   {
       for(int q=0;q<=m+1;q++)
       {
           if(vis[i][q][1]!=0&&vis[i][q][2]!=0&&vis[i][q][3]!=0)
              sol=min(sol,max(vis[i][q][1],max(vis[i][q][2],vis[i][q][3])));
       }
   }
   v1.clear();
   memset(vis,0,sizeof vis);
   cout<<sol<<endl;
    }


    return 0;
}
