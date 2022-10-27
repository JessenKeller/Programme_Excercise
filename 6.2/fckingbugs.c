#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define max 10000

int a[22], b[22], y[22];

int main() {
	
	int n, cases = 1;
	
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; ++ i) {
			scanf("%d%d%d", &y[i], &a[i], &b[i]);
		}
		
		int ans = y[0], det = b[0] - a[0];
		
		while ( ans < max ) {
			bool flag = true;
			for (int i = 1; i < n; ++ i) {
				if (ans < y[i] || (ans - y[i]) % (b[i] - a[i])) {
					flag = false;
					break;
				}
			}
			if ( flag ) {
				break;
			}
			ans += det;
		}
		printf("Case #%d:\n", cases ++);
		if ( ans < max ) {
			printf("The actual year is %d.\n", ans);
		} else {
			printf("Unknown bugs detected.\n");
		}
		puts("");
	}
	return 0;
}

