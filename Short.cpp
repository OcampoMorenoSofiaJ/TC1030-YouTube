#include "Short.h"
#include <iostream>

using namespace std;

Short::Short(int _idVideo, int _duracion,
             int _visitas, int _likes,
             int _dislikes, string _categoria,
             string _titulo, bool _vertical,
             int _segundos)

    : Video(_idVideo, _duracion, _visitas,
            _likes, _dislikes,
            _categoria, _titulo)
{
    vertical = _vertical;
    segundos = _segundos;
}

void Short::mostrarInfo() {
    cout << "=== SHORT ===" << endl;
    cout << "Duracion: " << segundos << " segundos" << endl;

    if(vertical){
        cout << "Formato Vertical" << endl;
    }
}