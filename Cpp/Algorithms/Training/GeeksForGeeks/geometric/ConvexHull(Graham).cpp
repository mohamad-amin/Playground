/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/22/17
 * Problem url: http://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pii, int> p3i;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<p3i> v3i;
typedef vector<vii> vvii;
typedef vector<p3i> vp3i;
typedef long double ld;
typedef vector<ld> vld;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define REPD(i, n) for (int (i) = (n) - 1; (i) >= 0; (i)--)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define FORD(i,a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rv(v) reverse(all(v))
#define CL(v, val) memset((v), (val), sizeof((v)))
#define SORT(a) sort(all(a))
#define un(v) SORT(v), (v).resize(unique(all(v)) - (v).begin())
#define eps 1.0e-11
#define X first
#define Y second
#define bit(n) (1 << (n))
#define bit64(n) (ll(1) << (n))
#define sqr(x) ((x) * (x))
#define N 101
#define M 1001

struct Point {
    int x, y;
};

Point pivot;

Point nextToTop(stack<Point> s) {
    Point p = s.top();
    s.pop();
    Point result = s.top();
    s.push(p);
    return result;
}

int distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool comparePoints(Point l, Point r) {
    // Find orientation
    int o = orientation(pivot, l, r);
    if (o == 0)
        return distSq(pivot, l) <= distSq(pivot, r);
    return o == 2;
}

void grahamScan(Point points[], int n) {
    
    int ymin = points[0].y, l = 0;
    for (int i = 1; i < n; i++) {
        int y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[l].x))
            ymin = points[i].y, l = i;
    }
    swap(points[0], points[l]);

    pivot = points[0];
    sort(points + 1, points + n, comparePoints);

    int m = 1; // Initialize size of modified array
    for (int i=1; i<n; i++) {
        while (i < n-1 && orientation(pivot, points[i], points[i+1]) == 0)
            i++;
        points[m++] = points[i];
    }

    if (m < 3) return;

    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    for (int i = 3; i < m; i++) {
        while (orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    while (!S.empty()) {
        Point p = S.top();
        cout << "(" << p.x << ", " << p.y <<")" << endl;
        S.pop();
    }

}

int main() {
    Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    grahamScan(points, n);
    return 0;
}