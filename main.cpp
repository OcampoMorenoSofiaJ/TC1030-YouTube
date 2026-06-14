#include <iostream>
#include <string>
using namespace std;

#include "Catalogo.h"
#include "Pelicula.h"
#include "Podcast.h"
#include "Short.h"
#include "VideoEducativo.h"
#include "VideoMusical.h"

int main()
{

    Catalogo catalogo;

    catalogo.agregarUsuario(new Usuario(1, "Ana Garcia", "ana@mail.com"));
    catalogo.agregarUsuario(new Usuario(2, "Luis Torres", "luis@mail.com"));
    catalogo.agregarUsuario(new Usuario(3, "Mia Ramirez", "mia@mail.com"));

    Canal *c1 = new Canal(1, "TechMex", 120000);
    Canal *c2 = new Canal(2, "CineClasico", 45000);
    Canal *c3 = new Canal(3, "MusicaLatina", 320000);
    catalogo.agregarCanal(c1);
    catalogo.agregarCanal(c2);
    catalogo.agregarCanal(c3);

    Pelicula *p1 = new Pelicula(101, 148, 500000, 42000, 800,
                                "Cine", "Interstellar",
                                "Christopher Nolan", "Warner Bros",
                                2014, "PG-13", 149.99);
    catalogo.agregarPelicula(p1);
    c2->agregarVideo(p1);

    VideoEducativo *ve1 = new VideoEducativo(102, 30, 85000, 7600, 120,
                                             "Educacion", "Punteros en C++",
                                             "Programacion", "Intermedio");
    catalogo.agregarVideo(ve1);
    c1->agregarVideo(ve1);

    VideoMusical *vm1 = new VideoMusical(103, 4, 2100000, 180000, 3000,
                                         "Musica", "Baila Conmigo",
                                         "Grupo Firme", "Amor Tumbado",
                                         "Banda");
    catalogo.agregarVideo(vm1);
    c3->agregarVideo(vm1);

    Podcast *pod1 = new Podcast(104, 60, 33000, 2900, 50,
                                "Tecnologia", "El Futuro de la IA",
                                "Daniela Cruz", 12);
    catalogo.agregarVideo(pod1);
    c1->agregarVideo(pod1);

    Short *sh1 = new Short(105, 1, 990000, 78000, 500,
                           "Entretenimiento", "Trick de programacion #42",
                           true, 58);
    catalogo.agregarVideo(sh1);
    c1->agregarVideo(sh1);

    int opcion = -1;

    while (opcion != 0)
    {
        catalogo.mostrarMenu();
        cin >> opcion;
        catalogo.limpiarBuffer();

        if (opcion == 1)
        {

            catalogo.mostrarVideos();
        }
        else if (opcion == 2)
        {

            catalogo.mostrarCanales();
        }
        else if (opcion == 3)
        {

            catalogo.mostrarPeliculas();
        }
        else if (opcion == 4)
        {

            catalogo.mostrarVideos();
            int iv = catalogo.pedirIndice("Indice del video a comentar: ", catalogo.totalVideos());
            if (iv == -1)
                continue;

            catalogo.mostrarUsuarios();
            int iu = catalogo.pedirIndice("Indice del usuario que comenta: ", catalogo.totalUsuarios());
            if (iu == -1)
                continue;

            string texto, fecha;
            cout << "Texto del comentario: ";
            getline(cin, texto);
            cout << "Fecha (dd/mm/aaaa): ";
            getline(cin, fecha);

            catalogo.agregarComentarioAVideo(iv, iu, texto, fecha);
        }
        else if (opcion == 5)
        {

            catalogo.mostrarVideos();
            int iv = catalogo.pedirIndice("Indice del video: ", catalogo.totalVideos());
            if (iv == -1)
                continue;
            catalogo.mostrarComentariosDeVideo(iv);
        }
        else if (opcion == 6)
        {

            catalogo.mostrarUsuarios();
            int iu = catalogo.pedirIndice("Indice del usuario: ", catalogo.totalUsuarios());
            if (iu == -1)
                continue;

            catalogo.mostrarCanales();
            int ic = catalogo.pedirIndice("Indice del canal: ", catalogo.totalCanales());
            if (ic == -1)
                continue;

            catalogo.suscribirUsuarioACanal(iu, ic);
        }
        else if (opcion == 7)
        {

            catalogo.mostrarVideos();
            int iv1 = catalogo.pedirIndice("Indice del primer video: ", catalogo.totalVideos());
            if (iv1 == -1)
                continue;
            int iv2 = catalogo.pedirIndice("Indice del segundo video: ", catalogo.totalVideos());
            if (iv2 == -1)
                continue;

            catalogo.compararPopularidad(iv1, iv2);
        }
        else if (opcion == 8)
        {

            catalogo.mostrarCanales();
            int ic = catalogo.pedirIndice("Indice del canal: ", catalogo.totalCanales());
            if (ic == -1)
                continue;
            catalogo.getCanal(ic)->mostrarVideos();
        }
        else if (opcion == 9)
        {

            catalogo.mostrarTodo();
        }
        else if (opcion == 0)
        {
            cout << "Hasta luego!" << endl;
        }
        else
        {
            cout << "Opcion no valida. Intenta de nuevo." << endl;
        }
    }

    return 0;
}
