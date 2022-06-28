#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int left=1;
        int right=n;
        while(left<=right){
            long mid=left+(right-left)/2;
            if((mid*(mid+1)/2==n)){
                return mid;
            }
            else if((mid*(mid+1)/2<n)){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return left-1;
    }
};