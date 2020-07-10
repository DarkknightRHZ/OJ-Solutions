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


int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    stack <int> tmp, st;
    int n, m, i, j, x, y;
    vector <int> lst;
    int weight[505];
    bool has[505] = {false};
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
    }
    int ans = 0;
    for (i = 0; i < m; i++) {
        scanf("%d", &x);
        lst.PB(x);
    }
    for (i = 0; i < lst.size(); i++) {
        x = lst[i];
        if (!has[x]) {
            has[x] = true;
            tmp.push(x);
        }
    }
    for (i = 1; i <= n; i++) {
        if (!has[i]) {
            st.push(i);
        }
    }
    while (!tmp.empty()) {
        st.push(tmp.top());
        tmp.pop();
    }
    for (i = 0; i < lst.size(); i++) {
        x = lst[i];
        while (st.top() != x && !st.empty()) {
            tmp.push(st.top());
            ans += weight[st.top()];
            st.pop();
        }
        if (!st.empty()) {
            st.pop();
        }
        while (!tmp.empty()) {
            st.push(tmp.top());
            tmp.pop();
        }
        st.push(x);
    }
    printf("%d\n", ans);
    return 0;
}
