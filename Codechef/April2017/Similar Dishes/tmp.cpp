
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

const int mx = 1e6 + 5;

map <string, int> mp;

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    string ara[4];
    string s;
    int t, cnt;
    scanf("%d", &t);
    while(t--) {
        cin >> ara[0] >> ara[1] >> ara[2] >> ara[3];
        mp.clear();
        mp[ara[0]]++;
        mp[ara[1]]++;
        mp[ara[2]]++;
        mp[ara[3]]++;
        cnt = 0;
        for (int i = 0; i < 4; i++) {
            cin >> s;
            if (mp[s]) {
                mp[s]--;
                cnt++;
            }
        }
        if (cnt >= 2) {
            cout << "similar" << endl;
        }
        else {
            cout << "dissimilar" << endl;
        }
    }
    return 0;
}
