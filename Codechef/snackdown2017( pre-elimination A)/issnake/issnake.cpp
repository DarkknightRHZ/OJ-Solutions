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

const int mx = 505;
const LL INF = 10000000000000005;

int X[] = {-1,1,0};
int Y[] = {0,0,1};

int ara[3][mx], n;
bool vis[3][mx];

bool isvalid(int x, int y) {
    if (x >= 0 && y >= 0 && x < 2 && y < n) {
        return true;
    }
    return false;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    int i, j, u, v;
    for (i = 0; i < 3; i++) {
        u = x + X[i];
        v = y + Y[i];
        if (isvalid(u, v)) {
            if (!vis[u][v] && ara[u][v] == 1) {
                dfs(u, v);
                break;
            }
        }
    }
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t, odd = 0, even = 0, i, j, x = 0, y = 0, tmp, pos, cnt = 0, cnt2;
    vector <PII> vp;
    bool emp, f, tr;
    char ch;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        x = -1, y = -1;
        cnt2 = 0;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < n; j++) {
                cin >> ch;
                if (ch == '#') {
                    ara[i][j] = 1;
                }
                else {
                    ara[i][j] = 0;
                }
            }
        }
        vp.clear();
        f = 0;
        for (i = 0; i < n; i++) {
            if (ara[0][i] == 1) {
                vp.PB({0,i});
                f = 1;
            }
            if (ara[1][i] == 1) {
                vp.PB({1,i});
                f = 1;
            }
            if (f) break;
        }
//        cout << vp.size() << endl;
        tr = 0;
        for (i = 0; i < vp.size(); i++) {
            memset(vis, 0, sizeof vis);
            f = 1;
            dfs(vp[i].first, vp[i].second);
            for (j = 0; j < n; j++) {
                if (ara[0][j] == 1 && !vis[0][j]) {
                    f = 0;
                    break;
                }
                else if (ara[1][j] == 1 && !vis[1][j]) {
                    f = 0;
                    break;
                }
            }
            if (f) {
                tr = 1;
                break;
            }
        }
        if (tr) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
