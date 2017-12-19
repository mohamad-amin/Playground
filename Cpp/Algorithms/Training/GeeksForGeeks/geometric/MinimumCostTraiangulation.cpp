/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 12/19/17
 * Problem url: http://www.geeksforgeeks.org/minimum-cost-polygon-triangulation/
 */
#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
};

double dist(Point a, Point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double perimiter(Point a, Point b, Point c) {
	return dist(a, b) + dist(b, c) + dist(c, a);
}

double minCostTraiangulation(Point *points, int n) {

	if (n < 3) {
		return 0.0;
	}	

	double dp[n][n];

	for (int gap = 0; gap < n; gap++) {
		for (int i=0, j=gap; j < n; i++, j++) {
			if (j < i + 2) {
				dp[i][j] = 0.0;
			} else {
				dp[i][j] = INT_MAX + 0.0;
				for (int k = i+1; k < j; k++) {
					dp[i][j] =  min(dp[i][j], dp[i][k] + perimiter(points[i], points[k], points[j]) + dp[k][j]);
				}
			}
		}
	}

	return dp[0][n-1];

}

int main() {
	Point points[] = {{0, 0}, {1, 0}, {2, 1}, {1, 2}, {0, 2}};
    int n = sizeof(points)/sizeof(points[0]);
    cout << minCostTraiangulation(points, n) << endl;
    return 0;
}