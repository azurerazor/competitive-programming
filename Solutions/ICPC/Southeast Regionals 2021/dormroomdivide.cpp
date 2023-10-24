#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cross(ll x1, ll y1, ll x2, ll y2) {
    return x1 * y2 - y1 * x2;
}

int main() {
    int n;
    cin >> n;

    vector<pair<ll, ll>> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    ll totalArea = 0;

    for (int i = 1; i < n - 1; i++) {
        totalArea += abs(cross(points[i].first - points[0].first, 
            points[i].second - points[0].second, 
            points[i + 1].first - points[0].first, 
            points[i + 1].second - points[0].second));
    }

    ll area = 0;
    double x, y;

    for (int p = 1; p < n - 1; p++) {
        area += abs(cross(points[p].first - points[0].first, 
            points[p].second - points[0].second, 
            points[p + 1].first - points[0].first, 
            points[p + 1].second - points[0].second)) * 2;

        if (area >= totalArea) {
            ll triArea = abs(cross(points[p].first - points[0].first, 
                points[p].second - points[0].second, 
                points[p + 1].first - points[0].first, 
                points[p + 1].second - points[0].second)) * 2;

            area -= triArea;

            ll remArea = totalArea - area;

            double ratio = (double) remArea / (double) triArea;

            x = (points[p + 1].first - points[p].first) * ratio + points[p].first;
            y = (points[p + 1].second - points[p].second) * ratio + points[p].second;
            break;
        }
    }

    cout << fixed << setprecision(10) << x << ' ' << y << '\n';

    return 0;
}