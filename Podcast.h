#ifndef PODCAST_H
#define PODCAST_H

#include "Video.h"

class Podcast : public Video {
private:
    string conductor;
    int episodios;

public:
    Podcast(int idVideo, int duracion, int visitas, int likes,
            int dislikes, string categoria, string titulo,
            string conductor, int episodios);

    void mostrarInfo() override;
};

#endif