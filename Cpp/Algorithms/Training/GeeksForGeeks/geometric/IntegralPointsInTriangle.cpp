/**
 * Created by Mohamad Amin Mohamadi (mohammadi.mohamadamin@gmail.com) on 12/19/17
 * Problem url: http://www.geeksforgeeks.org/count-integral-points-inside-a-triangle/
 */
#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x, y;
};

int countIntegralPointsInLine(Point a, Point b) {
	if (a.x == b.x) {
		return abs(a.y - b.y) - 1;
	}
	if (a.y == b.y) {
		return abs(a.x - b.x) - 1;
	}
	return __gcd(abs(a.x - b.x), abs(a.y - b.y)) - 1;
}

int area2(Point a, Point b, Point c) {
	int p = a.x * b.y + b.x * c.y + c.x * a.y;
	int m = a.y * b.x + b.y * c.x + c.y * a.x;
	return (p - m); 
}

int countIntegralPointsInTriangle(Point a, Point b, Point c) {
	int A2 = area2(a, b, c);
	int B = 3 + countIntegralPointsInLine(a, b) 
			  + countIntegralPointsInLine(a, c) 
			  + countIntegralPointsInLine(b, c);
	return (A2 - B + 2) / 2;
}

int main() {
	Point p{0, 0};
    Point q{5, 0};
    Point r{0, 5};
    cout << "Number of integral points inside given triangle is " << countIntegralPointsInTriangle(p, q, r) << endl;
	return 0;
}