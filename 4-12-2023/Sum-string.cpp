// this is only the functional code headerfiles and main are not included
// sum function.

string sum(string a,string b)
    {
        string ans="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0,carry=0;
        while(i<a.size() && i<b.size())
        {
            int sum=(a[i]-'0')+(b[i]-'0')+carry;
            
            carry=sum/10;
            ans+=(to_string(sum%10));
            i++;
            
        }
        while(i<a.size())
        {
            int sum=(a[i]-'0')+carry;
           
            carry=sum/10;
            ans+=(to_string(sum%10));
            i++;
        }
        while(i<b.size())
        {
            int sum=(b[i]-'0')+carry;
           
            carry=sum/10;
            ans+=(to_string(sum%10));
            i++;
        }
        if(carry)
        ans+=(to_string(carry));
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
	// function to check the a+b==c
    bool check(string &a,string &b,int index,int valid,string &og)
    {
        if(index==og.size())
        return valid;
        string match=sum(a,b);
        string cur="";
       
        for(int i=index;i<og.size();i++)
        {
            cur+=og[i];
            if(cur==match)
            return check(b,cur,i+1,1,og);
            
        }
        return false;
    }
	// main isSumString function
    int isSumString(string S){
        // code here 
        int n=S.size();
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                string a=S.substr(0,i);
                string b=S.substr(i,j-i);
                if(check(a,b,j,0,S))
                return 1;
            }
        }
        return 0;
    }

