				///************** Nguyen Hoang Anh - 20180010 - KHMT 04 - K63 **************///
#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define MOD 1000000007
#define HAN ""
#define ii pair <int , int>
#define lii pair <long long , int>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e5 + 5, M = 1e4 + 5;
int n, h[3];
bool dd[N];
ii prf[M];

bool dfs(int a, int b , int c)
{
    if (b == 2 || c == 2) return 1;
    int x , y , z;
    if (b){
    x = min(a + b , 10);
    y = b - (x - a);
    z = x*h[0] + y*h[1] + c*h[2];

    if (!dd[z])
    {
        dd[z] = 1;
        if (dfs(x, y , c)) {
            prf[++n] = mp(2 , 1);
            return 1;
        }
    }

    x = min (c + b , 4);
    y = b - (x - c);
    z = a*h[0] + y*h[1] + x*h[2];

    if (!dd[z])
    {
        dd[z] = 1;
        if (dfs(a , y , x)){
            prf[++n] = mp(2 ,3);
            return 1;
        }
    }
    }

    if (c){
    x = min(a + c , 10);
    y = c - (x - a);
    z = x*h[0] + b*h[1] + y*h[2];
    if (!dd[z])
    {
        dd[z] = 1;
        if (dfs(x, b, y)){
            prf[++n] = mp(3 , 1);
            return 1;
        }
    }

    x = min(b + c , 7);
    y = c - (x - b);
    z = a*h[0] + x*h[1] + y*h[2];
    if (!dd[z])
    {
        dd[z] = 1;
        if (dfs(a, x, y)){
            prf[++n] = mp(3, 2);
            return 1;
        }
    }
    }

    if(a){
        x = min(b + a, 7);
        y = a - (x - b);
        z = y*h[0] + x*h[1] + c*h[2];
        if (!dd[z])
        {
            dd[z] = 1;
            if (dfs(y, x , c)){
                prf[++n] = mp(1 , 2);
                return 1;
            }
        }

        x = min(c + a, 4);
        y = a - (x - c);
        z = y*h[0] + b*h[1] + x*h[2];
        if (!dd[z])
        {
            dd[z] = 1;
            if (dfs(y, b ,x)){
                prf[++n] = mp(1, 3);
                return 1;
            }
        }
    }
    return 0;
}
void in()
{
    printf("Co dap an !! \n");
    for (int i = n ; i > 0; --i) printf("Do nuoc tu binh %d sang binh %d\n", prf[i].f, prf[i].s);
}
main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    //make_test();
    //freopen(HAN".inp", "r", stdin);
    //freopen(HAN".out", "w", stdout);
    h[0] = 97*97, h[1] = 97, h[2] = 1;
    dd[7*h[1] + 4*h[2]] = 1;
    if (dfs(0 , 7 , 4)) in();
    else printf("Khong co phuong an nao !!!");
}
