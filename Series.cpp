#include "Series.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#include <sstream>
#include <fstream>

Series::Series(){
  iCant = 0;

}
//Leer todas series y episodios desde un archivo
void Series::leerArchivo(){
    // Declaración de variables para usarlas al leer cada línea del archivo
    string sId, sTitulo, sGenero, linea, dato;
    // Variable para llevar el contador de cantidad de series leídas del archivo
    int  iR;
    
    cout << "leer archivo\n";
    
    // Declaración de variable para el archivo
    fstream lectura;
    lectura.open("Serie.csv", ios::in);
    
    iR = 0;
    
    
    while ( getline(lectura, linea)) // lee una línea del archivo, corresponde a una serie
    {
        // Para que la mando desplegar ? para verificar que se esta leyendo correctamente el archivo
        cout << linea << endl; //borrar
        
        std::stringstream registro(linea);
        // used for breaking words
        int columna = 0;
        // Ciclo para separar los elementos de la serie (string)
        while (getline(registro, dato, ',')) // separamos los elementos de la serie leída
        {
            //  cout << dato ;
            switch (columna++)
            {
                case 0: // iD
                    arrSeries[iR].setId(dato);
                    break;
                case 1: // Titulo
                    arrSeries[iR].setTitulo(dato);
                    break;
                case 2: // duracion
                    arrSeries[iR].setDuracion(stoi(dato));
                    break;
                case 3: // genero
                    arrSeries[iR].setGenero(dato);
                    break;
                case 4: // calificación promedio
                    arrSeries[iR].setCalificacion(stod(dato));
                    break;
                case 5: //cant episodios - inicializar con 0 episodios todas las series
                    arrSeries[iR].setCantEpisodios(0);
                    break;
            }
        }
        // para verificar si se inicializo correctamente el objeto
        arrSeries[iR].imprimir();  // borrar
        // vamos por la siguiente serie del archivo
        iR++;
    }
    // Actualizar el atributo iCant - con la cantidad de series leídas del archivo
    iCant = iR;
    // Cerrar el archivo
    lectura.close();
    
    
    // LEER LOS EPISODIOS DE LAS SERIES
    
    cout << "leer archivo de episodios\n";
    // Declaracion  iS de que serie es el episodio que se leyo del archvio
    int iS,cantEpisodios;
    Episodio ep; // con que se inicializa ? con el Constructor default
    iS = 0;
    lectura.open("Episodio.csv", ios::in);

    while ( getline(lectura, linea))
    {
        // Desplegar el episodio leído - solo para corroborar
        cout << linea << endl; // se borra
        std::stringstream registro(linea);
        
        // used for breaking words
        //101,C++ con Objetos,4,5.0
        int columna = 0;
        while (getline(registro, dato, ',')) // separar los datos del episodio desde la línea registro
        {
            //  cout << dato ;
            switch (columna++)
            {
                case 0: // iD - convertir int  - sacar la posicion de la serie
                    iS = stoi(dato) - 1;  // a qué serie pertenece el episodio
                    break;
                case 1: // Titulo
                    ep.setTitulo(dato);
                    
                    break;
                case 2: // temporada
                    ep.setTemporada(stoi(dato)); // string to int
                    break;
                case 3: // calificacion
                    ep.setCalificacion(stod(dato)); // string to double
                    break;
                    
            }
        } // al salir de aqui ya se separo toda
        // añadir el episodio
        // Traer la cantidad de episodios de la serie iS - la 1a vez retorna 0
        cantEpisodios =  arrSeries[iS].getCantidadEpisodios();
        if (cantEpisodios < 5){
            //
            arrSeries[iS].setEpisodio(cantEpisodios, ep); //
            arrSeries[iS].setCantEpisodios(cantEpisodios + 1);
        }
    }
    lectura.close();
 
}


//Reporta todas las series y al final se muestra la calificacion promedio de todas las series
void Series::reporteTodasSeries(){

  double dAcum{0};
  for(int iS = 0; iS < iCant; iS++){
    if (arrSeries[iS].getCantidadEpisodios()> 0)
      cout << '\n';
      
    arrSeries[iS].imprimir();
    dAcum = dAcum + arrSeries[iS].getCalificacion();
  }
  if (iCant > 0)
    cout << "promedio de todas las series: " << dAcum / iCant << endl;
  else 
    cout << "No tenemos serie en el arreglo!";
    
  
}

//Reporte de series que tienen calificacion especifica
void Series::reporteConCalificacion(double _calificacion){
  
    for(int iS = 0; iS < iCant; iS++){
      if(arrSeries[iS].getCalificacion() == _calificacion){
      arrSeries[iS].imprimir();
      }
    }
    if (iCant > 0)
      cout << "No tenemos series en el arreglo" << endl;
    

}

//Reporte de series que tienen cierto genero
void Series::reporteGenero(std::string _genero){
  for(int iS = 0; iS < iCant; iS++){
      if(arrSeries[iS].getGenero() == _genero){
      arrSeries[iS].imprimir();
      }
    }
    if (iCant > 0)
      cout << "No tenemos series en el arreglo" << endl;
}

//Calcula la calificacion promedio de las series y despliega su titulo y calificacion promedio
void Series::calculaCalPromedioSerie(){
  for(int iS = 0; iS < iCant; iS++)
    arrSeries[iS].calculaCalificacionPromedio();

}

//Retorna el objeto serie que esta en posicion iS y recibe como parametros de entrada, no existe retorno una serie default y despliega un mensaje indicando que esa serie no existe
Serie Series::getSerie(int iS){
  Serie s;

  if (iS <= 0 && iS > iCant)

    return arrSeries[iS];
  
  else 
    cout << "Esa serie no existe " << endl;
    return s;
  
}

//Cambia el contenido dentro de una serie del arreglo, recibiendo el nuevo valor de la serie y el numero de la serie que se quiere cambiar
void Series::setSerie(int iS, Serie s){
  if (iS <= 0 && iS > iCant)

    arrSeries[iS] = s;
  
  else 
    cout << "Esa serie no existe " << endl;
    
}

//retorna la cantidad de series que hay hasta el momento
int Series::getCantidadSeries(){

return iCant;
}