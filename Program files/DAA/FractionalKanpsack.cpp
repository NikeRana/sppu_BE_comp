#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int weight;
    int value;
};

// Custom comparison function to sort items by value per unit weight
bool compare(Item a, Item b)
{
    double ratio1 = (double)a.value / a.weight;
    double ratio2 = (double)b.value / b.weight;
    return ratio1 > ratio2;
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(vector<Item> &items, int capacity)
{
    // Sort items in non-increasing order of their value-to-weight ratios
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item &item : items)
    {
        // If adding the entire item doesn't exceed the capacity, take the whole item
        if (currentWeight + item.weight <= capacity)
        {
            currentWeight += item.weight;
            totalValue += item.value;
        }
        else
        {
            // If adding the entire item would exceed capacity, take a fraction to fill the remaining space
            int remainingSpace = capacity - currentWeight;
            totalValue += (double)item.value * remainingSpace / item.weight;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main()
{
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items;
    for (int i = 0; i < numItems; i++)
    {
        Item item;
        cout << "Enter weight for item " << i + 1 << ": ";
        cin >> item.weight;
        cout << "Enter value for item " << i + 1 << ": ";
        cin >> item.value;
        items.push_back(item);
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(items, capacity);
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
