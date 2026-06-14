#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
using namespace std;

#include "Video.h"
#include "Comentario.h"

class Canal;

class Usuario {
private:
    int idUsuario;

    string nombre;
    string email;

    vector <Video*> videosGustados;

public:
    Usuario(int _idUsuario, string _nombre, string _email);
    // Es correcto poner video aquí?
    void verVideo(Video* video);
    void comentar(Video* video, const string& texto, const string& fecha);
    void darLike(Video* video);
    void suscribirse(Canal* canal);
};

#endif