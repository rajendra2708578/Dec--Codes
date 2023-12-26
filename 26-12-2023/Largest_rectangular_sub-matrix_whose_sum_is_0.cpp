
// this code contain only the functional code no header files or main files are included.
class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
      int n=a.size(),m=a[0].size();
      vector<vector<int>>prefixsum(n+1,vector<int>(m+1,0));
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
          {
              prefixsum[i][j]+=(prefixsum[i][j-1]+a[i-1][j-1]);
          }
      }
      int sr,er,sc,ec;
      int maxa=0;
      for(int i=1;i<=n;i++)
      {
          for(int j=i;j<=m;j++)
          {
              map<int,int>mp;
              mp[0]=0;
              int curs=0;
              for(int k=1;k<=n;k++)
              {
                  curs+=prefixsum[k][j]-prefixsum[k][i-1];
                  if(mp.count(curs))
                  {
                      int area=(j-i+1)*(k-mp[curs]);
                      if(area>maxa)
                      {
                         maxa=area;
                         sr=mp[curs]+1;
                         er=k;
                         sc=i;
                         ec=j;
                      }
                  }
                  else
                  {
                      mp[curs]=k;
                  }
              }
              
          }
      }
      vector<vector<int>>ans;
      if(maxa==0)
      return ans;
      for(int i=sr;i<=er;i++)
      {
          vector<int>vec;
          for(int j=sc;j<=ec;j++)
          {
              vec.push_back(a[i-1][j-1]);
          }
          ans.push_back(vec);
      }
      return ans;
  }
};
