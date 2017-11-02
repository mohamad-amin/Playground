/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/24/17
 * Problem url: http://www.geeksforgeeks.org/dynamic-programming-set-27-max-sum-rectangle-in-a-2d-matrix/
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

void solve(int n, int m, int **a) {

    long temp[n][m];
    long maxToHere[n];
    long answer = INT_MIN;

    REP(i, n) {
        maxToHere[i] = INT_MIN;
    }

    REP(i, n) {
        temp[i][0] = a[i][0];
        FOR(j, 1, m) {
            temp[i][j] = temp[i][j-1] + a[i][j];
        }
    }

    REP(i, m) {
        FOR(j, i, m) {
            REP(k, n) {
                long thisRow = temp[k][j] - temp[k][i] + a[k][i];
                if (k == 0) {
                    maxToHere[k] = thisRow;
                } else {
                    maxToHere[k] = max(thisRow, thisRow + maxToHere[k-1]);
                }
                answer = max(answer, maxToHere[k]);
            }
        }
    }

    cout << answer << endl;

}

int main() {

    int t, n, m;
    cin >> t;

    REP (k, t) {
        cin >> n;
        cin >> m;
        int **a;
        a = new int*[n];
        REP(i, n) a[i] = new int[m];
        REP (i, n) {
            REP (j, m) {
                cin >> a[i][j];
            }
        }
        solve(n, m, a);
    }

    return EXIT_SUCCESS;

}