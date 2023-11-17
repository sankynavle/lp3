#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    double ratio; // value per unit weight
};

// Function to compare items based on their value-to-weight ratio
bool compare(Item item1, Item item2) {
    return item1.ratio > item2.ratio;
}

// Function to solve the Fractional Knapsack Problem using a greedy approach
double fractionalKnapsack(int capacity, Item items[], int n) {
    // Calculate the value-to-weight ratio for each item
    for (int i = 0; i < n; ++i) {
        items[i].ratio = static_cast<double>(items[i].value) / items[i].weight;
    }

    // Sort items based on their value-to-weight ratio in non-increasing order
    sort(items, items + n, compare);

    double totalValue = 0.0;
    
    // Fill the knapsack
    for (int i = 0; i < n; ++i) {
        if (capacity <= 0) {
            break;
        }

        // Take the whole item if there is enough capacity
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take a fraction of the item to fill the remaining capacity
            totalValue += (static_cast<double>(capacity) / items[i].weight) * items[i].value;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Item " << i + 1 << ":\n";
        cout << "Weight: ";
        cin >> items[i].weight;
        cout << "Value: ";
        cin >> items[i].value;
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(capacity, items, n);

    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}


/*
weight=10,30,20,50
profit=40,30,80,70
W=60
*/