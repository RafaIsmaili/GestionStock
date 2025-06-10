#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "bib.h"

#include "ajout.h"
#include "sup.h"
#include "menu.h"
#include "afficheStock.h"

int main()
{
    int nbCat=0,nbType=0;
    Type TabType[20];
    Categorie TabCat[20];
    Produit Stock[100][50];
    int TabQte[50]={2,3,1,1};
    Categorie c1,c2,c3;
    c1.idCat=1;
    strcpy(c1.NomCat,"conserve");
    c2.idCat=2;
    strcpy(c2.NomCat,"Boisson");
    c3.idCat=3;
    strcpy(c3.NomCat,"Epice");
    TabCat[0]=c1;
    TabCat[1]=c2;
    TabCat[2]=c3;

    Type t1,t2,t3,t4;
    t1.idType=11;
    strcpy(t1.Nomtype,"tomate");
    t1.Cat=c1;

    t2.idType=12;
    strcpy(t2.Nomtype,"jus");
    t2.Cat=c2;

    t3.idType=10;
    strcpy(t3.Nomtype,"mais");
    t3.Cat=c1;

    t4.idType=45;
    strcpy(t4.Nomtype,"curcuma");
    t4.Cat=c3;
    nbCat=3;


    TabType[0]=t1;
    TabType[1]=t2;
    TabType[2]=t3;
    TabType[3]=t4;
    nbType=4;


    Produit p1,p2,p3,p4,p5,p6,p7;

    p1.id=50;
    strcpy(p1.nom,"pdt1");
    p1.type=t1;
    p1.dateexpiration.JJ=12;
    p1.dateexpiration.MM=12;
    p1.dateexpiration.AA=2021;

    p2.id=48;
    strcpy(p2.nom,"pdt2");
    p2.type=t2;
    p2.dateexpiration.JJ=14;
    p2.dateexpiration.MM=11;
    p2.dateexpiration.AA=2022;

    p3.id=27;
    strcpy(p3.nom,"pdt3");
    p3.type=t3;
    p3.dateexpiration.JJ=12;
    p3.dateexpiration.MM=12;
    p3.dateexpiration.AA=2021;

    p4.id=11;
    strcpy(p4.nom,"pdt4");
    p4.type=t4;
    p4.dateexpiration.JJ=25;
    p4.dateexpiration.MM=10;
    p4.dateexpiration.AA=2021;

    p5.id=48;
    strcpy(p5.nom,"pdt5");
    p5.type=t1;
    p5.dateexpiration.JJ=13;
    p5.dateexpiration.MM=12;
    p5.dateexpiration.AA=2020;


    p6.id=30;
    strcpy(p6.nom,"pdt6");
    p6.type=t2;
    p6.dateexpiration.JJ=10;
    p6.dateexpiration.MM=11;
    p6.dateexpiration.AA=2021;

    p7.id=60;
    strcpy(p7.nom,"pdt7");
    p7.type=t2;
    p7.dateexpiration.JJ=12;
    p7.dateexpiration.MM=12;
    p7.dateexpiration.AA=2021;



    Stock[0][0]=p1;
    Stock[0][1]=p5;

    Stock[1][0]=p2;
    Stock[1][1]=p6;
    Stock[1][2]=p7;

    Stock[2][0]=p3;

    Stock[3][0]=p4;

afficherMenu(&nbCat, &nbType, Stock, TabType, TabCat, TabQte);

    return 0;
}
