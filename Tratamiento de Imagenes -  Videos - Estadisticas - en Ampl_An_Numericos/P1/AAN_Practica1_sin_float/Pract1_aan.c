#include <stdlib.h>
#include <string.h>
#include "Pract1_aan.h"

int prueba_predeterminada(){
	
	struct canales Can1, Can2, Can_out;
	char *imagenes[]={"porto7.bmp","pp1.bmp","pla1.bmp","oscura1.bmp","oscura2.bmp",
					  "roja1.bmp","roja2.bmp","clara1.bmp","oscura3.bmp","Camp_Nou.bmp"};
	
	//Unir Canales:
	int i;
	printf("\n\n\nUNION DE IMAGENES:\n\n");
	for (i=4; i<6; i++){
		printf("DATOS EXTERNOS:\n\n");
		if (ami_read_bmp(imagenes[i],&Can1.red,&Can1.green,&Can1.blue,&Can1.width,&Can1.height)){
			printf ("Error abriendo la Imagen: %s",imagenes[i]);
			return 0;
		}
		if (ami_read_bmp(imagenes[i+1],&Can2.red,&Can2.green,&Can2.blue,&Can2.width,&Can2.height)){
			printf ("Error abriendo la Imagen: %s",imagenes[i+1]);
			return 0;
		}
	
		aan_unir_canales_unsigned_char(Can1.red,Can2.red,&Can_out.red,Can1.width,Can1.height);
		aan_unir_canales_unsigned_char(Can1.green,Can2.green,&Can_out.green,Can1.width,Can1.height);
		aan_unir_canales_unsigned_char(Can1.blue,Can2.blue,&Can_out.blue,Can1.width,Can1.height);
		Can_out.width = Can1.width*2+4;
		Can_out.height = Can1.height;
	
		if (ami_write_bmp("Imagenes_Unidas.bmp",Can_out.red,Can_out.green,Can_out.blue,Can_out.width,Can_out.height)){
			printf ("Error creando las Imagenes_Unidas.bmp");
			return 0;
		}
		free(Can1.red);
		free(Can1.green);
		free(Can1.blue);
		free(Can2.red);
		free(Can2.green);
		free(Can2.blue);
		free(Can_out.red);
		free(Can_out.green);
		free(Can_out.blue);
		printf("\n\nComprueba la imagen para proseguir\n\n");
		system("Imagenes_Unidas.bmp");
	}
	
	//Normalizar:
	printf("\n\n\nNORMALIZACION DE IMAGENES:\n\n");
	for (i=0; i<5; i++){
		printf("DATOS EXTERNOS:\n\n");
		if (ami_read_bmp(imagenes[i],&Can1.red,&Can1.green,&Can1.blue,&Can1.width,&Can1.height)){
			printf ("Error abriendo la Imagen: %s",imagenes[i]);
			return 0;
		}
		aan_normalizar_imagen_unsigned_char(Can1.red,Can1.green,Can1.blue,Can1.width,Can1.height);
		free(Can1.red);
		free(Can1.green);
		free(Can1.blue);
		printf("\n\nComprueba la imagen para proseguir\n\n");
		system("Imagen_Normalizda.bmp");
	}
	
	//RGB2HSV:
	printf("\n\n\nEXTRACCION DE H(tono), S(saturacion), V(brillo) EN IMAGENES:\n\n");
	for (i=0; i<10; i++){
		printf("DATOS EXTERNOS:\n\n");
		if (ami_read_bmp(imagenes[i],&Can1.red,&Can1.green,&Can1.blue,&Can1.width,&Can1.height)){
			printf ("Error abriendo la Imagen: %s",imagenes[i]);
			return 0;
		}
		aan_extraer_canales_HSV(Can1.red,Can1.green,Can1.blue,Can1.width,Can1.height);
		free(Can1.red);
		free(Can1.green);
		free(Can1.blue);
		printf("\n\nComprueba las imagenes para proseguir\n\n");
		system("Imagen_H_tono.bmp");
		system("Imagen_S_saturacion.bmp");
		system("Imagen_V_brillo.bmp");
	}
	return 1;
}

int tus_pruebas(int op_tp){
	
	struct canales Can1, Can2, Can_out;
	char name1[200],name2[200];
	int i;
	
	switch(op_tp){
		case 1: //Unir Canales:
				printf("\n\n\nUNION DE IMAGENES:\n\n");
	
				printf("Elija imagen 1: ");
				fgets(name1, 200, stdin);
   				fflush (stdin);
    			for (i=strlen(name1); (i>=0) && (name1[i-1]=='\n'); i--){
    				name1[i-1]=name1[i];
    			}
    			printf("\n\nImagen1 --> %s", name1);
	
				printf("\n\nElija imagen 2: ");
				fgets(name2, 200, stdin);
    			fflush (stdin);
    			for (i=strlen(name2); (i>=0) && (name2[i-1]=='\n'); i--){
    				name2[i-1]=name2[i];
    			}
    			printf("\n\nImagen2 --> %s", name2);
	
				printf("\n\nDATOS EXTERNOS:\n\n");
				if (ami_read_bmp(name1,&Can1.red,&Can1.green,&Can1.blue,&Can1.width,&Can1.height)){
					printf ("Error abriendo la Imagen1: %s",name1);
					printf ("\nComprueba que el nombre o la ruta sean correctos\n");
					return 0;
				}
				if (ami_read_bmp(name2,&Can2.red,&Can2.green,&Can2.blue,&Can2.width,&Can2.height)){
					printf ("Error abriendo la Imagen2: %s",name2);
					printf ("\nComprueba que el nombre o la ruta sean correctos\n");
					return 0;
				}
				if((Can1.width != Can2.width)||(Can1.height!=Can2.height)){
					printf ("\n\nERROR: Imagenes de distinto tamano, deben ser iguales\n\n");
					return 0;
				}
	
				aan_unir_canales_unsigned_char(Can1.red,Can2.red,&Can_out.red,Can1.width,Can1.height);
				aan_unir_canales_unsigned_char(Can1.green,Can2.green,&Can_out.green,Can1.width,Can1.height);
				aan_unir_canales_unsigned_char(Can1.blue,Can2.blue,&Can_out.blue,Can1.width,Can1.height);
				Can_out.width = Can1.width*2+4;
				Can_out.height = Can1.height;
	
				if (ami_write_bmp("Imagenes_Unidas.bmp",Can_out.red,Can_out.green,Can_out.blue,Can_out.width,Can_out.height)){
					printf ("Error creando las Imagenes_Unidas.bmp");
					return 0;
				}
				free(Can1.red);
				free(Can1.green);
				free(Can1.blue);
				free(Can2.red);
				free(Can2.green);
				free(Can2.blue);
				free(Can_out.red);
				free(Can_out.green);
				free(Can_out.blue);
				printf("\n\nComprueba la imagen para proseguir\n\n");
				system("Imagenes_Unidas.bmp");
				break;
		case 2: //Normalizar:
				printf("\n\n\nNORMALIZACION DE IMAGENES:\n\n");
				
				printf("Elija imagen para NORMALIZAR: ");
				fgets(name1, 200, stdin);
   				fflush (stdin);
    			for (i=strlen(name1); (i>=0) && (name1[i-1]=='\n'); i--){
    				name1[i-1]=name1[i];
    			}
    			printf("\n\nImagen --> %s", name1);
	
				printf("\n\nDATOS EXTERNOS:\n\n");
				if (ami_read_bmp(name1,&Can1.red,&Can1.green,&Can1.blue,&Can1.width,&Can1.height)){
					printf ("Error abriendo la Imagen: %s",name1);
					printf ("\nComprueba que el nombre o la ruta sean correctos\n");
					return 0;
				}
				aan_normalizar_imagen_unsigned_char(Can1.red,Can1.green,Can1.blue,Can1.width,Can1.height);
				free(Can1.red);
				free(Can1.green);
				free(Can1.blue);
				printf("\n\nComprueba la imagen para proseguir\n\n");
				system("Imagen_Normalizda.bmp");
				break;
		case 3: //RGB2HSV:
				printf("\n\n\nEXTRACCION DE H(tono), S(saturacion), V(brillo) EN IMAGENES:\n\n");
				printf("Elija imagen para EXTRAER H,S,V: ");
				fgets(name1, 200, stdin);
   				fflush (stdin);
    			for (i=strlen(name1); (i>=0) && (name1[i-1]=='\n'); i--){
    				name1[i-1]=name1[i];
    			}
    			printf("\n\nImagen --> %s", name1);
	
				printf("\n\nDATOS EXTERNOS:\n\n");
				if (ami_read_bmp(name1,&Can1.red,&Can1.green,&Can1.blue,&Can1.width,&Can1.height)){
					printf ("Error abriendo la Imagen: %s",name1);
					printf ("\nComprueba que el nombre o la ruta sean correctos\n");
					return 0;
				}
				aan_extraer_canales_HSV(Can1.red,Can1.green,Can1.blue,Can1.width,Can1.height);
				free(Can1.red);
				free(Can1.green);
				free(Can1.blue);
				printf("\n\nComprueba las imagenes para proseguir\n\n");
				system("Imagen_H_tono.bmp");
				system("Imagen_S_saturacion.bmp");
				system("Imagen_V_brillo.bmp");
				break;
	}
	return 1;
}

int main(){
	
	printf("******************MENU*********************\n");
	printf("*                                         *\n");
	printf("* Opciones: 1. PRUEBAS PREDETERMINADAS    *\n");
	printf("*           2. TUS PRUEBAS:               *\n");
	printf("*               1. Unir Imagenes          *\n");
	printf("*               2. Normalizar Imagenes    *\n");
	printf("*               3. Extraer canales H,S,V  *\n");
	printf("*           0. SALIR                      *\n");
	printf("*******************************************\n");
	
	int op,op_tp,cont;
	op = -1;
	while (op != 0){
		printf("\nMENU Opcion: ");
		scanf("%d",&op);
		fflush (stdin);
		switch (op){
			case 0: op = 0;
					break;
			case 1: printf("\n\nEsta prueba se ejecuta una sola vez,\n");
					printf("y finaliza su ejecucion.\n");
					printf("Desea continuar: 1. SI   2.NO\n");
					scanf("%d",&cont);
					while ((cont < 1) || (cont > 2)){
						printf("\n\nElija una respuesta valida: ");
						scanf("%d",&cont);
					}
					if (cont == 1){
						prueba_predeterminada();
						op = 0;
					}
					break;
			case 2: printf("\n\nTUS PRUEBAS: (elija un metodo) --> ");
					scanf("%d",&op_tp);
					while ((op_tp < 1) || (op_tp > 3)){
						printf("\n\nelija un metodo valido --> ");
						scanf("%d",&op_tp);
					}
					fflush (stdin);
					tus_pruebas(op_tp);
					break;
			default:
					printf("\n\nElija una opcion valida\n");
					break;
		}
	}
	printf("\n\n\nFIN\n\n");
	system("PAUSE");
	return 0;
	
}