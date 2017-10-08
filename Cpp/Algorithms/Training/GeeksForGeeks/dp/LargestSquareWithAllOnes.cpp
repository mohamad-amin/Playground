/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/24/17
 * Problem url: http://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
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
#define N 51
#define M 1001

long a[N][N];
int n, m;

void solve(int n, int m) {

    long answer = 0L;

    REP(i, n) {
        if (a[i][0] == 1) answer = 1L;
    }
    REP(j, m) {
        if (a[0][j] == 1) answer = 1L;
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            if (a[i][j] == 1) {
                a[i][j] = max(1L, min(a[i-1][j-1], min(a[i][j-1], a[i-1][j])) + 1);
                answer = max(answer, a[i][j]);
            }
        }
    }

    cout << answer << endl;

}

int main() {

    int t, n, m;
    cin >> t;

    REP (i, t) {
        cin >> n;
        cin >> m;
        REP (i, n) {
            REP (j, m) {
                cin >> a[i][j];
            }
        }
        solve(n, m);
    }

    return EXIT_SUCCESS;

}