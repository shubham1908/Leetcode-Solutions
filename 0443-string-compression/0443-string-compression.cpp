class Solution {
public:
    int compress(vector<char>& chars) {
        int j = 0, cnt = 1;
        char pre = chars[0];
        for(int i=1;i<chars.size();i++){
            if(chars[i] == pre){
                cnt++;
            } else {
                chars[j] = pre;
                j++;
                pre = chars[i];
                if(cnt == 1){
                    continue;
                }
                string x = "";
                while(cnt){
                    x += cnt%10+'0';
                    cnt/=10;
                }
                for(int k = x.length()-1;k>=0;k--){
                    chars[j] = x[k];
                    j++;
                }
                cnt = 1;
            }
        }
        chars[j] = pre;
        j++;
        if(cnt == 1){
            return j;
        }
        string x = "";
        while(cnt){
            x += cnt%10+'0';
            cnt/=10;
        }
        for(int k = x.length()-1;k>=0;k--){
            chars[j] = x[k];
            j++;
        }
        return j;
    }
};