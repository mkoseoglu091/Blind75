
class Solution(object):
    # 1. Two Sum
    # Return indexes of two elements that add up to target
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        for i, n in enumerate(nums):
            if target-n in dict:
                return [dict[target-n], i]
            else:
                dict[n] = i

    # 2. Best time to Buy and Sell Stock
    # Given a list of prices, returns max profit by selecting a day with low price,
    # and a day after that with a high price
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_profit = 0
        current_min = prices[0]
        current_max = prices[0]

        for price in prices:
            if current_max < price:
                current_max = price
                max_profit = max(max_profit, price - current_min)

            if current_min > price:
                current_min = price
                current_max = price

        return max_profit

    # 3. Contains Duplicate
    # checks if list contains duplicates
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        k = set()
        for num in nums:
            if num in k:
                return True
            else:
                k.add(num)

    # Tests
    def main(self):
        # Test for Two Sum
        print("Test for Two Sum")
        l = [11, 7, 2, 15]
        t = 9
        print("list:", l, "target:", t)
        print("result:", self.twoSum(l, t))
        print("-"*10)

        # Test for maxProfit
        print("Test for Max Profit")
        l = [7, 1, 5, 3, 6, 4]
        print("list:", l)
        print("result:", self.maxProfit([7, 1, 5, 3, 6, 4]))
        print("-"*10)

        # Test for
        print("Test for Contains Duplicate")
        l = [1, 2, 3, 1]
        print("result:", self.containsDuplicate(l))
        print("-"*10)


if __name__ == "__main__":
    array_solution = Solution()
    array_solution.main()
