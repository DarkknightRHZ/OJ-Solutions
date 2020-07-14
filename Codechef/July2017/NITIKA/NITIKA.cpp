
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

const LL mx = 1e5 + 5;
const LL INF = 10000000000000005;

int main()
{
    #ifdef O_Amay_Valo_Basheni
        freopen("get.txt","r",stdin);
    #endif // O_Amay_Valo_Basheni
    string s;
    string ss;
    int i, j, t;
    scanf("%d", &t);
//    cout << t << endl;
    cin.ignore();
    while (t--) {
        getline (cin, s);
        j = 0;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                j++;
            }
        }
//        cout << j << endl;
        if (j <= 0) {
            ss = "";
            for (i = 0; i < s.size(); i++) {
                if (!i) {
                    if (s[i] >= 'A' && s[i] <= 'Z') {
                        ss += s[i];
                    }
                    else {
                        ss += 'A' + (s[i] - 'a');
                    }
                }
                else ss += tolower(s[i]);
            }
            cout << ss << endl;
        }
        else {
            ss = "";
            ss += 'A' + (tolower(s[0])) - 'a';
            ss += '.';
            ss += ' ';
            for (i = 0; i < s.size(); i++) {
                if (s[i] == ' ') {
                    j--;
                    break;
                }
            }
            if (j) {
                ss += 'A' + (tolower(s[i+1])) - 'a';
                ss += '.';
                ss += ' ';
                i++;
                while (s[i] != ' ') i++;
                ss +=  'A' + (tolower(s[i+1])) - 'a';
                for (i = i + 2; i < s.size(); i++) {
                    ss += tolower(s[i]);
                }
            }
            else {
                i++;
                //while (s[i] != ' ') i++;
                ss += 'A' + (tolower(s[i])) - 'a';
                for (i = i + 1; i < s.size(); i++) {
                    ss += tolower(s[i]);
                }
            }
            cout << ss << endl;
        }
    }
    return 0;
}

