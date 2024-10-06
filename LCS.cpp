class Solution {
public:
    map<pair<int,int>,int> mp;

    int fun(int i, int j, int n1, int n2, string &text1, string &text2, vector<vector<int>> &dp){
        if(i==n1 || j==n2)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans;

        if(text1[i]==text2[j]){
            ans=dp[i][j]=1+fun(i+1,j+1,n1,n2,text1,text2,dp);
        }
        else{
            ans=max(fun(i+1,j,n1,n2,text1,text2,dp),fun(i,j+1,n1,n2,text1,text2,dp));
        }
        return dp[i][j]=ans;
        // if(i==n1 || j==n2)return 0;
        // if(mp.find({i,j})!=mp.end())return mp[{i,j}];
        // int ans;
        // if(text1[i]==text2[j]){
        //     return mp[{i,j}]=1+fun(i+1,j+1,n1,n2,text1,text2);
        // }else{
        //     ans=max(fun(i+1,j,n1,n2,text1,text2),fun(i,j+1,n1,n2,text1,text2));
        //     // int z1,z2;
        //     // if(mp.find({i+1,j})!=mp.end()){
        //     //     z1=mp[{i+1,j}];
        //     // }else{
        //     //     z1=fun(i+1,j,n1,n2,text1,text2);
        //     // }

        //     // if(mp.find({i,j+1})!=mp.end()){
        //     //     z2=mp[{i,j+1}];
        //     // }else{
        //     //     z2=fun(i,j+1,n1,n2,text1,text2);
        //     // }
        //     // ans=max(z1,z2);
        // }
        // return mp[{i,j}]=ans;

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return fun(0,0,n1,n2,text1,text2,dp);
    }
};
