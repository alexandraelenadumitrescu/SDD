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
Carte deepCopy(Carte original) {
	Carte copie;
	copie.id = original.id;
	copie.nrPagini = original.nrPagini;
	copie.pret = original.pret;

	copie.titlu = (char*)malloc(strlen(original.titlu) + 1);
	strcpy_s(copie.titlu, strlen(original.titlu) + 1, original.titlu);

	copie.autor = (char*)malloc(strlen(original.autor) + 1);
	strcpy_s(copie.autor, strlen(original.autor) + 1, original.autor);

	copie.categorie = original.categorie;
	return copie;
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
char* frecventeUQ(char* categorii) {
	char* copie = (char*)malloc(strlen(categorii) + 1);
	strcpy_s(copie, strlen(categorii) + 1, categorii);
	for (int i = 0;i < strlen(copie);i++) {
		for (int j = i+1;j < strlen(copie);) {
			if (copie[i] == copie[j]) {
				for (int k = j ;k < strlen(copie);k++) {
					copie[k] = copie[k+ 1];
				}
				
			}
			else {
				j++;
			}
		}
	}
	
	return copie;
	
}

void frecvente(char* categorii, char* frecventeUQ) {
	int count = 0;
	for (int i = 0;i < strlen(frecventeUQ);i++) {
		count = 0;
		for (int j = 0;j < strlen(categorii);j++) {
			
			if (categorii[j] == frecventeUQ[i]) {
				count++;
			}
		}
		printf("categoria %c apare de %d ori\n", frecventeUQ[i], count);
	}
}



/*
   Cerința 6:
   Să se afișeze cărțile unui anumit autor, citind numele autorului de la tastatură.
*/
void afisareCartiInFunctieDeAutor(Carte* carti,int nr) {
	Carte* autor=NULL;
	int count = 0;

	printf("introduceti numele autorului:\n");

	char buffer[256];
	scanf("%s", buffer);
	for (int i = 0;i < nr;i++) {
		//if (carti[i].autor == buffer)
			if (strcmp(carti[i].autor, buffer) == 0)
			{
			count++;
			autor = (Carte*)realloc(autor, sizeof(Carte)*count);
			autor[count - 1] = carti[i];
		}
	}
	afisareVector(autor, count);

}
/*
   Cerința 7:
   Să se sorteze cărțile după preț (crescător) și să se afișeze lista sortată.
*/
int minim(int lungime,Carte* carti,int start) {
	
	float minim = carti[0].pret;
	int index = 0;
	for (int i = start;i < lungime;i++) {
		if (minim > carti[i].pret) {
			index = i;
			minim = carti[i].pret;
		}
	}
	return index;
}

Carte* sortare(Carte* carti, int nrCarti) {
	Carte* copie = (Carte*)malloc(nrCarti * sizeof(Carte));
	for (int i = 0;i < nrCarti;i++) {
		//copie[i] = carti[i]; - shallow copy
		copie[i] = deepCopy(carti[i]);
	}
	
	for (int i = 0;i < nrCarti - 1;i++) {
		if (copie[i].pret > carti[minim(nrCarti,copie,i)].pret) {
			Carte aux = deepCopy(copie[i]);
			copie[i] = deepCopy(copie[minim(nrCarti,copie,i)]);
			copie[minim(nrCarti, copie, i)]=deepCopy(aux);
		}
	}
	return copie;
	
}
/*
   Cerința 8:
   Să se calculeze suma totală a prețurilor tuturor cărților dintr-o anumită categorie.
*/
float sumaTotalaPerCategorie(char categorie,Carte* carti,int nrCarti) {
	float suma = 0;
	int count = 0;
	for (int i = 0;i < nrCarti;i++) {
		printf(" % c % c\n", categorie, carti[i].categorie);
		if (carti[i].categorie == categorie) {
			
			suma += carti[i].pret;
			count++;
		}
	}
	return suma;
}

/*
   Cerința 9:
   Să se determine cartea cu **cel mai mare număr de pagini** și să se afișeze titlul și autorul acesteia.
*/
Carte maximPagini(int lungime, Carte* carti) {
	Carte carte;
	int maxim = carti[0].nrPagini;
	int index = 0;
	for (int i = 0;i < lungime;i++) {
		if (maxim < carti[i].nrPagini) {
			index = i;
			 maxim = carti[i].nrPagini;
		}
	}
	carte = deepCopy(carti[index]);
	printf("%s\n", carte.titlu);
	printf("%s\n", carte.autor);
	return carte;
}

/*
   Cerința 10:
   Să se afișeze toate cărțile care au prețul mai mare decât media prețurilor din fișier.
*/
float pretMediu1(Carte* carti, int lungime) {
	float suma = 0;
	for (int i = 0;i < lungime;i++) {
		suma += carti[i].pret;
	}
	return suma / lungime;
}

void pretPesteMedie(Carte* carti, int lungime) {
	float medie = pretMediu1(carti, lungime);
	for (int i = 0;i < lungime;i++) {
		if (carti[i].pret > medie) {
			afisareCarte(carti[i]);
		}
	}
}

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
	char* sir1 = (char*)malloc(strlen("abcabcabc") + 1);
	strcpy_s(sir1, strlen("abcabcabc") + 1, "abcabcabc");
	printf("%s", sir);
	printf("\n-------------\n");
	//printf("%s", frecventeUQ(sir));
	printf("\n-------------\n");
	frecvente(sir, frecventeUQ(sir));
	printf("\n-------------\n");

	frecvente(nrDeCartiPerCategorie(carti, n), frecventeUQ(nrDeCartiPerCategorie(carti, n)));

	printf("\n-------------\n");

	afisareCartiInFunctieDeAutor(carti,n);
	printf("%d", minim(n, carti,0));
	afisareVector(sortare(carti,n), n);
	printf("%f", sumaTotalaPerCategorie('T', carti, n));
	printf("%d", n);
	maximPagini(n,carti);
	pretPesteMedie(carti, n);
	return 0;
}