#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct partida{
	char mapa[100], tip_sit[100];
};

struct arma{
	char arm_1[100], arm_2[100], herram[100], hab[100];
	
	struct arma *sig;
	struct partida *aba;
};

struct equipo{
    int num_con;
	char nomb_f[100], nomb_p[100], tip_f[100];
	struct equipo *sig;
	struct arma *aba;
};


void agregar(equipo **p){
	equipo *aux = new equipo;
	int num,cont=0;
	printf("Introduzca el nombre de la Fuerza: ");
	fflush(stdin);
	gets(aux->nomb_f);
	fflush(stdin);
	printf("Introduzca el numero de integrantes de la Fuerza: ");
	scanf("%i",&aux->num_con);
	num = aux->num_con;
	
	while(cont < num){
		
		printf("Introduzca el nombre del operador de la fuerza: ");
		fflush(stdin);
		gets(aux->nomb_p);
		fflush(stdin);
		printf("Introduzca el tipo de operador de la fuerza: ");
		fflush(stdin);
		gets(aux->tip_f);
		fflush(stdin);
		cont++;
	}
	
	  aux->sig = (*p);
      aux->aba = NULL;
     (*p) = aux;
}

void agregar2(equipo **p){
    equipo *a = (*p);
	int bul, cont_p, max_p;
	char team[100], agen[100], enter[2];	
	
	
	printf("//  armamento //");
	printf("Ingrese la fuerza para su implementacion: \n");
	fflush(stdin);
	gets(team);
	fflush(stdin);
	bul = 0;
	
	while(a){
		if(strcmp(team, a->nomb_f) == 0){
			arma *e = new arma;
			max_p = a->num_con;
		    printf("Nombre del operador: ");
	      	fflush(stdin);
	    	gets(agen);
		    fflush(stdin);
		    
		    	if(strcmp(agen, a->nomb_p) == 0){
			    	printf("Arma Primaria: ");
				    fflush(stdin);
				    gets(e->arm_1);
				    fflush(stdin);
				    printf("Arma Secundaria: ");
				    fflush(stdin);
				    gets(e->arm_2);
				    fflush(stdin);
				    printf("Habilidad Especial con: ");
				    fflush(stdin);
				    gets(e->hab);
				    fflush(stdin);
				    printf("Herramienta: ");
				    fflush(stdin);
				    gets(e->herram);
				    fflush(stdin);
					 
				    e->aba = NULL;   
		            e->sig = NULL;   
		            arma *c= a->aba;   
		            if(c){        
                     while(c->sig){
                    c = c->sig;
                    }
                     c->sig=e; 
                    }         
                   else{
                    a->aba=e;
                   }
			}
			
		}
		
		a = a->sig;
	}
	
}



int main(){
	
	equipo *p = NULL;
     int op = -1;
     
    while(op != 0){
    system("cls");
    printf("ingrese una opcion\n");
        printf("(1).	Agregar una fuerza. \n");
		printf("(2).	Agregar armamento a la fuerza. \n");
		printf("(3).	imprimir en construccion \n");
		printf("0.	Fin del programa. \n");
     scanf("%i",&op);
	    switch(op){
		case 1: agregar(&p); 
		        break;
		        
		case 2: agregar2(&p); 
		        break;
	   }	
    } 
	
	
	system("PAUSE");
	return 0;
}
