#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "image.h"
#define TMP_STR_SIZE 256


image_t *charger_image_pgm(char *nom_fichier)
	{
	
	FILE *f;
	int i=0;

	image_t *img;
	unsigned int nb_ng;
	char tmp_str[TMP_STR_SIZE];
	

		
	f = fopen(nom_fichier,"r"); 
	if (f==NULL){
		fprintf(stderr,"Problème à l'ouverture du fichier");			
		return NULL;
	}
	do { 
		fgets(tmp_str,TMP_STR_SIZE,f);
	} while (*tmp_str == '#');
	
	if(strcmp("P2/n",tmp_str)<0) {
		fprintf(stderr,"Erreur de format");
		fclose(f);	
		return NULL;
	}

	do {
		fgets(tmp_str,TMP_STR_SIZE,f);
	} while (*tmp_str == '#');

	img=creer_image();



	sscanf(tmp_str, "%ld %ld \n",&img->w , &img->h);


	do { 
		fgets(tmp_str,TMP_STR_SIZE,f);
	} while (*tmp_str == '#');


	sscanf(tmp_str, "%d",&nb_ng);
	
	if (sscanf(tmp_str, "%d",&nb_ng)!=1){
		fprintf(stderr,"Nombre de valeurs supérieur à 1");	
		detruire_image(img);
		fclose(f);
		return NULL;
	}
	
	if (nb_ng!=255){
		fprintf(stderr,"Niveau de gris dépassé");	
		detruire_image(img);
		fclose(f);
		return NULL;
	}
	
	img->buff=(unsigned char*)malloc((img->h*img->w)*(sizeof(unsigned char)));
	unsigned char *p;
	p=img->buff;

	int j;

	for(i=0;i<(img->h);i++){
		for(j=0;j<(img->w);j++){

			fscanf(f,"%hhu ",p);
			p++;
		}
	}


	img->path=strdup(nom_fichier) ;
	
	fclose(f);
	return img;    
	}

int sauver_image_pgm(char *nom_fichier, image_t *img)
	{
	
	FILE *f;

	 
	f = fopen(nom_fichier,"w");
	if (f==NULL){
		fprintf(stderr,"Problème lors de l'ouverture du fichier");			
		return 0;
	}
	
	fprintf(f,"P2\n");
	fprintf(f,"%lu %lu\n",img->w,img->h);
	fprintf(f,"255\n");
	fwrite(img-> buff , img-> w, img->h , f); 
	fclose(f);

	return 1;
	}
