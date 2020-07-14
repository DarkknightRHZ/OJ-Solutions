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

const int mx = 1e5 + 5;
const int INF = 1e7;

bool pr[mx];
vector <int> prime, vi;
vector <PII> arr;
PII pos[mx];
int mp[1000005];
vector <PII> store[mx];

struct nod{
    int mn, mx, cnt;
    nod () {
        mn = INF;
        mx = 0;
        cnt = 0;
    }
};

nod tree[2097152];

void initP() {
    int i, j;
    for (i = 4; i < 1000; i += 2) pr[i] = 1;
    for (i = 3; i * i < 1000; i += 2) {
        if (!pr[i]) {
            for (j = i * i; j < 1000; j += i) {
                pr[j] = 1;
            }
        }
    }
    for (i = 2; i < 1000; i++) {
        if (!pr[i]) {
                prime.PB(i);
//                prPos[i] = prime.size() - 1;
        }
    }
}

void init(int node, int b, int e)
{
    if (b == e) {
        tree[node].mn = arr[b].first;
        tree[node].mx = arr[b].first;
        tree[node].cnt = arr[b].first == 0? 0: arr[b].second;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].mn = min(tree[Left].mn, tree[Right].mn);
    tree[node].mx = max(tree[Left].mx, tree[Right].mx);
    tree[node].cnt = tree[Left].cnt + tree[Right].cnt;
}
int query(int node, int b, int e, int i, int j, int x, int y)
{
    if (i > e || j < b || tree[node].cnt <= 0)
        return 0;
    if (b >= i && e <= j && tree[node].mn >= x && tree[node].mx <= y)
        return tree[node].cnt;
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j, x, y);
    int p2 = query(Right, mid + 1, e, i, j, x, y);
    return p1 + p2;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int n, m, q, l, r, x, y, i, j, cnt, cns, ans, u, v, mxP = 0, asn = 1, put = 0;
    initP();
    bool tr = 0;
//    cout << prime.size() << endl;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        vi.PB(x);
    }
    arr.PB({-1,0});
    for (i = 0; i < n; i++) {
        x = vi[i];
        pos[i+1].first = asn;
        if (mp[x]) {
            y = mp[x];
            for (j = 0; j < store[y].size(); j++) {
                arr.PB(store[y][j]);
                asn++;
            }
            pos[i+1].second = asn-1;
            continue;
        }
        mp[x] = ++put;
        tr = 0;
        for (j = 0; j < prime.size(); j++) {
            if (prime[j] > sqrt(x)) break;
            //mxP = max (mxP, prime[j]);
            cnt = 0;
            y = prime[j];
            if (x % y == 0) {
                while (x % y == 0) {
//                    if (mp[x] && mp[x] != put-1) {
//                        tr = 1;
//                        cns = mp[x];
//                        for (l = 0; l < store[cns].size(); l++){
//                            arr.PB(store[cns][l]);
//                            asn++;
//                        }
//                        //pos[i+1].second = asn-1;
//                        break;
//                    }
                    cnt++;
                    x /= y;
                }
                if (cnt) {
                    store[put-1].PB({y, cnt});
                    arr.PB({y, cnt});
                    asn++;
                }
            }
            if (tr) {
                    //pos[i+1].second = asn-1;
                    break;
            }
//            cum[j][i + 1] = cnt;
        }
//        if (x >= 2 && x <= 1000) {
//                mxP = max (mxP, x);
//                cns = prPos[x];
////                cout <<"YES " << x << " " << cns << " " << i << endl;
//                cum[cns][i + 1] = 1;
//        }
        if (x >= 2 && !tr) {
                //mxP = max (mxP, x);
                arr.PB({x, 1});
                store[put-1].PB({x, 1});
                asn++;
        }
        pos[i+1].second = asn-1;
    }
//    if (n < mx)
//    for (i = 0; i < prime.size(); i++) {
//        //if (prime[i] > mxP) break;
//        for (j = 1; j <= n; j++) {
//            cum[i][j] += cum[i][j - 1];
//        }
//    }
//    for (i = 0; i < n; i++) {
//        cout << arr[i + 1] << " ";
//    }
//    cout << endl;
//    for (i = 0; i < 3; i++) {
//        cout << "I = " << prime[i] << " ";
//        for (j = 1; j <= n; j++) {
//            cout << cum[i][j] << " ";
//        }
//        cout << endl;
//    }
    init(1, 1, asn-1);
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d %d %d %d", &l, &r, &x, &y);
        ans = 0;
//        u = lower_bound(prime.begin(), prime.end(), x) - prime.begin();
//        v = lower_bound(prime.begin(), prime.end(), y) - prime.begin();
//        if (u < prime.size()) {
//            if (v >= prime.size()) v--;
//            if (prime[v] > y) v--;
////            cout << u << " " << v << endl;
//            for (j = u; j <= v; j++) {
//                ans += (cum[j][r] - cum[j][l - 1]);
//            }
//        }
//        cout << "asi" << endl;
        ans += query(1, 1, asn-1, pos[l].first, pos[r].second, x, y);
        printf("%d\n", ans);
    }
    return 0;
}
