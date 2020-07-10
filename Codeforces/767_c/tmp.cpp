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

const int MX = 1e6 + 5;

vector <int> vi[MX];
vector <int> ans;
int ara[MX];
int cum[MX];
int cns;
int hand;

int solve(int node) {
    int ret = ara[node];
    int i, u, v;
    for (i = 0; i < vi[node].size(); i++) {
        ret += solve(vi[node][i]);
    }
    if (ret == cns) {
        ans.PB(node);
        ret = 0;
    }
    return ret;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int n, i, j, x, y, val, sum = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &x, &val);
        ara[i] = val;
        vi[x].PB(i);
        sum += val;
    }
    if (sum % 3) printf("-1\n");
    else {
        cns = sum / 3;
        x = vi[0][0];
//        cout << x << endl;
        for (i = 0; i < vi[x].size(); i++) {
            hand = 0;
            y = solve (vi[x][i]);
        }
        if (ans.size() < 2) printf("-1\n");
        else printf("%d %d\n", ans[0], ans[1]);
    }
    return 0;
}
