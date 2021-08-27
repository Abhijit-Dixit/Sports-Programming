void lps(string t,int l[]);

int KMP(string s,string t){
    int n,m;
    n=s.length();
    m=t.length();
    int lps[m]={0};
    LPS(t,lps);
    int i=0,j=0;
    int ans=0;
    while(i<n){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        else{
            if(j==0) i++;
            else j=lps[j-1];            
        }
        
        if(j==m){
            ans++;
            j=lps[j-1];
        }
        
    }
    return ans;

}

void LPS(string t,int l[]){
    int m=t.length();
    lps[0]=0;
    int len=0; //pointer to last element of prefix
    int i=1; //pointer to last element of suffix
    while(i<m){
        if(t[len]==t[i]){
            len++; // here len is increased before assigned to lps[i] because indices are one less than length
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[len-1]; //if 'len' doesn't match then we look for second best(largest) option which is lps[len-1]; 
            }
            else{
                lps[i]=0; // if len==0 then len cannot be reduced any furter, so simply increment i;
                i++;
            }
        }
    }
}
