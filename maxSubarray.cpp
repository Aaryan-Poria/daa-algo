#include <iostream>
#include <climits>
#include <vector>

using namespace std;


int maxCrossingSubarray(vector<int>& arr, int low, int mid, int high, int& leftIndex, int& rightIndex) {
    int leftSum = INT_MIN;
    int sum = 0;
    int maxLeft, maxRight;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = i;
        }
    }

    leftIndex = maxLeft;
    rightIndex = maxRight;
    return leftSum + rightSum;
}

int maxSubarray(vector<int>& arr, int low, int high, int& startIndex, int& endIndex) {
    if (low == high) {
        startIndex = endIndex = low;
        return arr[low];
    }

    int mid = (low + high) / 2;
    int leftStart, leftEnd;
    int rightStart, rightEnd;
    int crossStart, crossEnd;

    int leftSum = maxSubarray(arr, low, mid, leftStart, leftEnd);
    int rightSum = maxSubarray(arr, mid + 1, high, rightStart, rightEnd);
    int crossSum = maxCrossingSubarray(arr, low, mid, high, crossStart, crossEnd);

    if (leftSum >= rightSum && leftSum >= crossSum) {
        startIndex = leftStart;
        endIndex = leftEnd;
        return leftSum;
    }
    else if (rightSum >= leftSum && rightSum >= crossSum) {
        startIndex = rightStart;
        endIndex = rightEnd;
        return rightSum;
    }
    else {
        startIndex = crossStart;
        endIndex = crossEnd;
        return crossSum;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int startIndex, endIndex;
    int maxSum = maxSubarray(arr, 0, n - 1, startIndex, endIndex);

    cout << "Sum of the maximum subarray: " << maxSum << endl;
    cout << "Index of the starting element: " << startIndex << endl;
    cout << "Index of the ending element: " << endIndex << endl;
    cout << "The elements in the subarray: ";
    for (int i = startIndex; i <= endIndex; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
