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
const int N = 1e5 + 5;

void make_test()
{
	freopen(HAN".inp", "w", stdout);
	srand(time(0));
}
int d[N], n, dem;
priority_queue <ii> qu;
vector <int> a[N];
bool dd[N];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //make_test();
    //freopen(HAN".inp", "r", stdin);
    //freopen(HAN".out", "w", stdout);
    cin >> n;

    for (int i = 1 ; i <= n ; ++i)
    {
        int x , y;
        cin >> x >> y;
        d[x]++;
        d[y]++;
        a[x].pb(y);
        a[y].pb(x);
    }
    for (int i = 1 ; i <= n ; ++i) qu.push(ii(-d[i], -i));
    while (qu.size())
    {
        if (dem == n - 1) exit(0);
        int u = -qu.top().s;
        qu.pop();
        if (dd[u]) continue;
        dd[u] = 1;
        for (int i = 0 ; i < a[u].size(); ++i)
        {
            int v = a[u][i];
            if (!dd[v]) {
                cout <<v <<" ";
                d[v]--, dem++;
                if (v != 0) qu.push(ii(-d[v], -v));
                break;
            }
        }
    }
}
