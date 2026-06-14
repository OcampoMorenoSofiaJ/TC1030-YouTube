#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
using namespace std;

#include "Likeable.h"

class Comentario : public Likeable {
private:
    int idComentario;
    int likescom;

    string texto;
    string fecha;
    string autor;

public:
    Comentario(int _idComentario, string _texto, string _fecha, string _autor);
    void mostrarComentario();
    void darLike();
    void recibirLike() override;
};

#endif