#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &points[i].first, &points[i].second);
    }

    // Sort by x-coordinate
    sort(points.begin(), points.end());

    long long count = 0;

    // For each potential bottom-left corner
    for (int i = 0; i < n; i++) {
        set<int> y_set;

        // For each potential top-right corner (with larger x)
        for (int j = i + 1; j < n; j++) {
            int y_i = points[i].second;
            int y_j = points[j].second;

            // Check if this can form a rectangle with points[i] as bottom-left
            if (y_j > y_i) {
                // Check if any point in y_set has y in range (y_i, y_j)
                auto it = y_set.upper_bound(y_i);
                if (it == y_set.end() || *it >= y_j) {
                    count++;
                }
            }

            y_set.insert(y_j);
        }
    }

    printf("%lld\n", count);

    return 0;
}
