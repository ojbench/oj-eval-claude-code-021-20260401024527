#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<long long, long long>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    // Sort by x-coordinate
    sort(points.begin(), points.end());

    long long count = 0;

    // For each potential bottom-left corner
    for (int i = 0; i < n; i++) {
        // Collect y-coordinates of points between i and j (exclusive)
        multiset<long long> y_between;

        // For each potential top-right corner (with larger x)
        for (int j = i + 1; j < n; j++) {
            // Check if this can form a rectangle with points[i] as bottom-left
            if (points[j].second > points[i].second) {
                // Check if any point in y_between has y in range (y_i, y_j)
                // We need to find if there exists y such that points[i].second < y < points[j].second
                auto it = y_between.upper_bound(points[i].second);
                if (it == y_between.end() || *it >= points[j].second) {
                    // No point strictly between y_i and y_j
                    count++;
                }
            }

            // Add current point's y to between set for next iterations
            y_between.insert(points[j].second);
        }
    }

    cout << count << endl;

    return 0;
}
