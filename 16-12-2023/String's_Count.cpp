
//This only contain functional code no header file or main functional code 
// This is one of the method with O(N*2*3) time complexity
long long int solve(int index,int count1,int count2,int n,vector<vector<vector<int>>>&dp)
{
    if(count1>1 || count2>2)
      return 0;
      if(count1==1 && count2==2)
      return 1;
    if(index==n)
  {
      
      return 1;
  }
    long long int val1=0;
    if(dp[index][count1][count2]!=-1)
    return dp[index][count1][count2];
    val1+=solve(index+1,count1,count2,n,dp);
    val1+=solve(index+1,count1+1,count2,n,dp);
    val1+=solve(index+1,count1,count2+1,n,dp);
    return dp[index][count1][count2]=val1;
}
long long int countStr(long long int n){
    //complete the function here
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
    return solve(0,0,0,n,dp);
    //   return ((n*n*n + 3*n + 2)/2);
}

// Different method with O(1) Time complexity

// A O(1) CPP program to find number of strings
// that can be made under given constraints.
#include<bits/stdc++.h>
using namespace std;
int countStr(int n){
    
    int count = 0;
    
    if(n>=1){
        //aaa...
        count += 1;
        //b...aaa...
          count += n;
        //c...aaa...
        count += n;
        
        if(n>=2){
          //bc...aaa...
          count += n*(n-1);
          //cc...aaa...
          count += n*(n-1)/2;
          
          if(n>=3){
            //bcc...aaa...
            count += (n-2)*(n-1)*n/2;
          }
        }
    
    }
    
    return count;
    
}