//codigo de menu clave 2

/*codigo creado por: Ulises Edgardo Coreas Huezo
	
carnet: CH18030

fecha:28/11/2018*/
	
	
	//librerias
#include <iostream>
#include <windows.h>

	//cuerpo del programa
using namespace std;

//funcion para limpia la pantalla
void l(){
	system ("cls");
}

//funcion para detiene el programa
void p(){
	system ("pause");
}

//variables de las funciones utilizadas
void torre(); //variable para la funcion de las torres
void random();	//variable para la funcion de los numeros randoms



//Método  que me posiciona la flecha de la consola dadas 2 coordenadas.
	void gotoxy(int x,int y){ 
		//Variable Coordenada que guarda las coordenadas donde esta la flecha.
		COORD conCord;
		//cordenadas del eje x
		conCord.X=x;
		//cordenadas de eje y
		conCord.Y=y;
		
		//Metodo para posicionar el enuncuadi de la consola segun las coredenas especificadas
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),conCord); 
	}
	

int main()
{	


//comando para poner color en la consola
//8 significa el color del fondo, 0 significa el color de la letra
system("color 80");
//variable para regresar al menu
int opc;

//ciclo para la consola
do
{
	
//se le llama a la funcion para limpiar pantalla
	l();

//Imprime en pantalla las opciones que se puede seleccionar
cout<<"\n1. Torre de hanoi";
cout<<"\t2. Numeros random";
cout<<"\t0. u otra tecla para salir";

//Imprime la peticion de la opcion a seleccionar
cout<<"\n Ingrese opcion: ";
//adquiere el valor
cin>>opc;

// Estructura para tomar entrar a la opcion seleccionada
switch(opc)
{
	//Entra a la funcion de la torre
	case 1: torre();
	
 	break;
 	 
 	//Entra a la funcion de los numeros
 	case 2: random();
 	break;
 	
 	//Entra a la funcion de la salida
 	case 0: exit(1);
	
	/*en el caso que seleccione una opcion que no se encuentre
	se activara el los siguientes comandos*/
	
	default: 
	//se le llama a la funcion para limpiar pantalla	
	l();
	
	//se imprime en la pantalla
	cout<<"Opcion no valida!!"<<endl; 
	cout<<"Intente con otra opcion"<<endl;
	
	//se le llama a la funcion para detener la pantalla
	p();
	break;
 	
}
	//Returna a la seleccion de las opcciones
}while(opc);

return 0;
}

//se activa la funcion de la torre
void torre()
{
	
	//variables utilizadas
int posi;//representa la posicion para el disco
int posi2;//representa la posicion para el disco
int n;//representa la cantidad de disco
int i; //variable para el ciclo for
int j;//variable para el ciclo for
int desde; //se usa para indicar desde donde se movera el disco
int hacia;//se usa para indicar hasta dondes se movera el disco
int con; //almacena la cantidad de movimientos utilizados
int tam;//representa la posicion de los discos inicialmente
int tamdisco;//representa la posicion de los discos inicialmente
int espacios;//se usa para generar espacios en cada torre
int k; //se usa para el ciclo en la posicion de los dicos inicialmente
int matriz[100][3];//se usa para generar el rando de la imagen de la torre

char si;//se usa para seguir jugando
char fondo = 177;//se usa para el fundo al rededor de los discos y torres

	//comando para poner color en la consola
	//8 significa el color del fondo, 0 significa el color de la letra
	system("color 80");
  
  	//se le llama a la funcion para limpiar pantalla
    l();
    //se imprime en la pantalla
    gotoxy(15,8);//Indica la posicion de lo que se imprimira.
    cout<<"Las Torres de Hanoi"<<endl;
    gotoxy(10,12);//Indica la posicion de lo que se imprimira.
    cout<<"Digite la cantidad de discos: ";
    //optiene valor
    cin>>n;
 	//se le llama a la funcion para limpiar pantalla
	l();
	
    //ciclo para verificar si la cantidad de discos esta dentro del rango
    while(n>13||n<3)
    {
    	//se le llama a la funcion para limpiar pantalla
        l();
        //se imprime en la pantalla
        cout<<"Tiene que jugar minimo con tres discos y maximo con 13"<<endl;
		cout<<"Digite la cantidad de discos:";
		//optiene valor
        cin>>n;
    }
    
    //comandos para generar fondo y generar la posicion inicial de los discos
    tam=n+(n-1);
    //ciclo para generar el fondo
    for(i=1;i<=((tam*3)+3)+1;i++)
        cout<<fondo;
    cout<<endl<<fondo;
    //ciclo para generar los discos segon la cantidad seleccionada
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {	
        	//asignando la posicion de los discos
              if(j==0)
                  matriz[i][j]=i+1;
              else
                  matriz[i][j]=0;
                  //asignando la posicion del fondo
              for(k=1;k<=tam;k++)
              {		//si hay espacio se coloca el fondo
                   tamdisco=matriz[i][j]+(matriz[i][j]-1);
                   espacios=(tam-tamdisco)/2;
                   if(matriz[i][j]==0)
                       cout<<fondo;    
                   else
                   {
                   		//si no hay discos se genera el fondo
                       if(k<=espacios||k>(tam-espacios))
                           cout<<fondo;
                        //si debe ir el disco se genera el disco
                       else
                       //se imprime en la pantalla
                           cout<<"=";
                   }
			  }
              cout<<fondo;
        }
        cout<<endl<<fondo;
    }
// ciclo para que aparescan las torres desde el inicio hasta el final del juego
    for(i=1;i<=((tam*3));i++)
    {	//se verifica la posicion de la torre 3
        if(i==n-1)
            cout<<"T1";
        //se verifica la posicion de la torre 3
        else if(i==((n*2)+n)-2)
            cout<<"T2";
        //se verifica la posicion de la torre 3
        else if(i==(((n*2)+n)-3)+n*2)
            cout<<"T3";
        //se genera el fondo si hay disco ni torre
        else
            cout<<fondo;
    }
    cout<<endl;
    //si todo esta generado se llama la funcion para poder mover los discos
    for(i=1;i<=((tam*3)+4);i++)
        cout<<fondo;
    	
	cout<<"Las Torres de Hanoi"<<endl;
    while(matriz[0][1]!=1&&matriz[0][2]!=1)
    {
    	//se imprime en la pantalla
    cout<<"Lleva "<<con++<<" movimientos\n";
    cout<<"REGLA: No puede colocar un disco grande encima de uno pequeno"<<endl;
    do{
    	//se imprime en la pantalla la peticion desde donde decea mover el disco
        cout<<"Desde cual torre (T) desea mover el disco: ";
        cin>>desde;
        if(matriz[n-1][desde-1]==0){
        	//se imprime en la pantalla
		cout<<"No hay disco en esa torre"<<endl;
		}
    }
    while(matriz[n-1][desde-1]==0);
    //se imprime en la pantalla la peticion hacia donde decea mover el disco
    cout<<"Hacia cual torre (T) desea mover el disco: ";
    cin>>hacia;
    //comandos para poder mover los discos
    desde--;
    hacia--;
    //se realiza la peticion
    for(i=0;i<n;i++)
    {	//hace la funcion de donde se movera
        if(matriz[i][desde]!=0)
        {
        posi=matriz[i][desde];
        posi2=i;        
        i=n;
        }
    }
    //realiza la peticion
    for(i=n-1;i>=0;i--)
    {	//hace la funcnio de hatas donde se movera
        if(matriz[i][hacia]==0)
        {	//se coloca el disco en la posicion pedida
            if(matriz[i+1][hacia]>posi||i==(n-1))
            {
            matriz[i][hacia]=posi;
            matriz[posi2][desde]=0;
            }  			
        }
    }
    //se le llama a la funcion para limpiar pantalla
	l();
	//comando para generar el fondo donde no este ni un disco ni una torre
    for(i=1;i<=((tam*3)+3)+1;i++)
        cout<<fondo;
    cout<<endl<<fondo;
    //ciclo para generar el fondo
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {	//comando para generarse en los espacios sin torres y sin discos
              for(k=1;k<=tam;k++)
              {		//se verifica su hay algun disco o torre
                   tamdisco=matriz[i][j]+(matriz[i][j]-1);
                   espacios=(tam-tamdisco)/2;
                   if(matriz[i][j]==0)
                      cout<<fondo;
                    //si no hay nada se activa
                   else
                   {
                   		//se coloca el fondo
                       if(k<=espacios||k>(tam-espacios))
                           cout<<fondo;
                       else
                       //se imprime en la pantalla
                           cout<<"=";
                   }
              }
              cout<<fondo;
        }
        cout<<endl<<fondo;
    }
    //se coloca las torres en cada movimiento
    for(i=1;i<=((tam*3));i++)
    {
    	//se verifica la posicion de la torre 3
        if(i==n-1)
            cout<<"T1";
		//se verifica la posicion de la torre 3
        else if(i==((n*2)+n)-2)
            cout<<"T2";
        //se verifica la posicion de la torre 3
        else if(i==(((n*2)+n)-3)+n*2)
            cout<<"T3";
        //si no hay torre se genera el fondo
        else
            cout<<fondo;
    }
    
    cout<<endl;
    for(i=1;i<=((tam*3)+4);i++)
        cout<<fondo;
    }
    //sonido de bits
    Beep(687,200);
	Beep(534,200);
	Beep(754,200);  
	Beep(224,200);
	Beep(224,200);
    //se imprime en la pantalla con los movimientos usados
    gotoxy(15,10);//Indica la posicion de lo que se imprimira.
    cout<<"Felicitaciones acaba de ganar en "<<con<<" movimientos"<<endl;
	
    //se imprime en la pantalla la peticion
	cout<<"si desea volver a jugar dijite S "<<endl;
	cout<<"si no desea volver a jugar dijite cualquier otra tecla: "<<endl;
	//optiene valor
    cin>>si;
    con=0;
    //si dijita s o S seguira jugando
    if(si=='s'||si=='S'){
	
        torre();
	}
	//si dijita cualquier otra letra se regresara al menu
    else{
    	
    	
    //se le llama a la funcion para limpiar pantalla
	l();
 gotoxy(15,8);//Indica la posicion de lo que se imprimira.
 cout<<" gracias por jugar "<<" (^w^) ";
 gotoxy(15,15);//Indica la posicion de lo que se imprimira.
 cout<<" vuelva pronto "<<endl;
 
 p();

 getchar();
}
    
}

//se activa la funcion de los numeros randoms
void random()
{
	//variables utilizadas
	int i; //variable para el ciclo for
	int j;//variable para el ciclo for
	int vector [101];//matriz para saber cuantos valores se almacenara
	int temp;//ayuda para ordenar los datos

	//comando para poner color en la consola
	//8 significa el color del fondo, 0 significa el color de la letra
	system("color 80");
	
	//se le llama a la funcion para limpiar pantalla
	l();
	
	//se imprime en la pantalla
	cout<<"numeros randoms generados: "<<endl;
	for (i=0;i<=100; i++)
	{
		//optiene valor aleatoriamente
		vector[i]= rand()%100;
	 //se imprime en pantalla los resultados generados
		cout<<"("<<vector[i]<<") ";
	}
	//saltos de linea
	cout<<endl;
	cout<<endl;
	
	//se imprime en la pantalla
	cout<<"numeros randoms: "<<endl;
	//metodo de la burbuja
	//ciclo para odenar los valores
	for(i=1; i<=100; i++)
	{
		for(j=i+1; j<=100; j++)
		{
			//odena los valores segun la posicion que le correspinda
			if(vector [j] < vector[i])
			{
				//comando de ordenamiento
				temp=vector[j];
				vector[j]=vector[i];
				vector[i]=vector[j];
				vector[i]=temp;
			}
			
		}
	}
	
	//ciclo para imprimir todos los resultados
	for(i=1; i<=100; i++)
	{
		//se imprime en la pantalla el resultado en orden
		cout<<i<<") "<<vector[i];
		cout<<endl;
	}

p();
    
}	

