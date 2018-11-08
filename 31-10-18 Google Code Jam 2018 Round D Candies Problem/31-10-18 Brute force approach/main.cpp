/*
Code developed by Arka
*/
//Bad Solution
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define maxn 9223372036854775807
#define Fox(i,n) for(auto i=0;i<n;i++)
#define Fox1(i,n) for(auto i=1;i<=n;i++)
#define Foxi(i,a,b) for(auto i=a;i<=b;i++)
#define rep(i,a,n) for (auto i=a;i<n;i++)
#define per(i,a,n) for (auto i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define INF 1000000
using namespace std;

int main()
{
    int test,currentTestCase=1;
    ll n,o,d,m,l,a,b,c,sum,maxSum,oddCount;
    cin>>test;
    while(currentTestCase<=test)
    {
        cin>>n>>o>>d;
        int s[n+1];
        cin>>s[1]>>s[2]>>a>>b>>c>>m>>l;
        Foxi(i,3,n) s[i]=((a*s[i-1])+(b*s[i-2])+c)%m;
        Fox1(i,n) s[i] += l;
        maxSum=-maxn;
        Fox1(i,n)
        Foxi(j,i,n)
        {
            sum=0;
            oddCount=0;
            Foxi(k,i,j)
            {
                if(s[k]&1)
                {
                    oddCount++;
                }
                if(oddCount>o) { sum=-maxn;break;}
                sum += s[k];
                if(sum>d) { sum=-maxn;break;}
            }
            maxSum = max(sum,maxSum);
        }
        if(maxSum!=-maxn)
            cout<<"Case #"<<currentTestCase<<": "<<maxSum<<endl;
        else
            cout<<"Case #"<<currentTestCase<<": IMPOSSIBLE"<<endl;
        currentTestCase++;
    }
}
