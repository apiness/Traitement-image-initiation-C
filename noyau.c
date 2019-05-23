#include <stdlib.h>
#include "noyau.h"
#include <stdio.h>
#include <string.h>
#include "pgm_image.h"
#include "image.h"

#define TMP_STR_SIZE 128

/*noyau_t *creer_noyau(unsigned int dim){
    noyau_t *n=malloc(dim*dim*sizeof(unsigned int)+sizeof(unsigned int)); 
    if(n!=NULL){
            n->dim=dim;
            return n;
    }
	return NULL;
}

void detruire_noyau(noyau_t *pn){
    if(pn!=NULL){
        if(pn->coeffs != NULL)
            free(pn->coeffs);
        free(pn);
    }
}

noyau_t *charger_noyau(char *nom_fichier){
    FILE *f;
    f=fopen(nom_fichier,"r");
	if(f==NULL){
		printf("Erreur à l'ouverture");
		return NULL;
	}
    char s[TMP_STR_SIZE];
    fgets(s,TMP_STR_SIZE,f);
    int base=0;
    char **endptr;
    long int dim=strtol(s,endptr,base);
    noyau_t *t=creer_noyau(dim);
    t->dim=dim; //utiliser fscanf
    int i=0;
    while(*endptr){
        t->coeffs[i]=strtol(s,endptr,base);
        i++;
    }
    return t;
}*/
