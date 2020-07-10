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

/**
    solution hint:
        1) do union of all connected components
        2) find the diameters of each components (use two way dfs for it)
        3) for type 1 query, print the diameter of the component, for
        type 2 query, union both components and the resulting components diameter
        is = max(diameter1, diameter1, ceil(diameter1/2) + ceil(diameter2/2) + 1)
**/

const int mx = 3 * (1e5 + 5);

vector <int> vi[mx];
vector <int> store;
int parent[mx];
bool vis[mx];
bool vis2[mx];
int rnk[mx];
int diameter[mx];

int findParent(int id) {
    if (parent[id] == id) return id;
    return parent[id] = findParent(parent[id]);
}

void unite(int idx, int idy) {
    if (idx == idy) return;
    if (rnk[idx] > rnk[idy]) {
        parent[idy] = idx;
    }
    else parent[idx] = idy;
    if (rnk[idx] == rnk[idy]) {
        rnk[idy]++;
    }
}

pair <int, int> dfs (int id) {
    vis[id] = 1;
    store.PB(id);
    pair <int, int> ret, tmp;
    ret = {id, 0};
    int i, j, v;
    for (i = 0; i < vi[id].size(); i++) {
        v = vi[id][i];
        if (!vis[v]) {
            tmp = dfs(v);
            if (tmp.second > ret.second) {
                ret = tmp;
            }
        }
    }
    ret.second += 1;
    return ret;
}

pair <int, int> dfs2 (int id) {
    vis2[id] = 1;
    pair <int, int> ret, tmp;
    ret = {id, 0};
    int i, j, v;
    for (i = 0; i < vi[id].size(); i++) {
        v = vi[id][i];
        if (!vis2[v]) {
            tmp = dfs2(v);
            if (tmp.second > ret.second) {
                ret = tmp;
            }
        }
    }
    ret.second += 1;
    return ret;
}


int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    int n, m, q, i, j, x, y, pX, pY, cns;
    scanf("%d %d %d", &n, &m, &q);
    for (i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        vi[x].PB(y);
        vi[y].PB(x);
        /** this process of doing union of two nodes is slower compared to doing union of
            all the connected components found using a dfs (demonstrated in the lower part
            of the code) and gives a TLE verdict, so I had to omit using this method.
        //pX = findParent(x);
        //pY = findParent(y);
        //unite(pX, pY);
        **/
    }
    for (i = 1; i <= n; i++) {
//        cout << i << " -> " << parent[i] << endl;
    }
    pair <int, int> ret;
    store.clear();
    memset(vis, 0, sizeof vis);
    memset(vis2, 0, sizeof vis2);
    for (i = 1; i <= n; i++) {
        if (!vis[i]) {
            ret = dfs(i);
            for (j = 0; j < store.size(); j++) {
                x = store[j];
                parent[x] = i;
            }
            ret = dfs2(ret.first);
            diameter[i] = ret.second - 1;
            store.clear();
        }
    }
    for (i = 0; i < q; i++) {
        scanf("%d", &j);
        if (j == 1) {
            scanf("%d", &x);
            pX = findParent(x);
            printf("%d\n", diameter[pX]);
        }
        else {
            scanf("%d %d", &x, &y);
            pX = findParent(x);
            pY = findParent(y);
            if (pX == pY) {
                //printf("%d\n", diameter[pX]);
            }
            else {
                unite(pX, pY);
                cns = max(diameter[pX], diameter[pY]);
                x = diameter[pX] / 2;
                if (diameter[pX] & 1) x++;
                y = diameter[pY] / 2;
                if (diameter[pY] & 1) y++;
                cns = max(cns, x + y + 1);
                x = findParent(pX);
                diameter[x] = cns;
            }
        }
    }
    return 0;
}
