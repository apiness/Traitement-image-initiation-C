#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "image.h"

image_t *creer_image()
	{
	image_t *image = (image_t*)malloc (sizeof(image_t));
	if(image ==NULL) {
		printf("Problèmes lors de l'allocation\n") ;
			
	return NULL;
	}
	image -> w=0;
	image -> h=0;
	image -> path = NULL;
	image -> buff = NULL;
	
	return image;
}

image_t *copier_image(image_t *src)
	{
	if (src != NULL) {
		image_t *newImage = creer_image();
		if(newImage==NULL) {
			printf ("Problèmes lors de l'allocation\n");
			return NULL ;
		}
		newImage -> w = src -> w;
		newImage -> h = src -> h;
		newImage -> path = strdup ( src -> path) ;
		if (newImage -> path == NULL) {
			printf("Problèmes lors de l'allocation\n");
			free (newImage);
			return NULL;
		}
		newImage -> buff = malloc (sizeof (unsigned char) * src -> h* src -> w);
		if (newImage -> buff == NULL) {
			printf ("Problèmes lors de l'allocation\n");
			free (newImage -> path) ;
			free(newImage);
			return NULL;
		}
		memcpy(newImage->buff , src -> buff , sizeof(unsigned char) * src -> h* src -> w);
		return newImage;
	}
	return NULL;
}
		


void detruire_image(image_t *p)
	{
		if(p==NULL) {
			return;
		}
		
		free( p-> path);
		free (p -> buff ) ;
		free (p);
		
	}
