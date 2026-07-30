class Solution {
public:
    const long long LIM = 1000005;

    long long ways(vector<int>& c){
        int n=accumulate(c.begin(),c.end(),0),r=n;
        long double ans=1;
        for(int x:c){
            for(int i=1;i<=x;i++){
                ans*=r-x+i;
                ans/=i;
                if(ans>LIM) return LIM;
            }
            r-=x;
        }
        return min((long long)(ans+0.5),LIM);
    }

    string smallestPalindrome(string s,int k) {
        vector<int> f(26),h(26);
        for(char c:s) f[c-'a']++;

        string mid="",L;
        int m=0;
        for(int i=0;i<26;i++){
            h[i]=f[i]/2;
            m+=h[i];
            if(f[i]&1) mid+=char(i+'a');
        }

        if(ways(h)<k) return "";

        while(m--){
            for(int i=0;i<26;i++){
                if(!h[i]) continue;
                h[i]--;
                long long w=ways(h);
                if(w>=k){
                    L+=char(i+'a');
                    break;
                }
                k-=w;
                h[i]++;
            }
        }

        string R=L;
        reverse(R.begin(),R.end());
        return L+mid+R;
    }
};