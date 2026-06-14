#include "Usuario.h"

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

void Usuario::comentar(Video* video, const string& texto, const string& fecha){
    if (!video) return;
    Comentario comentario(0, texto, fecha, nombre);
    video->agregarComentario(comentario);
}

void Usuario::darLike(Video* video){
    if (!video) return;
    // Lista de Videos a los que se les ha dado like?
}

void Usuario::suscribirse(Canal* canal){
    // Hereda de canal?
}
