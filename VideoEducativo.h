#ifndef VIDEOEDUCATIVO_H
#define VIDEOEDUCATIVO_H

#include "Video.h"

class VideoEducativo : public Video {
private:
    string tema;
    string nivel;

public:
    VideoEducativo(int idVideo, int duracion, int visitas, int likes,
                   int dislikes, string categoria, string titulo,
                   string tema, string nivel);

    void mostrarInfo() override;
};

#endif