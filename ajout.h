#ifndef AJOUT_H_INCLUDED
#define AJOUT_H_INCLUDED

void AjouterCat(int *nbCat,Categorie TabCat[20]){
    if(*nbCat<20){
        Categorie cat;
        InitCat(&cat);
        bool verif =false;
        for(int i=0;i<*nbCat;i++){
                // strcmp pour la comparaison entre deux chaines de caractere
            if(strcmp(TabCat[i].NomCat , cat.NomCat) == 0 || TabCat[i].idCat == cat.idCat){
                verif= true;
                break;
            }
        }
        if(verif == true){
            printf( "La categorie existe deja! \n");
        }else{
            TabCat[*nbCat]= cat;
            printf("ajouter avec succes \n");
            *nbCat=*nbCat+1;
        }
    }else{
        printf("impossible d'ajouter une categorie, espace plein \n");
    }
}



void AjouterTyp(int *nbType,int *nbCat, Categorie TabCat[20],Type TAbType[20]){

    if(*nbType <50){
        printf( "choisissez parmi ces categories : \n");
        //afficher id et nom des categories
        for(int i = 0; i<*nbCat;i++){
            printf( "id: %d | nom: %s \n",TabCat[i].idCat, TabCat[i].NomCat);
        }

        Type type;
        InitType(&type);
        // chercher l'absence de type
        bool verifType =false;

        for(int i=0;i<nbType;i++){
        if(strcmp(TAbType[i].Nomtype,type.Nomtype) == 0 && TAbType[i].idType == type.idType){
            verifType= true;
        }
        }
        if(verifType){
            printf( "Le type existe deja! \n");
        }else{
            bool existeCat=false;
            //chercher l'existance categorie
            for(int j=0;j<*nbCat;j++){
                if(strcmp(TabCat[j].NomCat,type.Cat.NomCat) == 0 && TabCat[j].idCat == type.Cat.idCat){
                existeCat = true;
                break;
                }
            }
            if(existeCat){
                    TAbType[*nbType] = type;
                printf("ajouter avec succecs \n");

                *nbType=*nbType+1;
            }else{
                printf("La catecgorie n'existe pas \n");
            }
    }
}else{
        printf("impossible d'ajouter un type, espace sature \n");

        }
}


void AjouterPdt(Produit Stock[100][50], Type TabType[20], int TabQte[50], int *nbType){
    Produit pdt;
    //affichage type et cat de type
    for (int i=0; i<*nbType; i++){
        printf("id type :%d | nomtype : %s |id categorie : %d | nom categorie : %s \n",TabType[i].idType,TabType[i].Nomtype,TabType[i].Cat.idCat,TabType[i].Cat.NomCat);
    }
    InitPdt(&pdt);
    bool existeType =false;
    // verifier l'existance de type
    int position;
    for(int i=0;i<*nbType;i++){
        if((strcmp(TabType[i].Nomtype , pdt.type.Nomtype) == 0 )&&(TabType[i].idType == pdt.type.idType)){
            existeType = true;
            position=i;
            break;
        }
    }
    if(existeType ==true){
        bool existeProduit =false;
        //verifier l'existance de produit
        for(int c=0; c<TabQte[position];c++){
            if(Stock[position][c].id == pdt.id &&strcmp(Stock[position][c].nom,pdt.nom)==0 &&Stock[position][c].dateexpiration.AA==pdt.dateexpiration.AA &&
                 Stock[position][c].dateexpiration.JJ==pdt.dateexpiration.JJ &&Stock[position][c].dateexpiration.MM==pdt.dateexpiration.MM ){
                existeProduit=true;
                break;
            }
        }
        if(existeProduit==false){
            int indice=TabQte[position];
            Stock[position][indice]=pdt;
            TabQte[position]++;
        }else{
            printf("Le produit existe \n");
        }
    }else{
        printf("Veuillez creer le type d'abord !\n");
    }
}


#endif // AJOUT_H_INCLUDED
