#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

struct District {
    int i, j;
};

struct Citizen {
    District home, work;
};

int main() {
    int N, M, K, T;
    cin >> N >> M >> K >> T;
    vector<Citizen> citizens(N);
    rep(i, M) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        citizens[i] = Citizen{{a, b}, {c, d}};
    }
}
