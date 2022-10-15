#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void dec_to_bin (int n, char *s) // Subprogramul transforma numarul n din baza 10 in baza 2 si il intoarce ca sir de caractere (s) de ‘0’ sau ‘1’.
{
    int i;
    for(i=7; i>=0; i--)
    {
        s[i]='0'+n%2;
        n=n/2;
    }
    s[8]='\0';
}

int bin_to_dec(char *s) // Subprogramul primeste un numar in baza 2 ca sir de caractere si intoarce valoarea in baza 10.
{
    int i, n=0, p=1;
    for(i=7; i>=0; i--)
    {
        n=n+(s[i]-'0')*p;
        p=p*2;
    }
    return n;
}

void inmultire(int A[8][8], int B[8][8], int C[8][8]) // Subprogramul inmulteste maricele A si B.
{
    int i, j, x;
    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
        {
            C[i][j]=0;
            for(x=0; x<8; x++)
                C[i][j]=C[i][j]+A[i][x]*B[x][j];
            if(C[i][j]>1)
                C[i][j]=1;
        }
}

void transpusa (int A[8][8], int T[8][8]) // Subprogramul calculeaza transpusa matricei.
{
    int i, j;
    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
            T[i][j]=A[j][i];
}

int sum_X_0(int m[8][8])
{
    int i, j, scor=0, ok;
    for(j=0; j<8; j++)
    {
        ok=1;
        for(i=0; i<4; i++)
            if(m[i][j]==0)
                ok=0;
        if(ok==1)
            scor++;
        ok=1;
        for(i=4; i<8; i++)
            if(m[i][j]==0)
                ok=0;
        if(ok==1)
            scor++;
    }

    for(i=0; i<8; i++)
    {
        ok=1;
        for(j=0; j<4; j++)
            if(m[i][j]==0)
                ok=0;
        if(ok==1)
            scor++;
        ok=1;
        for(j=4; j<8; j++)
            if(m[i][j]==0)
                ok=0;
        if(ok==1)
            scor++;
    }

    ok=1;
    for(i=0; i<4; i++)
        if(m[i][i]==0)
            ok=0;
    if(ok==1)
        scor++;

    ok=1;
    for(i=4; i<8; i++)
        if(m[i][i]==0)
            ok=0;
    if(ok==1)
        scor++;

    ok=1;
    for(i=0; i<4; i++)
        if(m[i][i+4]==0)
            ok=0;
    if(ok==1)
        scor++;

    ok=1;
    for(i=4; i<8; i++)
        if(m[i][i-4]==0)
            ok=0;
    if(ok==1)
        scor++;

    ok=1;
    for(i=0; i<4; i++)
        if(m[i][3-i]==0)
            ok=0;
    if(ok==1)
        scor++;

    ok=1;
    for(i=4; i<8; i++)
        if(m[i][11-i]==0)
            ok=0;
    if(ok==1)
        scor++;

    ok=1;
    for(i=0; i<4; i++)
        if(m[i][7-i]==0)
            ok=0;
    if(ok==1)
        scor++;

    ok=1;
    for(i=4; i<8; i++)
        if(m[i][7-i]==0)
            ok=0;
    if(ok==1)
        scor++;
    return scor;
}

int main()
{
    int A[8][8], A2[8][8], T[8][8], AT[8][8], max, x, i, j, scorA, scorAT, scorA2;
    char AC[9][9], ATC[9][9], A2C[9][9];

    for(i=0; i<8; i++)
    {
        scanf("%d", &x);
        dec_to_bin(x, AC[i]); // Fiecare sir binar se salveaza in vectorul de cuvinte AC.
    }

    for(i=0; i<8; i++)
        for(j=0; j<8; j++)
            A[i][j]=AC[i][j]-'0'; // Pentru fiecare sir din AC, se salveaza corespondentul intreg in matricea A.

    inmultire(A, A, A2); // Se calculeaza A^2 (A2).
    transpusa(A, T); // Se calculeaza transpusa lui A (T).
    inmultire(A, T, AT); // Se calculeaza A*(A^t) (AT).

    scorA=sum_X_0(A); // Se calculeaza scorul lui A.
    scorAT=sum_X_0(AT); // Se calculeaza scorul lui A*(A^t).
    scorA2=sum_X_0(A2); // Se calculeaza scorul lui A^2.

    if(scorA>scorAT) // Se salveaza scorul maxim in max.
        max=scorA;
    else max=scorAT;
    if(scorA2>max)
        max=scorA2;

    if(max==scorA)
    {
        for(i=0; i<8; i++)
            printf("%d\n", bin_to_dec(AC[i])); // Se afiseaza numerele in baza 10.
    }
    else
    {
        if(max==scorAT)
        {
            for(i=0; i<8; i++)
                for(j=0; j<8; j++)
                    ATC[i][j]=AT[i][j]+'0'; // Salvam in ATC intregii din AT, sub forma de sir de caractere.

            for(i=0; i<8; i++)
                printf("%d\n", bin_to_dec(ATC[i])); // Se afiseaza numerele in baza 10.
        }
        else
        {
            for(i=0; i<8; i++)
                for(j=0; j<8; j++)
                    A2C[i][j]=A2[i][j]+'0'; // Salvam in A2C intregii din A2, sub forma de sir de caractere.

            for(i=0; i<8; i++)
                printf("%d\n", bin_to_dec(A2C[i])); // Se afiseaza numerele in baza 10.
        }
    }

    return 0;
}
