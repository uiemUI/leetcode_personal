#include"stand.h"

class NumArray {
public:
    NumArray(vector<int>& nums) {
        auto n=nums.size();
        if (n==0) return;
        numSum_.reserve(n);
        numSum_[0]=nums[0];
        for(size_t i=1;i<nums.size();++i)
        { 
            numSum_[i]=numSum_[i-1]+nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i>j) return 0;
        if (i==0) return numSum_[j];
        else return numSum_[j]-numSum_[i-1];
    }
    
private:
    vector<int> numSum_;


};
