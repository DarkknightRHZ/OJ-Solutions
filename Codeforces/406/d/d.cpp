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

typedef long long int           LL;
#define PB          push_back
#define PF          push_front
#define  V          vector
#define PII         pair <int,int>
#define PLI         pair <LL,int>


const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const LL INF = 10000000000000000;
LL ds[100005];
int n;
vector <PLI> vp[100005];
priority_queue <PLI, vector <PLI>, greater <PLI> > que;

void dijkastra(int x)
{
    int u,v,i,j;
    LL d;
    ds[x] = 0LL;
    while (!que.empty()) que.pop();
    que.push({0LL,x});
    while (!que.empty())
    {
        u = que.top().second;
        que.pop();
        for (i=0;i<vp[u].size();i++)
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
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    int n, q, s, i, j, a, b, p, u, x, y, v;
    LL w;
    scanf("%d %d %d", &n, &q, &s);
    for (i = 0; i < q; i++) {
        scanf("%d", &p);
        if (p == 1) {
            scanf("%d %d %I64d", &u, &v, &w);
            if (u != v)
            vp[u].PB({w,v});
//            vp[v].PB({w,u});
        }
        else if (p == 2) {
            scanf("%d %d %d %I64d", &u, &x, &y, &w);
            for (j = x; j <= y; j++) {
                if (u != j)
                vp[u].PB({w, j});
            }
        }
        else if (p == 3) {
            scanf("%d %d %d %I64d", &v, &x, &y, &w);
            for (j = x; j <= y; j++) {
                if (j != v)
                vp[j].PB({w, v});
            }
        }
    }
    for (i = 0; i < 100005; i++) ds[i] = INF;
    dijkastra(s);
    for (i = 1; i <= n; i++) {
        if (ds[i] == INF) {
            printf("-1 ");
        }
        else {
            printf("%I64d ", ds[i]);
        }
    }
    printf("\n");
    return 0;
}
