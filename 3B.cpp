				///************** H.A.N Smile **************///
#include <bits/stdc++.h>
#define f first
//#define s second
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
vector <int> a[N];
stack <int> st;
map <string, int> d;
string s[N];
int n, dem[N], low[N], num[N], fre[N], snt, tplt, path[N];
bool dd[N];
void visit(int u)
{
    st.push(u);
    num[u] = low[u] = ++snt;

    for (int i = 0; i < a[u].size(); ++i)
    {
        int v = a[u][i];
        if (!num[v]) {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!fre[v]) low[u] = min(low[u], low[v]);
    }

    if (low[u] == num[u])
    {
        tplt++;
        while(st.top() != u) {
            int v = st.top();
            fre[v] = tplt;
            st.pop();
        }
        fre[u] = tplt;
        st.pop();
    }
}
void timtplt()
{
    for (int i = 1; i <= n; ++i) if(!num[i]) visit(i);

    cout <<"So thanh phan lien thong manh la : " <<tplt <<"\n";
}
void phanb()
{
    string c;
    cin >> c;
    queue <string> ans;
    int u = d[c];
    for (int i = 1; i <= n; ++i) if (i != u && fre[u] == fre[i])
        ans.push(s[i]);
    cout <<"Nhung tu cung thanh phan lien thong voi " <<c <<" la: ";
    //cout <<ans.size() <<endl;
    while (ans.size())
    {
        cout <<ans.front() <<", ";
        ans.pop();
    }
    cout <<"\n";
}

void bfs(int p , int q)
{
    queue <int> qu;
    qu.push(p);
    dd[p] = 1;
    while (qu.size())
    {
        int u = qu.front();
        qu.pop();
        for (int i = 0; i < a[u].size(); ++i){
            int v = a[u][i];
            if (!dd[v]){
                path[v] = u;
                dd[v] = 1;
                qu.push(v);
            }
        }
    }

    stack <string> ans;
    while(q) ans.push(s[q]), q = path[q];
    while(ans.size() > 1) cout <<ans.top() <<" --> ", ans.pop();
    cout <<ans.top();
}

void phanc()
{
    string u , v;
    cin >> u >> v;
    bfs(d[u], d[v]);
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
    memset(dem , 0 , sizeof(dem));
    for (int j = 1 ; j < 5 ; ++j) dem[s[i][j]]++;
    for (int j = 1; j <= n; ++j) if (i != j)
    {
        int p = 0;
        for (int k = 0 ; k < 5 ; ++k) if (dem[s[j][k]]){
            p++;
            dem[s[j][k]]--;
            st.push(s[j][k]);
        }
        if (p == 4) a[i].pb(j);
        while(st.size()) {
            int u = st.top();
            st.pop();
            dem[u]++;
        }
    }
    }
    timtplt();
    phanb();
    phanc();
}
