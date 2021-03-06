// https://www.interviewbit.com/problems/longest-common-subsequence/
// Example Input
// Input 1:

//  A = "abbcdgf"
//  B = "bbadcgf"


// Example Output
// Output 1:

//  5

int Solution::solve(string A, string B) {

int n = A.length(), m = B.length();
int i, j, k;
int dp[n+1][m+1];

for(i=0; i<=n; i++)
	dp[i][0] = 0;

for(i=0; i<=m; i++)
	dp[0][i] = 0;

for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		if(A[i-1] == B[j-1])
			dp[i][j] = dp[i-1][j-1] + 1;
		
		else
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	}
}

return dp[n][m];
}