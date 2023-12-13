//this code only contain the functional code no header files and main function is included in it
// it required subarray of min length. 
// case 1 if the sum of all element is less than target means the sum of array will be used multiple times
// in anycase if we start with any value if the whole sum of array is less then target the somehow we are going to use the whole array atleast for target/sum times
// And the value of target will also be decreased by target%sum 
// now case 1 converted to case 2 where the target is less than sum
// now we can apply the sliding window but of num.size()*2 length and of repeating the array twice
//repeating twice becuase there is possible case where the ans could be inside the merge value from i<nums.size()  to j>nums.size()


int minSizeSubarray(vector<int>& nums, int target) {
        long long int sum=0;
        for(auto it:nums)
        {
            sum+=it;
        }
        if(sum==target)
        return nums.size();
        else
        {
            long long int total=0;
            if(target>sum)
            {
                 total=(target)/sum;
                target=target%sum;
               total*=nums.size();
            }
            if(target%sum==0)
            return total;
            long long int count=INT_MAX;
            vector<int>num;
            for(auto it:nums)
            {
                num.push_back(it);
            }
            for(auto it:nums)
            {
                num.push_back(it);
            }
            long long int i=0,j=0,sum=0;
            while(j<num.size())
            {
                sum+=num[j];
                while(sum>target && i<j)
                {
                    sum-=num[i];
                    i++;
                }
                if(sum==target)
                count=min(count,(j-i+1));
                j++;
            }
            if(count>=INT_MAX)
            return -1;
            else
            return total+count;
        }
        
    }