#include "Canal.h"
#include <iostream>
using namespace std;

Canal::Canal(int _idCanal, string _nombre, int _suscriptores)
{
    idCanal = _idCanal;
    nombre = _nombre;
    suscriptores = _suscriptores;
}

void Canal::agregarVideo(Video *video)
{
    if (video)
    {
        videos.push_back(video);
    }
}

void Canal::mostrarInfo() const
{
    cout << "=== CANAL ===" << endl;
    cout << "ID: " << idCanal << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Suscriptores: " << suscriptores << endl;
    cout << "Videos publicados: " << videos.size() << endl;
}

void Canal::mostrarVideos() const
{
    cout << " Videos del canal [" << nombre << "] ---" << endl;
    for (Video *v : videos)
    {
        v->mostrarInfo();
        cout << endl;
    }
}

int Canal::getIdCanal() const
{
    return idCanal;
}
string Canal::getNombre() const
{
    return nombre;
}
int Canal::getSuscriptores() const
{
    return suscriptores;
}

void Canal::agregarSuscriptor()
{
    suscriptores++;
}
