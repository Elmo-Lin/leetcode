#include<vector>
#include<iostream>
using namespace std;
// O(n)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size(), start=-1, end=-2;
        int mx=nums[0];
        int mn=nums[n-1];
        for(int i=1; i<n; i++){
            mx=max(mx, nums[i]);
            mn=min(mn, nums[n-1-i]);
            if(mx>nums[i]){
                end=i;
            }
            if(mn<nums[n-1-i]){
                start=n-1-i;
            }
        }
        return end-start+1;
    }
};

/*

O(nlogn)

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> res=nums;
        sort(res.begin(), res.end());
        int start=0;
        int end=nums.size()-1;
        while(start<nums.size() && nums[start]==res[start]){
            start++;
        }
        while(end>start && nums[end] == res[end]){
            end--;
        }
        return end-start+1;
    }
};
*/