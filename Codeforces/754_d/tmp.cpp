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

multiset <int> st;
vector <PII> vp, vs;

int main()
{
    #ifdef PowerIsPrayed
        freopen("get2.txt","r",stdin);
    #endif // PowerIsPrayed
    int n, k, i, j, l, r;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &l, &r);
        vp.PB({l, r});
        vs.PB({l, r});
    }
    sort (vp.begin(), vp.end());
    LL ans = 0;
    for (i = 0; i < n; i++) {
        st.insert(vp[i].second);
        if (st.size() > k) {
            st.erase(st.begin());
        }
        if (st.size() == k && ((*st.begin()) - vp[i].first + 1) > ans) {
            ans = ((*st.begin()) - vp[i].first + 1);
            l = vp[i].first;
            r = *st.begin();
        }
    }
    printf("%I64d\n", ans);
    if (ans == 0) {
        for (i = 0; i < k; i++) printf("%d ", i+1);
        printf("\n");
    }
    else {
        int cnt;
        for (i = 0, cnt = 0; i < n && cnt < k; i++) {
            if (vs[i].first <= l && vs[i].second >= r) {
                cnt++;
                printf("%d ", i+1);
            }
        }
        printf("\n");
    }
    return 0;
}
