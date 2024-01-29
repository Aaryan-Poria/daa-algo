#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Item {
public:
    string name;
    int value, weight;

    Item() {

    }

    Item(string name, int value, int weight) {
        this->name = name;
        this->value = value;
        this->weight = weight;
    }
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;

    return r1 > r2;
}

void fractionalKnapsack(vector<Item>& arr, int N) {
    sort(arr.begin(), arr.end(), compare);

    int currentWeight = 0;
    double finalValue = 0.0;

    vector<Item>::iterator itr;

    cout << "\n\n**************************   OUTPUT   ***************************************************\n\n";
    for (itr = arr.begin(); itr != arr.end(); ++itr) {
        if (currentWeight + itr->weight <= N) {
            currentWeight += itr->weight;
            finalValue += itr->value;

            cout << "Name of item: " << itr->name << '\n';
            cout << "Fraction for the item: 1\n";
            cout << "Total profit for this item: " << itr->value << "\n\n";

        }
        else {
            int remainingWeight = N - currentWeight;

            cout << "Name of item: " << itr->name << '\n';
            cout << "Fraction for the item: " << ((double)remainingWeight / (double)itr->weight) << '\n';
            cout << "Total profit for this item: " << (itr->value) * ((double)remainingWeight / (double)itr->weight) << '\n';

            finalValue += (itr->value) * ((double)remainingWeight / (double)itr->weight);
            break;
        }
    }


    cout << "\n\nThe total profit is: " << finalValue << '\n';


}

int main() {
    int size, numOfItems;

    cout << "Please enter the size of the knapsack: ";
    cin >> size;

    cout << "Please enter the number of items: ";
    cin >> numOfItems;

    vector<Item> knapsackArr(numOfItems);

    cout << "Please enter the details of the items: \n";

    for (int i = 0; i < knapsackArr.size(); ++i) {
        string itemName{};
        int profit;
        cout << "Enter the name of item " << (i + 1) << ": ";
        cin >> itemName;
        cout << "Enter the profit for the item: ";
        cin >> profit;

        int totalWeight{};
        cout << "Enter the weight of the item: ";
        cin >> totalWeight;

        knapsackArr[i] = Item(itemName, profit, totalWeight);


    }

    fractionalKnapsack(knapsackArr, size);




    return 0;
}