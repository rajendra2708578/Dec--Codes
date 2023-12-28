// this code contain only the functional code no header files or main files are inlcuded in iter_swap
//logic is simple we have use the two pointer one for wild and other for pattern
// if wild character match with the pattern character then we increrase the index of both
// if wild have "?" character then,also we increase the both index.
// when wild have "*" then we have 2 options 1) select only one character 2) select more then 1 character
//when pattern ends we check the rest of the wild charcter should be "*" else false
// when wild character end if pattern also ends then true else false.



bool solve(int index1,int index2,string &wild,string &pattern)
    {
        if(index2==pattern.size())
        {
            for(int i=index1;i<wild.size();i++)
            {
                if(wild[i]!='*')
                return false;
            }
            return true;
        }
        if(index1==wild.size())
        {
            if(index2==pattern.size())
            return true;
            else
            return false;
        }
        bool pos=false;
        if(pattern[index2]==wild[index1])
        pos|=solve(index1+1,index2+1,wild,pattern);
        else if(wild[index1]=='?')
        pos|=solve(index1+1,index2+1,wild,pattern);
        else if(wild[index1]=='*')
        {
            pos|=solve(index1+1,index2+1,wild,pattern);
            pos|=solve(index1,index2+1,wild,pattern);
        }
        return pos;
    }
    bool match(string wild, string pattern)
    {
        // code here
        return solve(0,0,wild,pattern);
    }