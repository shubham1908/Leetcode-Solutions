class Solution {
public:
    void merge(vector<int> &nums, int start, int mid, int end){
        int i1 = start, i2 = mid+1;
        vector<int> temp(end-start+1);
        int k = 0;
        while(i1<=mid && i2 <= end){
            if(nums[i1] <= nums[i2]){
                temp[k] = nums[i1];
                i1++;
            } else {
                temp[k] = nums[i2];
                i2++;
            }
            k++;
        }
        while(i1<=mid){
            temp[k] = nums[i1];
            i1++, k++;
        }
        while(i2 <= end){
            temp[k] = nums[i2];
            i2++, k++;
        }
        for(int i = start, k=0;i<=end;i++, k++){
            nums[i] = temp[k];
        }
    }
    
    void mergeSort(vector<int> &nums, int start, int end){
        if(start >= end){
            return;
        }
        int mid = (start+end)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, start, mid, end);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};