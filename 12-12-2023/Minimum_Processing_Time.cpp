// this function contain only functional code no header files and main is include

 int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int maxv=0;
        sort(processorTime.begin(),processorTime.end());
        sort(tasks.begin(),tasks.end(),greater<int>());
        int j=0;
        for(int i=0;i<tasks.size();i+=4)
        {
            maxv=max(maxv,tasks[i]+processorTime[j++]);
        }
        return maxv;
    }