#include <cstdio>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#define MaxN 1000

using namespace std;

int cmp1(int a, int b) {
	return a > b;
}

int main() {
	int CoinNum, PayAmt;
	int dp[MaxN];
	int FaceVal[MaxN];
	bool Choice[MaxN][MaxN];

	memset(FaceVal, 0, sizeof(FaceVal));
	memset(Choice, 0, sizeof(Choice));
	memset(dp, 0, sizeof(dp));

	scanf("%d%d", &CoinNum, &PayAmt);
	for (int i = 1; i <= CoinNum; i++)
		scanf("%d", &FaceVal[i]);
	sort(FaceVal + 1, FaceVal + CoinNum + 1, cmp1);
	for (int i = 1; i <= CoinNum; i++) {
		for (int j = PayAmt; j >= FaceVal[i]; j--) {
			if (dp[j] <= dp[j - FaceVal[i]] + FaceVal[i]) {
				Choice[i][j] = true;
				dp[j] = dp[j - FaceVal[i]] + FaceVal[i];
			}
		}
	}

	if (dp[PayAmt] != PayAmt) printf("No Solution");
	else {
		vector<int> arr;
		int v = PayAmt, index = CoinNum;
		while (v > 0) {
			if (Choice[index][v] == true) {
				arr.push_back(FaceVal[index]);
				v -= FaceVal[index];
			}
			index--;
		}

		for (long long unsigned i = 0; i < arr.size(); i++) {
			if (i != 0) printf(" ");
			printf("%d", arr[i]);
		}
	}
	return 0;
}

