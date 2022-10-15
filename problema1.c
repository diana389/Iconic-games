#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_anagram (char *s1, char *s2) // Subprogramul verifica daca cele doua cuvinte sunt anagrame
{
    if(strlen(s1)!=strlen(s2)) // O conditie este lungimea egala a sirurilor
        return 0;

    int i, v1[26]= {0}, v2[26]= {0}, size=strlen(s1);

    for(i=0; i<size; i++)
    {
        v1[s1[i]-'a']++; // In v1 s-a pastrat numarul de aparintii al fiecarei litere din s1.
        v2[s2[i]-'a']++; // In v2 s-a pastrat numarul de aparintii al fiecarei litere din s2.
    }

    for(i=0; i<25; i++)
        if(v1[i]!=v2[i]) // Pentru a fi anagrame, fiecare litera trebuie sa apara de un numar egal de ori in ambele siruri.
            return 0;
    return 1;
}

double compute_grade(char *s1, char *s2) // Subprogramul calculeaza gradul a doua cuvinte.
{
    int i, size=strlen(s1), k=0;

    if(is_anagram(s1,s2)==0) // Daca cuvintele sunt anagrame, gradul este -1.
        return -1;

    for(i=0; i<size; i++)
    {
        if(s1[i]!=s2[i])
            k++; // Se calculeaza numarul de caractere diferite.
    }

    return (double)k/size;
}

int main()
{
    int N, i, ok=1;
    char w[1000][102], s1[51], s2[51], aux[102];
    double grad[1000], aux1;

    scanf("%d", &N);
    getc(stdin);

    for(i=0; i<N; i++)
    {
        scanf("%s",s1);
        scanf("%s",s2);
        grad[i]=compute_grade(s1, s2); // Gradul perechii de pe linia i este retinut in vectorul grad, pe pozitia i.
        strcpy(w[i],s1); // Cele doua cuvinte de salveaza in matricea w.
        strcat(w[i]," ");
        strcat(w[i],s2);
    }

    while(ok) // Perechile se ordoneaza descrescator dupa grad.
    {
        ok=0;
        for(i=0; i<N-1; i++)
            if(grad[i]<grad[i+1])
            {
                strcpy(aux,w[i]);
                strcpy(w[i],w[i+1]);
                strcpy(w[i+1],aux);
                aux1=grad[i];
                grad[i]=grad[i+1];
                grad[i+1]=aux1;
                ok=1;
            }
    }

    ok=1;
    while(ok) //  In cazul in care mai multe perechi au acelasi grad, se ordoneaza lexicografic, tot descrescator.
    {
        ok=0;
        for(i=0; i<N-1; i++)
            if(grad[i]==grad[i+1] && strcmp(w[i],w[i+1])<0)
            {
                strcpy(aux,w[i]);
                strcpy(w[i],w[i+1]);
                strcpy(w[i+1],aux);
                aux1=grad[i];
                grad[i]=grad[i+1];
                grad[i+1]=aux1;
                ok=1;
            }
    }

    for(i=0; i<N; i++)
        printf("%s\n", w[i]);

return 0;
}