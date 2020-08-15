#include <bits/stdc++.h>

using namespace std;
bool exist(int n,vector<vector<int> >& dp,vector<int> v,int& start,int& endd)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            dp[i][j]=((j==0)?0:dp[i][j-1])+v[j];
            if(dp[i][j]%2==0)
            {
                start=i;
                endd=j;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n,0);
        for(int i=0;i<n;i++)
            cin>>v[i];

        vector<vector<int> > dp(n,vector<int>(n,0));
        int start=-1,endd=-1;
        bool b=exist(n,dp,v,start,endd);
        /*for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<dp[i][j]<<" ";
            cout<<"\n";
        }*/
        if(!b)
            cout<<-1<<"\n";
        else
        {
            cout<<endd-start+1<<"\n";
            for(int i=start;i<=endd;i++)
                cout<<i+1<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
