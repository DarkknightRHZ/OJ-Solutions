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
    char s, e;
    map <char, int> mp, mp2;
    mp['v'] = 0;
    mp['<'] = 1;
    mp['^'] = 2;
    mp['>'] = 3;
    map <int, char> rmp, rmp2;
    rmp[0] = 'v';
    rmp[1] = '<';
    rmp[2] = '^';
    rmp[3] = '>';
    rmp[4] = 'v';
    rmp[5] = '<';
    rmp[6] = '^';

    mp2['v'] = 0;
    mp2['>'] = 1;
    mp2['^'] = 2;
    mp2['<'] = 3;

    rmp2[0] = 'v';
    rmp2[1] = '>';
    rmp2[2] = '^';
    rmp2[3] = '<';
    rmp2[4] = 'v';
    rmp2[5] = '>';
    rmp2[6] = '^';

    int cnt, i, j, n;
    while (cin >> s >> e) {
            cin >> n;
            int rem = n % 4;
            if (rem == 0) {
                cout << "undefined" << endl;
            }
            else  {
                i = mp[s];
                j = mp2[s];
                if (rmp[i + rem] == rmp2[j + rem]) {
                    cout << "undefined" << endl;
                }
                else if (rmp[i + rem] == e) {
                    cout << "cw" << endl;
                }
                else if (rmp2[j + rem] == e) {
                    cout <<"ccw"<< endl;
                }
                else cout << "undefined" << endl;
            }
        }
    return 0;
}
