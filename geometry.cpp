#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cti(char c)
{
    return c - '0';
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s, t, st, sc;
    vector<pair<double, double>> tr(4);
    pair<double, double> tmp;
    while (getline(cin, t)) {
        s += t;
        if (s[s.size() - 1] == ')') {
            break;
        }
    }
    int n = 0;
    while (s[n] != '(') {
        ++n;
    }
    st = s.substr(0, n);
    if (st == "triangle") {
        int size = s.size();
        for (int i = 0; i < size - 1; ++i) {
            if (s[i] == '(') {
                i += 2;
                for (int j = i, k = 0; j < size - 3; ++j, ++k) {
                    int d = 4;
                    if (s[j] == '-') {
                        tr[k].first = cti(s[j + 1]) * -1;
                        d++;
                    } else {
                        tr[k].first = cti(s[j]);
                    }
                    if (s[j + 3] == '-') {
                        tr[k].second = cti(s[j + 4]) * -1;
                        ++d;
                    } else {
                        tr[k].second = cti(s[j + 3]);
                    }
                    j += d;
                }
                break;
            }
        }
        double p, sq, a, b, c;
        a
                = sqrt(pow(tr[0].first - tr[1].first, 2)
                       + pow(tr[0].second - tr[1].second, 2));
        b
                = sqrt(pow(tr[0].first - tr[2].first, 2)
                       + pow(tr[0].second - tr[2].second, 2));
        c
                = sqrt(pow(tr[1].first - tr[2].first, 2)
                       + pow(tr[1].second - tr[2].second, 2));
        p = a + b + c;
        sq = sqrt(p / 2 * (p / 2 - a) * (p / 2 - b) * (p / 2 - c));
        cout << "1. " << s << endl
             << "    perimeter = " << p << endl
             << "    area = " << sq << endl
             << "    intersects:" << endl;
    }else{
        cout<<"ERROR";
    }
    return 0;
}