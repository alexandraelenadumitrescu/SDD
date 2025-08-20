#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

/*
   Cerința 1:
   Fișierul "carti.txt" conține: id, număr pagini, preț, titlu, autor, categorie
   (valorile separate prin ',' sau '\n').
   Să se citească toate cărțile și să se afișeze pe ecran.
*/
struct Carte {
	int id;
	int nrPagini;
	float pret;
	char* titlu;
	char* autor;
	char categorie;

};
typedef struct Carte Carte;

Carte* citireCartiDinFisier(const char* numeFisier, int* numarCartiCitite) {
	FILE* f;
	f = fopen(numeFisier, "r");
	Carte* carti=NULL;
	char line[101];
	while (fgets(line, sizeof(line), f)) {
		//citesc cartea si o adaug in vector;
		(*numarCartiCitite)++;
		carti = (Carte*)realloc(carti,sizeof(Carte) * (*numarCartiCitite));
		char* buffer=NULL;
		
		char sep[4] = ",\n;";
		//fgets(line, 100, f);
		Carte c;
		c.id = atoi(strtok(line, sep));

		c.nrPagini = atoi(strtok(NULL, sep));

		c.pret = atof(strtok(NULL, sep));

		buffer = strtok(NULL, sep);
		c.titlu = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		strcpy_s(c.titlu, strlen(buffer) + 1,buffer);

		buffer = strtok(NULL, sep);
		c.autor = (char*)malloc(sizeof(char) * (strlen(buffer) + 1));
		strcpy_s(c.autor, strlen(buffer) + 1, buffer);

		buffer = strtok(NULL, sep);
		c.categorie = buffer[0];

		carti[(*numarCartiCitite) - 1] = c;

	}
	return carti;
}
void afisareCarte(Carte carte) {
	printf("id: %d\n", carte.id);
	printf("numar pagini: %d\n", carte.nrPagini);
	printf("pret: %f\n", carte.pret);
	printf("titlu: %s\n", carte.titlu);
	printf("autor: %s\n", carte.autor);
	printf("categorie: %c\n", carte.categorie);
	printf("\n");
}

void afisareVector(Carte* carti, int nrCarti) {
	for (int i = 0;i < nrCarti;i++) {
		printf("id: %d\n", carti[i].id);
		printf("numar pagini: %d\n", carti[i].nrPagini);
		printf("pret: %f\n", carti[i].pret);
		printf("titlu: %s\n", carti[i].titlu);
		printf("autor: %s\n", carti[i].autor);
		printf("categorie: %c\n", carti[i].categorie);
		printf("\n");


	
	}
}

/*
   Cerința 2:
   Să se determine și să se afișeze cartea cu **cel mai mare preț** din fișier.
*/
Carte pretMaxim(Carte* carti, int nrCarti) {
	float max = carti[0].pret;
	int index = 0;
	for (int i = 0;i < nrCarti;i++) {
		if (carti[i].pret > max) {
			max = carti[i].pret;
			index = i;
		}
	}
	return carti[index];
}

/*
   Cerința 3:
   Să se calculeze și să se afișeze **media prețurilor** tuturor cărților.
*/
float pretMediu(Carte* carti, int nr) {
	float medie = 0;
	for (int i = 0;i < nr;i++) {
		medie = medie + carti[i].pret;
	}
	return medie/nr ;
}

/*
   Cerința 4:
   Să se afișeze toate cărțile care au un anumit număr de pagini (de exemplu 300 pagini).
*/
void prag(Carte* carti, int nr,int prag) {
	for (int i = 0;i < nr;i++) {
		if (carti[i].nrPagini > prag) {
			afisareCarte(carti[i]);
		}
	}
}


/*
   Cerința 5:
   Să se calculeze și să se afișeze **numărul de cărți pentru fiecare categorie** din fișier.
*/
char* nrDeCartiPerCategorie(Carte* carti, int nrCarti) {
	char* categorii = (char*)malloc(nrCarti+1);
	for (int i = 0;i < nrCarti;i++) {
		categorii[i] = carti[i].categorie;
	}
	categorii[nrCarti] = '\0';
	return categorii;
}
char* frecvente(char* categorii) {
	for (int i = 0;i < strlen(categorii);i++) {
		for (int j = i+1;j < strlen(categorii);) {
			if (categorii[i] == categorii[j]) {
				for (int k = j ;k < strlen(categorii);k++) {
					categorii[k] = categorii[k+ 1];
				}
				
			}
			else {
				j++;
			}
		}
	}
	return categorii;
	
}

/*
   Cerința 6:
   Să se afișeze cărțile unui anumit autor, citind numele autorului de la tastatură.
*/

/*
   Cerința 7:
   Să se sorteze cărțile după preț (crescător) și să se afișeze lista sortată.
*/

/*
   Cerința 8:
   Să se calculeze suma totală a prețurilor tuturor cărților dintr-o anumită categorie.
*/

/*
   Cerința 9:
   Să se determine cartea cu **cel mai mare număr de pagini** și să se afișeze titlul și autorul acesteia.
*/

/*
   Cerința 10:
   Să se afișeze toate cărțile care au prețul mai mare decât media prețurilor din fișier.
*/


int main() {
	Carte* carti = NULL;
	int n = 0;
	carti = citireCartiDinFisier("fisier.txt", &n);
	afisareVector(carti, n);
	afisareCarte(pretMaxim(carti, n));
	printf("\n");
	printf("pretul mediu al cartilor este: %f \n", pretMediu(carti, n));
	prag(carti, n,200);
	printf("\n%s gata sirul", nrDeCartiPerCategorie(carti, n));
	char* sir =(char*)malloc( strlen("abcabcabc")+1);
	//sir = "abcabcabc";
	strcpy_s(sir, strlen("abcabcabc") + 1, "abcabcabc");
	printf("%s", sir);
	printf("\n-------------\n");
	printf("%s", frecvente(sir));
	return 0;
}