#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
int citireFisier(const char* numeFisier) {
	int* x;
	FILE* f;
	f = fopen(numeFisier, "r");
	if (f == NULL) {
		printf("eroare");
		return -1;
	}
	char buffer[101];
	char sep[4] = "\n,;";
	fgets(buffer, 100, f);
	x = atoi(strtok(buffer, sep));
	fclose(f);
	return x;
}

int main() {
	//int x = citireFisier("fisier.txt");
	int y = citireFisier("fisier.txt");
	for (char c = '0';c < 2;c++) {
		int x = citireFisier("fisier.txt");
		printf("%d\n", x);

	}
	//printf("%d\n", x);
	//printf("%d", y);

	return 0;
}