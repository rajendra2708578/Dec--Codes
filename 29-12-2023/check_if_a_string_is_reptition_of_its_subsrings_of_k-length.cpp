
// This code contain only the functional code no header files and main file is included 

class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	    unordered_map<string,int>mp;
	    if(n%k)
	    return 0;
	    for(int i=0;i<n;i+=k)
	    {
	        string check=s.substr(i,k);
	        mp[check]++;
	    }
	    int total=0,one=0,more=0;
	    for(auto it:mp)
	    {
	        if(it.second==1)
	        one++;
	        else if(it.second>1)
	        more++;
	        
	        total++;
	    }
	    if((more==1 && one==1 && total==2)||(more==1 && total==1))
	    return 1;
	    else if((one==2 && total==2))
	    return 1;
	    else
	    return 0;
	}
};