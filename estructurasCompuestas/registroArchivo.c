#include "registroArchivo.h"
#include "utilidades.h"

/// El usuario ingresa la cantidad de datos que quiera
void ingresarRegistros(){
    char opcion;
    stRegistroArchivo r;

    do{
        system("pause");
        r = ingresarUnRegistro();
        agregarRegistro(r);
        printf("\n\t\t ESC para salir ...  ");
        opcion = getch();
    }
    while(opcion!=27);
}
/// Se pide un dato al usuario y se retorna
stRegistroArchivo ingresarUnRegistro(){
    stRegistroArchivo r;

    printf("\n Apellido y Nombre............: ");
    gets(r.apeNom);
    fflush(stdin);
    printf("\n Legajo ......................: ");
    scanf("%d",&r.legajo);
    printf("\n ID Materia...................: ");
    scanf("%d",&r.idMateria);
    printf("\n Materia......................: ");
    gets(r.materia);
    fflush(stdin);
    printf("\n Nota.........................: ");
    scanf("%d",&r.nota);

    return r;
}
/// se guarda un dato en el archivo
void agregarRegistro(stRegistroArchivo r){
    FILE* pArchRegistro = fopen(arRegistro,"ab");
    if(pArchRegistro){
        fwrite(&r,sizeof(stRegistroArchivo),1,pArchRegistro);
        fclose(pArchRegistro);
    }
}
/// Se muestra un dato de tipo stRegistroArchivo
void mostrarUnRegistro(stRegistroArchivo r){
    printf("\n Legajo.....................: %d", r.legajo);
    printf("\n Nombre y Apellido..........: %s",r.apeNom);
    printf("\n ID Materia.................: %d",r.idMateria);
    printf("\n Materia....................: %s",r.materia);
    printf("\n Nota.......................: %d \n",r.nota);
    replicante('-',70);
}
/// Se recorre el archivo y usando la funcion mostrarUnRegistro() se muestran los datos del archivo
void mostrarRegistros(char archivo[]){
    stRegistroArchivo r;
    FILE* pArchRegistro = fopen(archivo,"rb");
    if(pArchRegistro){
        while(fread(&r,sizeof(stRegistroArchivo),1,pArchRegistro)>0){
            mostrarUnRegistro(r);
        }
    }
}

/// funcion que asigna en la variable recibida un nombre al azar
void getNombre(char n[]){
    char nombres[][20] = {"Amalia","Juan","Roberta","Antonio","Juana","Fernando","Fernanda","Anibal","Antonia","Roberto",
                           "Anastasia","Anastasio","Artura","Arturo","Maria","Mario","Tamara","Adolfo","Adolfa","Pedro","Alfredo",
                           "Alfreda","Mauro","Maura","Benicio","Benicia","Ildefonso","Ildefonsa","Cuchuflito","Cuchuflita",
                           "Remilgo"};

    strcpy(n,nombres[randomRango(0,sizeof(nombres)/(sizeof(char)*20))]);
}
/// funcion que asigna en la variable recibida un apellido al azar
void getApellido(char a[]){
    char apellidos[][20] = {"Gomez","Perez","Rodriguez","Latorre","Fernandez","Torquemada", "Marijuan", "Roca", "Mitre", "Rivadavia",
                            "San Martin", "Alvarez", "Comizo", "Borges", "Zama", "Recato", "Olvido", "Gil", "Trapero", "Restinga",
                            "De Antonio", "Ramirez", "Spinetta", "Cortez", "Gonzalez", "Andujar", "San Juan", "Bautista", "Anchorena", "Paso",
                            "Gaboto","Vega","Vargas","Lloret","Linares","Suarez","Sierra","Amenabar","Blanco","White","Black"};

    strcpy(a,apellidos[randomRango(0,sizeof(apellidos)/(sizeof(char)*20))]);
}

/// funcion que asigna en la variable recibida una materia al azar y retorna el id de materia
int getMateria(char m[]){
    char materias[][40] = {"Ingles I","Sistema de Procesamiento de Datos","Laboratorio de Computacion I","Matematica","Programacion I",
                            "Arquitectura y Sistemas Operativos", "Metodologia de la Investigacion", "Ingles II", "Laboratorio de Computacion II",
                            "Estadistica","Programacion II","Programacion III","Organizacion Empresarial","Organizacion Contable de la Empresa",
                            "Laboratorio de Computacion III","Elementos de Investigacion Operativa","Laboratorio de Computacion IV","Legislacion",
                            "Metodologia de Sistemas I","Administracion de Bases de Datos"};
    int idMateria = randomRango(0,sizeof(materias)/(sizeof(char)*40));
    //int idMateria = randomRango(0,21);
    strcpy(m,materias[idMateria]);

    return idMateria;
}

/// funcion que asigna en la variable recibida un apellido y un nombre concateandolos
void getApellidoYNombre(char an[]){
    //strcpy(an,"");
    an[0]='\0';
    char n[20];
    char a[20];
    getNombre(n);
    getApellido(a);
    strcat(an,a);
    strcat(an,", ");
    strcat(an,n);
}
/// Funcion que retorna un numero de legajo al azar
int getLegajo(){
    return rand()%70000+1;
}
/// Funcion que retorna una nota al azar
int getNota(){
    return rand()%10+1;
}
/// Funcion que genera un registro al azar y lo retorna
stRegistroArchivo cargoRegistroArchivoRandom(){
    stRegistroArchivo r;
    getApellidoYNombre(r.apeNom);
    r.idMateria=getMateria(r.materia);
    r.legajo=getLegajo();
    r.nota=getNota();
    return r;
}
/// funcion que guarda un dato de tipo stRegistroArchivo en el archivo especificado
void guardaRegistroArchivo(char archivo[], stRegistroArchivo r){
    FILE * pArch = fopen(archivo,"ab");
    if(pArch){
        fwrite(&r,sizeof(stRegistroArchivo),1,pArch);
        fclose(pArch);
    }
}
/// Funcion que llama a las funciones anteriores y genera y guarda en el archivo la cantidad de registros deseados
void generaArchivoRandom(int cantidad){
    stRegistroArchivo r;
    int i=0;
    printf("Generando archivo.");
    while(i<cantidad){
        (i % 400 == 0) ? printf("."):0;
        r = cargoRegistroArchivoRandom();
        guardaRegistroArchivo(arRegistro,r);
        i++;
    }
}
/// Funcion que cuenta la cantidad de registros en cualquier archivo, recibe el nombre de archivo y el sizeof del tipo de dato usado
int cuentaRegistros(char nombreArchivo[], int tamStruct){
    FILE* pArchi = fopen(nombreArchivo,"rb");
    int cantReg=0;
    if(pArchi){
        fseek(pArchi,0,SEEK_END);
        cantReg = ftell(pArchi)/tamStruct;
        fclose(pArchi);
    }
    return cantReg;
}
