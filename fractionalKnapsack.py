class ItemValue:
    def __init__(self, wt_, val_, ind_):
        self.wt = wt_
        self.val = val_
        self.ind = ind_
        self.cost = val_ // wt_

    def __lt__(self, other):
        return self.cost < other.cost

def fractionalKnapSack(wt, val, capacity):
    iVal = [ItemValue(wt[i], val[i], i) for i in range(len(wt))]
    iVal.sort(key=lambda x: x.cost, reverse=True)

    totalValue = 0
    for i in iVal:
        curWt = i.wt
        curVal = i.val
        if capacity - curWt >= 0:
            capacity -= curWt
            totalValue += curVal
        else:
            fraction = capacity / curWt
            totalValue += curVal * fraction
            capacity = int(capacity - (curWt * fraction))
            break
    return totalValue

if __name__ == "__main__":
    wt = [10, 40, 20, 30]
    val = [60, 40, 100, 120]
    capacity = 50

    maxValue = fractionalKnapSack(wt, val, capacity)
    print("Maximum value in Knapsack =", maxValue)

"""
1.Time complexity:
Sorting the items by their value-to-weight ratio in descending order takes O(n * log(n))
subsequent iteration through the sorted items has a time complexity of O(n)

2.Space Complexity
The items list and the selected_items list store information about the items, which requires O(n) space.
"""