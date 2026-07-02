#include <bits/stdc++.h>
using namespace std;

bool check(string recipe,long long nb,long long ns,long long nc, long long pb,
             long long ps, long long pc, long long budget, long long mid)
{


    long long countB = 0,countS = 0, countC = 0;
    
    for(char c : recipe){
        if(c == 'B') countB++;
        else if(c == 'S') countS++;
        else countC++;
    }

    long long needB = mid * countB;
    long long needS = mid * countS;
    long long needC = mid * countC;

    long long costB = (needB - nb) * pb;
    long long costS = (needS - ns) * ps;
    long long costC = (needC - nc) * pc;

    long long totalCost = costB + costS + costC;

    return totalCost <= budget;
}


int binarySearch(string recipe,long long nb,long long ns,long long nc, 
                 long long pb, long long ps, long long pc, long long budget)
{     
        
    long long low = 0;
    long long high = 1e13;
    long long minCost = 0;

    while(low < high){

        long long mid = low + (high-low)/2;

        if(check(recipe,nb,ns,nc,pb,ps,pc,budget,mid)){
            minCost = mid;
            low = mid+1;
        }

        else high = mid-1;
    }

    return minCost;
}

int main() {
    // 1. The recipe string (order doesn't matter for counting, but we read it as-is)
    string recipe;
    cout<<"Enter the recipe : ";
    cin >> recipe;

    // 2. Pantry stock: pieces of bread, sausage, cheese already owned
    long long nb, ns, nc;
    cin >> nb >> ns >> nc;

    // 3. Shop prices: cost per piece of bread, sausage, cheese
    long long pb, ps, pc;
    cin >> pb >> ps >> pc;

    // 4. Total budget available to spend at the shop
    long long budget;
    cin >> budget;

    int ans = binarySearch(recipe,nb,ns,nc,pb,ps,pc,budget);
    cout<<ans;

}