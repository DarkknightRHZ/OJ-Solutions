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

map <int, string> mp;

int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    mp[0] = "A";
    mp[1] = "B";
    mp[2] = "C";
    mp[3] = "D";
    mp[4] = "E";
    mp[5] = "F";
    mp[6] = "G";
    mp[7] = "H";
    mp[8] = "I";
    mp[9] = "J";
    mp[10] = "K";
    mp[11] = "L";
    mp[12] = "M";
    mp[13] = "N";
    mp[14] = "O";
    mp[15] = "P";
    mp[16] = "Q";
    mp[17] = "R";
    mp[18] = "S";
    mp[19] = "T";
    mp[20] = "U";
    mp[21] = "V";
    mp[22] = "W";
    mp[23] = "X";
    mp[24] = "Y";
    mp[25] = "Z";
    mp[26] = "Aa";
    mp[27] = "Ab";
    mp[28] = "Ac";
    mp[29] = "Ad";
    mp[30] = "Ae";
    mp[31] = "Af";
    mp[32] = "Ag";
    mp[33] = "Ah";
    mp[34] = "Ai";
    mp[35] = "Aj";
    mp[36] = "Ak";
    mp[37] = "Al";
    mp[38] = "Am";
    mp[39] = "An";
    mp[40] = "Ao";
    mp[41] = "Ap";
    mp[42] = "Aq";
    mp[43] = "Ar";
    mp[44] = "As";
    mp[45] = "At";
    mp[46] = "Au";
    mp[47] = "Av";
    mp[48] = "Aw";
    mp[49] = "Ax";
    mp[50] = "Ay";
    mp[51] = "Az";
    int n, m, pos = -1, i, j;
    string s;
    scanf("%d %d", &n, &m);
    vector <int> vi;
    vi.PB(-1);
    int ara[55];
    bool vis[55];
    for (i = 0; i < n - m + 1; i++) {
        cin >> s;
        if (s == "YES") {
            vi.PB(1);
        }
        else {
            vi.PB(0);
        }
    }
    if (vi[1] == 1) {
        for (i = 1; i <= m; i++) {
            ara[i] = i - 1;
        }
    }
    else {
        ara[1] = 0;
        for (i = 2; i <= m; i++) {
            ara[i] = i - 2;
        }
    }
    for (i = 2; i <= n - m + 1; i++) {
        if (vi[i] == 1) {
            memset(vis, 0, sizeof vis);
            for (j = 2; j <= i + m - 2; j++) {
                vis[ara[j]] = 1;
            }
            for (j = 0; j < 52; j++){
                if (!vis[j]) break;
            }
            ara[i + m - 1] = j;
        }
        else {
            ara[i + m - 1] = ara[i];
        }
    }
    for (i = 1; i <= n; i++) {
        cout << mp[ara[i]] <<" ";
    }
    cout << endl;
    return 0;
}
