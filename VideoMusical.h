#ifndef VIDEOMUSICAL_H
#define VIDEOMUSICAL_H

#include "Video.h"

class VideoMusical : public Video {
private:
    string artista;
    string album;
    string generoMusical;

public:
    VideoMusical(int idVideo, int duracion, int visitas, int likes,
                 int dislikes, string categoria, string titulo,
                 string artista, string album, string generoMusical);

    void mostrarInfo() override;
};

#endif