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

vector < PII > vi;

bool cmp (PII a, PII b) {
    return (a.first - a.second) < (b.first - b.second);
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int n, k, i, j, x, y;
    while (~scanf("%d %d", &n, &k)) {
        vi.clear();
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            vi.PB({x,0});
        }
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            vi[i].second = x;
        }
        sort (vi.begin(), vi.end(), cmp);
        int ans = 0, cnt = 0;
        for (i = 0; i < k; i++) {
            ans += (vi[i].first);
        }
        for (; i < n; i++) {
            if (vi[i].first - vi[i].second > 0) ans += (vi[i].second);
            else ans += (vi[i].first);
        }
        printf("%d\n", ans);
    }
    return 0;
}
