#include<vector>
#include<iostream>
using namespace std;












// brute solution
/*
class Solution {
public:
    int specialArray(vector<int>& nums) {
        for(int x=1; x<=100; x++){
            int count=0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]>=x){
                    count++;
                }
            }
            if(x==count){
                return x;
            }
        }
        return -1;
    }
};
*/