//
// Created by Utente on 30/07/2018.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "BitmapImage.h"//qui si include la classe da testare
#include "Filter.h"
#include "EdgeDetection.h"


#include "PGM.h"
#include "GrayPixel.h"

#include "PPM.h"
#include "RGBPixel.h"


using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        BitmapImage<GrayPixel> obj; //qua crei gli oggetti
        int w = 3;  //nel test creo la matrice di Laplace e si prova con l' EdgeDetection
        int h = 3;
        Filter *filter;

        ClassDeclaration() {
            obj = (-2, -2); //puoi metterci un costruttore quindi li inizializzi
            // grayImage = (3, 2);       //se metto questo fallisce il primo test
        }
    };
}


//Qua si devono fare i test

TEST_F(ClassDeclaration, creazioneImmagine) {
    ASSERT_EQ(1, obj.getWidth());
}

TEST_F(ClassDeclaration, nameOfYourTest2) {
    ASSERT_EQ("", "");
}

TEST_F(ClassDeclaration, matrice_predefinita_e_edge_detection_Gray) {

    PGM grayImage(w, h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            GrayPixel u(static_cast<unsigned char>(1)); //tutti i pixel esterni
            grayImage.pgmImage.setPixel(i, j, u);
        }
    }
    GrayPixel v(static_cast<unsigned char>(8)); //pixel centrale
    grayImage.pgmImage.setPixel(1, 1, v);


    cout << "Matrice di Laplace con i -1 cambiati di segno" << endl; //stampa
    for (int i = 0; i < h; i++) {
        cout << " " << endl;
        for (int j = 0; j < w; j++) {
            cout << (static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray())) << " ";
        }
    }

    filter = new EdgeDetection; // qui c'è la prova
    grayImage.matrixConvolutionPGM(*filter); //ho levato l'eccezione tanto ci pensano i test agli errori
    cout << endl << "\nL'immagine filtrata e': " << endl;
    for (int i = 0; i < h; i++) {
        cout << endl;
        for (int j = 0; j < w; j++) {
            if ((i == 0 && j == 0) || (i == 2 && j == 2)) {
                cout << (static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray())) << " ";
                ASSERT_EQ(8, static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray()));
            }
            else {
                cout << (static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray())) << " ";
                ASSERT_EQ(0, static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray()));
            }
        }
    }
    cout << endl;
    delete filter;

}

TEST_F(ClassDeclaration, matrice_predefinita_e_edge_detection_RGB) {

    PPM coloredImage(w, h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            RGBPixel u(static_cast<unsigned char>(1),
                       static_cast<unsigned char>(1),
                       static_cast<unsigned char>(1)); //tutti i pixel esterni
            coloredImage.ppmImage.setPixel(i, j, u);
        }
    }
    RGBPixel v(static_cast<unsigned char>(8),
               static_cast<unsigned char>(8),
               static_cast<unsigned char>(8)); //pixel centrale
    coloredImage.ppmImage.setPixel(1, 1, v);


    cout << "Matrice di Laplace con i -1 cambiati di segno" << endl; //stampa ho cambiato il segno per evitare che
    for (int i = 0; i < h; i++) { //i pixel impostino 0 ai colori(la convoluzone torna uguale)
        cout << " " << endl;
        for (int j = 0; j < w; j++) {
            cout << "(" << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB())) << ") ";
        }
    }

    filter = new EdgeDetection;
    coloredImage.matrixConvolutionPPM(*filter); //ho levato l'eccezione tanto ci pensano i test agli errori
    cout << endl << "\nLa matrice filtrata e': " << endl;
    for (int i = 0; i < h; i++) {
        cout << endl;
        for (int j = 0; j < w; j++) {
            cout << "(" << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB())) << ") ";
            if ((i == 0 && j == 0) || (i == 2 && j == 2)) {
                ASSERT_EQ(8, static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR()));
                ASSERT_EQ(8, static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG()));
                ASSERT_EQ(8, static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB()));
            } else {
                ASSERT_EQ(0, static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR()));
                ASSERT_EQ(0, static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG()));
                ASSERT_EQ(0, static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB()));
            }
        }
    }
    cout << endl;
    delete filter;
}