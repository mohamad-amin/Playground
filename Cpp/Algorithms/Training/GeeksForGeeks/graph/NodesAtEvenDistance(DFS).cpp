/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 9/24/17
 * Problem url: http://practice.geeksforgeeks.org/problems/nodes-at-even-distance/0
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

class Graph {

    int v;
    list<int> *adj;

public:
    Graph(int v);
    void addEdge(int a, int b);
    void solve(int src);

private:
    pii solveInternal(int src, bool *visited);

};


Graph::Graph(int v) {
    this->v = v;
    this->adj = new list<int>[v];
}

void Graph::addEdge(int a, int b) {
    this->adj[a].pb(b);
    this->adj[b].pb(a);
}

void Graph::solve(int src) {

    bool visited[v];
    REP(i, v) visited[i] = false;
    pii oe = solveInternal(src, visited);

    ll x = oe.X;
    ll y = oe.Y;
    ll ans = (x * (x-1)) / 2 + (y * (y-1)) / 2;
    cout << ans << endl;

}

pii Graph::solveInternal(int src, bool *visited) {

    list<int>::iterator i;
    pii result = mp(0, 0);
    pii child;

    visited[src] = true;
    for (i = adj[src].begin(); i != adj[src].end(); i++) {
        if (!visited[*i]) {
            child = solveInternal(*i, visited);
            result.X += child.Y + 1;
            result.Y += child.X;
        }
    }

    return result;

}

int main() {

    int t, v, a, b;
    cin >> t;

    REP(i, t) {
        cin >> v;
        Graph g(v);
        REP(j, v-1) {
            cin >> a >> b;
            g.addEdge(a-1, b-1);
        }
        g.solve(a-1);
    }

    return EXIT_SUCCESS;

}