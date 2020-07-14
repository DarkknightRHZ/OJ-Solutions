
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

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

//const int mx = 1e6 + 5;

int mos[1002][1002];
int cand[1002][1002];
pair <int, int> bound[1002];
int ans;

//vector <int> vi;

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    int t, cnt, n, q, l, r, k, i, j, z, x, y, tmp, total, upperDiv, lowerDiv, upperLimit, lowerLimit;
    scanf("%d", &t);
    while(t--) {
        memset(mos, 0, sizeof mos);
        memset(cand, -1, sizeof cand);
//        memset(ans, -1, sizeof ans);
//        vi.clear();
        scanf("%d %d", &n, &q);
        total = n/1000;
//        cout << total << endl;
        for (i = 0, z = 0; i <= total; i++) {
            tmp = 0;
            for (j = 0; j < 1000 && z < n; j++, z++) {
                scanf("%d", &cand[i][j]);
            }
        }
        for (i = 0, z = 0; i <= total; i++) {
            tmp = 0;
            for (j = 0; j < 1000 && z < n; j++, z++) {
                cout << z << " ";
                //scanf("%d", &cand[i][j]);
                tmp++;
//                cout << tmp << endl;
                if (j) {
                    if (cand[i][j] != cand[i][j-1]) {
                        tmp--;
                        mos[i][tmp]++;
                        tmp = 1;
                    }
                }
                if (j == 999 || z == n - 1) {
                    mos[i][tmp]++;
                }
            }
            for (j = 0, tmp = 0; cand[i][j] == cand[i][0] && j < 1000; j++){
                tmp++;
                //cout << "ASI" << endl;
            }
            bound[i].first = tmp;
            for (j = 999, tmp = 0; j >= 0 && cand[i][j] == cand[i][999] && cand[i][j] != -1; j--){
                tmp++;
            }
            bound[i].second = tmp;
        }
//        cout << endl;
        //cout << bound[0].first << " " << bound[0].second << endl;
        for (i = 0; i <= total; i++) {
            for (j = 999; j >= 0; j--) {
                mos[i][j] += mos[i][j+1];
            }
        }
//        for (i = 0; i <= total; i++) {
//            for (j = 0; j <= 4; j++) {
//                cout << "i " << i << " " << j << " " << mos[i][j] << endl;
//            }
//        }
//        cout << endl << endl;
        for (i = 0; i < q; i++) {
            scanf("%d %d %d", &l, &r, &k);
            l--; r--;
            upperDiv = r/1000;
            lowerDiv = l/1000;
            ans = 0;
            if (upperDiv == lowerDiv) {
                tmp = 0;
                l = l - 1000 * lowerDiv;
                r = r - 1000 * upperDiv;
                for (j = l; j <= r; j++) {
                    tmp++;
                    if (j > l) {
                        if (cand[lowerDiv][j] != cand[lowerDiv][j-1]) {
                            tmp--;
                            if (tmp >= k) {
                                ans++;
                            }
                            tmp = 1;
                        }
                    }
                    if (j == r) {
                        if (tmp >= k) {
                            ans++;
                        }
                    }
                }
            }
            else {
                l = l - 1000 * lowerDiv;
                r = r - 1000 * upperDiv;
                if (l < 1000 - bound[lowerDiv].second) {
                    tmp = 0;
                    for (j = l; j < 1000 - bound[lowerDiv].second; j++) {
                        tmp++;
                        if (j > l) {
                            if (cand[i][j] != cand[i][j-1]) {
                                tmp--;
                                if (tmp >= k) {
                                    ans++;
                                }
                                tmp = 1;
                            }
                        }
                        if (j == 1000 - bound[lowerDiv].second - 1) {
                            if (tmp >= k) {
                                ans++;
                            }
                        }
                    }
                    l = 1000 - bound[lowerDiv].second;
                }
                if (r > bound[upperDiv].first - 1 ) {
                    tmp = 0;
                    for (j = bound[upperDiv].first; j <= r; j++) {
                        tmp++;
                        if (j > bound[upperDiv].first) {
                            if (cand[i][j] != cand[i][j-1]) {
                                tmp--;
                                if (tmp >= k) {
                                    ans++;
                                }
                                tmp = 1;
                            }
                        }
                        if (j == r) {
                            if (tmp >= k) {
                                ans++;
                            }
                        }
                    }
                    r = bound[upperDiv].first - 1;
                }
                tmp = 1000 - l;
                for (j = lowerDiv + 1; j <= upperDiv; j++) {
                    if (j != upperDiv) {
                        if (cand[j][0] != cand[j-1][999]) {
                            if (tmp >= k) {
                                ans++;
                            }
                            tmp = bound[j].second;
                            ans += mos[j][k];
                            if (tmp >= k) {
                                ans--;
                            }
                        }
                        else {
                            if (bound[j].first < 1000) {
                                ans += mos[j][k];
                                if (bound[j].first < k && bound[j].first + tmp >= k) {
                                    ans++;
                                }
                                tmp = bound[j].second;
                                if (tmp >= k) {
                                    ans--;
                                }
                            }
                            else {
                                tmp += 1000;
                            }
                        }
                    }
                    else if (j == upperDiv) {
                        if (cand[j][0] != cand[j-1][999]) {
                            if (tmp >= k) {
                                ans++;
                            }
                            if (r + 1 >= k) {
                                ans++;
                            }
                        }
                        else {
                            if (r + 1 + tmp >= k) {
                                ans++;
                            }
                        }
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
