#include<iostream>
using namespace std;
//DEFINIMOS LAS CONSTANTES UTILIZADAS EN EL PROYECTO
int const filas=4;
int const columnas=5;

//CREACION DE FUNCIONES Y PREOCEDIMIENTOS

	//LLENADO DEL VECTOR PARA LOS NOMBRES DE LOS PUERTOS PERTECENE AL PUNTO 1
	void llenarVectorNombresPuertos(int n,string vector[]);
	void ImpresionVectorNombresPuertos(int n,string vector[],int npuertos);


	//LIMPIEZA E IMPRESION DE LAS MATRICES PERTENECE AL PUNTO 2
	void imprimirMatrizBooleana(bool matriz[filas][columnas]);
	void limpiarMatriz(bool disponibilidad[filas][columnas],int pesos[filas][columnas]);
	void imprimirMatrizTexto(string matriz[filas][columnas]);
	void imprimirMatrizEnteros(int matriz[filas][columnas]);
	
	//PROCEDIMIENTOS Y FUNCIONES EMPLEADOS PARA EL PUNTO 3 PARA PREGUNTAR POR CADA PUERTO
	void mostrarDisponibles(bool disponibilidad[filas][columnas]);
	float calcularOcupacion(bool disponibilidad[filas][columnas]);
	float valorRecaudadoPuerto(string puertoCarga[filas][columnas],string nombrePuerto);

	//Planteamiento para procedimientos 
		 //cantidad de contenedores
		 		void imprimirCantidadContenedores(bool disponibilidad[filas][columnas]);
		 		
		 //Ordenamiento de nombre de puerto y cantidad de contenedores ingresados ordenados de mayor a menor
		 		 void burbuja(int dimension ,string nombres[],int cantidadContenedores[]);
		
		//c.	Listado de las marcas de contenedores que van en la zona económica.
				void listadoMarcasEconomica(string marcas[filas][columnas],bool disponibilidad[filas][columnas]);
		
		//d.	Listado de las marcas de contenedores que van en la zona premium.
				void listadoMarcasPremium(string marcas[filas][columnas],bool disponibilidad[filas][columnas]);
				
		//e.	Dado el nombre de una empresa, determinar los contenedores que lleva por zona y el valor que debe pagar por los contenedores		
				void reporteMarca(string marcas[filas][columnas],string marcaBuscada,bool disponibilidad[filas][columnas]);
			
	//Planteamiento para funciones
		//a.	Promedio de peso de los contenedores que ocupan una celda (tener en cuenta solamente las celdas ocupadas).
				float promedioPeso(int pesos[filas][columnas], bool disponibilidad[filas][columnas]);
		
			//b.	Determinar la fila donde hay más carga
				int filaPesada(int pesos[filas][columnas],int dimension, float vector[]);
				
			//c.	Determinar la columna donde hay menos carga	
					int columnaliviana (int pesos[filas][columnas]);
				
				
			//d.	Dado el tipo de un artículo determinar la cantidad de contenedores de dicha clase.	
				int cantidadTipoArticulo(string tipoArticulo[filas][columnas], string tipoArticuloBuscado);
				
				//e.	Dado el nombre de un puerto de origen, determinar el promedio de peso que se ingresó en ese lugar
						float promedioPesoPuerto(int pesos[filas][columnas],string puertoCarga[filas][columnas],string puertoBuscado);
						
				//f.nombre de la empresa que posee el contenedor con mas peso
				string nombreEmpresaContenedorPesado(int pesos[filas][columnas], string marcas[filas][columnas]);	
				
				////g.	Peso del contenedor más liviano.
					int contenedorLiviano(int pesos[filas][columnas]);
			
		
		
//SOLICITUD DE DATOS DESDE LA MAIN
int main(){
//PASOS A REALIZAR.
//-------------------------------------------------------------------------------------------------

//1.    PREGUNTAR POR LA CANTIDAD DE PUERTOS Y SUS NOMBRES (LLENANDO UN VECTOR).

	cout<<"Trabajo Presentado Por Victor Manuel Garcia Castaneda "<<endl;
	cout<<endl;
	cout<<"bienvenidos a mi primer proyecto de logica de programacion "<<endl;
	cout<<endl;
	
	//creamos la variable para preguntar los puertos sirviendome de dimension.
	int cantidadPuertos=0;
	int validacionPuertos=0;
	
	
	//solicitamos la cantidad de puertos para definir el vector con los nombres de los puertos
	cout<<"ingrese la cantidad de puertos "<<endl;
	cin>>cantidadPuertos;
	
	
	cout<<endl;
	
	//Utilizamos un separador que me indique como donde sucede cada proceso uno para los datos, llenados y reportes solicitados
	cout<<"**********************************************************************"<<endl;
	cout<<"------------------------------------------------------"<<endl;
	
	//definimos el vector con los nombres de los puertos y de la cantidad de contenedores
	string nombresPuertos[cantidadPuertos];
	int cantidadContenedores[cantidadPuertos];

	//hacemos llamado al procedimiento para llenar el vector nombres puertos y su impresion
	llenarVectorNombresPuertos(cantidadPuertos,nombresPuertos);
	ImpresionVectorNombresPuertos(cantidadPuertos,nombresPuertos,cantidadPuertos);
	
	
//------------------------------------------------------------------------------------------------		
//2.	CREAR LAS MATRICES Y LIMPIARLAS
	
	//Definimos las matrices a utilizar.
	bool disponibilidad[filas][columnas];
	string marcas[filas][columnas];
	string puertoCarga[filas][columnas];
	string tipoArticulo[filas][columnas];
	int pesos[filas][columnas];
	
	//Limpiamos los tipos de matrices especialmente las de tipo entero y boleano.
	limpiarMatriz(disponibilidad,pesos);
	
	//Imprimimos las matrices para asegurar que todo se encuentre en orden.
	
	/*
	cout<<" a continuacion encontrara todas las matrices listas para usarse "<<endl;
	
	cout<<"Matriz disponibilidad"<<endl;
	imprimirMatrizBooleana(disponibilidad);
	
	cout<<"Matriz marcas"<<endl;
	imprimirMatrizTexto(marcas);
	
	cout<<"Matriz puerto carga"<<endl;
	imprimirMatrizTexto(puertoCarga);
	
	cout<<"Matriz tipo articulo"<<endl;
	imprimirMatrizTexto(tipoArticulo);
	
	cout<<"Matriz pesos"<<endl;
	imprimirMatrizEnteros(pesos);
	
	*/
	
// 3.	POR CADA PUERTO REALIZAR---->FOR

	//definimos algunas variables a utilizar para el punto c.
	int coordenadaFila=-1;
	int coordenadaColumna=-1;
	int contadorCoordenadaValida=0;
	int numerador=1;
	int conteoContenedorVect=1;
	//creamos la respuesta para determinar el procentaje y el valor recaudado del puerto actual
		float respuestaPorcentaje=0.0;
		float respuestaValorRecaudado=0.0;
	int iteracion=1;
	string puertoActual="";
	
	//variable para hacer una validacion del peso para comprobar que sean positivos
	int validacionPeso=0;
	
	

	//Planteamiento del ciclo for para preguntar por cada puerto.
		for(int i=0;i<cantidadPuertos;i++){
			
			//a.	Pregunta número de contenedores a ingresar en ese puerto
			cout<<endl;
			cout<<"bienvenido al puerto "<<nombresPuertos[i]<<endl;
			cout<<"ingrese el numero de contenedores para el puerto "<<nombresPuertos[i]<<endl;
			cin>>cantidadContenedores[i];
			cout<<endl;
			
			

			
			//b.	Reportar cuales casillas están disponibles
			mostrarDisponibles(disponibilidad);
		
			
			//c.	Preguntar las coordenadas del nuevo contenedor (VIDEO COMPARTIDO AL CORREO)
					do{
						cout<<"llenado del contenedor "<<numerador<<" para el puerto "<<nombresPuertos[i]<<endl;
						cout<<endl;
						
						cout<<"Ingrese coordenada Fila del nuevo contenedor "<<numerador<<" para el puerto "<<nombresPuertos[i]<<endl;
						cin>>coordenadaFila;
						
						cout<<"ingrese coordenada columna del nuevo contenedor  "<<numerador<<" para el puerto "<<nombresPuertos[i]<<endl;
						cin>>coordenadaColumna;
						cout<<endl;
						
						/*verificar que las filas y las columnas son correcta. Es decir que existen las posiciones en la matriz
						Ademas de ello se esta verificando si la coordenada en la fila existe tiene que ser 0 o mas pero no puede 
						ser mas grande que la cantidad de filas que se establecio desde el prinicipio lo mismo pasa que las columnas.
						Garantizando que la coordenada de la columna tiene que ser mas grande que 0 
						*/
					
						//i.V-erificacion de que la coordenada ingresada pertenece a la matriz
						if(coordenadaFila>=0 && coordenadaFila<filas /* SEPARADOR PARA FILAS Y COLUMNAS */ && coordenadaColumna>=0 && coordenadaColumna<columnas){
								/*
								if(disponibilidad[coordenadaFila][coordenadaColumna]==1) ' 
								Preguntar marca, peso, puerto no se pregunta porque el algoritmo lo sabe en ese momento,
								preguntar tipo articulo, modificar la disponibilidad.
								*/
								
									//Se realiza verificacion de que la coordenada ingresada esta disponible para realizarle sus preguntas
									if(disponibilidad[coordenadaFila][coordenadaColumna]==1){
										
										//como se cumple la condicion pasamos a realizar las preguntas 
										cout<<"la coordenada esta disponible o es valida. Por lo tanto le solicitare unos datos de vital importancia para el contenedor "<<numerador<<endl;
										cout<<"----------------------------------------------->>"<<endl;
										cout<<endl;
										
										//se usa un contador para realizar el ciclo while.
										contadorCoordenadaValida++;
												
										//----------------------------------------------------------------------
										
										//Preguntamos marca del contenedor
										cout<<"ingrese marca del contenedor "<<numerador<<" para el puerto "<<nombresPuertos[i]<<endl;
										cin>>marcas[coordenadaFila][coordenadaColumna];
										
										
											
										//-----------------------------------------------------------------------
											
										//preguntamos el peso del contenedor realizando una validacion
										do{
										cout<<"Ingrese peso del contenedor "<<numerador<<" para el puerto "<<nombresPuertos[i]<<endl;
										cin>>validacionPeso;
													
												if(validacionPeso<0){
													cout<<"ingreso un valor invalido es decir negativo vuelvalo a llenar "<<endl;
													cout<<endl;
												}else if(validacionPeso==0){
													cout<<"esta diciendo que el contenedor no pesa nada esta afirmacion es  incorrecta debe de tener un peso vuelva a llenar "<<endl;
													cout<<endl;
												}
												 
										}while(validacionPeso<=0);
										pesos[coordenadaFila][coordenadaColumna]=validacionPeso;
										cout<<endl;
										cout<<endl;
										
				
										//------------------------------------------------------------------------
										
										//No preguntamos el puerto porque el sistema ya lo conoce
										puertoCarga[coordenadaFila][coordenadaColumna]=nombresPuertos[i];
										
										
												
										//---------------------------------------------------------------------------
										
										//Preguntamos el tipo de articulo
										cout<<"Ingrese el tipo de articulo del contenedor "<<numerador<<" para el puerto "<<nombresPuertos[i]<<" solo la letra sea A, B O C en MAYUSCULA "<<endl;
										cout<<endl;
										cout<<"Tiene las siguientes opciones.Tipo A: Alimentos. Tipo B: Dispositivos electronicos. Tipo C: Ropa y demas textiles "<<endl;
										cin>>tipoArticulo[coordenadaFila][coordenadaColumna];
										
											
										//Se utiliza otro contador para realizar la numeracion del contenedor que me esten ingresando
										numerador++;
										
										//modificamos matriz de disponibilidad ya que se encuentra ocupada
										disponibilidad[coordenadaFila][coordenadaColumna]=0;
										cout<<"contenedor ingresado correctamente "<<endl;
										cout<<endl;
											//damos una informacion adicional
											cout<<"informacion adiicional acerca de los contenedores "<<endl;
											cout<<endl;
											cout<<" para el contenedor "<<conteoContenedorVect<<" del puerto "<<puertoCarga[coordenadaFila][coordenadaColumna]<<endl;
											conteoContenedorVect++;
											cout<<endl;
											cout<<"la Empresa "<<marcas[coordenadaFila][coordenadaColumna]<<" ha elegido la celda "<<"["<<coordenadaFila<<","<<coordenadaColumna<<"],"<<"lleva un contenedor de "<<pesos[coordenadaFila][coordenadaColumna]<<" kilos,"
											<<"fue ingresado en el puerto "<<puertoCarga[coordenadaFila][coordenadaColumna]<<" y el tipo de articulo que lleva dentro es de clase  "<<tipoArticulo[coordenadaFila][coordenadaColumna]<<endl;
											cout<<endl;	
										
										cout<<endl;
										cout<<"-------------------------------------------------------->>"<<endl;
										cout<<endl;
										
									
										
										
										
										//Si la condicion no se cumple entonces debemos de volver a preguntar.
				
									}else{
										//cout<<"la posicion esta ocupada por lo tanto introduzca una valida !sea honesto ¡ "<<endl;
										cout<<endl;
										mostrarDisponibles(disponibilidad);
										cout<<"Posicion ocupada "<<endl;
										cout<<"¿Profe qué esta tratando de hacer?. Vuelvalo a intentar "<<endl;
										cout<<"------------------------------------------------------->>"<<endl;
										cout<<"Vamos de nuevo "<<endl;
										cout<<endl;
									}
									
						//Si no se cumple que el valor ingresado pertenezca a una dimension de la matriz entonces 		
						}else{
							cout<<"La posicion no existe en la matriz ingrese de nuevo el valor para las coordenadas del nuevo contenedor "<<endl;
							cout<<"------------------------------------------->>"<<endl;
							cout<<endl;
							
						}
						
						
				}while(contadorCoordenadaValida<cantidadContenedores[i] );
				cout<<endl;
				//datos para cada puerto 
					//llamos al porcentaje y lo mostramos
						respuestaPorcentaje=calcularOcupacion(disponibilidad);
						cout<<"el porcentaje de ocupacion actual del barco para el puerto "<<nombresPuertos[i]<<" es "<<respuestaPorcentaje<<" % "<<endl;
						cout<<endl;
					
					//calculo del valor recaudado
						
						puertoActual=nombresPuertos[i];	
						respuestaValorRecaudado=valorRecaudadoPuerto(puertoCarga,puertoActual);
						cout<<" el valor recaudado para el puerto actual "<<nombresPuertos[i]<<" y es "<<respuestaValorRecaudado<<" USD "<<endl;
						cout<<endl;
						
				//---------------------------------------
				numerador=1;
				validacionPuertos++;
				//se reinicia porque comenzara con otro puerto
				contadorCoordenadaValida=0;
				cout<<endl;
				
				
	//terminacion for 						    
	}
	
//REPORTES
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	//datos para los ejercicio que debemos de pedir valores.Nombre de una empresa para determinar los contenedores que lleva por zona y el valor que de pagar 
	
		
	if(validacionPuertos==cantidadPuertos){
		cout<<"***********************************************"<<endl;
		cout<<endl;
		cout<<" AHORA PASAREMOS A LOS REPORTES "<<endl;
		//para saber la cantidad de contenedores en el barco
			imprimirCantidadContenedores(disponibilidad);
			cout<<endl;
			cout<<"----------------------------------------------"<<endl;
			cout<<endl;
			
		//para realizar el ordenamiento burbuja
			burbuja(cantidadPuertos,nombresPuertos,cantidadContenedores);
			cout<<endl;
			cout<<"----------------------------------------------"<<endl;
			cout<<endl;
		
		//listado de las amrcas que van en la zona economica 
			 listadoMarcasEconomica(marcas,disponibilidad);
			cout<<endl;
			cout<<"----------------------------------------------"<<endl;
			cout<<endl;
			
		//listado de las marcas qeu van en la zona premium
			listadoMarcasPremium(marcas,disponibilidad);
				cout<<endl;
				cout<<"----------------------------------------------"<<endl;
				cout<<endl;
				
		//datos para los ejercicio que debemos de pedir valores.Nombre de una empresa para determinar los contenedores que lleva por zona y el valor que de pagar
			string nombreEmpresa="";
			cout<<"ingrese el nombre de una empresa a la cual le quiera determinar los contenedores que lleva por zona y el valor que debe pagar por los contenedores"<<endl;
			cin>>nombreEmpresa;
			cout<<endl;
			reporteMarca(marcas,nombreEmpresa,disponibilidad);
			cout<<endl;
			cout<<"----------------------------------------------"<<endl;
			cout<<endl;
			
			
	//FUNCIONES		
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////			
		//promedio peso de los contenedores que ocupan una celda
			float promedioPesoContenedoresCelda=0.0;
			promedioPesoContenedoresCelda=promedioPeso(pesos,disponibilidad);
			cout<<"el promedio peso de los contenedores que ocupan una celda es "<<promedioPesoContenedoresCelda<<endl;
			cout<<endl;
			cout<<"----------------------------------------------"<<endl;
			cout<<endl;
		//-------------------------------------------
			
		//determinar la fila deonde hay mas cargas
			int masCargaFila=0;
			float vector[filas];
		 	masCargaFila=filaPesada(pesos,filas,vector);
		 	cout<<"la fila donde hay mas carga es "<<masCargaFila<<endl;
			cout<<endl;
			cout<<"----------------------------------------------"<<endl;
			cout<<endl;
			
			//-------------------------------------------
				
		//determinar la columna donde hay menos carga 
		//c.	Determinar la columna donde hay menos carga	
			int  menosColumna=0;
			menosColumna=columnaliviana(pesos);
			cout<<"la columna  donde hay menos carga es "<<menosColumna<<endl;
			cout<<endl;
			cout<<"----------------------------------------------"<<endl;
			cout<<endl;
					
					
			//-------------------------------------------
		//d.	Dado el tipo de un artículo determinar la cantidad de contenedores de dicha clase.
		string nombreTipoArticulo="";
		int respuestaClaseArt=0;
			cout<<"ingrese el tipo de articulo al cual le quiere determinar la cantidad de contenedores de dicha clase "<<endl;
			cin>>nombreTipoArticulo;
			
			cout<<endl;
			respuestaClaseArt=cantidadTipoArticulo(tipoArticulo,nombreTipoArticulo);
			cout<<"la cantidad de contenedores del tipo articulo buscado que es "<<nombreTipoArticulo<<"es"<<respuestaClaseArt<<endl;
			cout<<endl;
			cout<<"----------------------------------------------"<<endl;
			cout<<endl;
		
		//e.	Dado el nombre de un puerto de origen, determinar el promedio de peso que se ingresó en ese lugar
		
			string puertoBuscado="";
			cout<<"ingrese el nombre del  a la cual le quiera determinar el promedio del peso que se ingreso en ese lugar"<<endl;
			cin>>puertoBuscado;
			
			cout<<endl;
			float respuesta1=0;
			respuesta1=promedioPesoPuerto(pesos,puertoCarga,puertoBuscado);
			cout<<"el promedio de peso que se ingreso en ese lugar es de "<<respuesta1<<endl;
			cout<<endl;
			cout<<"----------------------------------------------"<<endl;
			cout<<endl;
			
		//f.empresa con mas peso
		 string respuesta2="";
		 respuesta2=nombreEmpresaContenedorPesado(pesos,marcas);
		 cout<<"el nombre de la empresa con el contenedor con mas peso es "<<respuesta2<<endl;
	
		//g.g.	Peso del contenedor más liviano.
		int respuesta3=0;
		respuesta3=contenedorLiviano(pesos);
		cout<<"el pesod el contenedor mas liviano es"<<respuesta3<<endl;
		//-------------------------------------------------------------------------------------------------------------------------------------------------------------
		cout<<"*********************************************************************************************"<<endl;
		cout<<"se ha terminado con la parte de llenado e impresion de reportes a continuacion se mostrara como quedan las matrices al finalizar el proceso "<<endl;
		cout<<endl;
	
		//Imprimimos las matrices para asegurar que todo se encuentre en orden.
			cout<<"Matriz disponibilidad"<<endl;
			imprimirMatrizBooleana(disponibilidad);
			cout<<endl;
			
			cout<<"Matriz marcas"<<endl;
			imprimirMatrizTexto(marcas);
			cout<<endl;
			
			cout<<"Matriz puerto carga"<<endl;
			imprimirMatrizTexto(puertoCarga);
			cout<<endl;
				
			cout<<"Matriz tipo articulo"<<endl;
			imprimirMatrizTexto(tipoArticulo);
			cout<<endl;
				
			cout<<"Matriz pesos"<<endl;
			imprimirMatrizEnteros(pesos);
			cout<<endl;
	
		cout<<"***********************************************"<<endl;
		cout<<endl;
	}else{
		cout<<" no se ha terminado la parte de llenado "<<endl;
	}
	
	
	
	
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//APARTADO PARA FUNCIONES, PROCEDIMIENTOS QUE SE NECESITE EN LA REALIZACION DEL PROYECTO.

////////////////////////////////////////////////////////////////////////////////////////////
/*   
	1.PREGUNTAR POR LA CANTIDAD DE PUERTOS Y SUS NOMBRES LLENANDO UN VECTOR
*/

	void llenarVectorNombresPuertos(int n,string vector[]){
		cout<<"A continuacion comenzara con el procedimiento para los nombres de los puertos para el barco guiarse "<<endl;
		cout<<endl;
		for(int i=0;i<n;i++){
			cout<<"Ingrese el nombre del puerto "<<i<<endl;
			cin>>vector[i];			
		}
		cout<<endl;
		cout<<"---------------------------------------------------------------->>"<<endl;
		

	}
	
	void ImpresionVectorNombresPuertos(int n,string vector[],int npuertos){
	cout<<"los puertos ingresados son "<<npuertos<<endl;
	cout<<endl;
		for(int i=0;i<n;i++){
			cout<<"el puerto "<<vector[i]<<endl;		
		}
		cout<<endl;
		cout<<"---------------------------------------------------------------->>"<<endl;

	}

////////////////////////////////////////////////////////////////////////////////////////////
/*   
	2.	CREAR LAS MATRICES Y LIMPIARLAS
	
	PROCEDIMIENTOS
*/
//APARTADO DE LIMPIEZA DE MATRIZ DE DISPONIBILIDAD Y DE PESOS
	void limpiarMatriz(bool disponibilidad[filas][columnas],int pesos[filas][columnas]){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				disponibilidad[i][j]=1;	
				pesos[i][j]=0;
			}
		}
	}

//   APARTADO DE LAS IMPRESIONES

	//    Impresion de la matriz de boleanos es decir la de disponibilidad
	void imprimirMatrizBooleana(bool matriz[filas][columnas]){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				cout<<matriz[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	
	//   Procedimiento para imprimir matrices de tipo string  que puede ser utilizado tanto para la matriz de marca, puerto carga y tipo de articulo.
	void imprimirMatrizTexto(string matriz[filas][columnas]){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				cout<<matriz[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	//  Procedimiento para realizar la impresion de las matrices de tipo entero
	void imprimirMatrizEnteros(int matriz[filas][columnas]){
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				cout<<matriz[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	



////////////////////////////////////////////////////////////////////////////////////////////
/*   
	3.LAS PREGUNTAS A REALIZAR POR CADA PUERTO
*/

//a.	Pregunta número de contenedores a ingresar en ese puerto

//b.	Reportar cuales casillas están disponibles
	void mostrarDisponibles(bool disponibilidad[filas][columnas]){
		cout<<"A continuacion se mostraran las casillas o celdas que se encuentran disponibles para su eleccion "<<endl;
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				if(disponibilidad[i][j]==1){
					//cout<<i<<","<<j<<endl;
					cout<<i<<","<<j<<endl;
				}
			}
	
		}
	}
//d.	Calcular porcentaje de ocupación del barco
	float calcularOcupacion(bool disponibilidad[filas][columnas]){
		//definimos el contador, la cantidad total y el porcentaje 
		int contadorOcupacion=0;
		int operacionDimension=0;
		operacionDimension=filas*columnas;
		float porcentajeOcupacion=0.0;
		
		//recorremos la matriz para determinar la cantidad de celdas ocupadas 
			for(int i=0;i<filas;i++){
					for(int j=0;j<columnas;j++){
				if(disponibilidad[i][j]==0){
					
					contadorOcupacion++;
				}
			}
		}
		cout<<endl;
		
		porcentajeOcupacion=(contadorOcupacion*100)/operacionDimension;
		
	return porcentajeOcupacion;	
}

//e.	Calcular el valor recaudado 
	float valorRecaudadoPuerto(string puertoCarga[filas][columnas],string nombrePuerto){
		//definimos un acumulador que guardara el valor para este puerto 
		float acumuladorMoney=0.0;
			//planteamos la condicion para determinar de que lo que hay en puerto carga pertecene como tal al puerto al que queremos encontrar el valor recaudado. Recorremos la matriz 
			for(int i=0;i<filas;i++){
					for(int j=0;j<columnas;j++){
						//despues de terminar el puerto acual se plantea analizar 
						if(puertoCarga[i][j]==nombrePuerto){
								
									//definimos la condicion para zona premium
									if((i>0 && i<filas-1 && j>0 && j<columnas-1)){
										
										acumuladorMoney=acumuladorMoney+300;	
									}else{
									//quiere decir que se encuentra en la zona economica 
			
								    	acumuladorMoney=acumuladorMoney+100;
				
									}
				}
			}
		}
		return acumuladorMoney;
	}

/////////////////////////////////////////////////////////////////////////////
/*
Reportes Procedimientos 
*/
	//a.	Cantidad de contenedores 
		void imprimirCantidadContenedores(bool disponibilidad[filas][columnas]){
			int contador=0;
			//recorremos la matriz y verificamos la celda ocupada y si es asi simplemente la contamos  
			for(int i=0;i<filas;i++){
				for(int j=0;j<columnas;j++){
					if(disponibilidad[i][j]==0){
						contador=contador+1;
					}
				}
			}
			cout<<"La cantidad de contenedores en el barco es "<<contador<<endl;
			cout<<endl;
	}
	
	//b.	Reporte de nombre de puerto y cantidad de contenedores ingresados ordenados de mayor a menor
	void burbuja(int dimension ,string nombres[],int cantidadContenedores[]){
		cout<<"Reporte nombre de puerto con la cantidad de contenedores ordenados de menor a mayor "<<endl;
		for(int i=0;i<dimension;i++){
			for(int j=0;j<dimension;j++){
				if(cantidadContenedores[i]>cantidadContenedores[j]){
					float auxTiempos=cantidadContenedores[i];
					cantidadContenedores[i]=cantidadContenedores[j];
					cantidadContenedores[j]=auxTiempos;
		
					string auxNombre=nombres[i];
					nombres[i]=nombres[j];
					nombres[j]=auxNombre;
					
				}
			}
		}
		cout<<"ordenamiento burbuja de mayor a menor "<<endl;
		for(int i=0;i<dimension;i++){
			cout<<nombres[i]<<" --> "<<cantidadContenedores[i]<<endl;
		}
		cout<<endl;	
	}
	
	//c.	Listado de las marcas de contenedores que van en la zona económica
	void listadoMarcasEconomica(string marcas[filas][columnas],bool disponibilidad[filas][columnas]){
		int economica=0;
		//debemos de recorrer la matriz para realizar el condicional e ir imprimiendo.
		  cout << "\tLas marcas que tiene los contenedores en la zona economica son: " << endl;
		  		 for (int i = 0; i < filas; i++) {
		        for (int j = 0; j < columnas; j++) {
		            if (disponibilidad[i][j] == 0) {
		                if (((i==0 || i==filas-1) || (j==0 || j==columnas-1))){
		                    cout << marcas[i][j] << "- " << endl;
		                    economica++;
		        		}
					}
		        }
		    }
		
			cout<<endl;
			if(economica>0){
				cout<<"si existieron contenedores en la zona economica "<<endl;
			}else{
				cout<<"no hay contenedores en la zona economica "<<endl;
			}
		cout<<endl;
	}
	
	//d.	Listado de las marcas de contenedores que van en la zona premium.
	void listadoMarcasPremium(string marcas[filas][columnas],bool disponibilidad[filas][columnas]){
		int premium=0;
		//debemos de recorrer la matriz para realizar el condicional e ir imprimiendo.
		  cout << "\tLas marcas que tiene los contenedores en la zona premium son: " << endl;
		  		 for (int i = 0; i < filas; i++) {
			        for (int j = 0; j < columnas; j++) {
			            if (disponibilidad[i][j] == 0) {
			                if (!((i==0 || i==filas-1) || (j==0 || j==columnas-1))){
			                    cout << marcas[i][j] << "- " << endl;
			                    premium++;
			        		}
						}
			        }
		    }
		
			cout<<endl;
			if(premium>0){
				cout<<"si existieron contenedores en la zona premium "<<endl;
			}else{
				cout<<"no hay contenedores en la zona premium"<<endl;
			}
		cout<<endl;
	}
	
	//e.	Dado el nombre de una empresa, determinar los contenedores que lleva por zona y el valor que debe pagar por los contenedores
	void reporteMarca(string marcas[filas][columnas],string marcaBuscada,bool disponibilidad[filas][columnas]){
		int contadorEconomica=0;
		int contadorPremium=0;
		int respuestaEco=0;
		int respuestaPremium=0;
		int total=0;
		
			 for (int i = 0; i < filas; i++) {
			        for (int j = 0; j < columnas; j++) {
			            if (disponibilidad[i][j] == 0 && marcas[i][j]==marcaBuscada) {
			            	//condicional zona economica
			                if (((i==0 || i==filas-1) || (j==0 || j==columnas-1))){
			                	contadorEconomica++;
			                //asegurar zona premium
			        		}else if(i>0 && i<filas-1 && j>0 && j<columnas-1){
			        			contadorPremium++;
							}
			        		
			        		
						}
			        }
		    }
		    
		respuestaEco=contadorEconomica*100;
		respuestaPremium=contadorPremium*300;
		
		if(contadorEconomica>0){
			cout<<"la cantidad de contenedores en la zona economica son "<<contadorEconomica<<" y debe de pagar por estos contenedores "<<respuestaEco<<endl;
			
		}else{
			cout<<" no existen contenedores en la zona economica "<<endl;
		}
		
		if(contadorPremium>0){
			cout<<"la cantidad de contenedores en la zona premium son "<<contadorPremium<<" y debe de pagar por estos contenedores "<<respuestaPremium<<endl;
			
		}else{
			cout<<" no existen contenedores en la zona premium "<<endl;
		}
		
		total=respuestaEco+respuestaPremium;
		cout<<"el total a pagar es "<<total;
		
		cout<<endl;
		    
	}
	
/////////////////////////////////////////////////////////////////////////////
/*
Reportes Funciones 
*/
	//a.	Promedio de peso de los contenedores que ocupan una celda (tener en cuenta solamente las celdas ocupadas).
	float promedioPeso(int pesos[filas][columnas], bool disponibilidad[filas][columnas]){
		cout<<"calculo de promedio de peso de los contenedores que ocupan una celda "<<endl;
		
		int  contador=0;
		float acumulador=0.0;
		float promedio=0.0;
		
			for(int i=0;i<filas;i++){
				for(int j=0;j<columnas;j++){
					if(disponibilidad[i][j]==0){
						acumulador=acumulador+pesos[i][j];
						contador++;
					}
				}
		}
		promedio=(acumulador)/(contador);
		return promedio;
	}
	
	//b.	Determinar la fila donde hay más carga
	int filaPesada(int pesos[filas][columnas],int dimension, float vector[]){
			int mayorSumaFilas=INT_MIN;
			int filaMayor=-1;
			int acumuladorFilas=0;
	
				for (int i=0;i<filas;i++){
					for(int j=0;j<columnas;j++){
					acumuladorFilas=acumuladorFilas+pesos[i][j];
				}
				vector[i]=acumuladorFilas;
				acumuladorFilas=0;
				
				//evaluamos las suma para determinar la fila con mayor suma
				if(vector[i]>mayorSumaFilas){
					mayorSumaFilas=vector[i];
					filaMayor=i;
					
				}
				
			}
		return filaMayor;
	cout<<endl;
}
	//c.	Determinar la columna donde hay menos carga
	int columnaliviana (int pesos[filas][columnas]){
		int menor = INT_MAX;
		int columnamenor = -1;
		int acumulador=0;
		for(int j=0;j<columnas;j++){
			for (int i=0; i<filas; i++){
			    acumulador=acumulador+pesos[i][j];
			}
			if(acumulador<menor){
				menor=acumulador;
				columnamenor=j;
			}
			acumulador=0;
			
		}
		return columnamenor; 
	}
	
	//d. d.	Dado el tipo de un artículo determinar la cantidad de contenedores de dicha clase.
	int cantidadTipoArticulo(string tipoArticulo[filas][columnas], string tipoArticuloBuscado){
		int contadorArticulo=0;
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				if(tipoArticulo[i][j]==tipoArticuloBuscado){
					contadorArticulo++;
					
				}
			}
		}
		
		return contadorArticulo;
	}
	
	//e.	Dado el nombre de un puerto de origen, determinar el promedio de peso que se ingresó en ese lugar
	float promedioPesoPuerto(int pesos[filas][columnas],string puertoCarga[filas][columnas],string puertoBuscado){
		float promedio=0;
		int contador=0;
		float acumulador=0;
		
			for(int i=0;i<filas;i++){
				for(int j=0;j<columnas;j++){
					if(puertoCarga[i][j]==puertoBuscado){
						acumulador=acumulador+pesos[i][j];
						contador++;
					}
				}
		}
		promedio=(acumulador)/(contador);
		return promedio;
	
	}
	
	//f.	Nombre de la empresa que posee el contenedor con más peso
string nombreEmpresaContenedorPesado(int pesos[filas][columnas], string marcas[filas][columnas]){
	int mayor=INT_MIN;
	int filaMayor=-1;
	string empresa="";
		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				if(pesos[i][j]>mayor){
					mayor=pesos[i][j];
					filaMayor=i;
					empresa=marcas[i][j];
					
				}
			}
		}
	return empresa;	
}


	//g.	Peso del contenedor más liviano.
	int contenedorLiviano(int pesos[filas][columnas]){
	int menor=INT_MAX;
	int filaMenor=-1;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(pesos[i][j]<menor){
				menor=pesos[i][j];
				filaMenor=i;
			}
		}
	}
	
	return menor;
}

	
	

	
