#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

ll min(ll a, ll b) { return (a <= b) ? a : b;}

int main() {
    int n; ll k, v;
    scanf("%i %lli %lli", &n, &k, &v);

    ll ans = k+1;

    for (int i = 0; i < n-1; i++) {
        ll a;
        scanf("%lli", &a);
        ans += min(k+1, a-v);
        v=a;
    }

    printf("%lli", ans);
}
