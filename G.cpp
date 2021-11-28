#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
const int MOD = 998244353;

int n;
vector<int> G[N];

ll dp[N], cnt[N], dp2[N];
ll fac[N];

void dfs(int u, int pre)
{
    int tmp_cnt = 0;
    for (auto v: G[u]) if (v != pre) tmp_cnt++;
    for (auto v: G[u]) if (v != pre)
    {

        dfs(v, u);
        //cout << u << ' ' << v << ' ' << cnt[v] << endl;
        if (cnt[v]%2 == 1)
        {
            tmp_cnt--;
            dp[v] = (fac[cnt[v]+1] * dp2[v])%MOD;
            //cout << dp2[v] << endl;
            dp2[u] = (dp2[u] * dp[v])%MOD;
        }
        else
        {
            dp[v] = (fac[cnt[v]] * dp2[v])%MOD;
            dp2[u] = (dp2[u] * dp[v])%MOD;
        }
    }
    cnt[u] = tmp_cnt;
}

int main()
{
    fac[2] = fac[0] = 1;
    for (int i = 4;i < N; i += 2)
    {
        fac[i] = (fac[i-2]*(i-1)%MOD);
    }
    scanf("%d", &n);
    for (int i = 1;i <= n; ++i) dp2[i] = 1;
    for (int i = 1;i < n; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0);
    printf ("%lld\n", fac[cnt[1]] * dp2[1]%MOD);

    return 0;
}
/*
5
1 2
1 3
3 4
3 5
*/
