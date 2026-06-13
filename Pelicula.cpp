#include "Pelicula.h"
#include <iostream>

using namespace std;

Pelicula::Pelicula(int _idVideo, int _duracion,
                   int _visitas, int _likes,
                   int _dislikes, string _categoria,
                   string _titulo, string _director,
                   string _estudio, int _año,
                   string _clasificacion,
                   double _precio)

    : Video(_idVideo, _duracion, _visitas,
            _likes, _dislikes,
            _categoria, _titulo)
{
    director = _director;
    estudio = _estudio;
    año = _año;
    clasificacion = _clasificacion;
    precio = _precio;
}

void Pelicula::mostrarInfo() {
    cout << "=== PELICULA ===" << endl;
    cout << "Director: " << director << endl;
    cout << "Estudio: " << estudio << endl;
    cout << "Año: " << año << endl;
    cout << "Clasificacion: " << clasificacion << endl;
    cout << "Precio: $" << precio << endl;
}