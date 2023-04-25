class SmallestInfiniteSet {
    private int[] nums;
    int cur = 1;
    
    public SmallestInfiniteSet() {
        nums = new int[3000];
        for(int i=0;i<3000;i++){
            nums[i] = i+1;
        }
    }
    
    public int popSmallest() {
        int x = cur;
        cur = nums[x];
        nums[x] = -1;
        return x;
    }
    
    public void addBack(int num) {
        if(num >=3000){
            return;
        }
        if(nums[num] == -1){
            if(num < cur){
                nums[num] = cur;
                cur = num;
            } else {
                for(int i = cur;i<num;i++){
                    if(nums[i] != -1 && nums[i] > num){
                        nums[num] = nums[i];
                        nums[i] = num;
                    }
                }
            }
        }
    }
}
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet obj = new SmallestInfiniteSet();
 * int param_1 = obj.popSmallest();
 * obj.addBack(num);
 */