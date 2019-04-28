#include "cti.hpp"
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

inline int area(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return (b.first - a.first) * (c.second - a.second)
            - (b.second - a.second) * (c.first - a.first);
}

inline bool intersect_1(int a, int b, int c, int d)
{
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool intersect(
        pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d)
{
    return intersect_1(a.first, b.first, c.first, d.first)
            && intersect_1(a.second, b.second, c.second, d.second)
            && area(a, b, c) * area(a, b, d) <= 0
            && area(c, d, a) * area(c, d, b) <= 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s, name, t, s1;
    vector<pair<int, int>> vp(100);
    pair<double, double> tmp;
    map<int, double> rad;
    map<int, string> na;
    map<int, vector<pair<int, int>>> map;
    int count = 1, it = 0;
    while (getline(cin, t)) {
        s1 += t;
    }
    for (int i = 0, num = 1; i < s1.size(); ++i) {
        if (s1[i] >= 'a' && s1[i] <= 'z') {
            if (s1.substr(i, 8) == "triangle") {
                na[num] = s1.substr(i, 8);
                vector<pair<int, int>> tm(4);
                i += 10;
                int j = i;
                for (int k = 0, d = 4; k < 4; ++j, ++k) {
                    d = 4;
                    if (s1[j] == '-') {
                        tm[k].first = cti(s1[j + 1]) * -1;
                        d++;
                    } else {
                        tm[k].first = cti(s1[j]);
                    }
                    if (s1[j + d - 2] == '-') {
                        tm[k].second = cti(s1[j + d - 1]) * -1;
                        ++d;
                    } else {
                        tm[k].second = cti(s1[j + d - 2]);
                    }
                    j += d;
                }
                map[num] = tm;
            }
            if (s1.substr(i, 6) == "circle") {
                na[num] = s1.substr(i, 6);
                vector<pair<int, int>> tm(1);
                i += 7;
                int d = 4;
                if (s1[i] == '-') {
                    tm[0].first = cti(s1[i + 1]) * -1;
                    d++;
                } else {
                    tm[0].first = cti(s1[i]);
                }
                if (s1[i + d - 2] == '-') {
                    tm[0].second = cti(s1[i + d - 1]) * -1;
                    ++d;
                } else {
                    tm[0].second = cti(s1[i + d - 2]);
                }
                map[num] = tm;
                i += d + 1;
                rad[num] = cti(s1[i]) + (double)cti(s1[i + 2]) / 10;
            }
            while (s1[i] >= 'a' && s1[i] <= 'z')
                ++i;
            num++;
        }
    }
    while (it != s1.size()) {
        int n = it;
        while (s1[n] != '(') {
            ++n;
        }
        name = s1.substr(it, n - it);
        n = it;
        while (s1[n] != ')') {
            ++n;
        }
        if (s1[n + 1] == ')') {
            s = s1.substr(it, n + 2 - it);
        } else
            s = s1.substr(it, n + 1 - it);
        it += s.size();
        if (name != "triangle" && name != "circle") {
            cout << count << ". " << s << "\n    unknown shape '" << name
                 << "'\n\n";
        } else if (name == "triangle") {
            if (s.size() < 30) {
                cout << count << ". " << s << "\n    invalid input format\n\n";
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
                p = a + b + c;
                sq = sqrt(p / 2 * (p / 2 - a) * (p / 2 - b) * (p / 2 - c));
                if (sq <= 0) {
                    cout << count << ". " << s << "\n    invalid triangle\n\n";
                } else {
                    cout << fixed;
                    cout << count << ". " << s << endl
                         << "    perimeter = " << p << setprecision(4) << endl
                         << "    area = " << sq << setprecision(4) << endl
                         << "    intersects:\n";
                    for (auto& i : map) {
                        if (i.first == count) {
                            continue;
                        }
                        if (na[i.first] == "circle") {
                            int l = 0;
                            for (auto& j : vp) {
                                if (j.first * j.first + j.second * j.second
                                    <= rad[i.first] * rad[i.first]) {
                                    ++l;
                                }
                            }
                            if (l > 0 && l < 3) {
                                cout << "        " << i.first << ". "
                                     << na[i.first] << endl;
                            }
                        }
                        if (na[i.first] == "triangle") {
                            int a1, b1, c1;
                            vector<pair<int, int>> vp1(3);
                            for (auto& j : i.second) {
                                vp1.push_back({j.first, j.second});
                            }
                            if (intersect(vp[0], vp[1], vp1[0], vp1[1])
                                || (intersect(vp[0], vp[1], vp1[1], vp1[2]))
                                || (intersect(vp[0], vp[1], vp1[0], vp1[2]))
                                || (intersect(vp[1], vp[2], vp1[0], vp1[1]))
                                || (intersect(vp[1], vp[2], vp1[1], vp1[2]))
                                || (intersect(vp[1], vp[2], vp1[0], vp1[2]))
                                || (intersect(vp[0], vp[2], vp1[0], vp1[1]))
                                || (intersect(vp[0], vp[2], vp1[1], vp1[2]))
                                || (intersect(vp[0], vp[2], vp1[0], vp1[2]))) {
                                cout << "        " << i.first << ". "
                                     << na[i.first] << endl;
                            }
                        }
                    }
                }
            }
        } else if (s.size() < 16) {
            cout << count << ". " << s << "\n    invalid input format\n\n";
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
            if (r <= 0) {
                cout << count << ". " << s << "\n    invalid circle\n\n";
            } else {
                cout << fixed;
                cout << count << ". " << s << endl
                     << "    perimeter = " << setprecision(4)
                     << 2 * 3.1415926535 * r << endl
                     << "    area = " << setprecision(4) << 3.1415926535 * r * r
                     << endl
                     << "    intersects:\n";
                for (auto& i : map) {
                    if (i.first == count) {
                        continue;
                    }
                    if (na[i.first] == "circle") {
                        for (auto& j : i.second) {
                            if (r + rad[i.first]
                                        >= sqrt(pow(j.first - p.first, 2)
                                                + pow(j.second - p.second, 2))
                                && sqrt(pow(j.first - p.first, 2)
                                        + pow(j.second - p.second, 2))
                                        <= max(r, rad[i.first])) {
                                cout << "       " << i.first << ". "
                                     << na[i.first] << endl;
                            }
                        }
                    }
                    if (na[i.first] == "triangle") {
                        int l = 0;
                        for (auto& j : i.second) {
                            if (j.first * j.first + j.second * j.second
                                <= r * r) {
                                ++l;
                            }
                        }
                        if (l > 0 && l < 3) {
                            cout << "        " << i.first << ". " << na[i.first]
                                 << endl;
                        }
                    }
                }
            }
        }
        ++count;
    }
    return 0;
}