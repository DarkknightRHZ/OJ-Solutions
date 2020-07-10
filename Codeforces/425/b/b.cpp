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

#define qr          cout << qur << endl;
typedef long long int           LL;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int GCD (int x, int y){if (x%y==0) return y; else return (GCD(y,x%y));}

const int mx = 1e5 + 5;

char s[mx];
char pat[mx];
bool has[30];
char qur[mx];


int main()
{
    #ifdef PowerIsPrayed
        freopen("get.txt","r",stdin);
    #endif // PowerIsPrayed
    scanf("%s", s);
    scanf("%s", pat);
    int q, n, i, j, k, l, patLen, len, cns;
    int hasS = -1;
    bool agree = 0;
    char ch, x, y;
    scanf("%d", &q);
//    cout << pat << endl;
    patLen = strlen(pat);
    len = strlen(s);
    for (i = 0; i < len; i++) {
        ch = s[i];
        has [ch - 'a'] = 1;
    }
    for (i = 0; i < patLen; i++) {
        if (pat[i] == '*') hasS = i;
    }
    for (i = 0; i < q; i++) {
        scanf("%s", qur);
//        cout << qur << endl;
        len = strlen(qur);
        if (hasS == -1 && len != patLen) {
//                cout << "AISI" << endl;
//            qr
            printf ("NO\n");
            continue;
        }
        else if (hasS == -1 && len == patLen) {
                for (j = 0; j < patLen; j++) {
                    if (pat[j] == qur[j]) continue;
                    if (pat[j] == '?' && has[qur[j] - 'a']) continue;
                    else {
        //                    cout << j << endl;
//                        qr
                        printf ("NO\n");
                        break;
                    }
            }
            if (j == patLen) {
//                    qr
                    printf ("YES\n");
            }
        }
        else if (len < patLen - 1) {
//                qr
            printf ("NO\n");
            continue;
        }
        else {
//            if (len == patLen) {
//                for (j = 0; j < patLen; j++) {
//                    if (pat[j] == qur[j]) continue;
//                    if (pat[j] == '?' && has[qur[j] - 'a']) continue;
//                    if (pat[j] == '*' && !has[qur[j] - 'a']) continue;
//                    else {
//    //                        cout << j << endl;
////                        qr
//                        printf ("NO\n");
//                        break;
//                    }
//                }
//                if (j == patLen) {
////                        qr
//                        printf ("YES\n");
//                }
//            }
            if (len >= patLen) {
                cns = len - patLen;
                agree = 1;
                for (j = hasS; j <= hasS + cns; j++) {
                    if (has[qur[j] - 'a']) {
                        agree = 0;
                        break;
                    }
                }
                if (agree)
                for (j = 0; j < hasS; j++) {
                    if (pat[j] == qur[j]) continue;
                    if (pat[j] == '?' && has[qur[j] - 'a']) continue;
                    else {
                        agree = 0;
                        break;
                    }
                }
                if (agree)
                for (k = hasS + cns +1, j = hasS + 1; j < patLen, k < len; j++, k++) {
                    if (pat[j] == qur[k]) continue;
                    if (pat[j] == '?' && has[qur[k] - 'a']) continue;
                    else {
                        agree = 0;
                        break;
                    }
                }
                if (agree) {
//                        qr
                    printf ("YES\n");
                }
                else {
//                    qr
                    printf ("NO\n");
                }
            }
            else if (len == patLen - 1) {
                for (j = 0, k =0; j < patLen && k < len; j++, k++) {
                    if (pat[j] == qur[k]) continue;
                    if (pat[j] == '?' && has[qur[k] - 'a']) continue;
                    if (pat[j] == '*') {
                            k--;
                            continue;
                    }
                    else {
//                            qr
    //                        cout << j << endl;
                        printf ("NO\n");
                        break;
                    }
                }
                if (j == patLen) {
//                        qr
                        printf ("YES\n");
                }
                else if (pat[j] == '*') {
//                        qr
                        printf ("YES\n");
                }
            }
        }
    }
    return 0;
}
