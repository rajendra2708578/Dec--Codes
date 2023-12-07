//Only the functional code is there no header files or main function is included 
// first we sort the coins in the increasing order 
// every time we add up new coins in the list
// if it is not possible to create a sum greater then the required value only including value of coins less then or equal to sum+1
// means every value is achievable below the prefix sum if value is greater the prefix sum then we have to add that value in the ans


 int minimumAddedCoins(vector<int>& coins, int target) {
        int ind=0,count=0,sum=0;
        sort(coins.begin(),coins.end());
        while(ind<coins.size() && sum<target)
        {
            if(coins[ind]<=sum+1)
            {
                sum+=coins[ind];
                ind++;
            }
            else
            {
                count++;
                sum+=(sum+1);
            }
        }
        while(sum<target)
        {
            count++;
            sum+=(sum+1);
        }
        return count;
    }