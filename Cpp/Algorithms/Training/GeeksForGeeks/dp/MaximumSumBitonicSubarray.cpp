/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/22/17
 * Problem url: http://www.geeksforgeeks.org/maximum-sum-bitonic-subarray/
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

    long h[n];
    long answer;
    bool increasing = true;

    REP (i, n) {
        h[i] = -1;
    }

    answer = h[0] = a[0];

    FOR (i, 1, n) {
        if (a[i] > a[i-1]) {
            if (increasing) {
                h[i] = h[i-1] + a[i];
            } else {
                h[i] = a[i-1] + a[i];
            }
            answer = max(answer, h[i]);
            increasing = true;
        } else if (a[i] < a[i-1]) {
            h[i] = h[i-1] + a[i];
            answer = max(answer, h[i]);
            increasing = false;
        } else {
            h[i] = a[i];
            answer = max(answer, h[i]);
            increasing = true;
        }
    }

    cout << answer << endl;

}

int xmain() {

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