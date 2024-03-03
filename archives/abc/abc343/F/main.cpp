#include "../../lib.hpp"

struct NumCnt {
    ll num;
    ll cnt;
};

struct Node {
    NumCnt first;
    NumCnt second;
};

bool operator<(const NumCnt &a, const NumCnt &b) { return a.num < b.num; }
bool operator>(const NumCnt &a, const NumCnt &b) { return a.num > b.num; }
bool operator==(const NumCnt &a, const NumCnt &b) { return a.num == b.num; }

bool operator<(const Node &a, const Node &b) { return a.first < b.first; }
bool operator>(const Node &a, const Node &b) { return a.first > b.first; }
bool operator==(const Node &a, const Node &b) { return a.first == b.first; }

struct ST {
   private:
    int n;
    vector<Node> dat;

   public:
    ST(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        dat.resize(2 * n - 1, {{-1, 0}, {-2, 0}});
    }

    void update(int i, ll x) {
        i += n - 1;
        dat[i] = {{x, 1}, {-1, 0}};
        while (i > 0) {
            i = (i - 1) / 2;
            Node left = dat[i * 2 + 1];
            Node right = dat[i * 2 + 2];
            ll first = -1, second = -2;
            for (auto &e : {left.first, left.second, right.first, right.second}) {
                if (e.num > first) {
                    second = first;
                    first = e.num;
                } else if (e.num > second && e.num != first) {
                    second = e.num;
                }
            }
            dat[i].first = {first, 0};
            dat[i].second = {second, 0};
            for (auto &e : {left.first, left.second, right.first, right.second}) {
                if (e.num == first) dat[i].first.cnt += e.cnt;
                if (e.num == second) dat[i].second.cnt += e.cnt;
            }
        }
    }

    Node query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return {{-1, 0}, {-2, 0}};
        if (a <= l && r <= b) return dat[k];

        Node vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        Node vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        ll first = -1, second = -2;
        for (auto &e : {vl.first, vl.second, vr.first, vr.second}) {
            if (e.num > first) {
                second = first;
                first = e.num;
            } else if (e.num > second && e.num != first) {
                second = e.num;
            }
        }
        NumCnt firstCnt = {first, 0};
        NumCnt secondCnt = {second, 0};
        for (auto &e : {vl.first, vl.second, vr.first, vr.second}) {
            if (e.num == first) firstCnt.cnt += e.cnt;
            if (e.num == second) secondCnt.cnt += e.cnt;
        }
        return {firstCnt, secondCnt};
    }

    // @brief [a, b)の最小値を求める
    Node query(int a, int b) { return query(a, b, 0, 0, n); }

    Node operator[](int a) { return query(a, a + 1); }
};

int main() {
    cout << fixed << setprecision(18);
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    cin >> A;
    ST st(N);
    for (int i = 0; i < N; i++) st.update(i, A[i]);

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            A[p - 1] = x;
            st.update(p - 1, x);
        } else {
            int l, r;
            cin >> l >> r;
            l--;
            Node res = st.query(l, r);
            cout << res.second.cnt << endl;
        }
    }
}
