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

const int mx = 1e6 + 5;

char s[mx];

int open[27];
int close[27];

vector < PII > vp;

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    int n, k, a, b, i ,j;
    while (~scanf("%d %d", &n, &k)) {
        scanf ("%s", s);
        memset (open, 0, sizeof open);
        memset (close, 0, sizeof close);
        int len = strlen(s);
        for (i = 0; i < len; i++) {
            a = s[i] - 'A';
            if (open[a] == 0) {
                open[a] = i+1;
            }
            close[a] = i+1;
        }
        vp.clear();
        for (i = 0; i <= 'Z' - 'A'; i++) {
            if (open[i] != 0 && close[i] != 0) {
                vp.push_back({open[i], close[i]});
            }
        }
        sort (vp.begin(), vp.end());
        int cnt = 0;
        priority_queue <int, vector <int>, greater <int> > Q;
        for (i = 0; i < vp.size(); i++) {
            if (Q.empty()) {
                Q.push(vp[i].second);
            }
            else {
                if (Q.top() < vp[i].first) {
                    Q.pop();
                    Q.push(vp[i].second);
                }
                else {
                    Q.push(vp[i].second);
                }
            }
            cnt = max (cnt, (int) Q.size());
        }
        if (cnt > k) printf ("YES\n");
        else printf ("NO\n");
    }
    return 0;
}
