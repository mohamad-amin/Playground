/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/22/17
 * Problem url: http://www.geeksforgeeks.org/count-triplets-whose-sum-equal-perfect-cube/
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

// dp[i][j] = number of occurance of j in Array[i, i+1, ..., n-1]
int dp[M][N];

void calculateDp(int items[], int n) {

    dp[n-1][items[n-1]] = 1;

    REP(j, N) {
        FORD(i, n-2, 0) {
            dp[i][j] = dp[i+1][j] + ((items[i] == j) ? 1 : 0);
        }
    }

}

int main() {

    int n;
    int items[M];

    cin >> n;
    REP(i, n) {
        cin >> items[i];
    }

    calculateDp(items, n);

    int count = 0;
    REP(i, n-2) {
        FOR(j, i+1, n-1) {
            // 25 = (15000^(1/3)) + 1
            REP(k, 25) {
                int cube = k * k * k;
                int remaining = cube - (items[i] + items[j]);
                if (remaining > 0) {
                    count += dp[j+1][remaining];
                }
            }
        }
    }

    cout << count << endl;
    return 0;

}