#ifndef SHORT_H
#define SHORT_H

#include "Video.h"

class Short : public Video {
private:
    bool vertical;
    int segundos;

public:
    Short(int idVideo, int duracion, int visitas, int likes,
          int dislikes, string categoria, string titulo,
          bool vertical, int segundos);

    void mostrarInfo() override;
};

#endif