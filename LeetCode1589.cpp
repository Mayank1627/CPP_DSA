#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout << "Enter size of nums: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements of nums:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int q;
    cout << "Enter number of requests: ";
    cin >> q;

    vector<vector<int>> requests(q, vector<int>(2));

    cout << "Enter requests (l r):\n";
    for (int i = 0; i < q; i++) {
        cin >> requests[i][0] >> requests[i][1];
    }

    // Step 1: Build Difference Array
    vector<int> diff(n, 0);

    for (auto &r : requests) {
        int l = r[0];
        int rr = r[1];

        diff[l]++;

        if (rr + 1 < n)
            diff[rr + 1]--;
    }

    // Step 2: Prefix Sum to get frequency of each index
    for (int i = 1; i < n; i++)
        diff[i] += diff[i - 1];

    // Step 3: Store {frequency, original index}
    vector<pair<int, int>> freq;

    for (int i = 0; i < n; i++)
        freq.push_back({diff[i], i});

    // Step 4: Sort frequencies and nums
    sort(freq.begin(), freq.end());
    sort(nums.begin(), nums.end());

    // Step 5: Construct optimal permutation
    vector<int> perm(n);

    for (int i = 0; i < n; i++)
        perm[freq[i].second] = nums[i];

    cout << "\nFrequency of each index:\n";
    for (int x : diff)
        cout << x << " ";

    cout << "\n\nOptimal Permutation:\n";
    for (int x : perm)
        cout << x << " ";

    return 0;
}