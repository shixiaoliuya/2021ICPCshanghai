#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[50010];
int ans[50010];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(a[i-1]=='1')
                dp[i]=dp[i-1]+1;
            else
                dp[i]=dp[i-1];
            //cout<<dp[i];
        }
        for(int k=1;k<=n;k++){
            int flag=0;
            for(int i=1;i<=n;i++){
                int l=max(i-k+1,1);
                int F=dp[i]-dp[l-1];
                if(F>(i-l+1)/2)
                    F=1;
                else
                    F=0;
                ans[k]=1;
                if(F!=b[i-1]-'0'){
                    ans[k]=0;
                    break;
                }
                if(k==i&&F==0){
                    for(int j=k+1;j<=n;j++)
                        ans[j]=0;
                    flag=1;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<(ans[i]==b[i-1]-'0'?1:0);
        }
        cout<<endl;
    }
    return 0;
}

