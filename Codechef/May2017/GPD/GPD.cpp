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

const int mx = 3 * (1e5 + 5);
//const int INF = 2222147483647;

int ky[mx];
int parent[mx];
bool vis[mx];
int r, k, X, Y, target,asn = 0;
//vector <LL> vi[mx];

vector <PII> resList;

unordered_map <int,int> mp;
//
//void solve(LL u, LL x, LL y) {
//    //printf("%lld\n", k^key[u]);
//    vis[u] = 1;
//    LL v, i;
//    for (i = 0; i < vi[u].size(); i++) {
//        v = vi[u][i];
//        if (!vis[v]) {
//            if (v == target) {
//                X = min(x, k^ky[v]);
//                Y = max(y, k^ky[v]);
//            }
//            else {
//                solve(v, min(x, k^ky[v]), max(y, k^ky[v]));
//            }
//        }
//    }
//}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int n, q, i, j, u, v, x, y, d;
    string s;
    //cout << mx << endl;
//    PII res;
//    cout << INF << endl;
    scanf("%d %d", &n, &q);
    scanf("%d %d", &r, &k);
    if (!mp[r]) mp[r] = ++asn;
    r = mp[r];
    ky[r] = k;
    parent[r] = -1;
    for (i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &v, &u, &k);
        if (!mp[v]) mp[v] = ++asn;
//        vi[mp[u]].PB(mp[v]);
        //vi[mp[v]].PB(mp[u]);
        v = mp[v];
        parent[v] = mp[u];
        ky[v] = k;
    }
//    scanf ("%lld", &d);
    int xorR = 0;
//    cout << "q " << q << endl;
//    LL RR = mp[r];
//    cout << q << endl;
//    cout << "P" << endl;
    cin.ignore();
    for (i = 0; i < q; i++) {
        getline(cin, s);
        d = 0;
//        scanf("%d", &d);
//        cout << s << endl;
        for (j = 0; s[j] != ' '; j++) {
            d *= 10;
            d += (s[j] - '0');
        }
        d = d^xorR;
//        cout << "T " << d << " " << xorR << endl;
        if (d == 0) {
            u = v = k = 0;
//            cout << "OK" << endl;
            while (s[j] == ' ') j++;
//            cout << "P" << endl;
            while (s[j] != ' ') {
                u *= 10;
                u += (s[j] - '0');
                j++;
            }
            while (s[j] == ' ') j++;
            while (s[j] != ' ') {
                v *= 10;
                v += (s[j] - '0');
                j++;
            }
            while (s[j] == ' ') j++;
            while (j < s.size()) {
                k *= 10;
                k += (s[j] - '0');
                j++;
            }
//            cout << "Up " << u << " " << v << " " << k << endl;
//            scanf("%d %d %d", &u, &v, &k);
            u ^= xorR;
            v ^= xorR;
            k ^= xorR;
//            cout << "U " << u << " " << v << " " << k << endl;
            if (!mp[v]) mp[v] = ++asn;
//            vi[mp[u]].PB(mp[v]);
            v = mp[v];
            parent[v] = mp[u];
            //vi[mp[v]].PB(mp[u]);
            ky[v] = k;
        }
        else if (d == 1) {
            v = k = 0;
//            cout << "OK" << endl;
            while (s[j] == ' ') j++;
//            cout <<"OKEND"<<endl;
            while (s[j] != ' ') {
                v *= 10;
                v += (s[j] - '0');
                j++;
            }
            while (s[j] == ' ') j++;
            while (j < s.size()) {
                k *= 10;
                k += (s[j] - '0');
                j++;
            }
//            cout << "JUMP" << endl;
//            cout << "Pp " << v << " " << k << endl;
//            cout << v << " " << k << " " << v << endl;
//            scanf("%d %d", &v, &k);
            v ^= xorR;
            k ^= xorR;
            v = mp[v];
//            cout << v << " " << k << " " << v << endl;
//            cout << "P " << v << " " << k << endl;
//            memset(vis, 0, sizeof vis);
            //cout << res.first << " " << res.second << endl;
//            target = mp[v];
//            X = Y = ky[RR]^k;
//            solve(RR, ky[RR]^k, ky[RR]^k);
            X = Y = ky[v]^k;
            for (j = v; j != -1; j = parent[j]) {
                X = min(X, ky[j]^k);
                Y = max(Y, ky[j]^k);
//                cout << "PPP" << endl;
            }
//            cout << "DONE" << endl;
            xorR = X^Y;
            resList.PB({X,Y});
        }
    }
    for (i = 0; i < resList.size(); i++) {
        printf("%d %d\n", resList[i].first, resList[i].second);
    }
    return 0;
}
