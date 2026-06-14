#include "Catalogo.h"
#include <iostream>
using namespace std;

Catalogo::Catalogo() : nextComentarioId(1) {}

Catalogo::~Catalogo()
{
    for (Video *v : videos)
        delete v;
    for (Canal *c : canales)
        delete c;
    for (Usuario *u : usuarios)
        delete u;
}

void Catalogo::agregarVideo(Video *video)
{
    if (video)
        videos.push_back(video);
}

void Catalogo::agregarCanal(Canal *canal)
{
    if (canal)
        canales.push_back(canal);
}

void Catalogo::agregarUsuario(Usuario *usuario)
{
    if (usuario)
        usuarios.push_back(usuario);
}

void Catalogo::agregarPelicula(Pelicula *pelicula)
{
    if (pelicula)
    {
        peliculas.push_back(pelicula);
        videos.push_back(pelicula);
    }
}

void Catalogo::mostrarVideos() const
{
    cout << "\n>Cargando videos...:" << endl;
    if (videos.empty())
    {
        cout << "No hay videos disponibles por el momento.\n";
        return;
    }
    for (int i = 0; i < (int)videos.size(); i++)
    {
        cout << "[" << i << "] ";
        videos[i]->mostrarInfo();
        cout << endl;
    }
}

void Catalogo::mostrarCanales() const
{
    cout << "\nCanales disponibles...:" << endl;
    if (canales.empty())
    {
        cout << "No hay canales disponibles por el momento.\n";
        return;
    }
    for (int i = 0; i < (int)canales.size(); i++)
    {
        cout << "[" << i << "] ";
        canales[i]->mostrarInfo();
        cout << endl;
    }
}

void Catalogo::mostrarUsuarios() const
{
    cout << "\n>Usuarios registrados...:" << endl;
    if (usuarios.empty())
    {
        cout << "No hay usuarios registrados por el momento.\n";
        return;
    }
    for (int i = 0; i < (int)usuarios.size(); i++)
    {
        cout << "[" << i << "] Usuario #" << i
             << " registrado en el sistema" << endl;
    }
}

void Catalogo::mostrarPeliculas() const
{
    cout << "\n>Peliculas en el catalogo...:" << endl;
    if (peliculas.empty())
    {
        cout << "No hay peliculas disponibles por el momento.\n";
        return;
    }
    for (int i = 0; i < (int)peliculas.size(); i++)
    {
        cout << "[" << i << "] ";
        peliculas[i]->mostrarInfo();
        cout << endl;
    }
}

void Catalogo::mostrarTodo() const
{
    mostrarVideos();
    mostrarCanales();
    mostrarUsuarios();
    mostrarPeliculas();
}

Video *Catalogo::getVideo(int i) const { return (i >= 0 && i < (int)videos.size()) ? videos[i] : nullptr; }
Canal *Catalogo::getCanal(int i) const { return (i >= 0 && i < (int)canales.size()) ? canales[i] : nullptr; }
Usuario *Catalogo::getUsuario(int i) const { return (i >= 0 && i < (int)usuarios.size()) ? usuarios[i] : nullptr; }
Pelicula *Catalogo::getPelicula(int i) const { return (i >= 0 && i < (int)peliculas.size()) ? peliculas[i] : nullptr; }

int Catalogo::totalVideos() const
{
    return videos.size();
}
int Catalogo::totalCanales() const
{
    return canales.size();
}
int Catalogo::totalUsuarios() const
{
    return usuarios.size();
}
int Catalogo::totalPeliculas() const
{
    return peliculas.size();
}

void Catalogo::agregarComentarioAVideo(int indiceVideo, int indiceUsuario, const string &texto, const string &fecha)
{
    Video *v = getVideo(indiceVideo);
    Usuario *u = getUsuario(indiceUsuario);
    if (!v || !u)
    {
        cout << "Algo salió mal al agregar el comentario." << endl;
        return;
    }
    u->comentar(v, texto, fecha);
    cout << "Comentario agregado correctamente." << endl;
    nextComentarioId++;
}

void Catalogo::mostrarComentariosDeVideo(int indiceVideo) const
{
    Video *v = getVideo(indiceVideo);
    if (!v)
    {
        cout << "Video no encontrado." << endl;
        return;
    }

    const vector<Comentario> &coms = v->getComentarios();
    if (coms.empty())
    {
        cout << "Este video no tiene comentarios" << endl;
        return;
    }

    cout << "\n--- Comentarios ---" << endl;
    for (const Comentario &c : coms)
    {
        const_cast<Comentario &>(c).mostrarComentario();
        cout << endl;
    }
}

void Catalogo::suscribirUsuarioACanal(int indiceUsuario, int indiceCanal)
{
    Usuario *u = getUsuario(indiceUsuario);
    Canal *c = getCanal(indiceCanal);
    if (!u || !c)
    {
        cout << "Algo salió mal al suscribir al usuario." << endl;
        return;
    }
    u->suscribirse(c);
    cout << "Suscrito" << endl;
}

void Catalogo::compararPopularidad(int indiceV1, int indiceV2) const
{
    Video *v1 = getVideo(indiceV1);
    Video *v2 = getVideo(indiceV2);
    if (!v1 || !v2)
    {
        cout << "Uno o ambos indices de video son invalidos." << endl;
        return;
    }
    *v1 > *v2;
}

void Catalogo::limpiarBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Catalogo::pedirIndice(const string &prompt, int maxExclusivo)
{
    int idx;
    cout << prompt;
    cin >> idx;
    limpiarBuffer();
    if (idx < 0 || idx >= maxExclusivo)
    {
        cout << "Indice fuera de rango." << endl;
        return -1;
    }
    return idx;
}

void Catalogo::mostrarMenu()
{
    cout << "\n|======================================|" << endl;
    cout << "|         TC1030 - YouTube             |" << endl;
    cout << "|======================================|" << endl;
    cout << "|  1. Mostrar todos los videos         |" << endl;
    cout << "|  2. Mostrar todos los canales        |" << endl;
    cout << "|  3. Mostrar todas las peliculas      |" << endl;
    cout << "|  4. Agregar comentario a un video    |" << endl;
    cout << "|  5. Ver comentarios de un video      |" << endl;
    cout << "|  6. Suscribirse a un canal           |" << endl;
    cout << "|  7. Comparar popularidad de videos   |" << endl;
    cout << "|  8. Ver videos de un canal           |" << endl;
    cout << "|  9. Mostrar todo el catalogo         |" << endl;
    cout << "|  0. Salir                            |" << endl;
    cout << "|======================================|" << endl;
    cout << "Opcion: ";
}
