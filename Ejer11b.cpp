#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    char nombreYApellido[25];
    int legajo;
}STR_ORDENADO;

void discardChars(){
        char c;
        while((c = getchar()) != '\n' && c != EOF);
        return;
}

void tamanioArchivo(FILE*f){
        int pos= ftell(f);
        fseek(f,0,SEEK_END);
        printf("Tamanio de esta mierda: %d\n",ftell(f));
        fseek(f,pos,SEEK_SET);
}

int main(){

    FILE*ordenado=fopen("D:\\Diego Facultad\\VSC\\Archivos\\ORDENADO.DAT","rb+");    
    if(ordenado==NULL){
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }


    STR_ORDENADO *aux=(STR_ORDENADO*)malloc(sizeof(STR_ORDENADO));
    int posCero=0;
    STR_ORDENADO *vacio=(STR_ORDENADO*)malloc(sizeof(STR_ORDENADO)); 
    int posDato=0;

    fseek(ordenado,0,SEEK_END);
    printf("%d\n",ftell(ordenado));
    fseek(ordenado,0,SEEK_SET);



    //fseek(ordenado,0,SEEK_SET);

    fread(aux,sizeof(STR_ORDENADO),1,ordenado);

    if(feof(ordenado)!=0){
        return 0;
    }
    
    while(posCero==0){
        if(aux->legajo==0){
            posCero=ftell(ordenado);
            vacio->legajo=aux->legajo;
            strcpy(vacio->nombreYApellido,aux->nombreYApellido);

        }
        else{
            posDato=ftell(ordenado);
            fread(aux,sizeof(STR_ORDENADO),1,ordenado);

        }
    }

    fseek(ordenado,posDato,SEEK_SET);
    fread(aux,sizeof(STR_ORDENADO),1,ordenado);


            tamanioArchivo(ordenado);



    while(!feof(ordenado)){

        if(aux->legajo!=0){
        
            posDato=(ftell(ordenado));
            fseek(ordenado,posCero-sizeof(STR_ORDENADO),SEEK_SET);
            printf("Posicion actuaaal: %d\n",ftell(ordenado));
            fwrite(aux,sizeof(STR_ORDENADO),1,ordenado);

            tamanioArchivo(ordenado);


            fseek(ordenado,posDato-sizeof(STR_ORDENADO),SEEK_SET);
            printf("Posicion actuaaal: %d\n",ftell(ordenado));
            fwrite(vacio,sizeof(STR_ORDENADO),1,ordenado);

            tamanioArchivo(ordenado);

            posCero+=sizeof(STR_ORDENADO);
            fread(aux,sizeof(STR_ORDENADO),1,ordenado);
            printf("Posicion actuaaal: %d\n",ftell(ordenado));

            tamanioArchivo(ordenado);

            }
        else{
            fread(aux,sizeof(STR_ORDENADO),1,ordenado);


        }


    }




    fclose(ordenado);
    return 0;
}
