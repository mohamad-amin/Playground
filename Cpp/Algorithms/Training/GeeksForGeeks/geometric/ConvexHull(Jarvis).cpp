/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/22/17
 * Problem url: http://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
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

short LINEAR = 0, CLOCK = 1, CCLOCK = 2;

short orientation(pii x, pii y, pii z) {
    long o = (long) (y.Y - x.Y) * (z.X - y.X) - (z.Y - y.Y) * (y.X - x.X);
    if (o == 0) {
        return LINEAR;
    } else {
        return o > 0 ? CLOCK : CCLOCK;
    }
}

pii points[N];

struct XGreater {
    bool operator()(const pii& l, const pii& h) const {
        if (l.X == h.X) {
            return l.Y < h.Y;
        } else {
            return l.X < h.X;
        }
    }
};

void solve(int n) {

    if (n < 3) {
        cout << -1 << endl;
        return;
    }

    int l = 0;
    vector<pii> hull;

    FOR(i, 1, n) {
        if (points[i].X < points[l].X) {
            l = i;
        }
    }
    int p = l, q;

    do {

        hull.pb(points[p]);

        q = (p+1) % n;

        REP(i, n) {
            if (orientation(points[p], points[q], points[i]) == CCLOCK) {
                q = i;
            }
        }

        p = q;

    } while (p != l);

    sort(hull.begin(), hull.end(), XGreater());

    REP(i, hull.size()) {
        cout << hull[i].X << " " << hull[i].Y;
        if (i + 1 != hull.size()) {
            cout << ", ";
        }
    }
    cout << endl;


}

int xmain() {

    int t, n, a, b;

    cin >> t;
    REP(i, t) {
        cin >> n;
        REP(j, n) {
            cin >> a >> b;
            points[j] = mp(a, b);
        }
        solve(n);
    }

    return 0;

}