/*
Problem Name: Non-Divisible Subset
Problem Algorithm: Implementation
Problem URL: https://www.hackerrank.com/challenges/non-divisible-subset/problem
*/

typedef struct {
    int op1, op2, sum;
} Permutation;

int nonDivisibleSubset(int k, vector<int> s) {
    size_t s_count = s.size();
    vector<Permutation> valid_perm;
    for (size_t i = 0; i < s_count - 1; i++) {
        for (size_t j = i + 1; j < s_count; j++) {
            printf("%d + %d = %d\n", s[i], s[j], s[i] + s[j]);
            if ((s[i] + s[j]) % k != 0) {
                Permutation perm = {s[i], s[j], s[i] + s[j]};
                valid_perm.push_back(perm);
            }
        }
    }
    std::unordered_set<int> set;
    size_t count = 0;
    for (size_t i = 0; i < valid_perm.size(); i++) {
        if (set.find(valid_perm[i].op1) == set.end()) {
            set.insert(valid_perm[i].op1);
        }
        if (set.find(valid_perm[i].op2) == set.end()) {
            set.insert(valid_perm[i].op2);
        }
    }
    auto it = set.begin();
    while (it != set.end()) {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
    return set.size();
}