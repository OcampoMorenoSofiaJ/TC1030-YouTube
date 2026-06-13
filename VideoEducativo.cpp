#include "VideoEducativo.h"
#include <iostream>

using namespace std;

VideoEducativo::VideoEducativo(int _idVideo, int _duracion,
                               int _visitas, int _likes,
                               int _dislikes, string _categoria,
                               string _titulo, string _tema,
                               string _nivel)

    : Video(_idVideo, _duracion, _visitas, _likes, _dislikes, _categoria, _titulo)
{
    tema = _tema;
    nivel = _nivel;
}

void VideoEducativo::mostrarInfo() {
    cout << "=== VIDEO EDUCATIVO ===" << endl;
    cout << "Tema: " << tema << endl;
    cout << "Nivel: " << nivel << endl;
}