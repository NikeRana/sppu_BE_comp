def knapsack_dynamic_programming(values, weights, capacity):
    n = len(values)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

    for i in range(n + 1):
        for w in range(capacity + 1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            elif weights[i - 1] <= w:
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]

    selected_items = []
    i, j = n, capacity
    while i > 0 and j > 0:
        if dp[i][j] != dp[i - 1][j]:
            selected_items.append(i - 1)
            j -= weights[i - 1]
        i -= 1

    selected_items.reverse()
    return dp[n][capacity], selected_items

if __name__ == "__main__":
    values = [60, 100, 120]
    weights = [10, 20, 30]
    capacity = 50

    max_value, selected_items = knapsack_dynamic_programming(values, weights, capacity)

    print("Maximum value:", max_value)
    print("Selected items:", selected_items)

"""
1.Time complexity:
Filling of DP array takes O(N*W)
The backtracking to find the selcted items takes O(N)

2.Space Complexity
Array of size (n + 1) x (W + 1) is used to store intermediate results, which requires O(n * W) space.
"""