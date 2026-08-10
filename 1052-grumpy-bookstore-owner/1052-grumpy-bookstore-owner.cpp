class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int initialSatisfied = 0;
        int n = customers.size();

        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                initialSatisfied += customers[i];
            }
        }

        int maxExtraSatisfied = 0;
        int currentExtra = 0;

        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i] == 1) {
                currentExtra += customers[i];
            }
        }

        maxExtraSatisfied = currentExtra;

        for (int i = minutes; i < n; ++i) {
            if (grumpy[i] == 1) {
                currentExtra += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                currentExtra -= customers[i - minutes];
            }

            maxExtraSatisfied = max(maxExtraSatisfied, currentExtra);
        }

        return initialSatisfied + maxExtraSatisfied;
    }
};