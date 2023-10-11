#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortowanie_szybkie(int *tab, int lewy, int prawy)
{
	int i, j, swap, pivot;
	i = lewy;
	j = prawy;
	pivot = tab[(lewy + prawy) / 2];
	do
	{
		while (*(tab + i) < pivot) i++;
		while (pivot < *(tab + j)) j--;
		if (i <= j)
		{
			swap = *(tab + i);
			*(tab + i) = *(tab + j);
			*(tab + j) = swap;
			i++;
			j--;
		}
	} while (i <= j);
	if (lewy<j) sortowanie_szybkie(tab, lewy, j);
	if (i<prawy) sortowanie_szybkie(tab, i, prawy);
}

void sortowanie_przez_wstawianie(int *tab, int l)
{
	printf("\nSortowanie przez wstawianie\n");
	int i, j, v;
	for (i = 1; i<l; i++)
	{
		j = i;
		v = *(tab + i);
		while ((j>0) && (*(tab + j - 1) > v))
		{
			*(tab + j) = *(tab + j - 1);
			j--;
		}
		*(tab + j) = v;
	}
}

void sortowanie_przez_scalanie(int *tab, int lewy, int prawy)
{
	int srodek;

	if (lewy != prawy)
	{
		srodek = (lewy + prawy) / 2;
		sortowanie_przez_scalanie(tab, lewy, srodek);
		sortowanie_przez_scalanie(tab, srodek + 1, prawy);
		scalanie(tab, lewy, srodek, prawy);
	}
}

void scalanie(int *tab, int lewy, int srodek, int prawy)
{
	int *tab_pom = (int *)malloc((prawy - lewy) * sizeof(int));
	int i = lewy, j = srodek + 1, k = 0;
	while (i <= srodek && j <= prawy)
	{
		if (*(tab + j) < *(tab + i))
		{
			*(tab_pom + k) = *(tab + j);
			j++;
		}
		else
		{
			*(tab_pom + k) = *(tab + i);
			i++;
		}
		k++;
	}

	if (i <= srodek)
	{
		while (i <= srodek)
		{
			*(tab_pom + k) = *(tab + i);
			i++;
			k++;
		}
	}
	else
	{
		while (j <= prawy)
		{
			*(tab_pom + k) = *(tab + j);
			j++;
			k++;
		}
	}

	for (i = 0; i <= prawy - lewy; i++)
		*(tab + lewy + i) = *(tab_pom + i);
}

void przywrocKopiec(int *tab, int n, int i){

	int j = i, ppot = i * 2 + 2, lpot = i * 2 + 1;
	if ((lpot<n) && (tab[j]<tab[lpot]))
		j = lpot;
	if ((ppot<n) && (tab[j]<tab[ppot]))
		j = ppot;
	if (i != j){
		int temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		przywrocKopiec(tab, n, j);
	}
}

void zbudujKopiec(int *tab, int n){
	int i;
	for (i = (n - 2) / 2; i >= 0; i--)
		przywrocKopiec(tab, n, i);}

void sortowaniePrzezKopcowanie(int *tab, int n){
	int i, temp;
	zbudujKopiec(tab, n);

	for (i = n - 1; i>0; i--){
		temp = tab[i];
		tab[i] = tab[0];
		tab[0] = temp;
		przywrocKopiec(tab, i, 0);
	}
	printf("\nSortowanie przez kopiec\n");
}
void czas(){
time_t czas;
time(&czas);
printf("\n%s",ctime(&czas));
}
void sortowanie_babelkowe(int *tab, int l)
{
	printf("\nSortowanie babelkowe\n");
	int i, temp, swap, j = 0;
	do
	{
		swap = 0;
		j++;
		i = l - 1;
		do
		{
			i--;
			if (*(tab + i) > *(tab + i + 1))
			{
				temp = *(tab + i + 1);
				*(tab + i + 1) = *(tab + i);
				*(tab + i) = temp;
				swap = 1;
			}
		} while (i > 0);
	} while (swap != 0);
}

void drukowanie_tablicy(int *tab, int l)
{
	int i;
	for (i = 0; i < l; i++)
	{
		printf("%d ", *(tab + i));
	}
}

void drukowanie_tablicy_od_tylu(int *tab, int l)
{
    printf("\n");
	int i;
	for (i = l-1; i > -1; i--)
	{
		printf("%d ", *(tab + i));
	}
	printf("\n");
}

void przywroc(int*tab1, int*tab2, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        (*(tab1 + i))=(*(tab2 + i));
    }
}

int main()
{
srand(time(NULL));
int *tab1,*tab2,n,wybor;
printf("\nPodaj rozmiar tablicy ");
scanf("%d", &n);
tab1=(int*)calloc(n, sizeof(int));
tab2=(int*)calloc(n, sizeof(int));

for (int i=0; i<n; i++)
{
    tab1[i]=1+(double)rand()/RAND_MAX* (n-1);
    tab2[i]=tab1[i];
}

printf("Przed sortowaniem\n");
drukowanie_tablicy(tab1, n);

printf("\n\n1.Sortowanie rosnaco.\n2.Sortowanie malejaco.\nWybor ");
scanf("%d", &wybor);

switch(wybor)
{
case 1: {
czas();
sortowanie_babelkowe(tab1, n);
czas();
drukowanie_tablicy(tab1, n);
przywroc(tab1, tab2, n);
czas();
sortowaniePrzezKopcowanie(tab1, n);
czas();
drukowanie_tablicy(tab1, n);
przywroc(tab1, tab2, n);
czas();
//sortowanie_przez_scalanie(tab1, 0, n-1);
//printf("\nSortowanie przez scalanie\n");
//czas();
//drukowanie_tablicy(tab1, n);
przywroc(tab1, tab2, n);
czas();
sortowanie_przez_wstawianie(tab1, n);
czas();
drukowanie_tablicy(tab1, n);
przywroc(tab1, tab2, n);
czas();
sortowanie_szybkie(tab1, 0, n-1);
printf("\nSortowanie szybkie\n");
czas();
drukowanie_tablicy(tab1, n);
przywroc(tab1, tab2, n);
break;}
case 2:
    {
czas();
sortowanie_babelkowe(tab1, n);
czas();
drukowanie_tablicy_od_tylu(tab1, n);
przywroc(tab1, tab2, n);
czas();
sortowaniePrzezKopcowanie(tab1, n);
czas();
drukowanie_tablicy_od_tylu(tab1, n);
przywroc(tab1, tab2, n);
czas();
//sortowanie_przez_scalanie(tab1, 0, n-1);
//printf("\nSortowanie przez scalanie\n");
//czas();
//drukowanie_tablicy_od_tylu(tab1, n);
przywroc(tab1, tab2, n);
czas();
sortowanie_przez_wstawianie(tab1, n);
czas();
drukowanie_tablicy_od_tylu(tab1, n);
przywroc(tab1, tab2, n);
czas();
sortowanie_szybkie(tab1, 0, n-1);
printf("\nSortowanie szybkie\n");
czas();
drukowanie_tablicy_od_tylu(tab1, n);
przywroc(tab1, tab2, n);
break;
}
}
return 0;
}
