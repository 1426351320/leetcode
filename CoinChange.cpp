class Solution 
{
public:
	int coinChange(vector<int>& coins, int amount);
};
int Solution::coinChange(vector<int>& coins, int amount)
{
	int CoinNum(coins.size());
	//滚动数组，因为除了当前第i行和i-1行之外，都用不到了，所以数组可以是两行
	vector<vector<int>> dp(2, vector<int>(amount + 1, amount+1));
	//对边界问题进行求解
	for (int i(0); i < 2; i++)
		dp[i][0] = 0;
	for (int i(1); i <= amount ; i++)
		if (i>=coins[0])
			dp[0][i] = min(1 + dp[0][i - coins[0]], dp[0][i]);

	for (int i(1); i < CoinNum; i++)
	{
		for (int j(1); j <= amount; j++)
		{
			if (j >= coins[i])
				dp[i%2][j] = min(dp[(i - 1)%2][j], 1 + dp[i%2][j - coins[i]]);
			else
				dp[i%2][j] = dp[(i - 1)%2][j];
		}
	}
	return dp[(CoinNum - 1)%2][amount]==(amount+1)?-1: dp[(CoinNum - 1) % 2][amount];
}