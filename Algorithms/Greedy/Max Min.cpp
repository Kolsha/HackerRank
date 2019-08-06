#include <bits/stdc++.h>
#include <iterator>
/*
 * Difficulty Medium
 * Max Score 35
 * https://www.hackerrank.com/challenges/angry-children/
 */

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    int realMin = INT_MAX;
    sort(arr.begin(), arr.end());
    deque<int> qmin(k), qmax(k);
    int i = 0;
    for (i = 0; i < k; i++) {
        // Remove all previous greater elements
        // that are useless.
        while ((!qmin.empty()) && arr[qmin.back()] >= arr[i])
            qmin.pop_back(); // Remove from rear

        // Remove all previous smaller that are elements
        // are useless.
        while ((!qmax.empty()) && arr[qmax.back()] <= arr[i])
            qmax.pop_back(); // Remove from rear

        // Add current element at rear of both deque
        qmax.push_back(i);
        qmin.push_back(i);
    }

    for (; i < arr.size(); i++) {
        // Element at the front of the deque 'G' & 'S'
        // is the largest and smallest
        // element of previous window respectively

        realMin = min((arr[qmax.front()] - arr[qmin.front()]), realMin);

        // Remove all elements which are out of this
        // window
        while (!qmax.empty() && qmax.front() <= i - k)
            qmax.pop_front();
        while (!qmin.empty() && qmin.front() <= i - k)
            qmin.pop_front();

        // Remove all previous greater elements
        // that are useless.
        while ((!qmin.empty()) && arr[qmin.back()] >= arr[i])
            qmin.pop_back(); // Remove from rear

        // Remove all previous smaller that are elements
        // are useless.
        while ((!qmax.empty()) && arr[qmax.back()] <= arr[i])
            qmax.pop_back(); // Remove from rear

        // Add current element at rear of both deque
        qmax.push_back(i);
        qmin.push_back(i);
    }


    realMin = min((arr[qmax.front()] - arr[qmin.front()]), realMin);
    return realMin;

}

int maxMin_old(int k, vector<int> arr) {

    sort(arr.begin(), arr.end());
    int realMin = INT_MAX;
    for (int i = 0; i <= (arr.size() - k); i++) {

        auto begin = arr.begin();

        advance(begin, i);
        auto end = begin;
        advance(end, k);

        int max_arr = *max_element(begin, end);
        int min_arr = *min_element(begin, end);

        int currMin = max_arr - min_arr;
        realMin = min(currMin, realMin);
        if (realMin < 1) return 0;
    }

    return realMin;

}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
