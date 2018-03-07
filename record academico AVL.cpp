#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

enum {IZQUIERDO, DERECHO};

typedef struct _nodo2 {
	int dato1;
	int FE1;
	struct _nodo2 *derecho;
	struct _nodo2 *izquierdo;
	struct _nodo2 *padre;
}tipoNodo2;

typedef tipoNodo2 *pNodo2;
typedef tipoNodo2 *Arbol2;



void Insertar(Arbol2 *a, int dat);

int Buscar(Arbol2 a, int dat);

int Vacio(Arbol2 r);

int EsHoja(pNodo2 r);

int NumeroNodos(Arbol2 a, int* c);

int AlturaArbol(Arbol2 a, int* altura);

int Altura(Arbol2 a, int dat);

void InOrden(Arbol2, void (*func)(int*));

void Equilibrar(Arbol2 *raiz, pNodo2 nodo, int, int);
void RSI(Arbol2 *raiz, pNodo2 nodo);
void RSD(Arbol2 *raiz, pNodo2 nodo);
void RDI(Arbol2 *raiz, pNodo2 nodo);
void RDD(Arbol2 *raiz, pNodo2 nodo);

void auxContador(Arbol2 a, int*);
void auxAltura(Arbol2 a, int, int*);

void Mostrar(int *d);

//----------------SEGUNDO ARBOL!! ----------------//

typedef struct _nodo {
   int dato;
   int FE;
   struct _nodo *derecho;
   struct _nodo *izquierdo;
   struct _nodo *padre;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;


void Insertar(Arbol *a, int dat);

int Buscar(Arbol a, int dat);

int Vacio(Arbol r);

int EsHoja(pNodo r);

int NumeroNodos(Arbol a, int* c);

int AlturaArbol(Arbol a, int* altura);

int Altura(Arbol a, int dat);

void InOrden(Arbol, void (*func)(int*));

void Equilibrar(Arbol *raiz, pNodo nodo, int, int);
void RSI(Arbol *raiz, pNodo nodo);
void RSD(Arbol *raiz, pNodo nodo);
void RDI(Arbol *raiz, pNodo nodo);
void RDD(Arbol *raiz, pNodo nodo);

void auxContador(Arbol a, int*);
void auxAltura(Arbol a, int, int*);

void MOstrar(int *d);

//------    arriba es a parte                   ------//

//   estructuras con su sig y aba y  arboles....         //
struct record{
	int valor;//periodo
	int codmateria,nota;
	char observaciones[10];
	struct record *izq,*der;
};


struct mateinscritas{
       int codemate,codesec;
       struct mateinscritas *sig;
};
       
struct planilla{
       int codemate,codesecsoli,cedu,numero;
       struct planilla *sig;
       struct mateinscritas *aba;
};

struct alumnos{
     int cedula,fechanaci,mesdenaci,anonaci,extracreditos,expe,indiaca;
     char nombre[90],apellido[90];
     float promedio;
	 struct alumnos *sig;
     struct planilla *aba;	
     struct record *arbol;
};

struct horario{	
	char dia[20];
	int horaini,horafin;
};

struct secciones{
 int codigosec,numsecc,ceduprofe,cupomax;
 char nombreprofe[100];
 char turno[100];
 struct horario *aba;
 struct secciones *sig;	
};

struct matearbol{
       int valor; //codigo de la materia
       int numcreditos;
       char materia[20];
      struct matearbol *izq,*der;
};

struct materia{
	char nommateria[100]; 
	int codigo,credimateria;
	struct materia *sig;
	struct secciones *aba;
};

struct semestre{
	int setre,cupomax;
	struct semestre *sig;
	struct materia *aba;
	struct matearbol *arbol;
};
//////////////////////////////////////////////



/////////////////////////////////////////////

// insertar cada estructura....

void agregarsemestre (semestre **p){
     semestre *aux = new semestre;
     
     printf("ingrese el numero del semestre\n");
     scanf("%i",&aux->setre);
     printf("ingrese el cupo maximo de creditos\n");
     scanf("%i",&aux->cupomax);
     
      aux->sig = (*p);
      aux->aba = NULL;
      aux->arbol=NULL; //inicializacion de arbol de materia
     (*p) = aux;
}

void agregarmaterias(semestre **p){
	semestre *a = (*p);
	int n=0,cont=0;
	
	printf("Ingrese el numero de semestre que desee agregar las materias\n");
	scanf("%i",&n);
	
	while(a){
		if (a->setre == n){
			cont = 1;
			materia *e = new materia;
			printf("ingrese el nombre de la materia del semestre %i\n",a->setre);
			fflush(stdin);
			gets(e->nommateria);
			fflush(stdin);
			printf("ingrese el codigo de la materia\n");
			scanf("%i",&e->codigo);
		    printf("ingrese el numero de creditos de la materia\n");
		    scanf("%i",&e->credimateria);
		    e->aba = NULL;   //inicializacion de seccion
		    e->sig = NULL;   //inicializacion de materia siguiente
		    materia *c= a->aba;    //puntero a materia de semestre seleccionado
		      if(c){         //si ya existe una materia
                while(c->sig){
                 c = c->sig;
                }
               c->sig=e;  //pega el ultimo nodo
            }         
            else{    //si no existe materia de semestre seleccionado
             a->aba=e;
            }
        }	
		a = a->sig;
	}
}

void agregarsecciones(semestre **p){
     semestre *a = (*p);
     int n=0,cont=0,mat;
     char nombre[90];
     
     printf("ingrese el numero del semestre  \n");
     scanf("%i",&n);
     
     while(a){
              
             if (a->setre == n){
                if (a->aba){
                    materia *k = a->aba;
                    printf("introduzca el codigo de la materia \n");
                    scanf("%i",&mat);
                    while (k){
                        if(k->codigo==mat){
                                                                     
                            secciones *l = new secciones;   //nueva seccion
                                     
                            printf("introduzca el codigo de la seccion\n");
                            scanf("%i",&l->codigosec);
                            printf("introduzca el numero de la seccion\n");
                            scanf("%i",&l->numsecc);
                            printf("introduzca la cedula del profesor\n");
                            scanf("%i",&l->ceduprofe);
                            printf("introduzca el nombre del profesor\n");
                            fflush(stdin);
                            gets(l->nombreprofe);
                            fflush(stdin);
                            printf("introduzca el cupo maximo\n");
                            scanf("%i",&l->cupomax);
                            printf("introduzca el turno\n");
                            fflush(stdin);
                            gets(l->turno);
                            fflush(stdin);
                                     
                            l->aba=NULL;  //inicializacion de alumno
                            l->sig=NULL;  //inicializacion de seccion siguiente
                            secciones *q = k->aba;
                                     
                           if (q){
                                while(q->sig){
                                    q = q->sig;
                                }
                                q->sig=l;
                            }else{
                               k->aba = l;    
                                }    
                        }
                        k=k->sig;
                    } 
                }   
            }
        a = a->sig;    
    }
}

void agregaralumnos(alumnos **q){
	
  alumnos *aux = new alumnos;
  
     printf("\n Ingrese el numero de cedula\n");
     scanf("%i",&aux->cedula);
     printf("\n Ingrese el nombre del alumno\n");
     fflush(stdin);
     gets(aux->nombre);
     fflush(stdin);
     printf("\n Ingrese el apellido del alumno\n");
     fflush(stdin);
     gets(aux->apellido);
     fflush(stdin);
     printf("\n Ingrese año de nacimiento\n");
     scanf("%i",&aux->anonaci);
     printf("\n Ingrese mes de nacimiento\n");
     scanf("%i",&aux->mesdenaci);
     printf("\n Ingrese dia de nacimiento\n");
     scanf("%i",&aux->fechanaci);
     printf("\n Ingrese extra-creditos\n");
     scanf("%i",&aux->extracreditos);
     printf("\n Ingrese indice academico\n");
     scanf("%i",&aux->indiaca);
     printf("\n Ingrese el numero de expediente \n");
     scanf("%i",&aux->expe);
      aux->sig = (*q);
      aux->aba = NULL;
	  aux->arbol = NULL;  //Inicializo record
     (*q) = aux;
}

void tenerplanilla(semestre *p,alumnos **q){
    semestre *a = (p);
    int n=0,cont=0,num=0,mat,cedu;
    char nombre[90];
    bool cond=false;
     
    printf("Ingrese el numero del Semestre de la materia a ingresar:\n");
    scanf("%i",&n);
     
       while(a){
              
            if (a->setre == n){
             	
                if (a->aba){
                    materia *k = a->aba;
                    printf("Introduzca la materia a agregar a la planilla\n");
                    scanf("%i",&mat);
                    while (k){
                        if(k->codigo==mat){
                           if(k->aba){
                        	
                        	  secciones *z = k->aba;
                        	  
                        	  
                        	  printf("Ingrese el NUMERO de la seccion que desea inscribir\n");
                              scanf("%i",&num);
                              
                        	while(z){
                            	  if(z->numsecc == num){
                            	  	printf("Ingrese el numero de cedula del alumno\n");
                            	  	scanf("%i",&cedu);
                            	  	alumnos *w=(*q);
                            	  	while(w){
                                     if (w->cedula == cedu){
                                          planilla *t = new planilla;
                                           printf("Ingrese numero de la planilla\n");
                                           scanf("%i",&t->numero);
                                          t->codesecsoli = num;
                                          t->codemate = mat; 
                                          t->sig = NULL;
                                          t->aba=NULL; 
                                          planilla *x=w->aba;
                                          printf("\n Planilla creada satisfacotriamente\n");
                                          system("pause");
                                          cond=true;
                                          if (x){
                                while(x->sig){
                                    x = x->sig;
                                }
                                x->sig=t;
                            }else{
                               w->aba = t;    
                                }    
                                      }
                                        w = w->sig;        
                                     }
                                     
			                    }
                               z = z->sig;
                               }
			             }	          
                        }
                     k=k->sig;
                    } 
                }   
            }  
          a = a->sig;     
        }
        if(cond==false){
             printf("No se pudo crear planilla, por favor revise alguna de las siguiente informaciones: alumno,semestre,materia o seccion)");}
}

void agregarmateriasinscritas(alumnos **q){
alumnos *aux=(*q); 
int ced,num;
    printf("\n Ingrese numero de cedula del alumno:");
    scanf("%i",&ced);
    while (aux){
             if(aux->cedula==ced){
                      planilla *t=aux->aba;
                      printf("\n Ingrese numero de la planilla a inscribir:");
                      scanf("%i",&num);
                      while(t){
                          if(t->numero==num){     
                           mateinscritas *l=new mateinscritas;
                           l->codemate=t->codemate;
                           l->codesec=t->codesecsoli;   //abajo de esto va la validacion de ver si se puede meter la materia 
                           t->aba=l; 
                           printf("\n Materia Inscrita Satisfactoriamente creada\n");
                           }                            
                      t=t->sig;
                      }                             
             }        
          aux=aux->sig;
    }
}

int conflictohora(semestre**p,char dia[],int horai, int horaf){
	semestre *a = (*p);

    
       while(a){
              
                if (a->aba){
                    materia *k = a->aba;
                    while (k){
                    
                           if(k->aba){
                        	
                        	  secciones *z = k->aba;
                        	  
                        	while(z){
                            		if(z->aba){
                            			horario*h=z->aba;
                            			if(((strcmp(dia,h->dia)==0)&&(h->horaini==horai)&&(h->horafin==horaf))||(((strcmp(dia,h->dia)==0)&&(horai>h->horaini)&&(h->horafin>horai))))
			                             
                                          return 1;
                            			else 
                            			  return 0;
									}
                        	    
                        	    	  		
									  
							z=z->sig;
							   }
						   }	          
                        
                     k=k->sig;
                    } 
                }   
            
           a = a->sig;    
        }
}
void agregarhorario(semestre**p){
	semestre *a = (*p);
    int n=0, cont=0, num=0, cedula=0, horai, horaf, mat, boo=0, a1=0, a2=0;
    char dia[90];
     
    printf("ingrese el numero del semestre \n");
    scanf("%i",&n);
     
       while(a){
              
            if (a->setre == n){
             	
                if (a->aba){
                    materia *k = a->aba;
                    printf("introduzca codigo de la materia \n");
                    scanf("%i",&mat);
                    while (k){
                        if(k->codigo==mat){
                           if(k->aba){
                        	
                        	  secciones *z = k->aba;
                        	  printf("ingrese el numero de la seccion\n");
                              scanf("%i",&num);
                        	while(z){
                        		
                            	if(z->numsecc == num){
																
                        	    				horario *k=new horario;
                        	    				while(boo==0){
                        	    				fflush(stdin);
												printf("Ingrese dia\n");
												gets(dia);
												fflush(stdin);
    	    	                                strcpy(k->dia,dia);
												printf("Ingrese hora de inicio\n");
												scanf("%i",&k->horaini);
												printf("Ingrese hora de fin\n");
												scanf("%i",&k->horafin);	
												  if((conflictohora(p,k->dia,k->horaini,k->horafin)) == 1){
                                                     printf("No disponible\n");
												   }
											       else 
											        break;
                                               }
												z->aba=k;
												
										}
									z=z->sig;
							   }
						   }	          
                        }
                     k=k->sig;
                    } 
                }   
            }
           a = a->sig;    
        }
}

	

//  modificaciones

void modificarsemes(semestre *p){
     int n,cont;
     cont=0;
     semestre *aux = p;
     printf("ingrese el numero del semestre que desea modificar\n");
     scanf("%i",&n);
     while(aux){
         if (aux->setre == n){
            printf("cuantos creditos desea para el semestre %i\n",aux->setre);
            scanf("%i",&aux->cupomax);
            cont=1;
            }              
      aux = aux->sig;          
     }
     if (cont == 0){
              printf("el semestre no se encontro registrado\n");
        }
}

void modificarmat(semestre *p){
        int n,cont,mat;
     cont=0;
     semestre *aux = p;
     printf("Ingrese el numero del semestre de la MATERIA que desea modificar\n");
     scanf("%i",&n);
     while(aux){
         if (aux->setre == n){
         	
           materia *m = aux->aba;
          
            printf("Indique codigo de la materia que se quiera cambiar\n");
            scanf("%i",&mat);
            
            while(m){
            	
             if(m->aba){
			     
                  if (m->codigo == mat){
                  	
                  	    printf("indique materia que se quiera cambiar\n");
                        fflush(stdin);
                        gets(m->nommateria);
                        fflush(stdin);
                        printf("indique nuevos creditos para la materia\n");
                        scanf("%i",&m->credimateria);
                        printf("indique nuevo codigo para la materia\n");
                        scanf("%i",&m->codigo);
                        cont++;
                    }
                }              
              m = m->sig;         
            }
        }
       aux = aux->sig;
    }  
       if (cont == 0){
              printf("la materia no se encontro registrado\n");
       }
 
}

void modificarsecc(semestre *p){
	int n,cont,n1,mat;
        char mate[50];
     cont=0;
     semestre *aux = p;
     printf("ingrese el numero del semestre de la seccion modificar\n");
     scanf("%i",&n);
    while(aux){
    	
       if(aux->setre == n){
       	
     	materia *t = aux->aba;
     	
     	  printf("indique codigo de materia para acceder a secciones\n");
			scanf("%i",&mat);           
			 while(t){
          	
               if(t->aba){
          		
          	        if(t->codigo==mat){
          		      secciones *a = t->aba;
          		      printf("introduzca el NUMERO de seccion para modificar\n");
          		      scanf("%i",&n1);
          		      
          		      while(a){
          		      	
          		      	    	if(a->numsecc == n1){
          		      	         printf("introduzca el codigo de la seccion\n");
                                 scanf("%i",&a->codigosec);	
          		      		     printf("introduzca la cedula del profesor\n");
                                 scanf("%i",&a->ceduprofe);
                                 printf("introduzca el nombre del profesor\n");
                                 fflush(stdin);
                                 gets(a->nombreprofe);
                                 fflush(stdin);
                                 printf("introduzca el cupo maximo\n");
                                 scanf("%i",&a->cupomax);
                                 printf("introduzca el turno\n");
                                 fflush(stdin);
                                 gets(a->turno);
                                 fflush(stdin);
                                }
					        
          		      	a = a->sig;
						}
                  }
			    }
			   t = t->sig;
		    }
	    }else{
	     printf("valor incorrecto\n");	
		}
	 aux = aux->sig;	
    }
	
}

void modificaralum(alumnos *q){
	int n,cont,n1,cedu,mat;
	alumnos *aux=q;
    printf("\n Ingrese numero de cedula del alumno a modificar: ");
    scanf("%i",&cedu);
    system("cls");
       printf("\n   ¿Que desea modificar?");
       printf("\n1) Cedula");
       printf("\n2) Nombre");
       printf("\n3) Apellido");
       printf("\n4) Extracreditos");
       printf("\n5) Fecha de nacimiento");
       printf("\n6) Numero de Expediente");
       scanf("%i",&n);
       switch(n){
       	case 1: 
       	  printf("\n Introduzca nueva cedula:");
       	  scanf("%i",&aux->cedula);
       	  break;
       	  case 2:
       	  	printf("\n Introduzca nuevo nombre:");
       	   fflush(stdin);
           gets(aux->nombre);
            fflush(stdin);
       	  break;
       	  case 3:
       	  	printf("\n Introduzca nuevo apellido:");
       	  fflush(stdin);
           gets(aux->apellido);
            fflush(stdin);
       	  break;
       	  case 4:
       	  	printf("\n Introduzca Extracreditos aprobados:");
       	  scanf("%i",&aux->extracreditos);
       	  break;
       	  case 5:
       	  	printf("\n Introduzca año de nacimiento:");
       	  scanf("%i",&aux->anonaci);
       	  printf("\n Introduzca mes ");
       	  scanf("%i",&aux->mesdenaci);
       	  printf("\n Dia:");
       	  scanf("%i",&aux->fechanaci);
       	  break;
       	  case 6:
       	  	printf("\n Ingrese numero para el expediente");
       	  	scanf("%i",&aux->expe);
       	  	break;
	   }
   
}

// hacer codigo de eliminar y crear
//no se puede hacer modificar pq hay q validar q se puedan meter las materias

void eliminarsemestre(semestre**p){
	semestre*aux=(*p);
	int num=0;
	
	printf("Ingrese el numero de semestre a eliminar\n");
	scanf("%i",&num);
	semestre *borra;

	while(aux){
			
			if (aux->setre == num){

				(*p)=aux->sig;
				
                borra = aux;
                
				delete borra;
				
				break;
			}

			else{

				while ((aux->sig!=NULL)&&(aux->sig->setre!=num))

					aux=aux->sig;

				if (aux->sig != NULL){

					borra = aux->sig;

					aux->sig = borra->sig;

					delete borra;
					
					break;
				}
			}
	
	  aux=aux->sig;
	}
}

void eliminarmateria(semestre**p){
	semestre*aux=(*p);
	int num,codi;
	printf("Ingrese el numero de semestre ");
	scanf("%i",&num);
	materia *borra;
	while(aux){
				
			if (aux->setre==num){
				if(aux->aba){
                             
					materia*m=aux->aba;
					printf("Ingrese codigo de materia");
					scanf("%i",&codi);
					
					while(m){
							if (m->codigo==codi){

								aux->aba=m->sig;

								delete m;

							}

							else{

								while ((m->sig!=NULL)&&(m->sig->codigo!=codi))

									m=m->sig;

								if (m->sig!=NULL){

									borra=m->sig;
				
									m->sig=borra->sig;
				
									delete borra;

								}

							}
					m=m->sig;
					}
					
				}	
			}

		
	aux=aux->sig;
	}
}

void eliminarsecc(semestre**p){
	semestre*aux=(*p);
	int num,codi,numse;
	printf("Ingrese el numero de semestre \n");
	scanf("%i",&num);
	secciones *borra;
	while(aux){
				
			if (aux->setre==num){
				if(aux->aba){
                             
					materia*m=aux->aba;
					
					printf("Ingrese codigo de materia");
					scanf("%i",&codi);
					
					while(m){
                             
                       if (m->codigo == codi){
                                           
		 			       if (m->aba){
                            	secciones *g = m->aba;
                            	
                            	printf("introduzca el numero de la seccion:\n");
                            	scanf("%i",&numse);
                            	
                            	while(g){
                                         
                                        if (g->numsecc == numse){
                                            m->aba=g->sig;
								            delete g;
                                                    
                                        }else{
                                          while ((g->sig!=NULL)&&(g->sig->numsecc != numse))
                                          
									       g=g->sig;
                                            
                                            if (g->sig!=NULL){

								         	 borra = g->sig;
				
                                             g->sig = borra->sig;
				
									       delete borra;

								            }    
                                        }
                                  g = g->sig;      
                                }
                           }
                       }
					m=m->sig;
				 }
					
				}	
			}

		
	aux=aux->sig;
	}
}

void eliminaralumn(alumnos **q){
	alumnos *aux=(*q);
	int num;
	printf("\n Ingrese numero de cedula:");
	 scanf("%i",&num); 
       while(aux){
	        if(aux->cedula==num){
	        	if(aux->aba){
               planilla *t=aux->aba;
                 while(t){
                 	planilla *temp=t;
                 	printf("ENTRO");
                 	system("pause");
                 	if(t->aba){
                 		delete (t->aba);
					 }
                  t=t->sig;
                  delete temp;
				 }
			}
			num=9;		     
		     }
		     if(num==9){
		     	alumnos *temp=aux;
		     	aux=aux->sig;
		     	delete temp;
		     	printf("\n Eliminacion Exitosa");
		     	system("pause");
		     	return;
			 }
       aux=aux->sig;
	   }
    system("PAUSE");
}

void eliminarpla(alumnos **q){
   alumnos *aux=(*q);
   int num;
   
     printf("\n Ingrese numero de cedula:");
	 scanf("%i",&num); 
       while(aux){
	        if(aux->cedula==num){
	        	planilla *t=aux->aba;
	        	printf("\n Ingrese numero de planilla a eliminar:");
	        	scanf("%i",&num);
	        	  while(t){
	        	  	if((t->numero==num)&&(t->aba==NULL)){
	        	  		((*q)->aba)=t->sig;
	        	  		delete t;
	        	  		printf("\n Borrado de planilla EXITOSO\n");
	        	  		system("pause");
	        	  		return;
					  }
					t=t->sig;
				  }
			}	       
	   aux=aux->sig;
	}
	printf("\n Error en eliminacion de planilla revise si puede ser por estos errores:\n");
	printf("\n Numero de planilla erroneo");
	printf("\n Numero de cedula erroneo");
	printf("\n La planilla posee una materia inscrita\n");
}
// fin codigo de eliminar

//imprimir cada llamado

void imprimirsemes(semestre *p){
     int n,cont;
     cont=0;
     semestre *aux = p;
     printf("ingrese el numero del semestre que desea imprimir\n");
     scanf("%i",&n);
     while(aux){
         if (aux->setre == n){
            printf("numero del semestre %i\n",aux->setre);
            printf("cupo maximo del semestre %i\n",aux->cupomax);
            cont=1;
            }              
      aux = aux->sig;          
     }
     if (cont == 0){
              printf("el semestre no se encontro registrado\n");
        }
system("PAUSE");
}

void imprimirmaterias(semestre *p){
	int n,mat;
	char nom[100];
	semestre *aux = p;
	
	printf("ingrese el numero del semestre que desea imprimir la materia\n");
	scanf("%i",&n);
	while (aux){
		if (aux->setre == n){
			
		  if (aux->aba){
		  	
		     materia *c = aux->aba;
		  	
              printf("Escriba el codigo de la materia que desea imprimir\n");
            	scanf("%i",&mat);
		      
	           while(c){
			   	
	             if(c->codigo==mat){
	    	           printf("materia:%s \n",c->nommateria);
	    	            printf("codigo de la materi:%i \n",c->codigo);
	    	            printf("creditos de la materia:%i \n",c->credimateria); 
		            }	
					system("PAUSE");
		         c=c->sig;
				 	
                }
            }
	    }
	 aux = aux->sig;
    }
}

void imprimirsecciones(semestre *p){
	int n=0,num=0,co;

	semestre *aux = p;
	
	printf("ingrese el numero del semestre que desea imprimir la materia\n");
	scanf("%i",&n);
	
	while (aux){
		if (aux->setre == n){
		
		  if (aux->aba){
		  	
		     materia *c = aux->aba;
		  	
              printf("Escriba el codigo de la materia que desea imprimir\n");
		    scanf("%i",&co);
	           while(c){
	             if(c->codigo == co){
	    	       if (c->aba){
	    	       secciones *d = c->aba;
	    	       
	    	       printf("introduzca el numero de la seccion que desea buscar\n");
	    	       scanf("%i",&num);

				   	if(d->numsecc == num){
				   		
				   	 printf("numero de la seccion: %i\n",d->numsecc);
				   	 printf("codigo de la seccion: %i\n",d->codigosec);
				   	 printf("cedula del profesor: %i\n",d->ceduprofe);
				   	 printf("nombre del profesor: %s\n",d->nombreprofe);
				   	 printf("cupo maximo: %i\n",d->cupomax);
				   	 printf("turno de la seccion: %s\n",d->turno);
				   	   }
				   } 				
		        }	
		         c=c->sig;	
                }
                system("PAUSE");
            }
	    }
	 aux = aux->sig;
    }
}

void imprimir_horario(semestre *p,alumnos *q){
	semestre *a = p;
	alumnos *d = q;
    int n=0, cont=0, num=0, cedula=0, horai, horaf, mat, boo=0, a1=0, a2=0, ced;
    char dia[90];
     
    printf("ingrese el numero del semestre \n");
    scanf("%i",&n);
     
       while(a){
              
            if (a->setre == n){
             	
                if (a->aba){
                    materia *k = a->aba;
                    printf("introduzca codigo de la materia \n");
                    scanf("%i",&mat);
                    while (k){
                        if(k->codigo==mat){
                           if(k->aba){
                        	
                        	  secciones *z = k->aba;
                        	  printf("ingrese el numero de la seccion\n");
                              scanf("%i",&num);
                        	while(z){
                            	if(z->numsecc == num){
                                 if (z->aba){
                                           horario *h = z->aba;
                                            printf("\n Ingrese numero de cedula: ");
	                                         scanf("%i",&ced);
											 while(d) {
											  if (d->cedula == ced){
											   printf("%s \n",d->nombre);
											   printf("%s \n",d->apellido);
                                               printf("%s \n",k->nommateria);
                                               printf("%i \n",z->numsecc);
                                               printf("%s \n",h->dia);
                                               printf("%i \n",h->horaini);
                                               printf("%i \n",h->horafin);
                                               
                                            }
											  d = d->sig;     
                                           }
                                    }else printf("no se encontro el horario registrado\n");
												
                                 }		
									z=z->sig;
						   }
						   }	          
                        }
                     k=k->sig;
                    } 
                }   
            }
           a = a->sig;    
        }
}

void imprimiralumnos(alumnos *q){
	alumnos *aux=q;
	int ced;
	printf("\n Ingrese numero de cedula: ");
	scanf("%i",&ced);
	while (aux){
          if(aux->cedula==ced){
               printf("\n Nombre del estudiante: %s",aux->nombre);
               printf("\n Apellido del estudiante: %s",aux->apellido);
               printf("\n Fecha de nacimiento: %i/%i/%i ",aux->fechanaci,aux->mesdenaci,aux->anonaci);
               printf("\n Extracredito APROBADOS: %i",aux->extracreditos);                
               printf("\n Numero de Expediente: %i",aux->expe);
               printf("\n Indice: %i",aux->indiaca);
               printf("\n");  
			               
        }               
      aux=aux->sig;
    }
  system("PAUSE"); 
}

void imprimiralumnostodos(alumnos *q){
	
     alumnos *aux=q;
     
     while(aux){
                printf("\n Nombre del estudiante: %s",aux->nombre);
               printf("\n Apellido del estudiante: %s",aux->apellido);
               printf("\n Fecha de nacimiento: %i/%i/%i ",aux->fechanaci,aux->mesdenaci,aux->anonaci);
               printf("\n Extracredito APROBADOS: %i",aux->extracreditos);                
               printf("\n Numero de Expediente: %i",aux->expe);
               printf("\n Indice: %i",aux->indiaca);  
               printf("\n"); 
               aux=aux->sig;
    }
}      
               

void imprimirsemes_mas_materias(semestre *p){   //CONSULTA #1
	semestre *aux = p;
	int n;
	printf("\n Ingrese el numero del semestre que desea imprimir las materias \n");
	scanf("%i",&n);
	while (aux){
		if (aux->setre == n){
			printf("\n Semestre: %i ",aux->setre);
			printf("\n Maximo Numero de Creditos: %i ",aux->cupomax);
			printf("\n");
			
		  if (aux->aba){
		  	
		     materia *c = aux->aba;
		     while(c){
		     	printf("\n Materia: %s ",c->nommateria);
	    	    printf("\n Codigo de la materia: %i ",c->codigo);
	    	    printf("\n Creditos de la materia: %i \n",c->credimateria);
	    	    c=c->sig;
	    	    
			 }
			 system("pause");
           }
        }
    aux= aux->sig;
    }
}
                                             //CONSULTA #2
void imprimirmateria_y_semestre(semestre *p){ //BUSCA una materia e imprime su informacion y a que semestre pertenece
	int n;
	char nom[100];
	semestre *aux = p;
	while (aux){
			
		  if (aux->aba){
		  	
		     materia *c = aux->aba;
		  	
              printf("Escriba el nombre de la materia que desea imprimir:\n");
		      fflush(stdin);
		      gets(nom);
		      fflush(stdin);
		      
	           while(c){
			   	
	             if(strcmp(c->nommateria,nom) == 0){
	             	printf("\n Semestre: %i",aux->setre);
	             	printf("\n Maximo cupo de creditos del Semestre:%i",aux->cupomax);
	             	printf("\n");
	    	        printf("\n Materia: %s ",c->nommateria);
	    	        printf("\n Codigo de la materia: %i ",c->codigo);
	    	        printf("\n Creditos de la materia:%i \n",c->credimateria); 
		            }	
					system("PAUSE");
		         c=c->sig;
				 	
                }
            }
	 aux = aux->sig;
    }
	
}

void imprimirsecciones_una_materia(semestre *p){ //CONSULTA #3
	int n=0,num=0;
	char nom[100];
	semestre *aux = p;

	while (aux){
		
		  if (aux->aba){
		  	
		     materia *c = aux->aba;
		  	
              printf("Escriba el nombre de la materia que desea imprimir\n");
		     fflush(stdin);
		     gets(nom);
		     fflush(stdin);
	           while(c){
	             if(strcmp(c->nommateria,nom) == 0){
	    	       if (c->aba){
	    	       secciones *d = c->aba;
	    	     
				   	while(d){
				   	 printf("Numero de la seccion: %i\n",d->numsecc);
				   	 printf("Codigo de la seccion: %i\n",d->codigosec);
				   	 printf("Cedula del profesor: %i\n",d->ceduprofe);
				   	 printf("Nombre del profesor: %s\n",d->nombreprofe);
				   	 printf("Cupo maximo: %i\n",d->cupomax);
				   	 printf("Turno de la seccion: %s\n",d->turno);
				   	 d=d->sig;
				   	 }
				   } 				
		        }	
		         c=c->sig;	
                }
                system("PAUSE");
            }
	 aux = aux->sig;
    }
}
void imprimirplanilla(alumnos *q){ //CONSULTA #4
     int n,cont;
     cont=0;
     alumnos *aux = q;
     printf("ingrese la cedula del estudiante\n");
     scanf("%i",&n);
     while(aux){
         if (aux->cedula == n){
              planilla *t= aux->aba;              
              while (t){                           
                printf("\n Codigo de la seccion que solicita %i",t->codesecsoli);
                printf("\n Codigo de la materia %i\n",t->codemate);
                cont=1;
                t=t->sig;
              }           
         }              
      aux = aux->sig;          
     }
     if (cont == 0){
              printf("La planilla no se encontro registrada\n");
        }
system("PAUSE");
}

void imprimirplanilla_por_cedula(alumnos *q){  //CONSULTA # 5
int i,j,aux2,e=0,k=0,cont=0,contal,contador=0;
system("cls");
 alumnos *aux=q; 
 while(aux){
 	if(aux->sig!=NULL){cont++;}
	aux=aux->sig;
}                    //cuenta cuantos alumnos hay
   aux=q;
int array[cont]; //array con numero de alumnos
    while(aux){ //mete los numeros de cedula en un arra
    	array[e]=aux->cedula;
    	e++;
    	aux=aux->sig;
    }        
k=0;	             
for(i=0;i<=cont-1;i++){
	contador=0;
	for(j=0;j<=cont-1;j++){
		if(array[j]>array[j+1]){
			aux2=array[j];
			array[j]=array[j+1];
			array[j+1]=aux2;
			contador++;
		}
	}
		if(contador==0)break;
} 
aux=q;
k=0;
            while((aux)&&(k<=cont)){     //impresion de planillas por orden de cedula
	            if(aux->cedula==array[k]){
	                printf("\n Cedula: %i\n",aux->cedula);
		            planilla *t= aux->aba;  					            
                    while (t){                           
                      printf("\n Codigo de la seccion que solicita %i",t->codesecsoli);
                      printf("\n Codigo de la materia %i",t->codemate);
                      t=t->sig;
                    }
                    aux=q;
				   k++;      		
	            }else
	         aux=aux->sig;   
            }
system("pause");
}


void imprimirmateinscritas(alumnos *q){   //CONSULTA #7
int n,cont;
     cont=0;
     alumnos *aux = q;
     printf("Ingrese la cedula del estudiante\n");
     scanf("%i",&n);
     while(aux){
         if (aux->cedula == n){
              planilla *t= aux->aba;              
              while (t){	
              if(t->aba){
			   mateinscritas *m= t->aba;	        
                   printf("\n Codigo de la seccion  %i",m->codesec);
                   printf("\n Codigo de la materia %i\n",m->codemate);
                   cont=1;
               }
                t=t->sig;
              }           
         }              
      aux = aux->sig;          
     }
     if (cont == 0){
              printf("No se encontro materia registrada\n");
     }
system("PAUSE");

}

void imprimiralumnosinscritos_seccion(alumnos *q){
	int n;
	alumnos *aux=q;
	printf("\n Ingrese codigo de la seccion para ver alumnos inscritos:");
	scanf("%i",&n);
	while(aux){
	     planilla *t=aux->aba;
	       while(t){
	       	mateinscritas *m=t->aba;
	       	while(m){
	       		if(m->codesec==n){
	       			printf("\n %s %s",aux->apellido,aux->nombre);
				   }
				m=NULL;   
			   }
	       	
	       t=t->sig;	
		   }
	aux=aux->sig;	
	}
	printf("\nNULL");
}
// PARTE DE CREAR ARCHIVO 

void creararchivosem(semestre**p){

semestre*t=(*p);

FILE* miarchivo;

miarchivo= fopen("semestre.txt","w");

while(t){
	
	fprintf(miarchivo,"%i\n",t->setre);
	
	fprintf(miarchivo,"%i\n",t->cupomax);
	
	
t=t->sig;

}

fclose(miarchivo);

}

void creararchivomat(semestre**p){
	

semestre*aux=(*p);

FILE* miarchivo;

miarchivo= fopen("materia.txt","w");	

		while(aux!=NULL){

			if(aux->aba){

				materia*t=aux->aba;

				  while(t!=NULL){

							fprintf(miarchivo,"%i\n",aux->setre);

							fprintf(miarchivo,"%s\n",t->nommateria);

							fprintf(miarchivo,"%i\n",t->codigo);

							fprintf(miarchivo,"%i\n",t->credimateria);

					t=t->sig;

				  }

			}

		aux = aux->sig;

		}

fclose(miarchivo);

}

void creararchivosec(semestre**p){

semestre*aux=(*p);

FILE* miarchivo;

miarchivo= fopen("secciones.txt","w");

		while(aux!=NULL){	

			if(aux->aba){

				materia*t=aux->aba;

				  while(t!=NULL){

						if(t->aba){

							secciones*j=t->aba;

							while(j!=NULL){

								fprintf(miarchivo,"%i\n",aux->setre);

							    fprintf(miarchivo,"%i\n",t->codigo);

								fprintf(miarchivo,"%i\n",j->codigosec);

								fprintf(miarchivo,"%i\n",j->numsecc);

								fprintf(miarchivo,"%i\n",j->ceduprofe);

								fprintf(miarchivo,"%s\n",j->nombreprofe);
								
								fprintf(miarchivo,"%i\n",j->cupomax);
								
								fprintf(miarchivo,"%s\n",j->turno);

							j=j->sig;

							}

						}

					t=t->sig;

				  }

			}

		aux = aux->sig;

		}

fclose(miarchivo);

}

void creararchialum(alumnos **q){
	
     alumnos *w = (*q);
     FILE* miarchivo;
     miarchivo= fopen("alumnos.txt","w");
     
      while(w){
 
   fprintf(miarchivo,"%i\n",w->cedula);
   
   fprintf(miarchivo,"%i\n",w->fechanaci);
   
   fprintf(miarchivo,"%i\n",w->mesdenaci);
   
   fprintf(miarchivo,"%i\n",w->fechanaci);
   
   fprintf(miarchivo,"%i\n",w->anonaci);
   
   fprintf(miarchivo,"%i\n",w->extracreditos);
   
   fprintf(miarchivo,"%i\n",w->expe); 
   
   fprintf(miarchivo,"%i\n",w->indiaca);
   
   fprintf(miarchivo,"%s\n",w->nombre);
   
   fprintf(miarchivo,"%s\n",w->apellido);
   
        w = w->sig;

      }
     fclose(miarchivo);
}

void creararchiplani(alumnos **q){
 alumnos *l = (*q);
 
 FILE* miarchivo;
      
  miarchivo= fopen("planilla.txt","w");
  
  while(l != NULL){
      if(l->aba){
           planilla *o = l->aba;
           while(o != NULL){
             
			fprintf(miarchivo,"%i\n",l->cedula);
			        
            fprintf(miarchivo,"%i\n",o->codemate);
           
            fprintf(miarchivo,"%i\n",o->codesecsoli);
           
            o = o->sig;       
           }
           
      }     
     l = l->sig;     
  }    
  fclose(miarchivo);
}

void creararmat(alumnos **q){
 alumnos *l = (*q);
 
 FILE* miarchivo;
      
  miarchivo= fopen("mateinscritas.txt","w");
  
  while(l != NULL){
  	
      if(l->aba){
      	
           planilla *o = l->aba;
           
           while(o != NULL){
              
		    if (o->aba){
		    	
		    	mateinscritas *g = o->aba;
		    	
		    	while(g != NULL){
		    		
		        	fprintf(miarchivo,"%i\n",l->cedula);
			        
                    fprintf(miarchivo,"%i\n",g->codemate);
           
                    fprintf(miarchivo,"%i\n",g->codesec);
					
					g = g->sig;	
				}
			}
           
            o = o->sig;       
           }
           
      }     
     l = l->sig;     
  }    
  fclose(miarchivo);
}

//     leer archivos //

void cargararchisem(semestre**p){
	

char aux[100];

semestre*t;

FILE* miarchivo;

miarchivo= fopen("semestre.txt","rt");  

if(miarchivo!=NULL){

	while(! feof(miarchivo)) {

		t=new semestre;


		fscanf(miarchivo," %[^\n]",aux);

		t->setre=atoi(aux);


		fscanf(miarchivo," %[^\n]",aux);

		t->cupomax=atoi(aux);

		t->sig = (*p);

		(*p)= t;

		t->aba=NULL;		

		

	}

}	

fclose(miarchivo);

}


void cargararchimat(semestre**p){
	

char aux[100];

semestre*t=(*p);

FILE* miarchivo;

miarchivo= fopen("materia.txt","rt");  

if(miarchivo!=NULL){

			while(! feof(miarchivo)) {

				fscanf(miarchivo," %[^\n]",aux);

				while(t){

					semestre*j=(*p);

					if(t->setre==atoi(aux)){

						materia *k=new materia;

						fscanf(miarchivo," %[^\n]",aux);

						strcpy(k->nommateria,aux);

						fscanf(miarchivo," %[^\n]",aux);
						
						k->codigo=atoi(aux);
						
						fscanf(miarchivo," %[^\n]",aux);

						k->credimateria=atoi(aux);

						k->aba=NULL;

						k->sig=t->aba;

						t->aba=k;

						t=j;

						fscanf(miarchivo," %[^\n]",aux);

					}

					else 



					t=t->sig;

				}





			}

}

fclose(miarchivo);	

}


void cargararchisecc(semestre**p){

char aux[100];

int cont=0;

semestre*t=(*p);



FILE* miarchivo;

miarchivo= fopen("secciones.txt","rt");  

if(miarchivo!=NULL){

			while(! feof(miarchivo)) {

				fscanf(miarchivo," %[^\n]",aux);

				while(t){

					semestre*j=(*p);

					if(t->setre==atoi(aux)){

						if(t->aba){

							materia*c=t->aba;

							materia*k=t->aba;

							fscanf(miarchivo," %[^\n]",aux);

							while(c){

								if((c->codigo==atoi(aux))){

									secciones*v=new secciones;

									fscanf(miarchivo," %[^\n]",aux);

									v->codigosec=atoi(aux);

									fscanf(miarchivo," %[^\n]",aux);

									v->numsecc=atoi(aux);

									fscanf(miarchivo," %[^\n]",aux);

									v->ceduprofe=atoi(aux);

									fscanf(miarchivo," %[^\n]",aux);

									strcpy(v->nombreprofe,aux);
									
									fscanf(miarchivo," %[^\n]",aux);
									
									v->cupomax=atoi(aux);
									
									fscanf(miarchivo," %[^\n]",aux);
									
									
									strcpy(v->turno,aux);

									v->sig=NULL;
									v->aba=NULL;

									secciones *aux2=c->aba;

									if(aux2){

									while(aux2->sig){

										aux2=aux2->sig;

									}

									aux2->sig=v;

									}

									else{

										c->aba=v;

									}

									fscanf(miarchivo," %[^\n]",aux);

									c=k;

									t=j;



								}

								else

									c=c->sig;

							}

						}

					}

					else 



					t=t->sig;

				}
			}

}

fclose(miarchivo);	

}

void cargararchialum(alumnos **q){
     
char aux[100];

alumnos*t;

FILE* miarchivo;

miarchivo= fopen("alumnos.txt","rt");  
     
     if(miarchivo!=NULL){
  
     	while(! feof(miarchivo)) {

		   t=new alumnos;

     		fscanf(miarchivo," %[^\n]",aux);

		    t->cedula=atoi(aux);
		    
		    fscanf(miarchivo," %[^\n]",aux);

		    t->fechanaci=atoi(aux);
		    
	    	fscanf(miarchivo," %[^\n]",aux);

		    t->mesdenaci=atoi(aux);
		    
	    	fscanf(miarchivo," %[^\n]",aux);

		    t->anonaci=atoi(aux);
		    
	    	fscanf(miarchivo," %[^\n]",aux);

		    t->extracreditos=atoi(aux);
		    
		    fscanf(miarchivo," %[^\n]",aux);

		    t->expe=atoi(aux);
		    
		    fscanf(miarchivo," %[^\n]",aux);

		    t->indiaca=atoi(aux);
		    
		    fscanf(miarchivo," %[^\n]",aux);

            strcpy(t->nombre,aux);
            
            fscanf(miarchivo," %[^\n]",aux);

            strcpy(t->apellido,aux);

		    t->sig = (*q);

		    (*q)= t;

		    t->aba=NULL;		

    	}

     }	
}

void cargararchipla(alumnos **q){
     char aux[100];
     
     alumnos*t=(*q);
 
     FILE* miarchivo;

     miarchivo= fopen("planilla.txt","rt");
        
      if(miarchivo != NULL){
                         
         while(!feof(miarchivo)){
          
           fscanf(miarchivo," %[^\n]",aux);
           
           while(t){
            alumnos*j = (*q);
            
            if(t->cedula == atoi(aux)){
                         
                 planilla *w = new planilla;
                 
                 fscanf(miarchivo," %[^\n]",aux);
            
                 w->codemate = atoi(aux);
                 
                 fscanf(miarchivo," %[^\n]",aux);
            
                 w->codesecsoli = atoi(aux);
                
                 fscanf(miarchivo," %[^\n]",aux);
            
                 w->cedu = atoi(aux);
                
                 fscanf(miarchivo," %[^\n]",aux);
            
         w->numero = atoi(aux);
         
         w->aba=NULL;

                 w->sig=t->aba;

                 t->aba=w;

                 t = j;

                 fscanf(miarchivo," %[^\n]",aux);
            }
            else t = t->sig;
            
           } 
         }     
     }
    fclose(miarchivo);   
}

alumnos *buscaralumno(alumnos*q,int cedu){
	if(q){
	
		alumnos *aux=q;
		while(aux){

			if(aux->cedula==cedu)
				return aux;
		aux=aux->sig;
		}
	}
	else 
	printf("alumno no ha sido posible encontrarlo\n"); return NULL;

}

semestre *buscarsemestre(semestre*p, int numero){
         if(p){
               semestre *aux=p;
               while(aux){
                          if(aux->setre==numero)
                          return aux;
                          aux=aux->sig;
                          }
                          }
         else 
         printf("Semestre no encontrado\n"); return NULL;
}                 

record *crear(int x){
	
	record *aux= new record;
	aux->valor=x;
	printf("\n Codigo de la materia ?:\n");
	scanf("%d",&aux->codmateria);
	printf("\n Nota obtenida por el estudiante :\n");
	scanf("%d",&aux->nota);
	printf("\n Observaciones :(Aprobado,Aprobado por Reparacion, Retirado o Reprobado)\n");
	fflush(stdin);
	gets(aux->observaciones);
	fflush(stdin);
	aux->izq=NULL;
	aux->der=NULL;
	
	return aux;
}

matearbol *crear2(int x){
        matearbol *aux= new matearbol;
        aux->valor=x;
        printf("Indique Nombre de la materia: \n");
        fflush(stdin);
        gets(aux->materia);
        fflush(stdin);
        printf("Indique Numero de creditos de la materia: \n");
        scanf("%d",&aux->numcreditos);
        aux->izq=NULL;
        aux->der=NULL;
        return aux;
        }

void insertarecord(record **r,int x){
	
	if (!(*r)) 
		*r = crear(x);
	else {
		if ((*r)->valor >= x){
			insertarecord(&((*r)->izq),x);
		}
		else {
			if ((*r)->valor < x){
				insertarecord(&((*r)->der),x);
			
			}
		}
	}
}

void insertarmatearbol(matearbol **m,int x){
     if(!(*m))
     *m = crear2(x);
     else{
          if((*m)->valor >= x){
                            insertarmatearbol(&((*m)->izq),x);
                            }
           else{
                if((*m)->valor < x){
                            insertarmatearbol(&((*m)->der),x);
                }                                  
           }
          }
}

void agregar_record(alumnos **q){
	int ced,o,num2;
	printf("Ingrese C.I del alumno:\n");
                         scanf("%i",&ced);
                         alumnos *auxp = *q;
                         bool cond2;
                         cond2=false;
                         while((auxp)&&(cond2==false)){
                         	if(auxp->cedula==ced)cond2=true;
                         	else auxp=auxp->sig;                        	
						 }
                         o = 0;
                         if(auxp != NULL){
                          while( o == 0 ){
							   
							   	printf("\n Ingrese año seguido de los numeros 21,22 o 23 a insertar \n");
							   	scanf("%i",&num2);
							   	record *m = auxp->arbol;
							   	insertarecord(&m,num2);
							   	auxp->arbol = m;
							    printf("Desea seguir insertando? Si=0 ");
							    scanf("%i",&o);
					       }
					   }
					   else
					   	printf("El Semestre no se encuentra\n");
}

void agregar_matearbol(semestre **p){
	int num,o,num2;
	printf("Ingrese numero del Semestre:\n");
                         scanf("%d",&num);
                         semestre *auxp= *p;
                         bool cond2;
                         cond2=false;
                         while((auxp)&&(cond2==false)){
                         	if(auxp->setre==num)cond2=true;
                         	else auxp=auxp->sig;                        	
						 }
                         o = 0;
                         if(auxp!=NULL){
                          while( o == 0 ){
							   
							   	printf("Ingrese Codigo de la materia a insertar\n");
							   	scanf("%d",&num2);
							   	matearbol *m=auxp->arbol;
							   	insertarmatearbol(&m,num2);
							   	auxp->arbol=m;
							    printf("Desea seguir insertando? Si=0 ");
							    scanf("%i",&o); // 1.cambiar opcion por si deseas seguir... anterior el valor se quedaba en la opcion que dabas.VE AL COMENTARIO 2.
					       }
					   }
					   else
					   	printf("El Semestre no se encuentra\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////CONSULTA 4///////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
void inorden3(record *r, int cod, int *contador){
     if(r){
           inorden3(r->izq,cod,contador);
           if((strcmp(r->observaciones,"Reprobado")==0)&&(r->codmateria==cod)){
            (*contador)++;
           }
           inorden3(r->der,cod,contador);
           }      
}  

int viendomate(alumnos *q, int codi){
	printf("\n Entro viendomate");
     int cont=0;
     alumnos *aux = q;
     
             planilla *u = aux->aba;
             while(u){
                if (u->codemate == codi){
                    mateinscritas *h=u->aba;
                    while(h){
                     if(h->codemate == codi){
                              cont++;
                              printf("\n Salio viendomate\n");
                              return cont;      
                     }
                     h = h->sig;
                    }             
                }
                u = u->sig;      
             }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////CONSULTA 3/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
void inorden2 (record *r){
	if (r){
		inorden2(r->izq);
        printf("Perido: %i \n",r->valor);
        printf("Nota Obtenida: %i \n",r->nota);
        printf("Codigo de la materia: %i \n",r->codmateria);
        printf("Observaciones: %s\n\n",r->observaciones);
		inorden2(r->der);
	}
}

void inorden(matearbol *m){
     if(m){
           inorden(m->izq);
           printf("Codigo de la materia : %i \n",m->valor);
           printf("Nombre de la materia:%s\n",m->materia);
           printf("Numero de creditos: %i\n-------------------------------------\n",m->numcreditos);
           inorden(m->der);
           }
}  
  
//CONSULTA 2 INICIO
int indice_estud(record *r, int *indice, int *materia){  //consulta #2
int j=0;
    if(r){	
		indice_estud(r->izq,indice,materia);
if (strcmp(r->observaciones,"Aprobado")==0)
{
			materia++;
            int a;
			a=r->nota;
			indice=indice+ a;
			j = *indice;
		    }
		indice_estud(r->der,indice,materia);
	}
return j;	
}

int ndice_estud(record *r, int *indice, int *materia){  //consulta #2
int j=0;
    if(r){	
		ndice_estud(r->izq,indice,materia);
if (strcmp(r->observaciones,"Aprobado")==0){
			j = (*materia)++;
            int a;
			a = r->nota;
			(*indice)=(*indice)+ a;
		    }
		ndice_estud(r->der,indice,materia);
	}
return j;	
}
// Fin de CONSULTA 2

//CONSULTA 3
void indices_todos_estud(alumnos *q){
	int i,j,k=0,cont=0,e=0,contal,contador=0;
	float aux2;
system("cls");
 alumnos *aux=q; 
 while(aux){
 	if(aux->sig!=NULL){cont++;}
	aux=aux->sig;
}                    //cuenta cuantos alumnos hay
   aux=q;
   float array[cont]; //array con numero de alumnos
    while(aux){ //mete los promedios en un array hasta llegar al maximo de alumnos 
    	array[e]=aux->promedio;
    	e++;
    	aux=aux->sig;
    }        
k=0;	             
for(i=0;i<=cont-1;i++){   //Ordenamiento del array mediante Burbuja
	contador=0;
	for(j=0;j<=cont-1;j++){
		if(array[j]>array[j+1]){
			aux2=array[j];
			array[j]=array[j+1];
			array[j+1]=aux2;
			contador++;
		}
	}
		if(contador==0)break;
} 
aux=q;
k=0;
                while(aux){       //Busca los promedios en el array ordenado
	                if(aux->promedio==array[0]){
		            printf("\n Peor Indice: %f",aux->promedio);
		            printf("\n Alumno : %s %s",aux->nombre,aux->apellido);		
                    }
                    if(aux->promedio == array[cont]){
		            printf("\n mejor Indice: %f",aux->promedio);
	            	printf("\n Alumno : %s %s",aux->nombre,aux->apellido);
		            }
                aux=aux->sig; 	
                }
                   
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////// programa principal
///////////////////////////////////

int main(){
	
	int op=-1,cedula=0,num=0,boo=1,o=0,num2=0,contador = 0;;

     semestre *p = NULL;
     semestre *aux2 = NULL;
     alumnos *q = NULL;
     alumnos *aux = NULL;
     record *r = NULL;
     matearbol *m = NULL;
     
   /* parte del arbol1*/ 
   
   Arbol ArbolInt=NULL;
   int altura;
   int nnodos,n,op1=0;
   
   /* parte del arbol2*/
   
   Arbol2 ArbolInt2 = NULL;
   int altura2;
   int nnodos2,n2,op2 = 0;
   /*  AVL  */
    
    while (op != 0){
     	
system("cls");
printf("---------------------------------");
printf("\n   Sistema de Inscripcion UCAB   \n");
printf("---------------------------------\n");
printf("\n Seleccione una opcion:\n");
printf("\n 1)Agregar Algun Registro ");
printf("\n 2)Modificar Algun Registro ");
printf("\n 3)Imprimir o Mostrar en Pantalla");
printf("\n 4)Eliminar Algun Registro ");
printf("\n 5)Opciones de Archivo \n");
printf("\n 6)ARBOL AVL CON NUMERO DE CEDULA DEL ALUMNO \n");
printf("\n 7)ARBOL AVL CON PERIODO DEL ALUMNO \n");
printf("\n Ingrese <0> para salir del sistema\n");
printf("\n Ingrese un numero distinto del menu para volver");

printf("\n"); 
	scanf("%i",&op);
     	
     	switch(op){
     case 1: 
     system("cls");
     printf("____________\n");
     printf("[ AGREGAR ]");
     printf("\n____________");
     printf("\n"); 
     printf("\n  1-Agregar Semestre \n");
     printf("  2-Agregar Materia \n");
     printf("  3-Agregar Seccion \n");
     printf("  4-Agregar Alumno \n");
     printf("  5-Agregar Horario \n");
     printf("  6-Agregar Planilla \n");
     printf("  7-Elegir una planilla para inscribir la materia\n");
     printf("  8-Agregar record\n");
     printf("  9-Agregar Materia(ARBOL) ***NUEVO\n");
      scanf("%i",&op);
     	
     	    switch(op){
     	    	case 1:agregarsemestre(&p);
     	    		break;
     	    		
     	    	case 2:agregarmaterias(&p);
				    break;
				    
				case 3:agregarsecciones(&p);
				    break;
				    
				case 4:agregaralumnos(&q);
				    break;
				    
				case 5:agregarhorario(&p); 
				    break;
				    
				case 6:tenerplanilla(p,&q);
				    break;
                    	
				case 7:agregarmateriasinscritas(&q);                  
                     break;
                     
				case 8: agregar_record(&q);
					    break; 
                           
                    case 9: agregar_matearbol(&p);                         
					break;
                                                                                                                 
				default:
				break;    				
            }
	break;	//del case 1	
	
	case 2:
	system("cls");
	printf("____________\n");
     printf("[ MODIFICAR ]");
     printf("\n____________");
     printf("\n"); 
     printf("\n  1-Modificar Semestre \n");
     printf("  2-Modificar Materia \n");
     printf("  3-Modificar Seccion \n");
     printf("  4-Modificar Alumno \n");
     printf("  5-Modificar Horario \n");
      scanf("%i",&op);
     	
     	    switch(op){
	        case 1: modificarsemes(p); 
                    break;
                    
            case 2: modificarmat(p);        
			        break;
            
			case 3: modificarsecc(p);
			        break;
			        
			case 4: modificaralum(q);
			        break;
	        case 5: 
	                break;
		}
		break;// del case 2
	case 3:
	system("cls");  
	printf("____________\n");
     printf("[ IMPRIMIR ]");
     printf("\n____________");
     printf("\n"); 
	printf("\n 1-Imprimir Semestre \n");
    printf(" 2-Imprimir Materia \n");
    printf(" 3-Imprimir Seccion \n");
    printf(" 4-Imprimir Alumno \n");
    printf(" 5-Imprimir Horario \n");
    printf(" 6-Imprimir Planilla \n");                                    //Consulta del proyecto #4
    printf(" 7-Imprimir todas las materias de un semestre\n");            //Consulta del proyecto #1
    printf(" 8-Imprimir la informacion y semestre de una materia dada\n");//Consulta del proyecto #2
    printf(" 9-Imprimir Secciones de una materia dada\n");                //Consulta del proyecto #3
    printf("10-Imprimir materias inscritas por un alumno\n");             //Consulta del proyecto #7
    printf("11-Imprimir alumnos inscritos en una seccion\n");            //Consulta del proyecto #8
    printf("12-Imprimir todos los alumnos\n");
    printf("13-Imprimir planillas por orden de cedula\n");
    printf("14-Orden Cronologico Record de un estudiante \n");
    printf("15-Inorden de Materia Arbol\n");
    printf("16-Indice de un estudiante \n");
    printf("17-Indice del Mejor y Peor estudiante\n");
    printf("18-Materia con alumnos en riesgo\n");
      scanf("%i",&op);
     	
     	    switch(op){
	        case 1: imprimirsemes(p);
                    break;
                    
            case 2: imprimirmaterias(p); 
                    break;
                    
            case 3: imprimirsecciones(p);
			        break;
			        
			case 4: imprimiralumnos(q);
				 	break;
				 	
			case 5: imprimir_horario(p,q);                        //HORARIO
			        break;
			        
			case 6: imprimirplanilla(q);                        //PLANILLA
					break;
						 	
	        case 7:imprimirsemes_mas_materias(p);  
			        break; 
			        
			case 8:imprimirmateria_y_semestre(p);
			        break;	
						             
			case 9:imprimirsecciones_una_materia(p);
			        break;
						
			case 10: imprimirmateinscritas(q);
			         break;
					  		
			case 11:imprimiralumnosinscritos_seccion(q);
			         break;	
					 	 	       
            case 12:imprimiralumnostodos(q);
                    break;
					 
			case 13:imprimirplanilla_por_cedula(q);
			        break;  
			        
			case 14:
			           printf("Ingrese la cedula del alumno\n");
					   scanf("%d",&cedula);
					   
					   aux=buscaralumno(q,cedula);
					   if(aux != NULL)
						   	inorden2(aux->arbol);
					   
					   else
					   	printf("El alumno no se encuentra\n");
			break;
           //----------------------------------------------------// 
            case 15: 
                 printf("Ingrese numero del semestre\n");
                 scanf("%d",&num);
                 printf("_______________________________________\n\n");
                 aux2=buscarsemestre(p,num);
                 if(aux2!=NULL)
                 inorden(aux2->arbol);
                 else
                 printf("Semestre no se encuentra \n");
                 break;
           //---------------------------------------------------------//      	
			case 16:
			printf("Ingrese CI del estudiante:\n");
			scanf("%d",&cedula);
				 
			aux = buscaralumno(q,cedula);
			
					   if(aux != NULL){
                              
					   int	indice=0,materia=0; float ind;
					   int au,au1;
                       					   
					   au = indice_estud(aux->arbol,&indice,&materia);
					   au1 = ndice_estud(aux->arbol,&indice,&materia);
					   printf("\n SALIO\n ");
					   printf("Notas: %i",indice);
					   printf("\nMaterias Aprobadas: %i",materia);
					   ind = (indice/materia);
					   printf("\nEl indice es: %f\n",ind);
					   /*alumnos *w = new alumnos*/
					   /*w->promedio=ind;*/}
					   
					   else
					   printf("El alumno no existe \n");
			break;
			//-------------------------------------------------------------------//
			case 17:
				alumnos *aux2;
				aux2=q;
				while(aux2){ //Calcula el indice de todos los alumnos
					int	indice=0,materia=0; 
					float ind;
					   int au,au1;
					 indice_estud(aux2->arbol,&indice,&materia);
					 ndice_estud(aux2->arbol,&indice,&materia);
					  ind = (indice/materia);
					  aux2->promedio=ind; //no guardara nada sino creas cajita
					  aux2=aux2->sig;}
					  indices_todos_estud(q);					  
			break;
			//-----------------------------------------------------------------//
            case 18:  
                 int code,a=0,b=0;
                 printf("Ingrese el codigo de la  materia\n");
                 scanf("%i",&code);
                 alumnos *auxiliar = q;
                 printf("\n Alumnos en Peligro: \n");
                 while(auxiliar){
                      if (auxiliar->arbol){
                      	record *h = auxiliar->arbol;
                           a = viendomate(q,code);
                           printf("\n A vale: %d",a);
			                inorden3(h,code,&contador);
						    printf("\n Contador vale: %d\n",contador);
							if(a+contador>=4){
							printf("%s %s",auxiliar->apellido,auxiliar->nombre);}
							contador=0;							        
                      } 
					  auxiliar=auxiliar->sig;    
                 }
                 printf("\n NULL");
                 break;
				 	   
				}//switch imprimir					   	 	         		          
	       break;//case 3
		case 4:
		system("cls"); 
		printf("____________\n");
     printf("[ ELIMINAR ]");
     printf("\n____________");
	 printf("\n"); 
	printf("\n  1-Eliminar Semestre \n");
    printf("  2-Eliminar Materia \n");
    printf("  3-Eliminar Seccion \n");
    printf("  4-Eliminar Alumno \n");
    printf("  5-Eliminar Planilla \n");
      scanf("%i",&op);
     	
     	    switch(op){
	        case 1: eliminarsemestre(&p); 
                    break;
                    
        	case 2: eliminarmateria(&p); 
                    break;
                    
            case 3: eliminarsecc(&p);
                     break;
                     
            case 4: eliminaralumn(&q);
                     break;  

	        case 5:  eliminarpla(&q);
			         break;         
            }
	break;//case 4
	
	case 5:
	   system("cls");  
	printf("1-Crear Archivo \n");
    printf("2-Cargar Archivo \n");
	scanf("%i",&op);
     	
     	    switch(op){
     	    	case 1:creararchivosem(&p);
                       creararchivomat(&p);
                       creararchivosec(&p);
                       creararchialum(&q);
                       creararchiplani(&q);
                      // creararmat(&q);
                     break;
                             
                case 2: cargararchisem(&p);
                     cargararchimat(&p);
                     cargararchisecc(&p);
                     cargararchialum(&q);
                     cargararchipla(&q);
                     break;
	        }
	break;
	
	case 6:
	    system("cls");
		    while (op1 == 0){
         	printf("Introduzca numero de cedula\n");
   	        scanf("%i",&n);
   	        Insertar(&ArbolInt, n);
   	        printf("Desea seguir insertando? Si = 0 y NO = 1\n");
   	        scanf("%i",&op1);
            }     
   
        printf("Altura de arbol %d\n", AlturaArbol(ArbolInt, &altura));
        /* Mostrar el árbol en tres ordenes distintos: */
        printf("InOrden: ");
        InOrden(ArbolInt, MOstrar);
       /* Veamos algunos parámetros */
        printf("N nodos: %d\n", NumeroNodos(ArbolInt, &nnodos));
        printf("Altura de 1 %d\n", Altura(ArbolInt, 1));
        printf("Altura de 10 %d\n", Altura(ArbolInt, 10));
        printf("Altura de arbol %d\n", AlturaArbol(ArbolInt, &altura));
       system("PAUSE");      
	break;
	
	case 7:
	 	    system("cls");
		    while (op2 == 0){
         	printf("Introduzca numero de periodo\n");
   	        scanf("%i",&n2);
   	        Insertar(&ArbolInt2, n2);
   	        printf("Desea seguir insertando? Si = 0 y NO = 1\n");
   	        scanf("%i",&op2);
            }     
   
        printf("Altura de arbol %d\n", AlturaArbol(ArbolInt2, &altura));
        /* Mostrar el árbol en tres ordenes distintos: */
        printf("InOrden: ");
        InOrden(ArbolInt2, Mostrar);
       /* Veamos algunos parámetros */
        printf("N nodos: %d\n", NumeroNodos(ArbolInt2, &nnodos2));
        printf("Altura de 1 %d\n", Altura(ArbolInt2, 1));
        printf("Altura de 10 %d\n", Altura(ArbolInt2, 10));
        printf("Altura de arbol %d\n", AlturaArbol(ArbolInt2, &altura2));
       system("PAUSE");  
	break;
    }
	 
system("PAUSE");

}
return 0;
}

void Insertar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual = *a;

   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat < actual->dato) actual = actual->izquierdo;
      else if(dat > actual->dato) actual = actual->derecho;
   }

   if(!Vacio(actual)) return;

   if(Vacio(padre)) {
      *a = (Arbol)malloc(sizeof(tipoNodo));
      (*a)->dato = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;
      (*a)->padre = NULL;
      (*a)->FE = 0;
   }

   else if(dat < padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->izquierdo = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
      actual->padre = padre;
      actual->FE = 0;
      Equilibrar(a, padre, IZQUIERDO, TRUE);
   }
 
   else if(dat > padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
      actual->padre = padre;
      actual->FE = 0;
      Equilibrar(a, padre, DERECHO, TRUE);
  }
}

void Equilibrar(Arbol *a, pNodo nodo, int rama, int nuevo)
{
   int salir = FALSE;

   while(nodo && !salir) {
      if(nuevo)
         if(rama == IZQUIERDO) nodo->FE--; 
         else                  nodo->FE++;
      else
         if(rama == IZQUIERDO) nodo->FE++; 
         else                  nodo->FE--;
      if(nodo->FE == 0) salir = TRUE; 
                                         
      else if(nodo->FE == -2) {
         if(nodo->izquierdo->FE == 1) RDD(a, nodo); 
         else RSD(a, nodo);                         
         salir = TRUE;
      }
      else if(nodo->FE == 2) {  
         if(nodo->derecho->FE == -1) RDI(a, nodo); 
         else RSI(a, nodo);                       
         salir = TRUE;
      }
      if(nodo->padre)
         if(nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
      nodo = nodo->padre; 
   }
}

void RDD(Arbol *raiz, Arbol nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->izquierdo;
   pNodo R = Q->derecho;
   pNodo B = R->izquierdo;
   pNodo C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else *raiz = R;

   Q->derecho = B;
   P->izquierdo = C;
   R->izquierdo = Q;
   R->derecho = P;

   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = Q;
   if(C) C->padre = P;

   switch(R->FE) {
      case -1: Q->FE = 0; P->FE = 1; break;
      case 0:  Q->FE = 0; P->FE = 0; break;
      case 1:  Q->FE = -1; P->FE = 0; break;
   }
   R->FE = 0;
}

void RDI(Arbol *a, pNodo nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->derecho;
   pNodo R = Q->izquierdo;
   pNodo B = R->izquierdo;
   pNodo C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else *a = R;

   P->derecho = B;
   Q->izquierdo = C;
   R->izquierdo = P;
   R->derecho = Q;


   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = P;
   if(C) C->padre = Q;


   switch(R->FE) {
      case -1: P->FE = 0; Q->FE = 1; break;
      case 0:  P->FE = 0; Q->FE = 0; break;
      case 1:  P->FE = -1; Q->FE = 0; break;
   }
   R->FE = 0;
}

void RSD(Arbol *a, pNodo nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->izquierdo;
   pNodo B = Q->derecho;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else *a = Q;


   P->izquierdo = B;
   Q->derecho = P;


   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;


   P->FE = 0;
   Q->FE = 0;
}

void RSI(Arbol *a, pNodo nodo)
{
   pNodo Padre = nodo->padre;
   pNodo P = nodo;
   pNodo Q = P->derecho;
   pNodo B = Q->izquierdo;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else *a = Q;


   P->derecho = B;
   Q->izquierdo = P;


   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;


   P->FE = 0;
   Q->FE = 0;
}

void InOrden(Arbol a, void (*func)(int*)){
   if(a->izquierdo) InOrden(a->izquierdo, func);
   func(&(a->dato));
   if(a->derecho) InOrden(a->derecho, func);
}

int Buscar(Arbol a, int dat){
   pNodo actual = a;

   
   while(!Vacio(actual)) {
      if(dat == actual->dato) return TRUE; 
      else if(dat < actual->dato) actual = actual->izquierdo; 
      else if(dat > actual->dato) actual = actual->derecho;
   }
   return FALSE;
}

int Altura(Arbol a, int dat){
   int altura = 0;
   pNodo actual = a;

   
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; 
      else {
         altura++; 
         if(dat < actual->dato) actual = actual->izquierdo;
         else if(dat > actual->dato) actual = actual->derecho;
      }
   }
   return -1; 
}

int NumeroNodos(Arbol a, int *contador){
   *contador = 0;

   auxContador(a, contador);
   return *contador;
}

void auxContador(Arbol nodo, int *c){
   (*c)++; 
   if(nodo->izquierdo) auxContador(nodo->izquierdo, c);
   if(nodo->derecho)   auxContador(nodo->derecho, c);
}

int AlturaArbol(Arbol a, int *altura){
   *altura = 0;
   
   auxAltura(a, 0, altura); 
   return *altura;
}

void auxAltura(pNodo nodo, int a, int *altura){
	
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1, altura);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1, altura);
   /* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
      árbol, actualizamos la altura actual del árbol */
   if(EsHoja(nodo) && a > *altura) *altura = a;
}

int Vacio(Arbol r){
   return r==NULL;
}

int EsHoja(pNodo r){
   return !r->derecho && !r->izquierdo;
}

void MOstrar(int *d){
   printf("%d, ", *d);
}

//----------------------------ROTACIONES DE MATEARBOL----------------------------------------//

void Insertar(Arbol2 *a, int dat)
{
   pNodo2 padre = NULL;
   pNodo2 actual2 = *a;

   while(!Vacio(actual2) && dat != actual2->dato1) {
      padre = actual2;
      if(dat < actual2->dato1) actual2 = actual2->izquierdo;
      else if(dat > actual2->dato1) actual2 = actual2->derecho;
   }

   if(!Vacio(actual2)) return;

   if(Vacio(padre)) {
      *a = (Arbol2)malloc(sizeof(tipoNodo2));
      (*a)->dato1 = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;
      (*a)->padre = NULL;
      (*a)->FE1 = 0;
   }

   else if(dat < padre->dato1) {
      actual2 = (Arbol2)malloc(sizeof(tipoNodo2));
      padre->izquierdo = actual2;
      actual2->dato1 = dat;
      actual2->izquierdo = actual2->derecho = NULL;
      actual2->padre = padre;
      actual2->FE1 = 0;
      Equilibrar(a, padre, IZQUIERDO, TRUE);
   }
 
   else if(dat > padre->dato1) {
      actual2 = (Arbol2)malloc(sizeof(tipoNodo2));
      padre->derecho = actual2;
      actual2->dato1 = dat;
      actual2->izquierdo = actual2->derecho = NULL;
      actual2->padre = padre;
      actual2->FE1 = 0;
      Equilibrar(a, padre, DERECHO, TRUE);
  }
}

void Equilibrar(Arbol2 *a, pNodo2 nodo, int rama, int nuevo)
{
   int salir = FALSE;

   while(nodo && !salir) {
      if(nuevo)
         if(rama == IZQUIERDO) nodo->FE1--; 
         else                  nodo->FE1++;
      else
         if(rama == IZQUIERDO) nodo->FE1++; 
         else                  nodo->FE1--;
      if(nodo->FE1 == 0) salir = TRUE; 
                                         
      else if(nodo->FE1 == -2) {
         if(nodo->izquierdo->FE1 == 1) RDD(a, nodo); 
         else RSD(a, nodo);                         
         salir = TRUE;
      }
      else if(nodo->FE1 == 2) {  
         if(nodo->derecho->FE1 == -1) RDI(a, nodo); 
         else RSI(a, nodo);                       
         salir = TRUE;
      }
      if(nodo->padre)
         if(nodo->padre->derecho == nodo) rama = DERECHO; else rama = IZQUIERDO;
      nodo = nodo->padre; 
   }
}

void RDD(Arbol2 *raiz, Arbol2 nodo)
{
   pNodo2 Padre = nodo->padre;
   pNodo2 P = nodo;
   pNodo2 Q = P->izquierdo;
   pNodo2 R = Q->derecho;
   pNodo2 B = R->izquierdo;
   pNodo2 C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else *raiz = R;

   Q->derecho = B;
   P->izquierdo = C;
   R->izquierdo = Q;
   R->derecho = P;

   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = Q;
   if(C) C->padre = P;

   switch(R->FE1) {
      case -1: Q->FE1 = 0; P->FE1 = 1; break;
      case 0:  Q->FE1 = 0; P->FE1 = 0; break;
      case 1:  Q->FE1 = -1; P->FE1 = 0; break;
   }
   R->FE1 = 0;
}

void RDI(Arbol2 *a, pNodo2 nodo)
{
   pNodo2 Padre = nodo->padre;
   pNodo2 P = nodo;
   pNodo2 Q = P->derecho;
   pNodo2 R = Q->izquierdo;
   pNodo2 B = R->izquierdo;
   pNodo2 C = R->derecho;

   if(Padre)
     if(Padre->derecho == nodo) Padre->derecho = R;
     else Padre->izquierdo = R;
   else *a = R;

   P->derecho = B;
   Q->izquierdo = C;
   R->izquierdo = P;
   R->derecho = Q;


   R->padre = Padre;
   P->padre = Q->padre = R;
   if(B) B->padre = P;
   if(C) C->padre = Q;


   switch(R->FE1) {
      case -1: P->FE1 = 0; Q->FE1 = 1; break;
      case 0:  P->FE1 = 0; Q->FE1 = 0; break;
      case 1:  P->FE1 = -1; Q->FE1 = 0; break;
   }
   R->FE1 = 0;
}

void RSD(Arbol2 *a, pNodo2 nodo)
{
   pNodo2 Padre = nodo->padre;
   pNodo2 P = nodo;
   pNodo2 Q = P->izquierdo;
   pNodo2 B = Q->derecho;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else *a = Q;


   P->izquierdo = B;
   Q->derecho = P;


   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;


   P->FE1 = 0;
   Q->FE1 = 0;
}

void RSI(Arbol2 *a, pNodo2 nodo)
{
   pNodo2 Padre = nodo->padre;
   pNodo2 P = nodo;
   pNodo2 Q = P->derecho;
   pNodo2 B = Q->izquierdo;

   if(Padre)
     if(Padre->derecho == P) Padre->derecho = Q;
     else Padre->izquierdo = Q;
   else *a = Q;


   P->derecho = B;
   Q->izquierdo = P;


   P->padre = Q;
   if(B) B->padre = P;
   Q->padre = Padre;


   P->FE1 = 0;
   Q->FE1 = 0;
}

void InOrden(Arbol2 a, void (*func)(int*)){
   if(a->izquierdo) InOrden(a->izquierdo, func);
   func(&(a->dato1));
   if(a->derecho) InOrden(a->derecho, func);
}

int Buscar(Arbol2 a, int dat){
   pNodo2 actual2 = a;

   
   while(!Vacio(actual2)) {
      if(dat == actual2->dato1) return TRUE; 
      else if(dat < actual2->dato1) actual2 = actual2->izquierdo; 
      else if(dat > actual2->dato1) actual2 = actual2->derecho;
   }
   return FALSE;
}

int Altura(Arbol2 a, int dat){
   int altura = 0;
   pNodo2 actual2 = a;

   
   while(!Vacio(actual2)) {
      if(dat == actual2->dato1) return altura; 
      else {
         altura++; 
         if(dat < actual2->dato1) actual2 = actual2->izquierdo;
         else if(dat > actual2->dato1) actual2 = actual2->derecho;
      }
   }
   return -1; 
}

int NumeroNodos(Arbol2 a, int *contador){
   *contador = 0;

   auxContador(a, contador);
   return *contador;
}

void auxContador(Arbol2 nodo, int *c){
   (*c)++; 
   if(nodo->izquierdo) auxContador(nodo->izquierdo, c);
   if(nodo->derecho)   auxContador(nodo->derecho, c);
}

int AlturaArbol(Arbol2 a, int *altura){
   *altura = 0;
   
   auxAltura(a, 0, altura); 
   return *altura;
}

void auxAltura(pNodo2 nodo, int a, int *altura){
	
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1, altura);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1, altura);
   /* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
      árbol, actualizamos la altura actual del árbol */
   if(EsHoja(nodo) && a > *altura) *altura = a;
}

int Vacio(Arbol2 r){
   return r==NULL;
}

int EsHoja(pNodo2 r){
   return !r->derecho && !r->izquierdo;
}

void Mostrar(int *d){
   printf("%d, ", *d);
}
