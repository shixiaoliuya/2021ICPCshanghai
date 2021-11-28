#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[3][1305][105];
int n, k;
ll v[110], t[110];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1;i <= n; ++i)
    {
        scanf("%lld%lld", &v[i], &t[i]);
    }
    memset(dp, -1, sizeof(dp));
    int p = 0;
    dp[p][50*13][0] = 0;
    for (int i = 1;i <= n; ++i)
    {
            for (int k = -50*13;k <= 50*13; ++k)
            {
                for (int l = 0;l <= k; ++l)
                {
                    if (dp[p][k+50*13][l] == -1) continue;
                    if (k+50*13+t[i] < 1305) dp[p^1][k+50*13+t[i]][l] =
                        max(dp[p^1][k+50*13+t[i]][l], dp[p][k+50*13][l]+v[i]);

                    if (l+1 <= k && k+50*13+t[i]*2 < 1305) dp[p^1][k+50*13+t[i]*2][l+1] =
                        max(dp[p^1][k+50*13+t[i]*2][l+1], dp[p][k+50*13][l]+v[i]);

                    if (k+50*13-t[i] >= 0) dp[p^1][k+50*13-t[i]][l] =
                        max(dp[p^1][k+50*13-t[i]][l], dp[p][k+50*13][l]+v[i]);

                    if (l+1 <= k && k+50*13-t[i]*2 >= 0) dp[p^1][k+50*13-t[i]*2][l+1] =
                        max(dp[p^1][k+50*13-t[i]*2][l+1], dp[p][k+50*13][l]+v[i]);
                    //assert(p^1 == 0 || p^1 == 1);
                    dp[p^1][k+50*13][l] = max(dp[p^1][k+50*13][l], dp[p][k+50*13][l]);
                    if (l+1 <= k) dp[p^1][k+50*13][l+1] = max(dp[p^1][k+50*13][l+1], dp[p][k+50*13][l]);
                }
            }
        p ^= 1;
    }
    ll ans = 0;
    for (int i = 0;i <= k; ++i) ans = max(ans, dp[p][50*13][i]);
    printf("%lld\n", ans);

    return 0;
}
