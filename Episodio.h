#ifndef Episodio_h
#define Episodio_h

#include <iostream>
#include <string.h>
#include <stdio.h>

class Episodio{
  private:
    std::string titulo {};
    int temporada{};
    double calificacion{};

  public:
  //constructores
    Episodio();
    Episodio(std::string _titulo, int _temporada, double _calificacion);
  //Setters
    void setTitulo (std::string _titulo);
    void setTemporada (int _temporada);
    void setCalificacion (double _calificacion);
  //Getters
    std::string getTitulo();
    int getTemporada();
    double getCalificacion();
  //otros
    void imprimir();

};

#endif 