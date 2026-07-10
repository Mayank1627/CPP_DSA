#include<bits/stdc++.h>
using namespace std;

int removeDigits(int num,vector<int> &memo){

    if(num == 0) return 0;

    if(memo[num] != -1) return memo[num];

    // For every number's branch in the recursive call we need to find minimum no. of Ways
    int ans = INT_MAX;

    int x = num;
    while(x){
        int digit = x % 10;

        if(digit){
            
            int ways = 1 + removeDigits(num-digit,memo);

            ans = min(ans,ways);
        }
        
        x /= 10;
    }

    return memo[num] = ans;

}

int main(){

    int num;
    cin>>num;
    vector<int> memo(num+1,-1);

    int ans = removeDigits(num,memo);
    cout<<ans;
}