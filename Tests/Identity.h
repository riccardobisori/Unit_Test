//
// Created by Utente on 24/09/2017.
//

#ifndef IMAGE_CONVOLUTION_IDENTITY_H
#define IMAGE_CONVOLUTION_IDENTITY_H


#include "Filter.h"

class Identity : public Filter {
public:
    Identity();
    virtual ~Identity();
};


//TODO forse sarebbe meglio usare dei vector perchè cosìdal debugger si vede tutto e poi anche pper l'output a schermo


#endif //IMAGE_CONVOLUTION_IDENTITY_H
