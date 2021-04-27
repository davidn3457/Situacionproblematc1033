#ifndef Serie_h
#define Serie_h
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "Episodio.h"


class Serie{
private:
  std::string id, titulo, genero;
  int duracion, cantEspisodios;
  double calificacion;
  //Composición - uno o mas atributos de una clase, en otra clase
  Episodio episodios[5];


public:
  //constructores
  Serie();
  Serie(std::string _id, std::string _titulo, std::string _genero, int _duracion, int _cantEpisodios, double _calificacion);

  //setters
  void setId(std::string _id);
  void setTitulo(std::string _titulo);
  void setDuracion(int _duracion);
  void setGenero(std::string _genero);
  void setCalificacion(double _calificacion);
  void setCantEpisodios(int _cantEpisodios);


  //setters
  std::string getId();
  std::string getTitulo();
  int getDuracion();
  std::string getGenero();
  double getCalificacion();
  int getCantidadEpisodios();

  //otros metodos
  void imprimir();

  Episodio getEpisodio(int iE);
  void setEpisodio(int iE,Episodio _episodio);
  void calculaCalificacionPromedio();

};
#endif /* Serie_h */
