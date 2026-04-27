// In The Name of Allah

// Bucket Sort
//
// Problem:   Sort an array of values that are roughly uniformly distributed
//            over a known range (here we assume floats in [0, 1)).
// Approach:  Distribute values into n buckets based on their range, sort each
//            bucket (insertion sort for small buckets), and concatenate.
//            With uniform input and n buckets, each bucket has O(1) elements
//            on average → linear total time.
// Time:      O(n + k) average, O(n^2) worst (all values into one bucket)
// Space:     O(n + k)
// Stable:    Yes (when the per-bucket sort is stable)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucket_sort(vector<double>& v) {
    int n = (int)v.size();
    if (n <= 1) return;
    vector<vector<double>> buckets(n);
    for (double x : v) {
        int idx = (int)(n * x);
        if (idx >= n) idx = n - 1;
        buckets[idx].push_back(x);
    }
    for (auto& b : buckets) sort(b.begin(), b.end());
    int k = 0;
    for (auto& b : buckets) for (double x : b) v[k++] = x;
}

int main() {
    vector<double> v = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    bucket_sort(v);
    cout << "Sorted:";
    for (double x : v) cout << " " << x;
    cout << endl;
    return 0;
}
