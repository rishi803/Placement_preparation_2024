

class Solution {
public:
    vector<vector<pair<int, int>>> route;
    vector<vector<int>> memo;

    int ans(int src, int dst, int k) {
        if (k < 0) return INT_MAX; // No more stops allowed
        if (src == dst) return 0;  // Reached destination
        if (memo[src][k] != -1) return memo[src][k]; // Check if already computed

        int res = INT_MAX;
        for (auto &node : route[src]) {
            int next_node = node.first;
            int price = node.second;
            int sub_problem = ans(next_node, dst, k - 1);
            if (sub_problem != INT_MAX) {
                res = min(res, price + sub_problem);
            }
        }

        return memo[src][k] = res; // Memorize the result
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        route.resize(n);
        for (auto &flight : flights) {
            route[flight[0]].emplace_back(flight[1], flight[2]);
        }

        memo.assign(n, vector<int>(k + 2, -1)); // Initialize memoization table

        int result = ans(src, dst, k + 1);
        return result == INT_MAX ? -1 : result;
    }
};
