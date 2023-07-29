class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxwater=0;
        while(i<j){
            if(height[i]>height[j]){
                maxwater = max(maxwater,(j-i)*height[j]);
                j--;
            }
            else{
                maxwater = max(maxwater,(j-i)*height[i]);
                i++;
            }
        }
        return maxwater;
    }
};