class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ak;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();){
            int count =1;
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]==arr[j]){
                    count++;
                }
            }
            ak.push_back(count);
            i = i+count;
        }
        sort(ak.begin(),ak.end());
        for(int i = 0;i<ak.size()-1;i++){
            if(ak[i]==ak[i+1]){
                return 0;
            }
        }
        return 1;
    }
};