#ifndef PGM_IMAGE
#define PGM_IMAGE
#include "image.h"

image_t *charger_image_pgm(char *nom_fichier);

int sauver_image_pgm(char *nom_fichier, image_t *img);
#endif
