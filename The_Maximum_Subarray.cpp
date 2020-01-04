/*
Problem Name: The Maximum Subarray
Problem Algorithm: Dynamic Programming
Problem URL: https://www.hackerrank.com/challenges/maxsubarray/problem
*/

vector<int> maxSubarray(vector<int> arr) {
    int local_sum, min = INT_MIN, local_min_index = 0;
    int max_ending_here = 0, max_so_far = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        if (max_so_far < arr[i]) {
            max_so_far = arr[i]; 
            local_min_index = i;
        }
    }
    local_sum = max_so_far;
    for (int i = 0; i < arr.size(); i++) {
        //subarray
        max_ending_here += arr[i];
        if (max_ending_here < 0) max_ending_here = 0;
        else if (max_so_far < max_ending_here) max_so_far = max_ending_here;
        //subsequent
        if (arr[i] > 0 && i != local_min_index) local_sum += arr[i];
    }
    return vector<int> {max_so_far, local_sum};
}