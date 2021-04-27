#include "Serie.h"
using namespace std;


//constructores
  Serie::Serie(){

  }
  Serie::Serie(std::string _id, std::string _titulo, std::string _genero, int _duracion, int _cantEpisodios, double _calificacion){
    id = _id;
    titulo = _titulo;
    genero = _genero;
    duracion = _duracion;
    cantEspisodios = _cantEpisodios;
    calificacion = _calificacion;

  }

  //setters
  void Serie::setId(std::string _id){
    id = _id;
  }
  void Serie::setTitulo(std::string _titulo){
    titulo = _titulo;
  }
  void Serie::setDuracion(int _duracion){
    duracion = _duracion;
  }
  void Serie::setGenero(std::string _genero){
    genero = _genero;
  }
  void Serie::setCalificacion(double _calificacion){
    calificacion = _calificacion;
  }
  void Serie::setCantEpisodios(int _cantEpisodios){
    cantEspisodios = _cantEpisodios;
  }

  //setters
  std::string Serie::getId(){
    return id;

  };
  std::string Serie::getTitulo(){
    return titulo;
  }
  int Serie::getDuracion(){
    return duracion;
  }
  std::string Serie::getGenero(){
    return genero;
  }
  double Serie::getCalificacion(){
    return calificacion;
  }
  int Serie::getCantidadEpisodios(){
    return cantEspisodios;
  }

  //otros metodos
  void Serie::imprimir(){
    cout << 'S' << id << '-' << titulo << ',' << duracion << ',' << genero << ',' << calificacion << ',' << cantEspisodios << endl;

    // si la serie no tiene episodios, el ciclo no se ejectua
    for(int iE = 0; iE < cantEspisodios; iE ++){
      cout << 'E' << iE << '-';
      episodios[iE].imprimir();
    }
  }

  Episodio Serie::getEpisodio(int iE){

    Episodio no_existe;

    //Si si exsite el episodio, se retorna
    if (iE >= 0 && iE <= cantEspisodios)
      return episodios[iE];
    else 
      cout << "Episodio no existe \n";
    //Si no existe, retorna un episodio default
    return no_existe;
  }
  void Serie::setEpisodio(int iE,Episodio _episodio){
    if (iE >= 0 && iE <= cantEspisodios)
       episodios[iE] = _episodio;
    else 
      cout << "Episodio no existe \n";
    
  }
  //calcular calificacion promedio de la serie
  void Serie::calculaCalificacionPromedio(){
    double dAcum{};
    for (int iE = 0; iE < cantEspisodios; iE++){
        dAcum = dAcum + episodios[iE].getCalificacion();
    }
    if (cantEspisodios > 0)
      calificacion = dAcum / cantEspisodios;
    else 
      calificacion = 0;
  }