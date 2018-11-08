/*
Code developed by Arka
*/
//Using Dynamic Programming
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
map<string,ll> dpSum;
map<string,ll> dpOdd;
string key;
int main()
{
    int test,currentTestCase=1;
    ll n,o,d,m,l,a,b,c,sum,maxSum,oddCount,tempSum,tempOdd;
    bool T;
    cin>>test;
    while(currentTestCase<=test)
    {
    	dpSum.clear();
    	dpOdd.clear();
        cin>>n>>o>>d;
        int s[n+1];
        cin>>s[1]>>s[2]>>a>>b>>c>>m>>l;
        Foxi(i,3,n) s[i]=((a*s[i-1])+(b*s[i-2])+c)%m;
        Fox1(i,n) s[i] += l;
        maxSum=-maxn;
        Fox1(i,n)
        Foxi(j,i,n)
        {
            T=false;
            key=to_string(i+1)+" "+to_string(j-1);
            if(!T && dpSum.find(key)!=dpSum.end() && dpOdd.find(key)!=dpOdd.end())
            {
            	T=true;
				{
					tempSum=s[i]+ s[j] + dpSum[key];
					tempOdd=(ll)(s[i]&1) + (ll)(s[j]&1) + dpOdd[key];
					dpSum[to_string(i)+" "+to_string(j)]=tempSum;
					dpOdd[to_string(i)+" "+to_string(j)]=tempOdd;
					//cout<<"dpSum["<<i<<" "<<j<<"]="<<tempSum<<" "<<dpSum[to_string(i)+" "+to_string(j)]<<endl;
					//cout<<"dpOdd["<<i<<" "<<j<<"]="<<tempOdd<<" "<<dpOdd[to_string(i)+" "+to_string(j)]<<endl;
				}
			}
			key=to_string(i+1)+" "+to_string(j);
            if(!T && dpSum.find(key)!=dpSum.end() && dpOdd.find(key)!=dpOdd.end())
            {
            	T=true;
				{
					tempSum=s[i] + dpSum[key];
					tempOdd=(ll)(s[i]&1) + dpOdd[key];
					dpSum[to_string(i)+" "+to_string(j)]=tempSum;
					dpOdd[to_string(i)+" "+to_string(j)]=tempOdd;
					//cout<<"dpSum["<<i<<" "<<j<<"]="<<tempSum<<" "<<dpSum[to_string(i)+" "+to_string(j)]<<endl;
					//cout<<"dpOdd["<<i<<" "<<j<<"]="<<tempOdd<<" "<<dpOdd[to_string(i)+" "+to_string(j)]<<endl;
				}
			}
			key=to_string(i)+" "+to_string(j-1);
            if(!T && dpSum.find(key)!=dpSum.end() && dpOdd.find(key)!=dpOdd.end())
            {
                T=true;
				{
					tempSum=s[j] + dpSum[key];
					tempOdd=(ll)(s[j]&1) + dpOdd[key];
					dpSum[to_string(i)+" "+to_string(j)]=tempSum;
					dpOdd[to_string(i)+" "+to_string(j)]=tempOdd;
					//cout<<"dpSum["<<i<<" "<<j<<"]="<<tempSum<<" "<<dpSum[to_string(i)+" "+to_string(j)]<<endl;
					//cout<<"dpOdd["<<i<<" "<<j<<"]="<<tempOdd<<" "<<dpOdd[to_string(i)+" "+to_string(j)]<<endl;
				}
            }
			key=to_string(i)+" "+to_string(j);
			if(!T)
			{
			    sum=0;
                oddCount=0;
				T=true;
				Foxi(k,i,j)
            	{
            		if(s[k]&1)
               		{
                   		oddCount++;
               		}
               		sum += s[k];
            	}
                dpSum[key]=sum;
            	dpOdd[key]=oddCount;
            	//cout<<"dpSum["<<i<<" "<<j<<"]="<<dpSum[to_string(i)+" "+to_string(j)]<<endl;
                //cout<<"dpOdd["<<i<<" "<<j<<"]="<<dpOdd[to_string(i)+" "+to_string(j)]<<endl;
			}
			//cout<<key<<endl;
			if(dpSum[key]<=d && dpOdd[key]<=o)
            maxSum = max(dpSum[key],maxSum);
        }
        if(maxSum!=-maxn)
            cout<<"Case #"<<currentTestCase<<": "<<maxSum<<endl;
        else
            cout<<"Case #"<<currentTestCase<<": IMPOSSIBLE"<<endl;
        currentTestCase++;
    }
}

