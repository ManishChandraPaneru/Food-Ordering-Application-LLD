#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int>&nums,int ind,int count,int prev){
  if(ind==0){

  }

  int one=0;
  if(count==0){
    1+longestSubsequence(nums,ind-1,nums[ind],nums[ind]);
  }

  int two=0;
  if(nums[ind]==prev){
    two=longestSubsequence(nums,ind-1,count-1,nums[ind]);
  }

  int three=longestSubsequence(nums,ind-1,count,prev);

  return max({one,two,three});
}

int main(){
  return 0;
}