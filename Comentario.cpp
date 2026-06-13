#include "Comentario.h"

using namespace std;
#include <iostream>

Comentario::Comentario(int _idComentario, int _likes, string _texto, string _fecha, string _autor) {
    idComentario = _idComentario;
    likescom = _likes;
    texto = _texto;
    fecha = _fecha;
    autor = _autor;
}

void Comentario::mostrarComentario() {
    cout << "Comentario ID: " << idComentario << endl;
    cout << "Likes: " << likescom << endl;
    cout << "Texto: " << texto << endl;
    cout << "Fecha: " << fecha << endl;
    cout << "Autor: " << autor << endl;
}

void Comentario::darLike() {
    likescom++;
}