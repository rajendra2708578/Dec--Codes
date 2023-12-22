


// this code contain only the functional code no header file and main function is included.

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
        vector<pair<int,pair<int,int>>>vec;
        for(int i=0;i<N;i++)
        {
            vec.push_back({F[i],{S[i],i}});
        }
        int startvalue=-1,finishvalue=-1;
        sort(vec.begin(),vec.end());
        vector<int>ans;
        for(int i=0;i<N;i++)
        {
            if(vec[i].second.first>finishvalue)
            {
                startvalue=vec[i].second.first;
                finishvalue=vec[i].first;
                ans.push_back(vec[i].second.second+1);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};