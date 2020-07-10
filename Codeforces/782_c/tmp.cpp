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

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const int mx = 2 * (1e5 + 5);

bool vis[mx];

int color[mx];

vector <int> vi[mx];

void dfs(int node, int clr) {
    vis[node] = 1;
    int i, j, x, y, u, v;
    int cl = 1;
    for (i = 0; i < vi[node].size(); i++) {
        u = vi[node][i];
        if (!vis[u]) {
            if (cl == color[node] || cl == clr) cl++;
            if (cl == clr || cl == color[node]) cl++;
            color[u] = cl++;
            dfs(u, color[node]);
        }
    }
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int n, i, j, x, y, cnt;
    scanf("%d", &n);
    for (i = 0; i < n - 1; i++) {
        scanf("%d %d", &x, &y);
        vi[x].PB(y);
        vi[y].PB(x);
    }
    color[1] = 1;
    memset(vis, 0, sizeof vis);
    dfs(1, 0);
    cnt = 0;
    memset(vis, 0, sizeof vis);
    for (i = 1; i <= n; i++) {
        if (!vis[color[i]]) {
            cnt++;
            vis[color[i]] = 1;
        }
    }
    printf("%d\n", cnt);
    for (i = 1; i <= n; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
    return 0;
}
