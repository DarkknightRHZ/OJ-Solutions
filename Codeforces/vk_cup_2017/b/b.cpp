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

const int mx = 150005;

bool vis[mx];
bool vis2[mx];
//int rnk[mx];
//int parent[mx];
//
//int findParent(int id) {
//    if (parent[id] == id) return id;
//    return parent[id] = findParent(parent[id]);
//}
//
//void unite(int idx, int idy) {
//    if (idx == idy) return;
//    if (rnk[idx] > rnk[idy]) {
//        parent[idy] = idx;
//    }
//    else parent[idx] = idy;
//    if (rnk[idx] == rnk[idy]) {
//        rnk[idy]++;
//    }
//}
//
//int has[mx];

vector <int> vi[mx];
bool tr;

void dfs(int id, int sz) {
    vis[id] = 1;
    if (vi[id].size() != sz) tr = 0;
    int i, v;
    for (i = 0; i < vi[id].size(); i++) {
        v = vi[id][i];
        if (!vis[v]) {
            dfs(v, sz);
        }
    }
}

int dfs2 (int id) {
    vis2[id] = 1;
    int i, v, ret = 1;
    for (i = 0; i < vi[id].size(); i++) {
        v = vi[id][i];
        if (!vis2[v]) {
            ret += dfs2(v);
        }
    }
    return ret;
}

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    int n,m, i, j, x, y, px, py;
    set <int> :: iterator it, it2;
    scanf("%d %d", &n, &m);
//    for (i = 1; i <= n; i++) {
//        parent[i] = i;
//    }
    for (i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        vi[x].PB(y);
        vi[y].PB(x);
//        px = findParent(x);
//        py = findParent(y);
//        has[x] = 1;
//        has[y] = 1;
//        unite(px, py);
    }
//    for (i = 1; i <= n; i++) {
//        cout << parent[i] << " " << i<< endl;
//    }
//    int cnt = 0;
//    for (i = 1; i <= n; i++) {
//        if (parent[i] == i && has[i]) {
//            cnt++;
//            if (cnt > 1) break;
//        }
//
//    }
////    cout << cnt << endl;
//    if (cnt > 1) printf("NO\n");
//    else printf("YES\n");
//    for (i = 1; i <= n; i++) {
//        sort(vi[i].begin(), vi[i].end());
//    }
    tr = 1;
    memset(vis, 0, sizeof vis);
    memset(vis2, 0, sizeof vis2);
    for (i = 1; i <= n; i++) {
        if (!vis[i]) {
            int sz = dfs2(i);
            dfs(i, sz-1);
        }
    }
    if (!tr) {
        printf("NO\n");
    }
    else printf("YES\n");
    return 0;
}
