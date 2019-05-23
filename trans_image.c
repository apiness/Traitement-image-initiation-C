#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "image.h"
#include "noyau.h"

void triBulle(int tab[], int n) 
{
	if ( n != 1 ){
		int i;
		for(i=0; i < n-1 ; i++){
			if( tab[i] > tab[i+1]){
				int tmp = tab[i];
				tab[i] = tab[i+1];
				tab[i+1] = tmp;
			}
		}
		triBulle(tab, n-1);
	}
}

image_t *negatif(image_t *src){
    if(src!=NULL){
        image_t *image=copier_image(src);
        int i;
        for(i=0; i<(image->h)*(image->w) ; i++){
            image->buff[i]=255-image->buff[i];
        }
        return image;

    	}

	return NULL;
}

image_t *rotation(image_t *src, int angle)
	{

	if(src==NULL){
		return NULL;
	}

	if ( angle != 90 || angle != 180 || angle != 270) {
		printf ( "erreur dans l'angle");
	}

	image_t *image= creer_image();



	if ( angle == 90) {

		int i;
		image ->w= src-> h;
		image ->h= src-> w;
		image->buff = malloc(sizeof(unsigned char)*(src->w*src->h));
		for(i=0;i<((image->w)*(image->h));i++)
		{
			(image->buff)[i] = VAL(src,(i%(src->h)),src->w-1-(i/(src->h)));
		}

	}


	if (angle==180) {
		image =rotation(src,90);
		image= rotation(image, 90);
	}


	if(angle == 270) {
		image=rotation(src,90);
		image=rotation(image,180);
		}
		
	return image;

	}

image_t *modifier_lumin(image_t *src, int pourcent){
	image_t *image = copier_image(src);
	int i;
	float percent = pourcent;	
	for (i=0;i<image->w * image->h;i++){
		if ((image->buff[i] * percent / 100) <= 255){
			image->buff[i] = image->buff[i] * percent / 100;
		}else{
			image->buff[i] = 255;
		}
	}
	return image;
}
	
	

image_t *bruiter_image(image_t *src, int pourcent)
	{
	int i;
	srand(time(NULL));
	image_t *image=copier_image(src);
	for(i=0;i<src->w*src->h;i++)
		{
		if(rand()%100<pourcent)
			{
			image->buff[i] = rand()%255;
			}
		}
	return image;

	}


image_t *filtrer_median(image_t *src)
	{
	if(src!=NULL){
		int i,j;
		for(i=0;i<(src->h)*(src->w);i++){
			unsigned long w = src->w;
			int tab[21];
			int n;
			for(j=i-2*w-1;j<=i-2*w+1;j++){
				n=j-i+2*w+1;
				if(j<0){
					tab[n]=src->buff[i];
				}else{
					tab[n]=src->buff[j];
				}
			}
			for(j=i-w-2;j<=i-w+2;j++){
				n=j-i+w+5;
				if(j<0){
					tab[n]=src->buff[i];
				}else{
					tab[n]=src->buff[j];
				}
			}
			for(j=i-2;j<=i+2;j++){
				n=j-i+10;
				if(j<0){
					tab[n]=src->buff[i];
				}else{
					tab[n]=src->buff[j];
				}
			}
			for(j=i+w-2;j<=i+w+2;j++){
				n=j-i+w+15;
				if(j<0){
					tab[n]=src->buff[i];
				}else{
					tab[n]=src->buff[j];
				}
			}
			for(j=i+2*w-1;j<=i+2*w+1;j++){
				n=j-i-2*w+19;
				if(j<0){
					tab[n]=src->buff[i];
				}else{
					tab[n]=src->buff[j];
				}
			}
			triBulle(tab,21);
			src->buff[i]=tab[10];
		}
		return src;
	}
			
	return NULL;
	}

image_t *convoluer(image_t *src, noyau_t *pn)
	{
	return NULL;
	}
