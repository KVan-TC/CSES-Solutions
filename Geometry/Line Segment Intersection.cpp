#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Point {
    int x, y;
    void read() {
        cin >> x >> y;
    }
    Point operator -(const Point& b) const { return Point{x - b.x, y - b.y}; }
    ll operator *(const Point& b) const { return 1LL * x * b.y - 1LL * b.x * y; }

    ll cross(const Point&b, const Point&c) const { return (b - *this) * (c - *this); }
};

int T;
Point P[4];

bool onSegment(const Point& a, const Point& b, const Point& p) {
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) && min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

bool intersect(Point a, Point b, Point c, Point d) {
    ll d1 = a.cross(b, c);
    ll d2 = a.cross(b, d);
    ll d3 = c.cross(d, a);
    ll d4 = c.cross(d, b);

    if ((d1 > 0) != (d2 > 0) && (d3 > 0) != (d4 > 0)) return 1;
    if (d1 == 0 && onSegment(a, b, c)) return 1;
    if (d2 == 0 && onSegment(a, b, d)) return 1;
    if (d3 == 0 && onSegment(c, d, a)) return 1;
    if (d4 == 0 && onSegment(c, d, b)) return 1;
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 4; i++)
            P[i].read();

        cout << (intersect(P[0], P[1], P[2], P[3]) ? "YES\n" : "NO\n");
    }

    return 0;
}
