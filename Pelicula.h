#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
private:
    string director;
    string estudio;
    int año;
    string clasificacion;
    double precio;

public:
    Pelicula(int idVideo, int duracion, int visitas,
             int likes, int dislikes,
             string categoria, string titulo,
             string director, string estudio,
             int año, string clasificacion,
             double precio);

    void mostrarInfo() override;
};

#endif