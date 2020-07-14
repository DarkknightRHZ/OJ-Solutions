
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

//typedef unsigned long           LL;
typedef long long int           LL;
#define PLLL        pair < LL, PLL >

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const LL mx = 1e5 + 5;
const LL INF = 10000000000000005;

vector <PLL> vpl[mx];

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    LL T, n, d, t, s, i, j, x, y, D;
    priority_queue <PLL> q;
    scanf("%lld", &T);
    while(T--) {
        scanf("%lld %lld", &n, &D);
        //q.clear();
        for (i = 0; i <= D; i++) {
            vpl[i].clear();
        }
        for (i = 0; i < n; i++) {
            scanf("%lld %lld %lld", &d, &t, &s);
//            cout << d << " " << t << " " << s << endl;
            vpl[d].PB({s, t});
//            cout << vpl[d].size()<<endl;
        }
        PLL tmp;
        bool strt = 0;
        for (i = 1LL; i <= D; i++) {
            if (vpl[i].size() && !strt) {
                for (j = 0; j < vpl[i].size(); j++) {
                    q.push(vpl[i][j]);
                }
                tmp = q.top();
                q.pop();
                strt = 1;
            }
            else if (vpl[i].size()) {
                for (j = 0; j < vpl[i].size(); j++) {
                    q.push(vpl[i][j]);
                }
                if (tmp.first < q.top().first) {
//                        cout << tmp.first << " " << q.top().first << endl;
                    q.push(tmp);
                    tmp = q.top();
                    q.pop();
                }
            }
            if (strt) {
                tmp.second--;
                if (tmp.second <= 0) {
                    if (q.empty()) {
                        strt = 0;
                    }
                    else {
//                        cout << "AISI" << endl;
                        tmp = q.top();
                        q.pop();
                    }
                }
            }
//            cout << tmp.first << " " << tmp.second << endl;
        }
        LL ans = 0;
        if (tmp.second >= 0) ans += tmp.first * tmp.second;
        while (!q.empty()) {
//            cout << "P" << endl;
            ans += q.top().first * q.top().second;
            q.pop();
        }
        printf ("%lld\n", ans);
    }
    return 0;
}

