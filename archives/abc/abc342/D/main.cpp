#include "../../lib.hpp"

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vi A(N);
    cin >> A;
    map<vi, ll> mp;
    ll zero_cnt = 0;
    rep(i, N) {
        ll a = A[i];
        if (a == 0) {
            zero_cnt++;
            continue;
        }
        map<ll, ll> primes;
        for (ll j = 2; j * j <= a; j++) {
            if (a % j == 0) {
                ll cnt = 0;
                while (a % j == 0) {
                    a /= j;
                    cnt++;
                }
                primes[j] = cnt;
            }
        }
        vi vec;
        for (auto [k, v] : primes) {
            if (v % 2 == 1) vec.push_back(k);
        }
        if (a > 1) vec.push_back(a);
        mp[vec]++;
    }
    ll ans = 0;
    for (auto [k, v] : mp) {
        ans += (ll)v * (v - 1) / 2;
    }
    ans += (ll)zero_cnt * (N - 1) - zero_cnt * (zero_cnt - 1) / 2;
    cout << ans << endl;
}
