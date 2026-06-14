#ifndef LIKEABLE_H
#define LIKEABLE_H

class Likeable {
public:
    virtual void recibirLike() = 0;
    virtual ~Likeable() {}
};

#endif