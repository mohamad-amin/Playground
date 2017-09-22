/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/22/17
 * Problem url: http://www.geeksforgeeks.org/maximum-sum-bi-tonic-sub-sequence/
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

void solve(const int a[], int n) {

    // dp[i][j] = max sum ending at i, j = 0 -> increasing, j = 1 -> decreasing
    long dp[n][2];
    int increasing = 0, decreasing = 1;
    long answer = -1;

    REP (i, n) {
        dp[i][0] = dp[i][1] = a[i];
    }

    answer = dp[0][0];

    FOR (i, 1, n) {
        REP (k, i) {
            if (a[k] < a[i]) {
                dp[i][increasing] = max(dp[i][increasing], dp[k][increasing] + a[i]);
            } else if (a[k] > a[i]) {
                dp[i][decreasing] =
                        max(dp[i][decreasing],
                            max(dp[k][decreasing] + a[i], dp[k][increasing] + a[i])
                        );
            }
        }
        answer = max(answer, max(dp[i][increasing], dp[i][decreasing]));
    }

    cout << answer << endl;

}

int main() {

    int t, n;
    cin >> t;

    REP (i, t) {
        cin >> n;
        int a[n];
        REP (j, n) {
            cin >> a[j];
        }
        solve(a, n);
    }

    return EXIT_SUCCESS;

}