#include "Podcast.h"
#include <iostream>

using namespace std;

Podcast::Podcast(int _idVideo, int _duracion,
                 int _visitas, int _likes,
                 int _dislikes, string _categoria,
                 string _titulo, string _conductor,
                 int _episodios)

    : Video(_idVideo, _duracion, _visitas,
            _likes, _dislikes,
            _categoria, _titulo)
{
    conductor = _conductor;
    episodios = _episodios;
}

void Podcast::mostrarInfo() {
    cout << "=== PODCAST ===" << endl;
    cout << "Conductor: " << conductor << endl;
    cout << "Episodios: " << episodios << endl;
}