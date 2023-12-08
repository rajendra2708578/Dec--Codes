// this is functional code header files and main function is not included
// No matter how many times operations are taken,the total bit number for the specific position is unchanged
// The K biggest integers can be made from those bits collected from all number
// we collect all set bit from array of element 
// Then try to create the k biggest element if there is set bit 
// add there square sums

 const int mod=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int>vec(32,0);
       for(int i=0;i<nums.size();i++)
       {
           for(int j=0;j<32;j++)
           {
               int value=(1<<j);
               if((value&nums[i])!=0)
               {
                   vec[j]+=1;
                   
               }
           }
       }
       long long int total=0;
    //    
       for(int i=0;i<k;i++)
       {
           long long int sum=0;
           for(int i=30;i>=0;i--)
           {
               if(vec[i]>=1)
               {
                   sum|=(1<<i);
                   vec[i]-=1;
               }
           }
           total+=(sum*sum);
           total%=mod;
       }
        return total;
    }