
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
bool marked[mx][mx];
vector < vector <LL> > vii[mx];
unordered_set <LL> st;

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL t, n, i, j, k, l, x, y, cnt, cns, ans, ans1, ans2, cn, cnt2;
    vector <LL> vi;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &n, &k);
        for (i = 0; i < mx; i++) {
            vii[i].clear();
        }
        st.clear();
        for (i = 0; i < n; i++) {
            scanf("%lld", &y);
            vi.clear();
            memset(taken, 0, sizeof taken);
            for (j = 0; j < y; j++) {
                scanf("%lld", &x);
                if (!taken[x]) vi.PB(x);
                taken[x] = 1LL;
            }
            if (vi.size()) vii[vi.size()].PB(vi);
            if (vi.size()) st.insert(vi.size());
        }
//        cout << "P" << endl;
        memset(marked, 0, sizeof marked);
        ans  = 0;
        for (auto it = st.begin(); it != st.end(); it++) {
            x = *it;
            for (i = 0; i < vii[x].size(); i++) {
                if (marked[x][i]) continue;
                marked[x][i] = 1LL;
                vi = vii[x][i];
                memset(taken, 0, sizeof taken);
                for (j = 0; j < vi.size(); j++) {
                    y = vi[j];
                    taken[y] = 1LL;
                }
                ans1 = ans2 = 0;
                ans1 = 1;
                cnt = vi.size();
                for (j = i + 1LL; j < vii[x].size(); j++) {
                    if (marked[x][j]) continue;
                    cns = 0;
                    for (l = 0; l < vii[x][j].size(); l++) {
                        y = vii[x][j][l];
                        if (taken[y]) cns++;
                        else break;
                    }
                    if (cns == cnt) {
                            ans1++;
                            marked[x][j] = 1;
                    }
                }
                if (cnt == k) {
                    ans += ((ans1 * (ans1 - 1LL)) / 2LL);
                    continue;
                }
                cn = k - cnt;
                for (j = 0; j < vii[cn].size(); j++) {
                    cnt2 = cns = 0;
                    if (marked[cn][j]) continue;
                    vi = vii[cn][j];
                    for (l = 0; l < vi.size(); l++) {
                        y = vi[l];
                        if (!taken[y]) cns++;
                        else break;
                    }
                    if (cns == cn) {
                        ans2++;
                        marked[cn][j] = 1LL;
                    }
                }
//                cout << ans1 << " " << ans2 << endl;
                ans += ans1 * ans2;
            }
        }
        printf("%LLd\n", ans);
    }
    return 0;
}

