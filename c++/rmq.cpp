#include <bits/stdc++.h>

using namespace std;
ifstream f("rmq.in");
ofstream g("rmq.out");
int n,m,p;
vector<vector<int>> rmq;
void citire(),add_line(int);

int main()
{
    citire();
    for(int i=1;(1<<i)<=n;i++)
        add_line(i);
    for(;m;m--)
    {
        int x,y,lg,i;
        f>>x>>y;
        lg=y-x+1;
        i=31-__builtin_clz(lg);
        lg=1<<i;
        g<<min(rmq[i][x],rmq[i][y-lg+1])<<'\n';

    }
    return 0;
}
void citire()
{
    f>>n>>m;
    vector<int> x(n+5,0);
    for(int i=1;i<=n;i++)
        f>>x[i];
    rmq.push_back(x);

}
void add_line(int i)
{
    vector<int> x(n+5,0);
    int st=1,dr=1<<i,mi;
    mi=dr/2+1;
    for(;dr<=n;st++,mi++,dr++)
        x[st]=min(rmq[i-1][st],rmq[i-1][mi]);
    rmq.push_back(x);
}
