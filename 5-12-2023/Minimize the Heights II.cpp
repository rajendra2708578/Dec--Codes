// This only include the functional code header files and main function is not included
// approach obiviously the last and first element difference will be the 
// max in normal condition but either we can increase or decrease the height of tower by k
// we start from 1 index not zero becuase we already first and last value and the difference remain the same either we increase together or decrease together
// but if we move opposite one increase and one decrease then the difference get bigger , which is not a desire results for us
// start the iteration from 1 to n-1 index
// every time we try to avoid negative value so if any element less the k is avoided
// if arr[i] >=k is and for every index we assume this is first time we decrease the k from tower 
// if arr[i]-k for i index for first time then arr[i-1]+k and arr[i-1]-k must be the case
// and localmin value would be either arr[0]+k or arr[i]-k and local maximum value would be arr[i-1]+k or arr[n-1]-k;
// then check for minimum difference among all the cases.
int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int ans=arr[n-1]-arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]<k)continue;
            int tempmin=min(arr[0]+k,arr[i]-k);
            int tempmax=max(arr[i-1]+k,arr[n-1]-k);
            ans=min(ans,tempmax-tempmin);
        }
        return ans;
    }