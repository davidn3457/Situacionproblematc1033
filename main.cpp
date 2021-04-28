//David Nuñez
//A01634928
//Reflexión: Primer avance de la situación problema, utilizamos los conceptos vistos en clase;getters, setters, headers. Utilizando buenas practicas realizamos un codigo que servirá de menu para nuestra aplicación. 

#include <iostream>
#include "Series.h"
#include "Serie.h"
using namespace std;

int menu(){
  int opcion;
  cout << "\n1. leerArchivo \
  \n2. reporte de Todas las series y promedio \
  \n3. reporte de Series con cierta califciacion \
  \n4. reporte de Series de cierto Genero \
  \n5. calculaCalPromedioSerie \
  \n6. getSerie \
  \n7. getSerie \
  \n8. getCantidadSeries \
  \n0. Salir \
  \n9. Teclea la opcion: ";
  cin >> opcion;
  return opcion;
}

int main(int argc, const char* argv[]){
  Serie s;
  Series netflix;
  
  int opcion, iS, iCantSeries;
  std::string genero, titulo;
  opcion = menu();

  while (opcion != 0){
      switch (opcion) {
        case 1:
          netflix.leerArchivo();
          break;
        case 2:
          cout <<"Reporte de todas las series\n ";
          netflix.reporteTodasSeries();
          break;
        case 3: 
          int calificacion;
          cout << "Reporte de Series con cierta Calificacion\n Ingresa la calificacion: ";
          cin >> calificacion;

          netflix.reporteConCalificacion(calificacion);
          break;
        case 4:
          cout << "Reporte de Serires por genero\n Ingresa el genero: ";
          cin >> genero;

          netflix.reporteGenero(genero);
          break;
        
        case 5: 
          netflix.calculaCalPromedioSerie();
          cout << "Calificacion promedio calculada\n";
          break;

        case 6:
          cout << "Ingrese el id de la serie: ";
          cin >> iS;
          s = netflix.getSerie(iS);
          s.imprimir();
          break;

        case 7:
          cout << "ingresa el id de la serie: ";
          cin >> iS;
          cin.ignore();

          if (iS >= 0 && iS <netflix.getCantidadSeries())
          {
            s = netflix.getSerie(iS);
            cout << "La información actual de la serie:\n";
            s.imprimir();
            cout << "Ingresa el nuevo titulo <si no quieres cambio da <enter>>:";
            getline(cin, titulo);

            if (titulo !="")
              s.setTitulo(titulo);
            
            cout << "Ingresa la nueva duracion <si no quieres cabio teclea 0>:";
            cin >> duracion;
            cin.ignore();

            if (duracion != 0)
              s.setDuracion(duracion);
            
            cout << "Ingresa el nuevo genero <si no quieres cambio da <enter>>:";
            getline(cin, genero);
            if (genero !="")
              s.setGenero(genero);
            
            cout << "La información nueva de la serie es:\n";
            s.imprimir();
            netflix.setSerie(iS, s);
          }
          else
            cout << "Esa serie no existe!!\n";
          break;




            


          }

          s=netflix.getSerie(iS);

          cout << "la información actual de la serie: \n";
          s.imprimir();

          cout << "Ingresa el nuevo titulo de la serie: \n ";
          
          break;

        case 8:
          iCantSeries = netflix.getCantidadSeries();

          cout << "Existen: " << iCantSeries << " en existencia\n";
          break;

        default:
          cout << "Opcion Incorrecta!\n";
          break;
      }

      opcion = menu();

  }

return 0;

}