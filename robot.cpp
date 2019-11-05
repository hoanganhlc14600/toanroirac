				///************** H.A.N Smile **************///
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define MOD 1000000007
#define HAN ""
#define ii pair<int , int>
#define lii pair <long long , int>
#define ll long long
#define pb push_back
using namespace std;
const int N = 105;

int path[N][N], a, b , c , d, r , m , n;
ii par[N][N];
vector <ii> ed[N];
void djk(int p)
{
    priority_queue <ii> qu;
    qu.push(mp(0 , p));
    while (qu.size())
    {
        int u = qu.top().s;
        int du = -qu.top().f;
        qu.pop();
        if (du != path[p][u]) continue;
        for (int  i = 0; i < ed[u].size(); ++i){
            int v = ed[u][i].f;
            int dv = ed[u][i].s;
            if (path[p][v] > path[p][u] + dv){
                path[p][v] = path[p][u] + dv;
                qu.push(mp(-path[p][v], v));
            }
        }
    }
}

void setup()
{
    queue <ii> qu;
    qu.push(mp(a, b));
    par[a][b] = mp(-1 , -1);
    while(qu.size())
    {
        int u = qu.front().f;
        int v = qu.front().s;
        qu.pop();
        for (int i = 0 ; i < ed[u].size(); ++i)
        {
            int uu = ed[u][i].f;
            if (par[uu][v] == mp(0, 0) && path[uu][v] > r) {
                par[uu][v] = mp(u, v);
                qu.push(mp(uu,v));
            }
        }

        for (int i = 0; i < ed[v].size(); ++i)
        {
            int vv = ed[v][i].f;
            if (par[u][vv] == mp(0 , 0) && path[u][vv] > r){
                par[u][vv] = mp(u, v);
                qu.push(mp(u, vv));
            }
        }

        if(par[c][d] != mp(0 , 0)) break;
    }
}

void in()
{
    stack <ii> st;
    while (mp(c,d) != mp(-1, -1)){
        st.push(mp(c,d));
        int x = par[c][d].f;
        int y = par[c][d].s;
        c = x;
        d = y;
    }
    cout <<"Lich di chuyen" <<"    " <<"Khoang cach\n";
    while(st.size())
    {
        cout <<st.top().f <<" " <<st.top().s <<"                " <<path[st.top().f][st.top().s] <<"\n";
        st.pop();
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x , y , z;
        cin >> x >> y >> z;
        ed[x].pb(mp(y,z));
        ed[y].pb(mp(x,z));
    }
    memset(path, 60 , sizeof(path));
    cin >> a >> b >> c >> d >>r;
    for (int i = 0; i < n; ++i) path[i][i] = 0;

    for (int i = 0; i < n; ++i) djk(i);
    setup();
    if (par[c][d] == mp(0 , 0)) cout <<"Khong the!!";
    else in();
}
