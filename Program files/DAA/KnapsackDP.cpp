#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an item with weight and value
struct Item {
    int weight;
    int value;
};

// Function to solve the 0-1 Knapsack problem using dynamic programming
int knapsackDP(vector<Item> items, int knapsackCapacity) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(knapsackCapacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= knapsackCapacity; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][knapsackCapacity];
}

int main() {
    vector<Item> items = {
        {10 , 60},
        {20 , 100},
        {30 , 120}
    };
    int knapsackCapacity = 50;

    int maxTotalValue = knapsackDP(items, knapsackCapacity);

    cout << "Maximum total value: " << maxTotalValue << endl;

    return 0;
}
