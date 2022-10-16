# ICONIC GAMES
  
## PROBLEMA 1

Durata implementarii: 1.5h

***Rezolvare:***
Sortarea perechilor de cuvinte in functie de gradul acestora.<br>
Functia `compute_grade` primeste ca parametrii doua cuvinte si verifica daca sunt anagrame (functia `is_anagram`), iar in caz contrar returneaza raportul dintre rezultat si lungimea totala a sirurilor.

##  PROBLEMA 2

Durata implementarii: 3h

***Rezolvare:*** 
Am construit o matrice (***'sah'***) in care sunt evidentiati nebunii. <br>
Pentru fiecare, am creat functiile `search_dp` si `search_ds` care returneaza numarul de nebuni cu care se ataca piesa pe diagonala paralela cu cea principala si, respectiv, cu cea secundara.<br>
Pentru cea de-a doua parte a problemei, in cazul in care numarul de perechi este diferit de 1, se afiseaza "NU". Altfel, am parcurs din nou matricea, iar pentru fiecare valoare am verificat:

* daca este egala cu 1; <br>
* daca nebunul face parte din perechea gasita (prin verificarea pe diagonale prin cele doua functii); <br>
* daca se poate muta astfel incat sa nu se atace cu niciun nebun (functia move);

In cazul in care sunt indeplinite conditiile, se afiseaza "DA".

##  PROBLEMA 3

Durata implementarii: 6h

***Rezolvare:***
Am facut cate o functie pentru fiecare miscare a cubului rubik, care modifica matricea asociata. Fiecare dintre ele implica rotirea fetei respective si mutarea culorilor de pe marginea fetei.

##  PROBLEMA 4

Durata implementarii: 2h

***Rezolvare:*** 
Am calculat scorurile pentru fiecare matrice (functia `sum_X_0`) si maximul dintre ele.
