#include<vector>
#include<iostream>
using namespace std;

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1;
        int right=n;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isBadVersion(mid)==true){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};