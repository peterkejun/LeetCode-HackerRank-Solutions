/*
Problem Name: Max Min
Problem Algorithm: Greedy
Problem URL: https://www.hackerrank.com/challenges/angry-children/problem
*/

int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int min_unfairness = INT_MAX;
    for (int i = 0; i < arr.size() - k + 1; i++) {
        int unfairness = arr[i + k - 1] - arr[i];
        if (unfairness < min_unfairness) min_unfairness = unfairness;
    }
    return min_unfairness;
}