#include "Video.h"
using namespace std;
#include <iostream>

Video::Video (int _idVideo, int _duracion, int _visitas, int _likes, int _dislikes, string _categoria, string _titulo) {
    idVideo = _idVideo;
    duracion = _duracion;
    visitas = _visitas;
    likes = _likes;
    dislikes = _dislikes;
    categoria = _categoria;
    titulo = _titulo;
}

void Video::agregarComentario(const Comentario& comentario) {
    comentarios.push_back(comentario);
}

const vector<Comentario>& Video::getComentarios() const {
    return comentarios;
}

void operator>(Video& v1, Video& v2) {
    if (v1.likes > v2.likes){
        cout << "El video " << v1.titulo << " es más popular que " << v2.titulo << endl;
    } else {
        cout << "El video " << v2.titulo << " es más popular que " << v1.titulo << endl;
    }
}
