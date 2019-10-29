				///************** H.A.N Smile **************///
#include <bits/stdc++.h>
#define f first
#define mp make_pair
#define MOD 1000000007
#define HAN ""
#define ii pair<int , int>
#define lii pair <long long , int>
#define ll long long
#define pb push_back
using namespace std;
const int N = 6e3 + 5;
ifstream fp;
//char s[N][5], p[5], q[5];
string s[N], p , q;
map <string, int> d;
vector<int> a[N];
bool dd[N];
int n, tplt, path[N];
void dfs(int u)
{
    dd[u] = 1;
    for (int i = 0 ;  i < a[u].size(); ++i)
    {
        int v = a[u][i];
        if (!dd[v]) dfs(v);
    }
}

void bfs(int p , int q)
{
    memset(dd, 0 , sizeof(dd));
    queue <int> qu;
    qu.push(p);
    dd[p] = 1;
    while (qu.size())
    {
        int u = qu.front();
        qu.pop();

        for (int i = 0 ; i < a[u].size(); ++i)
        {
            int v = a[u][i];
            if (!dd[v]) {
                path[v] = u;
                dd[v] = 1;
                qu.push(v);
            }
        }
    }
    stack <string> st;
    while(q) st.push(s[q]), q = path[q];
    while (st.size() > 1) cout <<st.top() <<"-->", st.pop();
    cout <<st.top();
}
main()
{
    ios_base::sync_with_stdio(0);
    fp.open("sgb-words.txt");
    while(fp >> s[++n]);
    fp.close();
    n--;
    for (int i = 1; i <= n; ++i){
    d[s[i]] = i;
    for (int j = i + 1; j <= n; ++j)
    {
        int dem = 0;
        for (int k = 0 ; k < 5 ; ++k) dem += (s[i][k] != s[j][k]);
        if (dem == 1) a[i].pb(j), a[j].pb(i);
    }
    }

    for (int i = 1; i <= n; ++i) if (!dd[i]) dfs(i), tplt++;
    printf("So thanh phan lien thong la : %d \n", tplt);
    cin >> p >> q;
    bfs(d[p] , d[q]);
}
