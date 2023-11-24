#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n; ll t;
    cin >> n >> t;
    vector<pair<ll, int>> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i].first;
        nums[i].second = i;
    }
    sort(nums.begin(), nums.end());
 
    tuple<int, int, int> ans = {-1, -1, -1};
 
    for (int i = 0; i < n; i++) {
        int p1 = 0, p2 = n-1;
 
        while (p2 > p1) {
            if (p2 == i) {
                p2--;
                continue;
            }
            if (p1 == i) {
                p1++;
                continue;
            }
 
            if (nums[p1].first + nums[p2].first + nums[i].first == t) {
                ans = {nums[p1].second+1, nums[p2].second+1, nums[i].second+1};
                break;
            } else if (nums[p1].first + nums[p2].first + nums[i].first < t) {
                p1++;
            } else {
                p2--;
            }
        }
    }
 
    if (get<0>(ans) != -1) {
        cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans) << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }
}