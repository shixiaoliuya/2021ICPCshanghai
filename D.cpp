#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int p, q;


struct Fac
{
    ll p, q;

    void gcd()
    {
        ll d = __gcd(p, q);
        p /= d;
        q /= d;
    }

    bool isSqrt()
    {
        ll a = sqrt((double)p);
        ll b = sqrt((double)q);
        //cout << "in" << endl;
        return (a*a == p && b*b == q);
    }

    void Sqrt()
    {
        p = sqrt(p);
        q = sqrt(q);
    }

    void mul(ll x)
    {
        p *= x;
        q *= x;
    }
};

void solve()
{
    scanf("%d%d", &q, &p);
    Fac fb;
    fb.p = p;
    fb.q = q;

    Fac dlt;
    dlt.p = p;
    dlt.q = q;

    dlt.p = dlt.p * dlt.p;
    dlt.q = dlt.q * dlt.q;
    dlt.gcd();
    dlt.q = dlt.q - dlt.p*4;
    if (dlt.q < 0)
    {
        puts("0 0");
        return;
    }
    dlt.gcd();
    if (!dlt.isSqrt())
    {
        puts("0 0");
        return;
    }
    dlt.Sqrt();
    //cout << fb.q << ' ' << fb.p << endl;
    //cout << dlt.q << ' ' << dlt.p << endl;'
    ll dltp = dlt.p;
    ll fbp = fb.p;
    fb.mul(dltp);
    dlt.mul(fbp);
    //cout << fb.q << ' ' << fb.p << endl;
    //cout << dlt.q << ' ' << dlt.p << endl;

    fb.q += dlt.q;
    //cout << fb.q << ' ' << fb.p << endl;
    fb.p *= 2;
    fb.gcd();
    printf("%lld %lld\n", min(fb.q, fb.p), max(fb.p, fb.q));
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) solve();

    return 0;
}
