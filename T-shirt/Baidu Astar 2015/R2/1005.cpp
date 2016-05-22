char s[100005];
int len;
int next[100005][27];
int dp[100005];
LL f[100005];
int main() {
    //freopen(NAME".in","r",stdin);
    //freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        printf("Case #%d:\n",CA);
        scanf("%s",s);
        len=strlen(s);
        for(i=len;i>0;i--)
            s[i]=s[i-1];
        for(j=0;j<26;j++)next[len+1][j]=len+1;
        for(i=len;i>=1;i--){
            for(j=0;j<26;j++)next[i][j]=next[i+1][j];
            next[i][s[i]-'a']=i;
        }
        for(i=j=0;j<26;j++)next[0][j]=next[1][j];
        for(i=len;i>=0;i--){
            dp[i]=MOD,f[i]=0;
            for(j=0;j<26;j++){
                int id=next[i+1][j];
                if(id<=len){
                    if(dp[id]<dp[i])
                        dp[i]=dp[id];
                }else {
                    dp[i]=-1;
                    break;
                }
            }
            f[i]=0;
            for(j=0;j<26;j++){
                int id=next[i+1][j];
                if(id>len){
                    f[i]++;
                }else {
                    if(dp[id]==dp[i])
                        f[i]+=f[id];
                }
            }
            f[i]%=MOD;f[i]+=MOD;f[i]%=MOD;
            dp[i]++;
        }
        cout<<dp[0]+1<<" "<<f[0]%MOD<<"\n";
    }
    return 0;
}