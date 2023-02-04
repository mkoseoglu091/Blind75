#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Helper structs and classes

// Helper ListNode struct used in problems with linked lists provided by leetcode
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Helper Node struct used in N-ary tree
class Node {
   public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

// Helper TreeNode struct used in binary tree related questions
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*********************************************************/

class Solution {
   public:
    // 1. Two Sum
    // return the indexes of the elements that add up to target
    static vector<int> twoSum(vector<int> &nums, int target) {
        /*
        // brute force method
        vector<int> result;
        for(int i{}; i<nums.size()-1; ++i){
            for(int j{i+1}; j<nums.size(); ++j){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result {-1, -1};
        */
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) == map.end())
                map[nums[i]] = i;
            else
                return {map[target - nums[i]], i};
        }

        return {-1, -1};
    }

    // 2. Best Time to Buy and Sell Stock
    // Given prices on each day, return the maximum profit by buying
    // on one day and selling on a different day that comes after
    static int maxProfit(vector<int> &prices) {
        int x = INT_MAX, y = 0;

        for (auto p : prices) {
            x = min(p, x);
            y = max(y, p - x);
        }
        return y;
    }

    // 3. Contains Dubplicate
    // GIven a vector of nums, returns true if a duplicate exists
    static bool containsDuplicate(vector<int> &nums) {
        unordered_map<int, int> map;
        for (int i{}; i < nums.size(); i++) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = i;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Test for 1. Two Sum
    cout << "Test for Two Sum:" << endl;
    vector<int> input{11, 7, 2, 15};
    int target = 9;
    for (int i : Solution::twoSum(input, target)) {
        cout << i << " ";
    }
    cout << endl
         << "-----" << endl;

    // Test for 2. Best Time to Buy and Sell Stock
    cout << "Test for Best TIme to Buy and Sell Stock:" << endl;
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << Solution::maxProfit(prices);
    cout << endl
         << "-----" << endl;

    // Test for 3. Contains Duplicate
    cout << "Test for Contains Duplciate:" << endl;
    vector<int> nums{1, 2, 3, 1};
    cout << (Solution::containsDuplicate(nums) ? "Duplicate Found" : "No Duplicate Found");
    cout << endl
         << "-----" << endl;

    return 0;
}