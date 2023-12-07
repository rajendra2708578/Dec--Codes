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
	
	// this approach takes around nlogn time
	
	//
	//Only the functional code is there no header files or main function is included 
	long long int countXHelper(long long int N, int X)
    {

        long long int cnt = 0;

        for (long long int i = 1; i <= N; i *= 10) {
            long long int divi = i * 10;
            long long int quot = N / divi;
            long long int rem = N % divi;

            if (quot > 0) {
                cnt = cnt + (quot * i);
            }

            if (X == 0) {
                cnt = cnt - i;
            }

            if (rem >= X * i) {
                cnt = cnt + (min(rem - X * i + 1, i));
            }
        }

        return cnt;
    }

    int countX(int L, int R, int X)
    {

        return countXHelper(R - 1, X) - countXHelper(L, X);
    }
	// this takes log(R) time