//Only the functional code is there no header files or main function is included 

 int check(string str,int x)
    {
        int count=0;
        for(auto it:str)
        {
            if(it-'0'==x)
            count++;
        }
        return count;
    }
    int countX(int L, int R, int X) {
        // code here
        int sum=0;
        for(int i=L+1;i<R;i++)
        {
            sum+=check(to_string(i),X);
        }
        return sum;
    }
	
	//