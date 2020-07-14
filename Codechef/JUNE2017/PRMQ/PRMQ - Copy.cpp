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
#define PH          pair < PII, PII >

//typedef unsigned long           LL;
typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const int mx = 1e5 + 5;
const int INF = 1e7;

bool pr[1000005];
bool taken[1000005];
vector <int> prime, vi;
vector <PII> arr;
PII pos[mx];
int mp[1000005];
vector <PII> store[mx];
vector <int> st;
vector <PH> vph;
vector <int> vpi[mx];

void initP() {
    int i, j;
//    memset(pr, 0, sizeof pr);
    for (i = 4; i < 1000005; i += 2) pr[i] = 1;
    for (i = 3; i * i < 1000005; i += 2) {
        if (!pr[i]) {
            for (j = i * i; j < 1000005; j += i) {
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
bool cmp (PH x, PH y) {
    if (x.first.first == y.first.first) {
        return x.first.second < y.first.second;
    }
    return x.first.first < y.first.first;
}

int tree[2000005], treeMx;

int query(int idx){
       int sum=0;
       while(idx>0){
             sum+=tree[idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(int idx, int x)
{
       while(idx<=treeMx)
       {
             tree[idx]+=x;
             idx += idx & (-idx);
       }
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get2.txt","r",stdin);
        freopen("got2.txt","w+",stdout);
    #endif // O_Amay_Valo_Basheni
    int n, m, q, l, r, x, y, i, j, cnt, cns, ans, u, v, mxP = 0, asn = 1, put = 0, z, mpx, mpy, sqr;
    double start, en;
//    start = clock();
    initP();
//    en = clock();
//    printf("Prime building %f\n", (en - start)/1000);
    bool tr = 0;
//    cout << prime.size() << endl;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        vi.PB(x);
        if (!taken[x]) {
            taken[x] = 1;
            st.PB(x);
        }
    }
//    en = clock();
//    printf("Input taking %f\n", (en - start)/1000);
//    cout <<"Input done" <<endl;
    sort (st.begin(), st.end());
//    en = clock();
//    printf("Input sort %f\n", (en - start)/1000);
    for (int it = 0; it < st.size(); it++) {
        x = st[it];
        mp[x] = ++put;
        mpx = put;
        cnt = 0;
        tr = 0;
        if (pr[x]) {
            sqr = sqrt(x);
    //        cout << "x " << x << " " << pr[x] << endl;
            for (i = 0; i < prime.size() && prime[i] <= sqr; i++) {
                y = prime[i];
                if (!pr[x] && x >= 2) {
                    //cout <<"prime found " << x << endl;
                    ///store[mpx].PB({x, 1});
                    break;
                }
                if (x % y == 0) {
                    cnt = 0;
    //                if (mp[x] != 0 && mp[x] != mpx) {
    //                    mpy = mp[x];
    //                    for (j = 0; j < store[mpy].size(); j++) {
    //                        store[mpx].PB({store[mpy][j]});
    //                    }
    //                    tr = 1;
    //                    break;
    //                }
    //                if (tr) break;
                    while (x % y == 0) {
                        if (mp[x] != 0 && mp[x] != mpx) {
    //                        cout << "duplicate " << x << endl;
                            tr = 1;
                            mpy = mp[x];
                            if (cnt) store[mpx].PB({y, cnt});
                            //store[mpx] += store[mpy];
                            for (j = 0; j < store[mpy].size(); j++) {
                                store[mpx].PB(store[mpy][j]);
                            }
                            break;
                        }
                        cnt++;
                        x /= y;
                    }
                    if (tr) break;
                    store[mpx].PB({y, cnt});
                }
                if (tr) break;
            }
        }
        if (tr) continue;
        if (x >= 2) {
            store[mpx].PB({x, 1});
        }
    }
//    en = clock();
//    printf ("Prime factorisation %f", (en - start)/1000);
    for (i = 1; i <= put; i++) {
        sort(store[i].begin(), store[i].end());
    }
//    en = clock();
//    printf ("Sorting factors %f\n", (en - start)/1000);
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
    }
    for (i = 1; i <= asn; i++) {
        vph.PB({{arr[i].first, arr[i].second}, {i, i}});
    }
//    en = clock();
//    printf ("Preparing array %f\n", (en - start)/1000);
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
//    en = clock();
//    printf ("buildin tree %f\n", (en - start)/1000);
//    cout<<"asn " << asn<<endl;
//    en = clock();
//    printf ("%d %d %d\n", tree[1].mx, tree[1].cnt);
//    printf ("Time for one query %f\n",(en - start)/1000);
    scanf("%d", &q);
//    double deltatime, mxdelta = 0.0, mndelta = 20000.0;
    for (i = 0; i < q; i++) {
        scanf("%d %d %d %d", &l, &r, &x, &y);
        vph.PB({{y+1, -1 *(i+1)}, {pos[l].first, pos[r].second}});
        vph.PB({{x, -1 * (i+1)}, {pos[l].first, pos[r].second}});
//        ans = 0;
//        deltatime = clock();
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
//        ans = query(1, 1, asn-1, pos[l].first, pos[r].second, y) - query(1, 1, asn-1, pos[l].first, pos[r].second, x - 1);
//        mxdelta = max((clock() - deltatime) / 1000, mxdelta);
//        mndelta = min((clock() - deltatime) / 1000, mndelta);
//        deltatime = clock();
//        printf("%d\n", ans);
    }
    sort(vph.begin(), vph.end(), cmp);
    treeMx = vph.size();
    PH phtm;
    int phx, phy, pha, phb;
    for (i = vph.size()-1; i>=0; i--) {
        phtm = vph[i];
        phx = phtm.first.first;
        phy = phtm.first.second;
        pha = phtm.second.first;
        phb = phtm.second.second;
        if (phy >= 0) {
            update(pha, phy);
        }
        else {
            ans = query(phb) - query(pha-1);
            phy = -1 * phy;
            vpi[phy].PB(ans);
        }
    }
    for (i = 1; i <= q; i++) {
        printf("%d\n", abs(vpi[i][0] - vpi[i][1]));
    }
//    printf ("Max querry time %f Min querry time %f\n", mxdelta, mndelta);
//    en = clock();
//    printf ("finishing querrys %f\n", (en - start)/1000);
    return 0;
}
