
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

const LL mx = 2505;
const LL INF = 10000000000000005;

bool taken[mx];
//bool marked[mx][mx];
vector < int> vi[mx];
//unordered_set <LL> st;

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL t, n, i, j, k, l, x, y, cnt, cns, ans, ans1, ans2, cn, cnt2;
//    vector <LL> vi;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &n, &k);
        for (i = 0; i < mx; i++) {
            vi[i].clear();
        }
//        st.clear();
        for (i = 0; i < n; i++) {
            scanf("%lld", &y);
            memset(taken, 0, sizeof taken);
            for (j = 0; j < y; j++) {
                scanf("%lld", &x);
                if (!taken[x]) vi[i].PB(x);
                taken[x] = 1LL;
            }
        }
        LL ans = 0LL;
        for (i = 0; i < n; i++) {
            memset(taken, 0, sizeof taken);
            for (j = 0; j < vi[i].size(); j++) {
                taken[vi[i][j]] = 1;
            }
            cns = vi[i].size();
            cnt = k - cns;
            if (cnt == 0) {
                ans += (n - i - 1LL);
                continue;
            }
            for (j = i + 1LL; j < n; j++) {
                cn = 0;
                for (l = 0; l < vi[j].size(); l++) {
                    if (!taken[vi[j][l]]) cn++;
                }
                if (cn == cnt) {
                    ans++;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

