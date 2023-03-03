class Solution {
public:
    int strStr(string haystack, string needle) {
        int left=0,right=needle.size()-1;
        while(right<haystack.size()){
            if(haystack[left]==needle[0] and haystack[right]==needle[needle.size()-1]){
                int i=left,j=0;
                while(i<=right and haystack[i++]==needle[j++])
                if(i==right+1)return left;
            }
            left++;right++;
        }
        return -1;
    }
};