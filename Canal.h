#ifndef CANAL_H
#define CANAL_H

#include "Video.h"

#include <string>
#include <vector>
using namespace std;

class Canal
{
private:
    int idCanal;
    string nombre;
    int suscriptores;
    vector<Video *> videos;

public:
    Canal(int _idCanal, string _nombre, int _suscriptores);

    void agregarVideo(Video *video);
    void mostrarInfo() const;
    void mostrarVideos() const;

    void agregarSuscriptor();

    int getIdCanal() const;
    string getNombre() const;
    int getSuscriptores() const;
};

#endif
