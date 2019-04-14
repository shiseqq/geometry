#include "cti.hpp"
#include <cmath>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream file("input.txt");
    freopen("output.txt", "w", stdout);
    string s, st;
    vector<pair<int, int>> vp(100);
    pair<double, double> tmp;
    int count = 1;
    while (!file.eof()) {
        getline(file, s);
        int n = 0;
        while (s[n] != '(') {
            ++n;
        }
        st = s.substr(0, n);
        if (st != "triangle" && st != "circle") {
            cout << count << ". " << s << "\nunknown shape '" << st << "'\n\n";
        } else {
            if (st == "triangle") {
                if (s.size() < 30) {
                    cout << count << ". " << s << "\ninvalid input format\n\n";
                } else {
                    vp.clear();
                    vp.resize(4);
                    int size = s.size();
                    for (int i = 0; i < size - 1; ++i) {
                        if (s[i] == '(') {
                            i += 2;
                            for (int j = i, k = 0; j < size - 3; ++j, ++k) {
                                int d = 4;
                                if (s[j] == '-') {
                                    vp[k].first = cti(s[j + 1]) * -1;
                                    d++;
                                } else {
                                    vp[k].first = cti(s[j]);
                                }
                                if (s[j + d - 2] == '-') {
                                    vp[k].second = cti(s[j + d - 1]) * -1;
                                    ++d;
                                } else {
                                    vp[k].second = cti(s[j + d - 2]);
                                }
                                j += d;
                            }
                            break;
                        }
                    }
                    double p, sq, a, b, c;
                    a
                            = sqrt(pow(vp[0].first - vp[1].first, 2)
                                   + pow(vp[0].second - vp[1].second, 2));
                    b
                            = sqrt(pow(vp[0].first - vp[2].first, 2)
                                   + pow(vp[0].second - vp[2].second, 2));
                    c
                            = sqrt(pow(vp[1].first - vp[2].first, 2)
                                   + pow(vp[1].second - vp[2].second, 2));
                    double m = max(max(a, b), c);
                    if (a + b < m || a + c < m || b + c < m) {
                        cout << count << ". " << s << "\ninvalid triangle\n\n";
                        return 0;
                    }
                    p = a + b + c;
                    sq = sqrt(p / 2 * (p / 2 - a) * (p / 2 - b) * (p / 2 - c));
                    cout << fixed;
                    cout << count << ". " << s << endl
                         << "    perimeter = " << p << setprecision(4) << endl
                         << "    area = " << sq << setprecision(4) << endl
                         << "    intersects:" << endl;
                }
            } else if (st == "circle") {
                if (s.size() < 16) {
                    cout << count << ". " << s << "\ninvalid input format\n\n";
                } else {
                    pair<int, int> p;
                    double r;
                    int size = s.size();
                    for (int i = 0; i < size - 1; ++i) {
                        if (s[i] == '(') {
                            i++;
                            int d = 4;
                            if (s[i] == '-') {
                                p.first = cti(s[i + 1] * -1);
                                ++d;
                            } else {
                                p.first = cti(s[i]);
                            }
                            if (s[i + d - 2] == '-') {
                                p.second = cti(s[i + d - 1]) * -1;
                                ++d;
                            } else {
                                p.second = cti(s[i + d - 2]);
                            }
                            i += d + 1;
                            r = cti(s[i]) + (double)cti(s[i + 2]) / 10;
                        }
                    }
                    cout << fixed;
                    cout << count << ". " << s << endl
                         << "    perimeter = " << setprecision(4)
                         << 2 * 3.1415926535 * r << endl
                         << "    area = " << setprecision(4)
                         << 3.1415926535 * r * r << endl
                         << "    intersects:" << endl;
                }
            }
        }
        ++count;
    }
    file.close();
    return 0;
}