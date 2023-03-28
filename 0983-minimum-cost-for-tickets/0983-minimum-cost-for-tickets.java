class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int[] dp = new int[366];
        int j = 0;
        dp[0] = 0;
        for(int i = 1;i<366;i++){
            if(j < days.length && days[j] == i){
                dp[i] = dp[i-1] + costs[0];
                j++;
            } else {
                dp[i] = dp[i-1];
            }
            dp[i] = Math.min(dp[i], Math.min(dp[i-7>0?i-7:0] + costs[1], dp[i-30>0?i-30:0] + costs[2]));
            // System.out.println(i + " "+ dp[i] + " "+ (j-1));
        }
        return dp[365];
    }
}