#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct Point {
    long long x, y;
    int id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].id = i;
    }

    // Sort points by x-coordinate, then by y-coordinate
    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    long long count = 0;

    // For each pair of points, check if they can form an empty rectangle
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // points[i] is bottom-left candidate, points[j] is top-right candidate
            if (points[i].x >= points[j].x || points[i].y >= points[j].y) {
                continue; // Not a valid rectangle (not bottom-left to top-right)
            }

            // Check if any point lies inside or on the boundary (except the two corners)
            bool empty = true;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;

                // Check if point k is inside or on the boundary of the rectangle
                if (points[k].x >= points[i].x && points[k].x <= points[j].x &&
                    points[k].y >= points[i].y && points[k].y <= points[j].y) {
                    empty = false;
                    break;
                }
            }

            if (empty) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
