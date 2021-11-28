#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[105][1305][105];
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
    dp[0][50*13][0] = 0;
    for (int i = 1;i <= n; ++i)
    {
            for (int k = -50*13;k <= 50*13; ++k)
            {
                for (int l = 0;l <= k; ++l)
                {
                    if (k+50*13+t[i] < 1305 && dp[i-1][k+50*13][l] != -1)
                        dp[i][k+50*13+t[i]][l] =
                        max(dp[i][k+50*13+t[i]][l], dp[i-1][k+50*13][l]+v[i]);

                    if (l+1 <= k && k+50*13+t[i]*2 < 1305 && l > 1 && dp[i-1][k+50*13][l-1] != -1)
                        dp[i][k+50*13+t[i]*2][l] =
                        max(dp[i][k+50*13+t[i]*2][l], dp[i-1][k+50*13][l-1]+v[i]);

                    if (k+50*13-t[i] >= 0 && dp[i-1][k+50*13][l] != -1)
                        dp[i][k+50*13-t[i]][l] =
                        max(dp[i][k+50*13-t[i]][l], dp[i-1][k+50*13][l]+v[i]);

                    if (l+1 <= k && k+50*13-t[i]*2 >= 0 && l > 1 && dp[i-1][k+50*13][l] != -1)
                        dp[i][k+50*13-t[i]*2][l] =
                        max(dp[i][k+50*13-t[i]*2][l], dp[i-1][k+50*13][l]+v[i]);
                    //assert(p^1 == 0 || p^1 == 1);
                    if (dp[i-1][k+50*13][l] != -1) dp[i][k+50*13][l] =
                        max(dp[i][k+50*13][l], dp[i-1][k+50*13][l]);
                    if (l > 1 && dp[i-1][k+50*13][l-1] != -1)
                        dp[i][k+50*13][l] = max(dp[i][k+50*13][l], dp[i-1][k+50*13][l-1]);
                }
            }
    }
    ll ans = 0;
    for (int i = 0;i <= k; ++i) ans = max(ans, dp[n][50*13][i]);
    printf("%lld\n", ans);

    return 0;
}
