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
#include <unordered_set>

using namespace std;

#define PB          push_back
#define PF          push_front
#define  V          vector
#define PII         pair <int,int>

typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

vector <int> vi[200005];
bool mark[200005];

set <PII> st;

int up[200005];

vector <int> res;

int main()
{
    #ifdef PowerIsPrayed
        freopen("get2.txt","r",stdin);
    #endif // PowerIsPrayed
    int n, a, b, i, j, q, k, maxBid, smaxBid, maxId, l, x;
    set <PII> :: iterator it;
    scanf("%d", &n);
    for (i = 0; i <= n; i++) {
        vi[i].PB(0);
    }
    memset(mark, 0, sizeof mark);
    memset(up, 0, sizeof up);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        vi[a].PB(b);
        mark[a] = 1;
        if (up[a] < b) {
            up[a] = b;
        }
    }
    for (i = 1; i <= n; i++) {
        if (mark[i]) {
            st.insert({up[i],i});
        }
    }
//    cout << "THIQ ASE" << endl;
    scanf("%d", &q);
//    for (i = 1; i <= n; i++) {
//        cout << i << " " << up[i] << endl;
//    }
//    cout << endl;
    for (l = 0; l < q; l++) {
        res.clear();
        scanf("%d", &k);
        for (j = 0; j < k; j++) {
            scanf("%d", &a);
            res.PB(a);
            st.erase({up[a],a});
        }
//        cout << st.size() << endl;
        if (st.empty()) {
            printf("0 0\n");
            for (i = 0; i < res.size(); i++) {
                if(up[res[i]]) st.insert({up[res[i]],res[i]});
            }
            res.clear();
            continue;
        }
        PII mxP, smxP;
        it = st.end();
        it--;
        mxP = *it;
//        cout << st.size() << endl;
        //cout <<"size " << st.size() << " " << a << endl;
//        cout << mxP.second <<  " g " <<endl;
        if (st.size() == 1) {
//            cout << "ASI " << endl;
          printf("%d %d\n", mxP.second, vi[mxP.second][1]);
            for (i = 0; i < res.size(); i++) {
               if(up[res[i]]) st.insert({up[res[i]],res[i]});
            }
          res.clear();
          continue;
        }
        it--;
        smxP = *it;
//        cout << smxP.second <<  " gh " <<endl;
        maxBid = lower_bound(vi[mxP.second].begin(),vi[mxP.second].end(),up[smxP.second]) - vi[mxP.second].begin();
//        if (vi[mxP.second][maxBid] == 0) maxBid++;
        printf("%d %d\n", mxP.second, vi[mxP.second][maxBid]);
        for (i = 0; i < res.size(); i++) {
            if(up[res[i]]) st.insert({up[res[i]],res[i]});
        }
//        cout << endl;
        res.clear();
    }
    return 0;
}
