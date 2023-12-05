// This is the functional code header files and main is not included
// Best way to solve is to get the & of whole array if it provide a 0 value
// then look for subarray which & gives us the 0 value
// else answer would be 1 becuase we need the sum to be minimum if suppose minvalue of & is 1 
// and we split it in 2 subarray the sum would be 2 but if we kept as whole single array the answer would be 1

 int maxSubarrays(vector<int>& nums) {
        int minv=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            minv=(minv&nums[i]);

        }
        if(minv>=1)
        return 1;
        unordered_map<int,int>mp;
        int value=(1<<20)-1;
        int check=value;
        for(int i=0;i<nums.size();i++)
        {
            check=check&nums[i];
            if(check==0)
            {
                mp[0]++;
                check=value;
            }
        }
        return mp[0];
    }