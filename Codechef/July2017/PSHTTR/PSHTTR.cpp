
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

//int edge[1005][1005];
map <PII, int> mp;
int parent[mx];
bool vis[mx];
int L[mx];
int P[mx][22];
int T[mx];

vector <int> g[mx];

void dfs(int from,int u,int dep)
{
    T[u]=from;
    L[u]=dep;
    for(int i=0;i<(int)g[u].size();i++)
    {
        int v=g[u][i];
        if(v==from) continue;
        dfs(u,v,dep+1);
    }
}

int lca_query(int N, int p, int q)
  {
      int tmp, log, i;

      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;

        log=1;
      while(1) {
        int next=log+1;
        if((1<<next)>L[p])break;
        log++;

      }

        for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];

      if (p == q)
          return p;

        for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];

      return T[p];
  }

void lca_init(int N)
  {
      memset (P,-1,sizeof(P));
      int i, j;
       for (i = 0; i < N; i++)
          P[i][0] = T[i];

      for (j = 1; 1 << j < N; j++)
         for (i = 0; i < N; i++)
             if (P[i][j - 1] != -1)
                 P[i][j] = P[P[i][j - 1]][j - 1];
}


void dfs1 (int x) {
    if (vis[x]) return;
    vis[x] = 1;
    int i, j, u, v;
    for (i = 0; i <g[x].size(); i++) {
        v = g[x][i];
        if (!vis[v]) {
            parent[v] = x;
            dfs1 (v);
        }
    }
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t, n, m, u, v, k, c, i, j, x, y, xr;
    scanf("%d", &t);
    while(t--) {
        for (i = 0; i < mx; i++) {
            g[i].clear();
        }
        scanf("%d", &n);
        mp.clear();
        for (i = 0; i < n-1; i++) {
            scanf("%d %d %d", &u, &v, &c);
            u--, v--;
            g[u].PB(v);
            g[v].PB(u);
            //edge[u][v] = edge[v][u] = c;
            mp[{u,v}] = c;
            mp[{v,u}] = c;
        }
        memset (parent, -1, sizeof parent);
        memset (vis, 0, sizeof vis);
        dfs1 (0);
        dfs (0, 0, 0);
        lca_init(n);
        scanf ("%d", &m);
        for (i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &k);
            u--, v--;
//            cout << u << " " << v << " " << k << endl;
            x = lca_query(n, u, v);
            xr = 0;
            for (j = u; j != x && parent[j] != -1; j = parent[j]) {
                y = parent[j];
                if (mp[{j,y}] <= k) {
                    xr ^= mp[{j,y}];
                }
            }
            for (j = v; j != x && parent[j] != -1; j = parent[j]) {
                y = parent[j];
                if (mp[{j,y}] <= k) {
                    xr ^= mp[{j,y}];
                }
            }
            printf ("%d\n", xr);
        }
    }
    return 0;
}

