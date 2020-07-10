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

typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

#define mx 100005

int L[mx];
bool vis[mx];
int subSetSize[mx];
int P[mx][22];
int T[mx];
vector<int>g[mx];

void buildSet(int id) {
    vis[id] = 1;
    int i, j, v, ret = 1;
    for (i = 0; i < g[id].size(); i++) {
        v = g[id][i];
        if (!vis[v]) {
            buildSet(v);
            ret += subSetSize[v];
        }
    }
    subSetSize[id] = ret;
}

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

int findAncestor(int id, int lvl) {
    int tmp, log = 1, i;  // Gpt runtime error for not assigning any value to log
    while(1) {
        int next=log+1;
        if((1<<next)>L[id])break;
        log++;

      }
    for (i = log; i >= 0; i--)
        if (L[id] - (1 << i) >= lvl)
            id = P[id][i];
    return id;
}

int solve(int n, int x, int y) {
    int lca, i, j, distX, distY, distXY, ret1, ret2;
    lca = lca_query(n,x,y);
    distXY = L[x] + L[y] - 2 * L[lca];
    //cout << distXY << endl;
    if (distXY & 1) return 0;
    if (L[x] == L[y]) {
//        cout << L[lca] << " " << L[x] << endl;
        ret1 = findAncestor(x, L[lca] + 1);
        ret2 = findAncestor(y, L[lca] + 1);
//        cout << ret1 <<  " " << ret2 << endl;
        return n - subSetSize[ret1] - subSetSize[ret2];
    }
    else {
        if (L[x] < L[y]) swap(x,y);
        distX = distXY / 2;
        ret1 = findAncestor(x, L[x] - distX);
        ret2 = findAncestor(x, L[x] - distX + 1);
        return subSetSize[ret1] - subSetSize[ret2];
    }
}

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    int n, m, q, i, j, x, y;
    scanf("%d", &n);
    for (i = 0; i < n - 1; i++) {
        scanf("%d %d", &x, &y);
        x--; y--;
        g[x].PB(y);
        g[y].PB(x);
    }
    dfs(0,0,0);
    memset(vis, 0, sizeof vis);
    buildSet(0);
    lca_init(n);
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &x, &y);
        if (x == y) {
            printf("%d\n", n);
            continue;
        }
        printf("%d\n", solve(n,x - 1,y - 1));
    }
    return 0;
}
