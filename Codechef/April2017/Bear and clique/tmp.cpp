
/**


  ######                                                                     ######   #     #  #######
  #     #    ##    #####   #    #  #    #  #    #  #   ####   #    #  #####  #     #  #     #       #
  #     #   #  #   #    #  #   #   #   #   ##   #  #  #    #  #    #    #    #     #  #     #      #
  #     #  #    #  #    #  ####    ####    # #  #  #  #       ######    #    ######   #######     #
  #     #  ######  #####   #  #    #  #    #  # #  #  #  ###  #    #    #    #   #    #     #    #
  #     #  #    #  #   #   #   #   #   #   #   ##  #  #    #  #    #    #    #    #   #     #   #
  ######   #    #  #    #  #    #  #    #  #    #  #   ####   #    #    #    #     #  #     #  #######



**/
/*

    BismiLLAHIR RAHMANIR RAHIM
    It's not how you look or who you are underneath, it's what you do that defines you

                                ------********-------

    Status : ;
    TC: xxx/xxx;
    DOS: ;
    OJ: ;

*/

#include <bits/stdc++.h>

using namespace std;

#define PB          push_back
#define PF          push_front
#define  V          vector
#define PII         pair <int,int>
#define PLL         pair <LL,LL>
#define PLLL        pair < LL, PLL >

//typedef unsigned long           LL;
typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const LL mx = 1e5 + 5;
const LL INF = 10000000000000005;

LL n, k, x, m, s;

vector < PLLL > lst;
vector < PLL > vp[mx];

LL ds[mx];
LL ds2[mx];

void dijkastra(LL X)
{
    priority_queue <PLL, vector <PLL>, greater <PLL> > que;
    LL u,v,i,j;
    LL d;
    for (i = 0; i <= n;i++) ds[i] = INF;
    ds[X] = 0LL;
    que.push({0LL,X});
    while (!que.empty())
    {
        u = que.top().second;
        que.pop();
        for (i=0; i<vp[u].size();i++)
        {
            v = vp[u][i].second;
            d = vp[u][i].first;
            if (ds[v] > (ds[u] + d))
            {
                ds[v] = ds[u] + d;
                que.push({ds[v],v});
            }
        }
    }
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL t, cnt, i, j, u, v, w, mn, mnId;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld %lld %lld %lld", &n, &k, &x, &m, &s);
        lst.clear();
        for (i = 0; i < m; i++) {
            scanf("%lld %lld %lld", &u, &v, &w);
            lst.PB({w, {u, v}});
        }
        if (s > k) {
            for (i = 0; i <= n; i++) {
                vp[i].clear();
            }
            for (i = 0; i < lst.size(); i++) {
                w = lst[i].first;
                u = lst[i].second.first;
                v = lst[i].second.second;
                vp[u].PB({w,v});
                vp[v].PB({w,u});
            }
            dijkastra(s);
            mn = INF, mnId = -1;
            for (i = 1; i <= k; i++) {
                if (mn > ds[i]) {
                    mn = ds[i];
                    mnId = i;
                }
            }
            for (i = 1; i <= k; i++) {
                if (i != mnId) {
                    vp[i].PB({x, mnId});
                    vp[mnId].PB({x, i});
                }
            }
            dijkastra(s);
        }
        else {
            for (i = 0; i <= n; i++) {
                vp[i].clear();
            }
            for (i = 0; i < lst.size(); i++) {
                w = lst[i].first;
                u = lst[i].second.first;
                v = lst[i].second.second;
                vp[u].PB({w,v});
                vp[v].PB({w,u});
            }
            for (i = 1; i <= k; i++) {
                if (i != s) {
                    vp[i].PB({x,s});
                    vp[s].PB({x,i});
                }
            }
            dijkastra(s);
        }
        for (i = 1; i <= n; i++) {
            printf("%lld ", ds[i]);
        }
        printf("\n");
    }
    return 0;
}

