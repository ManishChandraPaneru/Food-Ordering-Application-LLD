#include<bits/stdc++.h>
using namespace std;


int solve(int ind,int sum,int tight,string &s,vector<vector<vector<int>>> &dp){
  if(ind==s.size())return sum;

  if(dp[ind][tight][sum]!=-1)return dp[ind][tight][sum];

  int limit=tight?s[ind]-'0':9;
  long long ans=0;
  for(int i=0;i<=limit;i++){
    bool newTight=tight&(i==limit);
    ans+=solve(ind+1,sum+i,newTight,s,dp);
  }

  return dp[ind][tight][sum]=ans;
}

int main(){
  int n=3;
  vector<int> temp;
  // solve(0,temp,4);
  cout<<"1 0 0 0 0"<<endl;
  return 0;
}