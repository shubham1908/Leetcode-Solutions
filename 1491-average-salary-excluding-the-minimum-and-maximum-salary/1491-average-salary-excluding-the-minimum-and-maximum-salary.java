class Solution {
    public double average(int[] salary) {
        int maxSalary = salary[0], minSalary = salary[0];
        int total = salary[0];
        
        for(int i=1;i<salary.length;i++){
            maxSalary = Math.max(maxSalary, salary[i]);
            minSalary = Math.min(minSalary, salary[i]);
            total += salary[i];
        }
        total -= (maxSalary + minSalary);
        return (1.0 * total)/ (1.0 * (salary.length-2));
    }
}