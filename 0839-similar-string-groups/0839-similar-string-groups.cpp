vector<int>par(2001,0);
int n,w;
class Solution {
public:
    
    int find(int x) {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    }
    void Union(int x, int y) {
        par[find(x)] = find(y);
    }
    
    
    bool sim(string a,string b){
        int x=0;
        for(int i=0;i<w;i++){
            if(a[i]!=b[i]){
                x++;
            }
        }
        if(x==0 || x==2){
            return true;
        }
        return false;
    }
    
    int numSimilarGroups(vector<string>& v) {
        n=v.size();
        w=v[0].length();
        par.resize(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        if(n<(w*w)){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(sim(v[i],v[j])){
                        // cout<<v[i]<<' '<<v[j]<<'\n';
                        Union(i,j);
                        cout<<i<<' '<<j<<'\n';
                    }
                }
            }
        }
        else{
            map<string,int>mp;
            for(int i=0;i<n;i++){
                mp[v[i]]=i;
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<w;j++){
                    for(int k=1;k<w;k++){
                        string a=v[i];
                        char t=a[j];
                        a[j]=a[k];
                        a[k]=t;
                        if(mp.find(a)!=mp.end())
                            Union(mp[a],i);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            cout<<par[i]<<' ';
            ans+=(par[i]==i);
        }
        return ans;
    }
};