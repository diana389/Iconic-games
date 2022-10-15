#include <stdio.h>
#include <stdlib.h>

int search_dp(int sah[100][100], int M, int x, int y) // Subprogramul cauta nebunii cu care nebunul curent se ataca, pe diagonala paralela cu diagonala principala.
{
    int dif=y-x, i, per=0, ok=0;

        if(sah[x][y]==0)
    {
        ok=1;
        sah[x][y]=1;
    }

    if(dif>0)
    {
        for(i=0; i<M-dif; i++)
            if(sah[i][i+dif]==1)
                per++;
    }
    else
    {
        for(i=-dif; i<M; i++)
            if(sah[i][i+dif]==1)
                per++;
    }

    if(per>0)
        per--;
    if(ok)
        sah[x][y]=0;

    return per;
}

int search_ds(int sah[100][100], int M, int x, int y) // Subprogramul cauta nebunii cu care nebunul curent se ataca, pe diagonala paralela cu diagonala secundara.
{
    int dif=y-x, i, per=0, ok=0;

    if(sah[x][y]==0)
    {
        ok=1;
        sah[x][y]=1;
    }

    if(dif<M)
    {
        for(i=0; i<=x+y; i++)
            if(sah[i][x+y-i]==1)
                per++;
    }
    else
    {
        for(i=x+y-M+1; i<M; i++)
            if(sah[i][x+y-i]==1)
                per++;
    }

        if(per>0)
        per--;
    if(ok)
        sah[x][y]=0;

    return per;
}

int move (int sah[100][100], int M, int x, int y) // Subprogramul verifica pentru ficare pozitie libera din matrice daca, in cazul in care nebunul ar fi mutat in locul respectiv, s-ar mai forma vreo pereche.
{
    int i, j;

    sah[x][y]=0;
    for(i=0; i<M; i++)
        for(j=0;j<M;j++)
            if(sah[i][j]==0 && search_dp(sah, M, i, j)==0 && search_ds(sah, M, i, j)==0)
                    return 1;
    sah[x][y]=1;

    return 0;  
}

int main()
{
    int M, N, x, y, per=0, i, j, sah[100][100]= {0};

    scanf("%d%d", &M, &N);
    for(i=0; i<N; i++)
    {
        scanf("%d%d", &x, &y);
        sah[x][y]=1; // Pozitiile pe care se afla nebunii sunt marcate cu 1.
    }

    for(i=0; i<M; i++)
        for(j=0; j<M; j++)
            if(sah[i][j]==1)
            {
                per=per+search_dp(sah, M, i, j); // Pentru fiecare nebun, am adunat la per numarul nebunilor cu care se ataca pe diagonala principala.
                per=per+search_ds(sah, M, i, j); // Pentru fiecare nebun, am adunat la per numarul nebunilor cu care se ataca pe diagonala secundara.
            }

    per=per/2; // Fiecare pereche a fost gasita de 2 ori, deci per se injumatateste.
    printf("%d\n", per);

    if(per==1)
    {
        for(i=0; i<M; i++)
            for(j=0; j<M; j++)
                if(sah[i][j]==1 && (search_dp(sah, M, i, j) || search_ds(sah, M, i, j)) && move(sah, M, i, j)) // Daca nebunul care se afla intr-o pereche poate fi mutat, afisam "DA".
                	{
                        printf("DA\n");
                             return 0;
                     }
    }
    printf("NU\n"); // In cazul in care niciunul nu a putut fi mutat, se afiseaza "NU".

    return 0;
}