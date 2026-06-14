#ifndef CATALOGO_H
#define CATALOGO_H

#include "Video.h"
#include "Canal.h"
#include "Usuario.h"
#include "Pelicula.h"

#include <vector>
#include <string>
#include <limits>
using namespace std;

class Catalogo
{
private:
    vector<Video *> videos;
    vector<Canal *> canales;
    vector<Usuario *> usuarios;
    vector<Pelicula *> peliculas;

    int nextComentarioId;

public:
    Catalogo();
    ~Catalogo();

    void agregarVideo(Video *video);
    void agregarCanal(Canal *canal);
    void agregarUsuario(Usuario *usuario);
    void agregarPelicula(Pelicula *pelicula);

    void mostrarVideos() const;
    void mostrarCanales() const;
    void mostrarUsuarios() const;
    void mostrarPeliculas() const;
    void mostrarTodo() const;

    Video *getVideo(int indice) const;
    Canal *getCanal(int indice) const;
    Usuario *getUsuario(int indice) const;
    Pelicula *getPelicula(int indice) const;

    int totalVideos() const;
    int totalCanales() const;
    int totalUsuarios() const;
    int totalPeliculas() const;

    void agregarComentarioAVideo(int indiceVideo, int indiceUsuario, const string &texto, const string &fecha);
    void mostrarComentariosDeVideo(int indiceVideo) const;
    void darLikeComentarioAVideo(int indiceVideo, int indiceUsuario, int indiceComentario);
    void suscribirUsuarioACanal(int indiceUsuario, int indiceCanal);
    void compararPopularidad(int indiceV1, int indiceV2) const;

    void limpiarBuffer();
    int pedirIndice(const string &prompt, int maxExclusivo);
    void mostrarMenu();
};

#endif