#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void interschimb (char s1[33], char s2[33], int poz1, int poz2) // Subprogramul inlocuieste culoarea de pe pozitia poz1 din s1 cu cea de pe pozitia poz2 din s2
{
    char cul2[11], *p, aux1[33]="", aux2[33];
    int n=0;
    strcpy(aux2,s2); 
    p=strtok(aux2, "."); // Se despart culorile din sirul s2 dupa delimitatorul '.', pentru a afla culoarea de pe pozitia poz2
    while(p && n<poz2)
    {
        n++;
        p=strtok(NULL, ".");
    }
    strcpy(cul2,p); //  Se retine culoarea de pe pozitia poz2 in cul2
    n=0;
    p=strtok(s1, "."); // Se despart culorile din sirul s1
    while(p)
    {
        if(n!=poz1) // Culorile de pe pozitii diferite de poz1 raman nemodificate
        {
            strcat(aux1,p); 
            strcat(aux1,".");
        }
        else // Pe pozitia poz1, culoarea se inlocuieste cu cul2
        {
            strcat(aux1,cul2);
            strcat(aux1,".");
        }
        n++;
        p=strtok(NULL, ".");
    }
    strcpy(s1,aux1);
    s1[strlen(s1)-1]='\0';
}

void rotire_dr(char rubik[18][33], int l) // Subprogramul roteste catre dreapta fata cubului care corespunde liniilor l, l+1, l+2 din matricea rubik
{
    char aux[33];
    strcpy(aux,rubik[l]);
    interschimb(rubik[l], rubik[l], 2, 0);
    interschimb(rubik[l], rubik[l+1], 1, 0);
    interschimb(rubik[l], rubik[l+2], 0, 0);
    interschimb(rubik[l+1], rubik[l+2], 0, 1);
    interschimb(rubik[l+2], rubik[l+2], 0, 2);
    interschimb(rubik[l+2], rubik[l+1], 1, 2);
    interschimb(rubik[l+2], aux, 2, 2);
    interschimb(rubik[l+1], aux, 2, 1);
}

void rotire_st(char rubik[18][33], int l) // Subprogramul roteste catre stanga fata cubului care corespunde liniilor l, l+1, l+2 din matricea rubik
{
    char aux[33];
    strcpy(aux,rubik[l]);
    interschimb(rubik[l], rubik[l], 0, 2);
    interschimb(rubik[l], rubik[l+1], 1, 2);
    interschimb(rubik[l], rubik[l+2], 2, 2);
    interschimb(rubik[l+1], rubik[l+2], 2, 1);
    interschimb(rubik[l+2], rubik[l+2], 2, 0);
    interschimb(rubik[l+2], rubik[l+1], 1, 0);
    interschimb(rubik[l+2], aux, 0, 0);
    interschimb(rubik[l+1], aux, 0, 1);
}

void F (char rubik[18][33]) // Subprogramul executa miscarea F
{
    char aux[3][33];
    int i;
    for(i=0; i<3; i++)
    {
        strcpy(aux[i],rubik[i+12]);
    }

    for(i=0; i<3; i++)
        interschimb(rubik[i+12], rubik[9], 2, i);

    for(i=0; i<3; i++)
        interschimb(rubik[9], rubik[17-i], i, 0);

    for(i=0; i<3; i++)
        interschimb(rubik[i+15], rubik[8], 0, i);

    for(i=0; i<3; i++)
        interschimb(rubik[8], aux[2-i], i, 2); // Culorile de pe marginea fetei sunt mutate

    rotire_dr(rubik, 0); // Fata corespunzatoare este rotita
}

void F1 (char rubik[18][33]) // Subprogramul executa miscarea F'
{
    char aux[3][33];
    int i;
    for(i=0; i<3; i++)
    {
        strcpy(aux[i],rubik[i+12]);
    }

    for(i=0; i<3; i++)
        interschimb(rubik[14-i], rubik[8], 2, i);

    for(i=0; i<3; i++)
        interschimb(rubik[8], rubik[15+i], i, 0);

    for(i=0; i<3; i++)
        interschimb(rubik[17-i], rubik[9], 0, i);

    for(i=0; i<3; i++)
        interschimb(rubik[9], aux[i], i, 2);

    rotire_st(rubik, 0);
}

void B (char rubik[18][33]) // Subprogramul executa miscarea B
{
    char aux[3][33];
    int i;
    for(i=0; i<3; i++)
    {
        strcpy(aux[i],rubik[i+6]);
    }
    for(i=0; i<3; i++)
        interschimb(rubik[6], rubik[i+15], i, 2);

    for(i=0; i<3; i++)
        interschimb(rubik[17-i], rubik[11], 2, i);

    for(i=0; i<3; i++)
        interschimb(rubik[11], rubik[i+12], i, 0);

    for(i=0; i<3; i++)
        interschimb(rubik[14-i], aux[0], 0, i);

    rotire_dr(rubik, 3);
}

void B1 (char rubik[18][33]) // Subprogramul executa miscarea B'
{
    char aux[3][33];
    int i;
    for(i=0; i<3; i++)
    {
        strcpy(aux[i],rubik[i+6]);
    }
    for(i=0; i<3; i++)
        interschimb(rubik[6], rubik[14-i], i, 0);

    for(i=0; i<3; i++)
        interschimb(rubik[i+12], rubik[11], 0, i);

    for(i=0; i<3; i++)
        interschimb(rubik[11], rubik[17-i], i, 2);

    for(i=0; i<3; i++)
        interschimb(rubik[i+15], aux[0], 2, i);
  
    rotire_st(rubik, 3);
}

void U (char rubik[18][33]) // Subprogramul executa miscarea U
{
    char aux[3][33];
    int i;
    for(i=0; i<3; i++)
    {
        strcpy(aux[i],rubik[i+12]);
    }

    for(i=0; i<3; i++)
        interschimb(rubik[12], rubik[0], i, i);

    for(i=0; i<3; i++)
        interschimb(rubik[0], rubik[15], i, i);

    for(i=0; i<3; i++)
        interschimb(rubik[15], rubik[3], i, i);

    for(i=0; i<3; i++)
        interschimb(rubik[3], aux[0], i, i);

    rotire_dr(rubik, 6);
}

void U1 (char rubik[18][33]) // Subprogramul executa miscarea U'
{
    char aux[3][33];
    int i;
    for(i=0; i<3; i++)
    {
        strcpy(aux[i],rubik[i+3]);
    }

    for(i=0; i<3; i++)
        interschimb(rubik[3], rubik[15], i, i);

    for(i=0; i<3; i++)
        interschimb(rubik[15], rubik[0], i, i);

    for(i=0; i<3; i++)
        interschimb(rubik[0], rubik[12], i, i);

    for(i=0; i<3; i++)
        interschimb(rubik[12], aux[0], i, i);

    rotire_st(rubik, 6);
}

void D (char rubik[18][33]) // Subprogramul executa miscarea D
{
    char aux[3][33];
    int i;
    for(i=0; i<3; i++)
    {
        strcpy(aux[i],rubik[i+3]);
    }

    for(i=0; i<3; i++)
        interschimb(rubik[5], rubik[17], i, i);

    for(i=0; i<3; i++)
        interschimb(rubik[17], rubik[2], i, i);

    for(i=0; i<3; i++)
        interschimb(rubik[2], rubik[14], i, i);

    for(i=0; i<3; i++)
        interschimb(rubik[14], aux[2], i, i);

    rotire_dr(rubik, 9);
}

void D1 (char rubik[18][33]) // Subprogramul executa miscarea D'
{
    char aux[3][33];
    int i;
    for(i=0; i<3; i++)
    {
        strcpy(aux[i],rubik[i+12]);
    }

    for(i=0; i<3; i++)
        interschimb(rubik[14], rubik[2], i, i);

    for(i=0; i<3; i++)
        interschimb(rubik[2], rubik[17], i, i);

    for(i=0; i<3; i++)
        interschimb(rubik[17], rubik[5], i, i);

    for(i=0; i<3; i++)
        interschimb(rubik[5], aux[2], i, i);

    rotire_st(rubik, 9);
}

void R (char rubik[18][33]) // Subprogramul executa miscarea R
{
    char aux[3][33];
    int i;
    for(i=0; i<3; i++)
    {
        strcpy(aux[i],rubik[i+6]);
    }

    for(i=0; i<3; i++)
        interschimb(rubik[i+6], rubik[i], 2, 2);

    for(i=0; i<3; i++)
        interschimb(rubik[i], rubik[i+9], 2, 2);

    for(i=0; i<3; i++)
        interschimb(rubik[i+9], rubik[5-i], 2, 0);

    for(i=0; i<3; i++)
        interschimb(rubik[5-i], aux[i], 0, 2);

    rotire_dr(rubik, 15);
}

void R1 (char rubik[18][33]) // Subprogramul executa miscarea R'
{
    char aux[3][33];
    int i;
    for(i=0; i<3; i++)
    {
        strcpy(aux[i],rubik[i+9]);
    }

    for(i=0; i<3; i++)
        interschimb(rubik[i+9], rubik[i], 2, 2);

    for(i=0; i<3; i++)
        interschimb(rubik[i], rubik[i+6], 2, 2);

    for(i=0; i<3; i++)
        interschimb(rubik[i+6], rubik[5-i], 2, 0);

    for(i=0; i<3; i++)
        interschimb(rubik[5-i], aux[i], 0, 2);
 
    rotire_st(rubik, 15);
}

void L (char rubik[18][33]) // Subprogramul executa miscarea L
{
    char aux[3][33];
    int i;
    for(i=0; i<3; i++)
    {
        strcpy(aux[i],rubik[i+9]);
    }

    for(i=0; i<3; i++)
        interschimb(rubik[i+9], rubik[i], 0, 0);

    for(i=0; i<3; i++)
        interschimb(rubik[i], rubik[i+6], 0, 0);

    for(i=0; i<3; i++)
        interschimb(rubik[i+6], rubik[5-i], 0, 2);

    for(i=0; i<3; i++)
        interschimb(rubik[5-i], aux[i], 2, 0);

    rotire_dr(rubik, 12);
}

void L1 (char rubik[18][33]) // Subprogramul executa miscarea L'
{
    char up[3][33];
    int i;
    for(i=0; i<3; i++)
    {
        strcpy(up[i],rubik[i+6]);
    }

    for(i=0; i<3; i++)
        interschimb(rubik[i+6], rubik[i], 0, 0);

    for(i=0; i<3; i++)
        interschimb(rubik[i], rubik[i+9], 0, 0);

    for(i=0; i<3; i++)
        interschimb(rubik[i+9], rubik[5-i], 0, 2);

    for(i=0; i<3; i++)
        interschimb(rubik[5-i], up[i], 2, 0);

    rotire_st(rubik, 12);
}

int main()
{
    int i, k;
    char cul1[11], cul2[11], cul3[11], cul4[11], cul5[11], cul6[11], rubik[18][33], move[3];
    
    scanf("%s%s%s%s%s%s", cul1, cul2, cul3, cul4, cul5, cul6);
    for(i=0; i<18; i++)
        scanf("%s",rubik[i]);
    getc(stdin);
    scanf("%d", &k);

    for(i=0; i<k; i++)
    {
        scanf("%s", move);
        if(strcmp(move, "F")==0)
            F(rubik);
        if(strcmp(move, "F'")==0)
            F1(rubik);
        if(strcmp(move, "B")==0)
            B(rubik);
        if(strcmp(move, "B'")==0)
            B1(rubik);
        if(strcmp(move, "U")==0)
            U(rubik);
        if(strcmp(move, "U'")==0)
            U1(rubik);
        if(strcmp(move, "D")==0)
            D(rubik);
        if(strcmp(move, "D'")==0)
            D1(rubik);
        if(strcmp(move, "R")==0)
            R(rubik);
        if(strcmp(move, "R'")==0)
            R1(rubik);
        if(strcmp(move, "L")==0)
            L(rubik);
        if(strcmp(move, "L'")==0) 
            L1(rubik);
    }

    for(i=0; i<18; i++)
      printf("%s\n",rubik[i]);
      
    return 0;
}