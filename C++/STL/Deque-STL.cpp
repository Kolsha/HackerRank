#include <iostream>
#include <deque>
#include <vector>
/*
 * Difficulty Medium
 * Max Score 50
 * https://www.hackerrank.com/challenges/deque-stl/
 */
using namespace std;

void printKMax(int arr[], int n, int k) {

    int win_sz = k;
    deque<int> dq(win_sz);
    vector<int> result;
    size_t i;
    for (i = 0; i < win_sz; i++) {

        while ((!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back(); // Remove from rear
        // Add new element at rear of queue
        dq.push_back(i);
    }

    for (; i < n; ++i) {



        // cout << arr[dq.front()] << " ";
        result.push_back(arr[dq.front()]);

        // Remove the elements which are out of this window
        while ((!dq.empty()) && dq.front() <= i - win_sz)
            dq.pop_front(); // Remove from front of queue

        while ((!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);

    }


    // cout << arr[dq.front()] << " ";
    result.push_back(arr[dq.front()]);
    for (auto &&m : result) {
        cout << m << " ";
    }


}

int main() {

    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        cout << endl;
        t--;
    }
    return 0;
}

