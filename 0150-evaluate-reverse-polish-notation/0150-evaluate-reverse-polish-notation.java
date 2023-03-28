class Solution {
    private int getNumberFromToken(String num){
        boolean negFlag = false;
        int x = 0;
        if(num.charAt(0) == '-'){
            x = 1;
            negFlag = true;
        }
        int res = 0;
        for(int i=num.length()-1, k=1;i>=x;i--, k*=10){
            res += (num.charAt(i)-'0') * k;
        }
        if(negFlag){
            res = -res;
        }
        return res;
    }
    
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for(String token: tokens){
            if(!token.equals("+") && !token.equals("-") && !token.equals("*") && !token.equals("/")){
                
                int num = getNumberFromToken(token);
                stack.push(num);
                continue;
            }
            int num2 = stack.pop(), num1 = stack.pop();
            int result = 0;
            switch(token) {
                case "+":
                    result = num1+num2;
                    break;
                case "-":
                    result = num1-num2;
                    break;
                case "*":
                    result = num1 * num2;
                    break;
                case "/":
                    result = num1 / num2;
                    break;
            }
            stack.push(result);
        }
        return stack.pop();
    }
}