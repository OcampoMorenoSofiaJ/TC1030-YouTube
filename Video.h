#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

#include "Comentario.h"
#include "likeable.h"
#include <vector>

class Video : public Likeable {
private:
    int idVideo;
    int duracion;
    int visitas;
    int likes;
    int dislikes;

    string categoria;
    string titulo;

    vector <Comentario> comentarios;
public:
    Video(int idVideo, int duracion, int visitas, int likes, int dislikes, string categoria, string titulo);
    void agregarComentario(const Comentario& comentario);
    const vector<Comentario>& getComentarios() const;

    virtual void recibirLike() = 0;
    virtual void mostrarInfo() = 0;
    friend void operator>(Video& v1, Video& v2);

};

#endif