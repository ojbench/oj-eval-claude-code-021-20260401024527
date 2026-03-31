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

    // For each potential bottom-left corner
    for (int i = 0; i < n; i++) {
        // Collect all points to the right of point i
        set<long long> y_coords;

        // For each potential top-right corner
        for (int j = i + 1; j < n; j++) {
            // Check if points[j] can be top-right corner with points[i] as bottom-left
            if (points[j].y > points[i].y) {
                // Before considering this as top-right, check if the rectangle is empty
                // We need to ensure no point in y_coords is in the range [points[i].y, points[j].y]

                // Find if any y-coordinate in the set is within the range (points[i].y, points[j].y)
                auto it = y_coords.upper_bound(points[i].y);
                if (it == y_coords.end() || *it >= points[j].y) {
                    // No point in between, this is a valid empty rectangle
                    count++;
                }
            }

            // Add current point's y-coordinate to the set for future checks
            y_coords.insert(points[j].y);
        }
    }

    cout << count << endl;

    return 0;
}
