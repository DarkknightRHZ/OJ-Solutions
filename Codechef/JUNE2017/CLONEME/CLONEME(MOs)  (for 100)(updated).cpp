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
#define PH          pair < pair < PII, PII >, int >
#define PP          pair < PII, int >

//typedef unsigned long           LL;
typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const int mx = 1e5 + 5;
const LL INF = 10000000000000005;

int block, treeMx;
int idx[100005];
vector <int> vi;
vector <PH> vph;
vector <PP> vpp[2];
//vector <PH> vphStore[400];
int ans[mx];
vector < vector <int> > viTree[10];
vector <int> tree[2];

int query(int id, int idx){
       int sum=0;
       while(idx>0){
             sum+=tree[id][idx];
             idx -= idx & (-idx);
       }
       return sum;
}

void update(int id, int idx, int x)
{
       while(idx<=treeMx)
       {
             tree[id][idx]+=x;
             idx += idx & (-idx);
       }
}

bool cmp (PP x, PP y) {
    int ax, bx, ay, by;
    ax = x.first.first;
    bx = x.first.second;
    ay = y.first.first;
    by = y.first.second;
    if (ax / block != ay / block) {
        return ax / block < ay / block;
    }
    return bx < by;
}

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get3.txt","r",stdin);
        //freopen ("got3.txt", "w+",stdout);
    #endif // O_Amay_Valo_Basheni
    int t, n, q, i, j, x, y, a, b, c, d, cnsOne, cnsTwo, ret1, ret2, k, div, inc, I;
    int cura, curb, curc, curd, cnt = 0, id;
    tree[0].resize(mx);
    tree[1].resize(mx);
    PH str;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &q);
        block = sqrt(n);
//        cout << "P" << endl;
//        block = sqrt(block);
        vi.clear();
        treeMx = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            vi.PB(x);
            treeMx = max (treeMx, x);
        }
        treeMx++;
        vph.clear();
        for (I = 0, inc = 0; I < q; I++, inc++) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            a--,b--,c--,d--;
            if (a > c) {
                swap (a, c);
                swap (b, d);
            }
            //vphStore[d/block].PB({{{a, b}, {c, d}}, i});
            vph.PB({{{a, b}, {c, d}}, i});
            if (inc == 9) {
                inc = -1;
                memset(ans, 0, sizeof ans);
                for (i = 0; i < mx; i++) {
                    tree[0][i] = 0;
                    tree[1][i] = 0;
                }
                vpp[0].clear();
                vpp[1].clear();
                for (i = 0; i < vph.size(); i++) {
                    id = vph[i].second;
                    a = vph[i].first.first.first;
                    b = vph[i].first.first.second;
                    c = vph[i].first.second.first;
                    d = vph[i].first.second.second;
                    vpp[0].PB({{a, b}, id});
                    vpp[1].PB({{c, d}, id});
                }
                sort (vpp[0].begin(), vpp[0].end(), cmp);
                sort (vpp[1].begin(), vpp[1].end(), cmp);
                id = vpp[0][0].second;
                idx[id] = 0;
                cura = a = vpp[0][0].first.first.first;
                curb = b = vpp[0][0].first.first.second;
                cnt = 0;
                for (i = cura; i <= curb; i++) {
                    x = vi[i];
                    update(0,x, 1);
                }
                for (i = 1; i < vpp[0].size(); i++){
                    id = vpp[0][i].second;
                    idx[id] = i;
                    a = vpp[0][i].first.first;
                    b = vpp[0][i].first.second;
                    while (cura < a) {
                        x = vi[cura];
                        valAra[x]--;
                        val[i][x] = valAra[x];
                        cnt--;
                    }
                    while (cura > a) {
                        cura--;
                        x = vi[cura];
                        valAra[x]++;
                        val[i][x] = valAra[x];
                        cnt++;
                    }
                    while (curb < b) {
                        curb++;
                        x = vi[curb];
                        valAra[x]++;
                        val[i][x] = valAra[x];
                        cnt++;
                    }
                    while (curb > b) {
                        x = vi[curb];
                        valAra[x]--;
                        val[i][x] = valAra[x];
                        cnt--;
                    }
                    cntAra[i] = cnt;
                }

                cnt = cntAra[0];
                id = vpp[1][0].second;
                curc = vpp[1][0].first.frist;
                curd = vpp[1][0].first.second;
                int ID;
                ID = idx[id];
                for (i = curc, cnt = cntAra[ID]; i <= curd; i++) {
                    x = vi[curc];
                    cnt -= abs(val[ID][x]);
                    val[]
                }
                vph.clear();
            }
        }
        for (i = 0; i < q; i++) {
            if (ans[i] == 1) {
                //printf("YES\n");
            }
            else {
                //printf("NO\n");
            }
        }
    }
    return 0;
}
