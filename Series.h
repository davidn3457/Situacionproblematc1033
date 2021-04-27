#ifndef Series_h
#define Series_h
#include <stdio.h>
#include "Serie.h"

class Series{
  private:
    Serie arrSeries[100];
    int iCant;

  public:
    Series();
    //Leer todas series y episodios desde un archivo
    void leerArchivo();

    //Reporta todas las series y al final se muestra la calificacion promedio de todas las series
    void reporteTodasSeries();

    //Reporte de series que tienen calificacion especifica
    void reporteConCalificacion(double _calificacion);

    //Reporte de series que tienen cierto genero
    void reporteGenero(std::string _genero);

    //Calcula la calificacion promedio de las series y despliega su titulo y calificacion promedio
    void calculaCalPromedioSerie();

    //Retorna el objeto serie que esta en posicion iS y recibe como parametros de entrada, no existe retorno una serie default y despliega un mensaje indicando que esa serie no existe
    Serie getSerie(int iS);

    //Cambia el contenido dentro de una serie del arreglo, recibiendo el nuevo valor de la serie y el numero de la serie que se quiere cambiar
    void setSerie(int iS, Serie s);

    //retorna la cantidad de series que hay hasta el momento
    int getCantidadSeries();


};
#endif /* Series_h */