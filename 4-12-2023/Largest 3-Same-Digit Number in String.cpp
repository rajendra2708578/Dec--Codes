// It is only the functional code Header files and main function is not included

string largestGoodInteger(string num) {
        string val="0";
        for(int i=0;i<num.size()-2;i++)
        {
            if(num[i]==num[i+1] && num[i+1]==num[i+2])
            {
                if(num.substr(i,3)>val)
                val=num.substr(i,3);
            }
        }
        return val.size()<3?"":val;
    }