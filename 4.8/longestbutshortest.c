#include <stdio.h>
#include <string.h>
#define size 20020

int main() {
	char s[size];
	int i = 0, j = 0, len, maxlen = -1, minlen = 1000, maxst = 0, minst = 0;
	gets(s);
	len = strlen(s);
	i = 0;

	while (1) {
		while (i < len && (s[i] == ' ' || s[i] == ',')) i++;
		if (i >= len) break;
		j = i;

		while (j < len && !(s[j] == ' ' || s[j] == ',')) j++;

		if (j - i > maxlen) {
			maxlen = j - i;
			maxst = i;
		}

		if (j - i < minlen) {
			minlen = j - i;
			minst = i;
		}
		i = j;
	}

	for (i = 0; i < maxlen; i++) printf("%c", s[maxst + i]);
	printf("\n");
	for (i = 0; i < minlen; i++) printf("%c", s[minst + i]);
	printf("\n");
	return 0;
}
