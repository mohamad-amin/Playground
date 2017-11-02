/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/22/17
 * Problem url: http://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
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
#define N 15001
#define M 1001

short LINEAR = 0, CLOCK = 1, CCLOCK = 2;

void print(pii a, string x) {
    cout << "(" << a.X << "," << a.Y << ") " << x << " ";
}

short orientation(pii x, pii y, pii z) {
    long long o = (y.Y - x.Y) * (z.X - y.X) - (z.Y - y.Y) * (y.X - x.X);
    if (o == 0) {
        return LINEAR;
    } else {
        return o > 0 ? CLOCK : CCLOCK;
    }
}

bool onSegment(pii a, pii m, pii b) {
    return m.X <= max(a.X, b.X) && m.X >= min(a.X, b.X)
           && m.Y <= max(a.Y, b.Y) && m.Y >= min(a.Y, b.Y);
}

bool intersect(pii a, pii b, pii x, pii y) {

    short o1 = orientation(a, b, x);
    short o2 = orientation(a, b, y);
    short o3 = orientation(x, y, a);
    short o4 = orientation(x, y, b);

    if (o1 != o2 && o3 != o4) {
        return true;
    }

    if (o1 == LINEAR && onSegment(a, x, b)) return true;
    if (o2 == LINEAR && onSegment(a, y, b)) return true;
    if (o3 == LINEAR && onSegment(x, a, y)) return true;
    if (o4 == LINEAR && onSegment(x, b, y)) return true;

    return false;

}

int main() {

    int t, a, b;
    pii m, n, o, p;

    cin >> t;
    REP(i, t) {
        cin >> a >> b;
        m = mp(a, b);
        cin >> a >> b;
        n = mp(a, b);
        cin >> a >> b;
        o = mp(a, b);
        cin >> a >> b;
        p = mp(a, b);
        if (intersect(m, n, o, p)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;

}