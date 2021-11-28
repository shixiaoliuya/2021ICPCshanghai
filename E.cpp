#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N], k, n;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1;i <= n; ++i) scanf("%d", &a[i]);
    sort(a+1, a+1+n);
    int cnt = 1, pre = a[1];
    for (int i = 2;i <= n; ++i)
    {
        if ((a[i]-pre) >= k)
        {
            pre = a[i];
            cnt++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}
