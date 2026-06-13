#include "VideoMusical.h"
#include <iostream>

using namespace std;

VideoMusical::VideoMusical(int _idVideo, int _duracion,
                           int _visitas, int _likes,
                           int _dislikes, string _categoria,
                           string _titulo, string _artista,
                           string _album, string _generoMusical)

    : Video(_idVideo, _duracion, _visitas, _likes,
            _dislikes, _categoria, _titulo)
{
    artista = _artista;
    album = _album;
    generoMusical = _generoMusical;
}

void VideoMusical::mostrarInfo() {
    cout << "=== VIDEO MUSICAL ===" << endl;
    cout << "Artista: " << artista << endl;
    cout << "Album: " << album << endl;
    cout << "Genero: " << generoMusical << endl;
}