class Solution {
    public int arraySign(int[] nums) {
        int negCnt = 0;
        for(int num: nums){
            negCnt += num < 0 ? 1: 0;
            if(num == 0){
                return 0;
            }
        }
        if(negCnt % 2 ==  0){
            return 1;
        }
        return -1;
    }
}