/*
Problem Name: Greedy Florist
Problem Algorithm: Greedy
Problem URL: https://www.hackerrank.com/challenges/greedy-florist/problem
*/

int getMinimumCost(int k, vector<int> c) {
    sort(c.begin(), c.end());
    vector<int> num_purchases(k, 0);
    int cost = 0, j = 0;
    for (int i = c.size() - 1; i >= 0; i--) {
        cost += c[i] * (num_purchases[j] + 1);
        num_purchases[j]++;
        j = j + 1 == k ? 0 : j + 1;
    }
    return cost;
}