class Solution 
{
public:
	int coinChange(vector<int>& coins, int amount);
};
int Solution::coinChange(vector<int>& coins, int amount)
{
	int CoinNum(coins.size());
	//�������飬��Ϊ���˵�ǰ��i�к�i-1��֮�⣬���ò����ˣ������������������
	vector<vector<int>> dp(2, vector<int>(amount + 1, amount+1));
	//�Ա߽�����������
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