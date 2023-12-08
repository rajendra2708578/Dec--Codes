// This code only include functional code no header files and main function is included.

bool check(int val)
    {
        for(int i=2;i*i<=val;i++)
        {
            if(val%i==0)
            return false;
        }
        return true;
    }
    int minNumber(int arr[],int N)
    {
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum==1)
        return 1;
        else if(sum==0)
        return 2;
        
        for(int i=0;i<=10000;i++)
        {
            if(check(sum+i))
            return i;
        }
        return -1;
    }