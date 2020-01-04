/*
Problem Name: Candies
Problem Algorithm: Greedy
Problem URL: https://www.hackerrank.com/challenges/candies/problem
*/

long candies(int n, vector<int> arr) {
    int num_candies = 1;
    vector<int> num_arr (n, 1);
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            num_candies++;
        } else {
            num_candies = 1;
        }
        num_arr[i] = num_candies;
    }
    long sum_candies = max(num_arr[n - 1], 1);
    num_candies = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1]) {
            num_candies++;
        } else {
            num_candies = 1;
        }
        sum_candies += max(num_arr[i], num_candies);
    }
    return sum_candies;
}