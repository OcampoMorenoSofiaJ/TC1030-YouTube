#include "Usuario.h"
#include "Canal.h"

using namespace std;
#include <iostream>

Usuario::Usuario(int _idUsuario, string _nombre, string _email) {
    idUsuario = _idUsuario;
    nombre = _nombre;
    email = _email;
}

void Usuario::verVideo(Video* video) {
    if (video) {
        cout << "Viendo un video" << endl;
    }
}

void Usuario::comentar(Video* video, int idComentario, const string& texto, const string& fecha){
    if (!video) return;
    Comentario comentario(idComentario, texto, fecha, nombre);
    video->agregarComentario(comentario);
}

bool Usuario::darLike(Likeable* likeable){
    if (!likeable) return false;
    if (dynamic_cast<Video*>(likeable)) {
        likeable->recibirLike();
        return true;
    }
    if (dynamic_cast<Comentario*>(likeable)) {
        likeable->recibirLike();
        return true;
    }
    return false;
}

void Usuario::suscribirse(Canal* canal){
    if (!canal) return;

    for (Canal* c : suscripciones) {
        if (c == canal) {
            cout << "Ya estas suscrito al canal: " << canal->getNombre() << endl;
            return;
        }
    }

    suscripciones.push_back(canal);
    canal->agregarSuscriptor();
    cout << "Te suscribiste a: " << canal->getNombre() << endl;
}
