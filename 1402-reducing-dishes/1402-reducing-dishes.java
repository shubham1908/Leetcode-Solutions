class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int runSum = 0, ans = 0;
        for(int i=0;i<satisfaction.length;i++){
            runSum += satisfaction[i];
            ans += (i+1)*satisfaction[i];
        }
        for(int i=0;runSum < 0 && i<satisfaction.length; i++){
            ans -= runSum;
            runSum -= satisfaction[i];
        }
        return ans;
    }
}