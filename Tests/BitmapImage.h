//
// Created by Utente on 24/09/2017.
//

#ifndef IMAGE_CONVOLUTION_BITMAPIMAGE_H
#define IMAGE_CONVOLUTION_BITMAPIMAGE_H

#include <stdexcept>
#include "Filter.h"
#include "RGBPixel.h"

template<typename T>
class BitmapImage {
public:
    BitmapImage(int w = 1, int h = 1);

    virtual ~BitmapImage();

    T getPixel(int x, int y);

    bool setPixel(int w, int h, const T &pixel);

    void matrixConvolution(const Filter &kernel); // rende l'immagine filtrata

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);

    T *getBuffer() const;

    void setBuffer(int w, int h);

    void replaceBuffer(T *newBuffer);


private:
    int width, height;
    T *buffer;

};

template<typename T>
T *BitmapImage<T>::getBuffer() const {
    return buffer;
}

template<typename T>
void BitmapImage<T>::setBuffer(int w, int h) {
    delete[] buffer;
    buffer = new T[w * h];
}

template<typename T>
void BitmapImage<T>::replaceBuffer(T *newBuffer) {
    buffer = newBuffer;
}

template<typename T>
BitmapImage<T>::BitmapImage(int w, int h) : width(w), height(h) {
    if (width < 0)
        width = 1;
    if (height < 0)
        height = 1;
    buffer = new T[width * height];
}

template<typename T>
BitmapImage<T>::~BitmapImage() {
    delete[] buffer;
};

template<typename T>
T BitmapImage<T>::getPixel(int x, int y) {
    if (x < 0)
        x = 0;
    if (x >= height)
        x = height - 1;
    if (y < 0)
        y = 0;
    if (y >= width)
        y = width - 1;
    return buffer[y * height + x];
}

template<typename T>
bool BitmapImage<T>::setPixel(int w, int h, const T &pixel) {
    if (w < 0 || w >= height || h < 0 || h >= width)
        return false;
    else {
        buffer[h * height + w] = pixel;
        return true;
    }
}

template<typename T>
int BitmapImage<T>::getWidth() const {
    return width;
}

template<typename T>
void BitmapImage<T>::setWidth(int width) {
    BitmapImage::width = width;
}

template<typename T>
int BitmapImage<T>::getHeight() const {
    return height;
}

template<typename T>
void BitmapImage<T>::setHeight(int height) {
    BitmapImage::height = height;
}

/*
template<typename T>
BitmapImage<T> BitmapImage<T>::matrixConvolution(BitmapImage<T> &im, const Filter &kernel) {
    int kCols = kernel.getColumns();
    int kRows = kernel.getRows();
    int kCenterX = kCols / 2;
    int kCenterY = kRows / 2;
    int i, j, m, mm, n, nn, ii, jj;
    BitmapImage<T> modifiedImage(width, height);

    for (i = 0; i < width; i++) {      // righe immagine
        for (j = 0; j < height; j++) {       // colonne immagine
            for (m = 0; m < kRows; m++) {   // righe kernel
                mm = kRows - 1 - m;      // indice righe kernel opposto
                for (n = 0; n < kCols; n++) {  // colonne kernel
                    nn = kCols - 1 - n;  // indice colonne kernel opposto
                    ii = i + (m - kCenterY); // indici usati per controllo valori fuori dai bordi
                    jj = j + (n - kCenterX);

                    if (ii >= 0 && ii < width && jj >= 0 && jj < height) // controllo degli indici
                        // out[i][j] += in[ii][jj] * (kernel[mm][nn]);
                        modifiedImage.buffer[j * width + i] +=
                                im.buffer[jj * width + ii] * kernel.getBuffer()[nn * kRows + mm];
                }
            }
        }
    }
    return modifiedImage;
}



template<typename T>
void BitmapImage<T>::matrixConvolution(const Filter &kernel) {
    int kCols = kernel.getColumns();
    int kRows = kernel.getRows();
    int kCenterX = kCols / 2;
    int kCenterY = kRows / 2;
    int i, j, m, mm, n, nn, ii, jj;
    T tmpBuffer[width * height];

    for (i = 0; i < width; i++) {      // righe immagine
        for (j = 0; j < height; j++) {       // colonne immagine
            for (m = 0; m < kRows; m++) {   // righe kernel
                mm = kRows - 1 - m;      // indice righe kernel opposto
                for (n = 0; n < kCols; n++) {  // colonne kernel
                    nn = kCols - 1 - n;  // indice colonne kernel opposto
                    ii = i + (m - kCenterY); // indici usati per controllo valori fuori dai bordi
                    jj = j + (n - kCenterX);

                    if (ii >= 0 && ii < width && jj >= 0 && jj < height) { // controllo degli indici
                        // out[i][j] += in[ii][jj] * (kernel[mm][nn]);
                        tmpBuffer[j * width + i] +=
                                buffer[jj * width + ii] * kernel.getBuffer()[nn * kRows + mm];
                    }

                }
            }
        }
    }
    for (int p = 0; p < width; p++) {
        for (int q = 0; q < height; q++) {
            buffer[p * width + q] = tmpBuffer[p * width + q];
        }
    }
}

*/



#endif //IMAGE_CONVOLUTION_BITMAPIMAGE_H
