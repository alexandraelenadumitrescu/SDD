#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int citireDinFisier(const char* numeFisier) {
	int x;
	FILE* f;
	f = fopen(numeFisier, "r");
	if (f == NULL) {
		printf("eroare");
		return -1;
	}

	char buffer[101];
	char sep[4] = ",\n;";
	fgets(buffer, 100, f);
	x = atoi(strtok(buffer, sep));
	fclose(f);
	return x;
}
int main() {
	int x = citireDinFisier("fisier.txt");
	printf("%d", x);
	return 0;
}