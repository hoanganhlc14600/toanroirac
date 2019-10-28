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
int n , m, numcolor;
vector<int> a[N];
ii edge[N], bac[N];
string s[N];
int color[N];
bool dd[N];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //make_test();
    freopen("dothitomau.dot", "w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >>edge[i].f >>edge[i].s;
        a[edge[i].f].pb(edge[i].s);
        a[edge[i].s].pb(edge[i].f);
        bac[edge[i].f].f++;
        bac[edge[i].s].f++;
    }
    for (int i = 1; i <= n; ++i) bac[i].s = i;

    sort(bac + 1 , bac + 1 + n);
    numcolor = n;
    for (int i = n; i > 0 ; i--)
    {
        memset(dd, 0 , sizeof(dd));
        int u = bac[i].s;
        for (int j = 0; j < a[u].size(); ++j)
        {
            int v = a[u][j];
            dd[color[v]] = 1;
        }

        for (int j = 1; j <= numcolor; ++j) if (!dd[j]) {
            color[u] = j;
            break;
        }
    }

    cout <<"graph dothi\n" <<"{\n";
    for (int i = 1; i <= n; ++i)
    {
        switch (color[i])
        {
        case 1:
            s[i] = "red1"; break;
        case 2:
            s[i] = "blue1"; break;
        case 3:
            s[i] = "orange1"; break;
        case 4:
            s[i] = "pink1"; break;
        case 5:
            s[i] = "yellow1"; break;
        case 6:
            s[i] = "purple"; break;
        case 7:
            s[i] = "brown"; break;
        case 8:
            s[i] = "grey"; break;
        case 9:
            s[i] = "green1"; break;
        case 10:
            s[i] = "black"; break;
        case 11:
            s[i] = "white"; break;
        case 12:
            s[i] = "tan1"; break;
        case 13:
            s[i] = "salmon1"; break;
        case 14:
            s[i] = "SkyBlue1"; break;
        case 15:
            s[i] = "RoyalBlue1"; break;
        case 16:
            s[i] = "VioletRed"; break;
        case 17:
            s[i] = "plum"; break;
        case 18:
            s[i] = "thistle"; break;
        case 19:
            s[i] = "seashell1"; break;
        case 20:
            s[i] = "WhiteSmoke"; break;
        }

        cout <<i <<" [fillcolor=" <<s[i] <<", style=filled];\n";
    }

    for (int i = 1; i <= m ; ++i) cout <<edge[i].f <<" -- " <<edge[i].s <<";\n";
    cout <<"}";
}
