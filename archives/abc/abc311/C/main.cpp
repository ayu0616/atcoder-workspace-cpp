#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vi a(n);
    for (auto &&i : a)
    {
        cin >> i;
        i--;
    }
    vector<int> visited(n, false);
    deque<int> q;
    q.push_back(0);
    visited[0] = true;
    while (!q.empty())
    {
        int now = q.front();
        q.pop_front();
        int next = a[now];
        if(!visited[next]){
            visited[next] = true;
            q.push_back(next);
        }else{
            vi ans;
            ans.push_back(now+1);
            while (now != next)
            {
                ans.push_back(next+1);
                next = a[next];
            }
            cout<<ans.size()<<endl;
            cout<<ans<<endl;
            return 0;
        }
    }
}
