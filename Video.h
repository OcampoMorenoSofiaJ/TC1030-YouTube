#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

#include "Comentario.h"
#include "Likeable.h"
#include <vector>

class Video : public Likeable{
private:
    int idVideo;
    int duracion;
    int visitas;
    int likes;
    int dislikes;

    string categoria;
    string titulo;

    vector<Comentario> comentarios;

public:
    Video(int idVideo, int duracion, int visitas, int likes, int dislikes, string categoria, string titulo);
    void agregarComentario(const Comentario &comentario);
    vector<Comentario> &getComentarios();
    const vector<Comentario> &getComentarios() const;

    void recibirLike();
    bool darLikeComentario(int indiceComentario);

    virtual ~Video() {}
    virtual void mostrarInfo() = 0;
    friend void operator>(Video &v1, Video &v2);
};

#endif