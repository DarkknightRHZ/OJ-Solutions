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

const int INF = 1e9;

int n;
int ara[405][405];
int parent[405];
bool vis[405];
int level[405];
vector <int> store;

int bfs1(int node, int typ, int dest) {
    memset(vis, 0, sizeof vis);
    int u, v, i, j, lvlU, lvlV;
    queue <PII> q;
    for (i = 1; i <= n; i++) {
        level[i] = -1;
    }
    q.push({node, 0});
    vis[node] = 1;
    parent[node] = -1;
    bool foundDest = 0;
    while (!q.empty()) {
        u = q.front().first;
        lvlU = q.front().second;
        q.pop();
        for (i = 1; i <= n; i++) {
            if (i == u || vis[i]) continue;
            if (ara[u][i] == typ) {
                q.push({i,lvlU+1});
                parent[i] = u;
                vis[i] = 1;
                if (i == dest) {
                    foundDest = 1;
                }
            }
        }
    }
    if (!foundDest) return -1; ///Got a WA for not checking this (if destination reached.)..Silly mistake :-/
    store.clear();
    for (i = dest; i != -1; i = parent[i]) {
        store.PB(i);
    }
    reverse(store.begin(), store.end());
    for (i = 0; i < store.size(); i++) {
        u = store[i];
        level[u] = i;
    }
    return level[dest];
}

int bfs2(int node, int typ, int dest) {
    memset(vis, 0, sizeof vis);
    int u, v, i, j, lvlU, lvlV;
    queue <PII> q;
    q.push({node, 0});
    vis[node] = 1;
    while (!q.empty()) {
        u = q.front().first;
        lvlU = q.front().second;
        q.pop();
        for (i = 1; i <= n; i++) {
            if (i == u || vis[i]) continue;
            if (ara[u][i] == typ && ((level[i] != level[u] + 1) || i == node || i == dest)) {
                vis[i] = 1;
                q.push({i, lvlU + 1});
                if (i == dest) {
                    return lvlU + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    int m, x, y, i, j, ret1 = -1, ret2 = -1;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        ara[x][y] = ara[y][x] = 1;
    }
    x = bfs1(1, 1, n);
    if (x == -1) {
        printf("-1\n");
        //cout << " PAISI " << endl;
        return 0;
    }
    y = bfs2(1, 0, n);
    if (y == -1) {
        printf("-1\n");
        return 0;
    }
    ret1 = max(x, y);
    x = bfs1(1, 0, n);
    y = bfs2(1, 1, n);
    ret2 = max(x, y);
    printf("%d\n", min (ret1, ret2));
    return 0;
}
