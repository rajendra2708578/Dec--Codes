// the code contain only the functional code no header files or main function is included in it 
// we have use the 4D dp 4 variables as one for current current,two how many element we can delete (de), three previous elements what was the previous element
// fourth is the frequecy of the current element.
// the case is simply take or nontake
// if we take then we have 2 case first) if previous element is same as current element 
// in this case also there is 2 case when freq is around 1 or 9 or 99 it count increased by 1
//if freq is not 1 or 9 or 99 then count remain the same
// if previous element is not same as current element then the count is increased becuase we got the element for the first time.
// if we do not take the element then we simply increased the index and decreased the delete element by 1 and rest remain the same.


long long int dp[105][105][27][105];
class Solution {
public:
    
    int solve(int index,int de,int prevele,int freq,string &str)
    {
        if(index==str.size())
        return 0;
        if(dp[index][de][prevele][freq]!=-1)
        return dp[index][de][prevele][freq];
        int nontake=1e9,take=1e9;
        if(de>0)
        nontake=solve(index+1,de-1,prevele,freq,str);

        if(prevele==str[index]-'a')
            {
                if(freq==1|| freq==9|| freq==99)
                take=solve(index+1,de,prevele,freq+1,str)+1;
                else
                take=solve(index+1,de,prevele,freq+1,str);
            }
            else
            {
                take=solve(index+1,de,str[index]-'a',1,str)+1;
            }
        
        return dp[index][de][prevele][freq]=min(take,nontake);
    }
    int getLengthOfOptimalCompression(string s, int k) {
      
        for(int i=0;i<s.size()+1;i++)
        {
            for(int j=0;j<s.size()+1;j++)
            {
                for(int k=0;k<27;k++)
                {
                    for(int n=0;n<s.size()+1;n++)
                    {
                        dp[i][j][k][n]=-1;
                    }
                }
            }
        }
        return solve(0,k,26,0,s);
    }
};