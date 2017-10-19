/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/24/17
 * Problem url: http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/
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

char a[N][N];
bool v[N][N];
int n, m;

bool visit(int i, int j) {
    if (i < n && j < m && i > -1 && j > -1 && a[i][j] == 'X' && !v[i][j]) {
        v[i][j] = true;
        return true;
    } else {
        return false;
    }
}

void dfs(int i, int j) {
    if (visit(i, j)) {
        dfs(i, j+1);
        dfs(i, j-1);
        dfs(i+1, j);
        dfs(i-1, j);
    }
}

void solve() {

    int answer = 0;

    REP(i, n) {
        REP(j, m) {
            if (a[i][j] == 'X' && !v[i][j]) {
                answer++;
                dfs(i, j);
            }
        }
    }

    cout << answer << endl;

}

int main() {

    int t;
    cin >> t;
    REP(test, t) {
        cin >> n >> m;
        REP(i, n) {
            REP(j, m) {
                cin >> a[i][j];
                v[i][j] = false;
            }
        }
        solve();
    }

    return EXIT_SUCCESS;

}