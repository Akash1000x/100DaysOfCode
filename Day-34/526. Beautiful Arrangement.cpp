class Solution {
public:
    void countArrangements(int n, int currNum, vector<int>& v, int& count) {
        if (currNum > n) {
            count++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (v[i]==0 && (i % currNum == 0 || currNum % i == 0)) {
                v[i] = currNum;
                countArrangements(n, currNum + 1, v, count);
                v[i] = 0; // Backtrack
            }
        }
    }

    int countArrangement(int n) {
        vector<int> v(n + 1);
        int count = 0;
        countArrangements(n, 1, v, count);
        return count;
    }
};
