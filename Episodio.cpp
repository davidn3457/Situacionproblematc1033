#include "Episodio.h"
using namespace std;


//constructores
    Episodio::Episodio(){
    }

    
    Episodio::Episodio(std::string _titulo, int _temporada, double _calificacion){
      titulo = _titulo;
      temporada = _temporada;
      calificacion = _calificacion;
    }
  //Setters
    void Episodio::setTitulo (std::string _titulo){
      titulo = _titulo;
    }
    void Episodio::setTemporada (int _temporada){
      temporada = _temporada;
    }
    void Episodio::setCalificacion (double _calificacion){
      calificacion = _calificacion;
    }
  //Getters
    std::string Episodio::getTitulo(){
      return titulo;
    }
    int Episodio::getTemporada(){
      return temporada;
    }
    double Episodio::getCalificacion(){
      return calificacion;
    }
  //otros
    void Episodio::imprimir(){
      cout << titulo << ',' << temporada << ',' << calificacion << endl; 
    }