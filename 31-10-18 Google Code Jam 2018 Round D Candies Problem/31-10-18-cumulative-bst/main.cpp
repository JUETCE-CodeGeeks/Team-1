/*
Code developed by Arka
*/
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <cstdio>
#include<set>
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define maxn 9223372036854775807
#define maxN 500010
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

int s[maxN];
ll sum[maxN];

void eraseSingleElement(multiset<long long> &s, long long key) {
	auto itr = s.find(key);
	auto _itr = itr;
	_itr++;
	s.erase(itr, _itr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test,currentTestCase=1;
    ll n,o,d,m,l,L,a,b,c,maxSum,oddCount;
    cin>>test;
    while(currentTestCase<=test)
    {
        oddCount=0;
        maxSum=-maxn;
        cin>>n>>o>>d;
        cin>>s[1]>>s[2]>>a>>b>>c>>m>>L;
        Foxi(i,3,n) s[i]=((a*s[i-1])+(b*s[i-2])+c)%m;
        Fox1(i,n) s[i] += L;
        Fox1(i,n) sum[i] = sum[i-1]+s[i];
        //Fox(i,n+1) cout<<sum[i]<<" ";
        std::multiset<ll> cs;
        l=1;
        Fox1(i,n)
        {
            cs.insert(sum[i-1]);
            oddCount += s[i] & 1;
            while (oddCount > o)
            {
                oddCount -= s[l]&1;
                eraseSingleElement(cs, sum[l-1]);
                l++;
            }
            auto itr = cs.lower_bound(sum[i] - d);
            if (itr != cs.end())
            {
                maxSum = std::max(maxSum, sum[i] - *itr);
            }
        }
        if(maxSum!=-maxn)
        cout<<"Case #"<<currentTestCase<<": "<<maxSum<<"\n";
        else
        cout<<"Case #"<<currentTestCase<<": IMPOSSIBLE"<<"\n";
        currentTestCase += 1;
    }
}
