//
// Created by Utente on 30/07/2018.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "BitmapImage.h"//qui si include la classe da testare
#include "Filter.h"
#include "EdgeDetection.h"
#include "Identity.h"
#include "Blur.h"
#include "Emboss.h"
#include "Sharpen.h"

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

TEST_F(ClassDeclaration, matrice_predefinita_e_edge_detection_RGB) {
    PPM coloredImage(w, h);
    int q = 1;
    Filter *filtro = new EdgeDetection;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            RGBPixel u(static_cast<unsigned char>(q),
                       static_cast<unsigned char>(q),
                       static_cast<unsigned char>(q));
            coloredImage.ppmImage.setPixel(i, j, u);
            q++;
        }
    }
    cout << "La matrice creata è: " << endl; //stampa
    for (int i = 0; i < h; i++) {
        cout << " " << endl;
        for (int j = 0; j < w; j++) {
            cout << "(" << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB())) << ") ";
        }
    }
    coloredImage.matrixConvolutionPPM(*filtro); //ho levato l'eccezione tanto ci pensano i test agli errori
    cout << endl << "\nLa matrice filtrata e': " << endl;
    for (int i = 0; i < h; i++) {
        cout << endl;
        for (int j = 0; j < w; j++) {
            cout << "(" << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB())) << ") ";
        }
    }
    cout << endl;
    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getR()));
    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getG()));
    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getB()));

    ASSERT_EQ(10,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getR()));
    ASSERT_EQ(10,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getG()));
    ASSERT_EQ(10,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getB()));

    ASSERT_EQ(10,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getR()));
    ASSERT_EQ(10,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getG()));
    ASSERT_EQ(10,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getB()));

    ASSERT_EQ(10,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getR()));
    ASSERT_EQ(10,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getG()));
    ASSERT_EQ(10,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getB())); //1a colonna


    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getR()));
    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getG()));
    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getB()));   //2a colonna


    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getR()));
    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getG()));
    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getB())); //3a colonna


    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getR()));
    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getG()));
    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getB())); //4a colonna


    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getB()));

    ASSERT_EQ(19,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getR()));
    ASSERT_EQ(19,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getG()));
    ASSERT_EQ(19,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getB())); //5a colonna


    delete filtro;
}






TEST_F(ClassDeclaration, matrice_predefinita_e_edge_detection_gray){
    PGM grayImage(w, h);
    int p = 1;
    Filter *filtro = new EdgeDetection;// qui c'è la prova
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            GrayPixel u(static_cast<unsigned char>(p));
            grayImage.pgmImage.setPixel(i, j, u);
            p++;
        }
    }
    cout << "La matrice creata è: " << endl; //stampa
    for (int i = 0; i < h; i++) {
        cout << " " << endl;
        for (int j = 0; j < w; j++) {
            cout << (static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray())) << " ";
        }
    }
    grayImage.matrixConvolutionPGM(*filtro); //ho levato l'eccezione tanto ci pensano i test agli errori
    cout << endl << "\nL'immagine filtrata e': " << endl;
    for (int i = 0; i < h; i++) {
        cout << endl;
        for (int j = 0; j < w; j++) {
            cout << (static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray())) << " ";
        }
    }
    cout << endl;
    ASSERT_EQ(7,static_cast<int> (grayImage.pgmImage.getBuffer()[0].getGray()));
    ASSERT_EQ(10,static_cast<int> (grayImage.pgmImage.getBuffer()[1].getGray()));
    ASSERT_EQ(10,static_cast<int> (grayImage.pgmImage.getBuffer()[2].getGray()));
    ASSERT_EQ(10,static_cast<int> (grayImage.pgmImage.getBuffer()[3].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[4].getGray()));  //1a colonna

    ASSERT_EQ(2,static_cast<int> (grayImage.pgmImage.getBuffer()[5].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[6].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[7].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[8].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[9].getGray()));  //2a colonna

    ASSERT_EQ(2,static_cast<int> (grayImage.pgmImage.getBuffer()[10].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[11].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[12].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[13].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[14].getGray())); //3a colonna

    ASSERT_EQ(2,static_cast<int> (grayImage.pgmImage.getBuffer()[15].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[16].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[17].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[18].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[19].getGray())); //4a colonna

    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[20].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[21].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[22].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[23].getGray()));
    ASSERT_EQ(19,static_cast<int> (grayImage.pgmImage.getBuffer()[24].getGray()));//5a colonna


    delete filtro;
}


TEST_F(ClassDeclaration, matrice_predefinita_e_identity_RGB) {
    PPM coloredImage(w, h);
    int q = 1;
    Filter *filtro = new Identity;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            RGBPixel u(static_cast<unsigned char>(q),
                       static_cast<unsigned char>(q),
                       static_cast<unsigned char>(q));
            coloredImage.ppmImage.setPixel(i, j, u);
            q++;
        }
    }
    cout << "La matrice creata è: " << endl; //stampa
    for (int i = 0; i < h; i++) {
        cout << " " << endl;
        for (int j = 0; j < w; j++) {
            cout << "(" << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB())) << ") ";
        }
    }
    coloredImage.matrixConvolutionPPM(*filtro); //ho levato l'eccezione tanto ci pensano i test agli errori
    cout << endl << "\nLa matrice filtrata e': " << endl;
    for (int i = 0; i < h; i++) {
        cout << endl;
        for (int j = 0; j < w; j++) {
            cout << "(" << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB())) << ") ";
        }
    }
    cout << endl;
    ASSERT_EQ(1,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getR()));
    ASSERT_EQ(1,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getG()));
    ASSERT_EQ(1,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getB()));

    ASSERT_EQ(6,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getR()));
    ASSERT_EQ(6,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getG()));
    ASSERT_EQ(6,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getB()));

    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getR()));
    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getG()));
    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getB()));

    ASSERT_EQ(16,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getR()));
    ASSERT_EQ(16,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getG()));
    ASSERT_EQ(16,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getB()));

    ASSERT_EQ(21,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getR()));
    ASSERT_EQ(21,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getG()));
    ASSERT_EQ(21,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getB())); //1a colonna


    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getR()));
    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getG()));
    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getB()));

    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getR()));
    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getG()));
    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getB()));

    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getR()));
    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getG()));
    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getB()));

    ASSERT_EQ(17,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getR()));
    ASSERT_EQ(17,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getG()));
    ASSERT_EQ(17,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getB()));

    ASSERT_EQ(22,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getR()));
    ASSERT_EQ(22,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getG()));
    ASSERT_EQ(22,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getB()));   //2a colonna


    ASSERT_EQ(3,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getR()));
    ASSERT_EQ(3,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getG()));
    ASSERT_EQ(3,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getB()));

    ASSERT_EQ(8,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getR()));
    ASSERT_EQ(8,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getG()));
    ASSERT_EQ(8,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getB()));

    ASSERT_EQ(13,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getR()));
    ASSERT_EQ(13,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getG()));
    ASSERT_EQ(13,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getB()));

    ASSERT_EQ(18,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getR()));
    ASSERT_EQ(18,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getG()));
    ASSERT_EQ(18,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getB()));

    ASSERT_EQ(23,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getR()));
    ASSERT_EQ(23,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getG()));
    ASSERT_EQ(23,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getB())); //3a colonna


    ASSERT_EQ(4,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getR()));
    ASSERT_EQ(4,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getG()));
    ASSERT_EQ(4,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getB()));

    ASSERT_EQ(9,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getR()));
    ASSERT_EQ(9,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getG()));
    ASSERT_EQ(9,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getB()));

    ASSERT_EQ(14,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getR()));
    ASSERT_EQ(14,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getG()));
    ASSERT_EQ(14,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getB()));

    ASSERT_EQ(19,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getR()));
    ASSERT_EQ(19,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getG()));
    ASSERT_EQ(19,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getB()));

    ASSERT_EQ(24,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getR()));
    ASSERT_EQ(24,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getG()));
    ASSERT_EQ(24,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getB())); //4a colonna


    ASSERT_EQ(5,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getR()));
    ASSERT_EQ(5,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getG()));
    ASSERT_EQ(5,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getB()));

    ASSERT_EQ(10,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getR()));
    ASSERT_EQ(10,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getG()));
    ASSERT_EQ(10,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getB()));

    ASSERT_EQ(15,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getR()));
    ASSERT_EQ(15,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getG()));
    ASSERT_EQ(15,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getB()));

    ASSERT_EQ(20,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getR()));
    ASSERT_EQ(20,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getG()));
    ASSERT_EQ(20,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getB()));

    ASSERT_EQ(25,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getR()));
    ASSERT_EQ(25,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getG()));
    ASSERT_EQ(25,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getB())); //5a colonna


    delete filtro;
}

TEST_F(ClassDeclaration, matrice_predefinita_e_identity_gray){
    PGM grayImage(w, h);
    int p = 1;
    Filter *filtro = new Identity;// qui c'è la prova
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            GrayPixel u(static_cast<unsigned char>(p));
            grayImage.pgmImage.setPixel(i, j, u);
            p++;
        }
    }
    cout << "La matrice creata è: " << endl; //stampa
    for (int i = 0; i < h; i++) {
        cout << " " << endl;
        for (int j = 0; j < w; j++) {
            cout << (static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray())) << " ";
        }
    }
    grayImage.matrixConvolutionPGM(*filtro); //ho levato l'eccezione tanto ci pensano i test agli errori
    cout << endl << "\nL'immagine filtrata e': " << endl;
    for (int i = 0; i < h; i++) {
        cout << endl;
        for (int j = 0; j < w; j++) {
            cout << (static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray())) << " ";
        }
    }
    cout << endl;
    ASSERT_EQ(1,static_cast<int> (grayImage.pgmImage.getBuffer()[0].getGray()));
    ASSERT_EQ(6,static_cast<int> (grayImage.pgmImage.getBuffer()[1].getGray()));
    ASSERT_EQ(11,static_cast<int> (grayImage.pgmImage.getBuffer()[2].getGray()));
    ASSERT_EQ(16,static_cast<int> (grayImage.pgmImage.getBuffer()[3].getGray()));
    ASSERT_EQ(21,static_cast<int> (grayImage.pgmImage.getBuffer()[4].getGray()));  //1a colonna

    ASSERT_EQ(2,static_cast<int> (grayImage.pgmImage.getBuffer()[5].getGray()));
    ASSERT_EQ(7,static_cast<int> (grayImage.pgmImage.getBuffer()[6].getGray()));
    ASSERT_EQ(12,static_cast<int> (grayImage.pgmImage.getBuffer()[7].getGray()));
    ASSERT_EQ(17,static_cast<int> (grayImage.pgmImage.getBuffer()[8].getGray()));
    ASSERT_EQ(22,static_cast<int> (grayImage.pgmImage.getBuffer()[9].getGray()));  //2a colonna

    ASSERT_EQ(3,static_cast<int> (grayImage.pgmImage.getBuffer()[10].getGray()));
    ASSERT_EQ(8,static_cast<int> (grayImage.pgmImage.getBuffer()[11].getGray()));
    ASSERT_EQ(13,static_cast<int> (grayImage.pgmImage.getBuffer()[12].getGray()));
    ASSERT_EQ(18,static_cast<int> (grayImage.pgmImage.getBuffer()[13].getGray()));
    ASSERT_EQ(23,static_cast<int> (grayImage.pgmImage.getBuffer()[14].getGray())); //3a colonna

    ASSERT_EQ(4,static_cast<int> (grayImage.pgmImage.getBuffer()[15].getGray()));
    ASSERT_EQ(9,static_cast<int> (grayImage.pgmImage.getBuffer()[16].getGray()));
    ASSERT_EQ(14,static_cast<int> (grayImage.pgmImage.getBuffer()[17].getGray()));
    ASSERT_EQ(19,static_cast<int> (grayImage.pgmImage.getBuffer()[18].getGray()));
    ASSERT_EQ(24,static_cast<int> (grayImage.pgmImage.getBuffer()[19].getGray())); //4a colonna

    ASSERT_EQ(5,static_cast<int> (grayImage.pgmImage.getBuffer()[20].getGray()));
    ASSERT_EQ(10,static_cast<int> (grayImage.pgmImage.getBuffer()[21].getGray()));
    ASSERT_EQ(15,static_cast<int> (grayImage.pgmImage.getBuffer()[22].getGray()));
    ASSERT_EQ(20,static_cast<int> (grayImage.pgmImage.getBuffer()[23].getGray()));
    ASSERT_EQ(25,static_cast<int> (grayImage.pgmImage.getBuffer()[24].getGray()));//5a colonna


    delete filtro;
}


TEST_F(ClassDeclaration, matrice_predefinita_e_blur_RGB) {
    PPM coloredImage(w, h);
    int q = 1;
    Filter *filtro = new Blur;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            RGBPixel u(static_cast<unsigned char>(q),
                       static_cast<unsigned char>(q),
                       static_cast<unsigned char>(q));
            coloredImage.ppmImage.setPixel(i, j, u);
            q++;
        }
    }
    cout << "La matrice creata è: " << endl; //stampa
    for (int i = 0; i < h; i++) {
        cout << " " << endl;
        for (int j = 0; j < w; j++) {
            cout << "(" << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB())) << ") ";
        }
    }
    coloredImage.matrixConvolutionPPM(*filtro); //ho levato l'eccezione tanto ci pensano i test agli errori
    cout << endl << "\nLa matrice filtrata e': " << endl;
    for (int i = 0; i < h; i++) {
        cout << endl;
        for (int j = 0; j < w; j++) {
            cout << "(" << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB())) << ") ";
        }
    }
    cout << endl;
    ASSERT_EQ(1,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getR()));
    ASSERT_EQ(1,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getG()));
    ASSERT_EQ(1,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getB()));

    ASSERT_EQ(4,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getR()));
    ASSERT_EQ(4,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getG()));
    ASSERT_EQ(4,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getB()));

    ASSERT_EQ(8,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getR()));
    ASSERT_EQ(8,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getG()));
    ASSERT_EQ(8,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getB()));

    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getR()));
    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getG()));
    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getB()));

    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getR()));
    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getG()));
    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getB())); //1a colonna


    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getR()));
    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getG()));
    ASSERT_EQ(2,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getB()));

    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getR()));
    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getG()));
    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getB()));

    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getR()));
    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getG()));
    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getB()));

    ASSERT_EQ(17,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getR()));
    ASSERT_EQ(17,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getG()));
    ASSERT_EQ(17,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getB()));

    ASSERT_EQ(15,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getR()));
    ASSERT_EQ(15,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getG()));
    ASSERT_EQ(15,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getB()));   //2a colonna


    ASSERT_EQ(3,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getR()));
    ASSERT_EQ(3,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getG()));
    ASSERT_EQ(3,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getB()));

    ASSERT_EQ(8,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getR()));
    ASSERT_EQ(8,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getG()));
    ASSERT_EQ(8,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getB()));

    ASSERT_EQ(13,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getR()));
    ASSERT_EQ(13,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getG()));
    ASSERT_EQ(13,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getB()));

    ASSERT_EQ(18,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getR()));
    ASSERT_EQ(18,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getG()));
    ASSERT_EQ(18,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getB()));

    ASSERT_EQ(16,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getR()));
    ASSERT_EQ(16,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getG()));
    ASSERT_EQ(16,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getB())); //3a colonna


    ASSERT_EQ(4,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getR()));
    ASSERT_EQ(4,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getG()));
    ASSERT_EQ(4,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getB()));

    ASSERT_EQ(9,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getR()));
    ASSERT_EQ(9,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getG()));
    ASSERT_EQ(9,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getB()));

    ASSERT_EQ(14,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getR()));
    ASSERT_EQ(14,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getG()));
    ASSERT_EQ(14,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getB()));

    ASSERT_EQ(19,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getR()));
    ASSERT_EQ(19,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getG()));
    ASSERT_EQ(19,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getB()));

    ASSERT_EQ(16,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getR()));
    ASSERT_EQ(16,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getG()));
    ASSERT_EQ(16,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getB())); //4a colonna


    ASSERT_EQ(3,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getR()));
    ASSERT_EQ(3,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getG()));
    ASSERT_EQ(3,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getB()));

    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getR()));
    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getG()));
    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getB()));

    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getR()));
    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getG()));
    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getB()));

    ASSERT_EQ(14,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getR()));
    ASSERT_EQ(14,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getG()));
    ASSERT_EQ(14,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getB()));

    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getR()));
    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getG()));
    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getB())); //5a colonna


    delete filtro;
}

TEST_F(ClassDeclaration, matrice_predefinita_e_blur_gray){
    PGM grayImage(w, h);
    int p = 1;
    Filter *filtro = new Blur;// qui c'è la prova
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            GrayPixel u(static_cast<unsigned char>(p));
            grayImage.pgmImage.setPixel(i, j, u);
            p++;
        }
    }
    cout << "La matrice creata è: " << endl; //stampa
    for (int i = 0; i < h; i++) {
        cout << " " << endl;
        for (int j = 0; j < w; j++) {
            cout << (static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray())) << " ";
        }
    }
    grayImage.matrixConvolutionPGM(*filtro); //ho levato l'eccezione tanto ci pensano i test agli errori
    cout << endl << "\nL'immagine filtrata e': " << endl;
    for (int i = 0; i < h; i++) {
        cout << endl;
        for (int j = 0; j < w; j++) {
            cout << (static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray())) << " ";
        }
    }
    cout << endl;
    ASSERT_EQ(1,static_cast<int> (grayImage.pgmImage.getBuffer()[0].getGray()));
    ASSERT_EQ(4,static_cast<int> (grayImage.pgmImage.getBuffer()[1].getGray()));
    ASSERT_EQ(8,static_cast<int> (grayImage.pgmImage.getBuffer()[2].getGray()));
    ASSERT_EQ(12,static_cast<int> (grayImage.pgmImage.getBuffer()[3].getGray()));
    ASSERT_EQ(11,static_cast<int> (grayImage.pgmImage.getBuffer()[4].getGray()));  //1a colonna

    ASSERT_EQ(2,static_cast<int> (grayImage.pgmImage.getBuffer()[5].getGray()));
    ASSERT_EQ(7,static_cast<int> (grayImage.pgmImage.getBuffer()[6].getGray()));
    ASSERT_EQ(12,static_cast<int> (grayImage.pgmImage.getBuffer()[7].getGray()));
    ASSERT_EQ(17,static_cast<int> (grayImage.pgmImage.getBuffer()[8].getGray()));
    ASSERT_EQ(15,static_cast<int> (grayImage.pgmImage.getBuffer()[9].getGray()));  //2a colonna

    ASSERT_EQ(3,static_cast<int> (grayImage.pgmImage.getBuffer()[10].getGray()));
    ASSERT_EQ(8,static_cast<int> (grayImage.pgmImage.getBuffer()[11].getGray()));
    ASSERT_EQ(13,static_cast<int> (grayImage.pgmImage.getBuffer()[12].getGray()));
    ASSERT_EQ(18,static_cast<int> (grayImage.pgmImage.getBuffer()[13].getGray()));
    ASSERT_EQ(16,static_cast<int> (grayImage.pgmImage.getBuffer()[14].getGray())); //3a colonna

    ASSERT_EQ(4,static_cast<int> (grayImage.pgmImage.getBuffer()[15].getGray()));
    ASSERT_EQ(9,static_cast<int> (grayImage.pgmImage.getBuffer()[16].getGray()));
    ASSERT_EQ(14,static_cast<int> (grayImage.pgmImage.getBuffer()[17].getGray()));
    ASSERT_EQ(19,static_cast<int> (grayImage.pgmImage.getBuffer()[18].getGray()));
    ASSERT_EQ(16,static_cast<int> (grayImage.pgmImage.getBuffer()[19].getGray())); //4a colonna

    ASSERT_EQ(3,static_cast<int> (grayImage.pgmImage.getBuffer()[20].getGray()));
    ASSERT_EQ(7,static_cast<int> (grayImage.pgmImage.getBuffer()[21].getGray()));
    ASSERT_EQ(11,static_cast<int> (grayImage.pgmImage.getBuffer()[22].getGray()));
    ASSERT_EQ(14,static_cast<int> (grayImage.pgmImage.getBuffer()[23].getGray()));
    ASSERT_EQ(12,static_cast<int> (grayImage.pgmImage.getBuffer()[24].getGray()));//5a colonna


    delete filtro;
}

TEST_F(ClassDeclaration, matrice_predefinita_e_emboss_RGB) {
    PPM coloredImage(w, h);
    int q = 1;
    Filter *filtro = new Emboss;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            RGBPixel u(static_cast<unsigned char>(q),
                       static_cast<unsigned char>(q),
                       static_cast<unsigned char>(q));
            coloredImage.ppmImage.setPixel(i, j, u);
            q++;
        }
    }
    cout << "La matrice creata è: " << endl; //stampa
    for (int i = 0; i < h; i++) {
        cout << " " << endl;
        for (int j = 0; j < w; j++) {
            cout << "(" << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB())) << ") ";
        }
    }
    coloredImage.matrixConvolutionPPM(*filtro); //ho levato l'eccezione tanto ci pensano i test agli errori
    cout << endl << "\nLa matrice filtrata e': " << endl;
    for (int i = 0; i < h; i++) {
        cout << endl;
        for (int j = 0; j < w; j++) {
            cout << "(" << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB())) << ") ";
        }
    }
    cout << endl;
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getB()));

    ASSERT_EQ(15,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getR()));
    ASSERT_EQ(15,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getG()));
    ASSERT_EQ(15,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getB())); //1a colonna


    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getB()));

    ASSERT_EQ(69,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getR()));
    ASSERT_EQ(69,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getG()));
    ASSERT_EQ(69,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getB()));   //2a colonna


    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getB()));

    ASSERT_EQ(73,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getR()));
    ASSERT_EQ(73,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getG()));
    ASSERT_EQ(73,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getB())); //3a colonna


    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getB()));

    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getB()));

    ASSERT_EQ(77,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getR()));
    ASSERT_EQ(77,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getG()));
    ASSERT_EQ(77,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getB())); //4a colonna


    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getB()));

    ASSERT_EQ(17,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getR()));
    ASSERT_EQ(17,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getG()));
    ASSERT_EQ(17,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getB()));

    ASSERT_EQ(37,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getR()));
    ASSERT_EQ(37,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getG()));
    ASSERT_EQ(37,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getB()));

    ASSERT_EQ(57,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getR()));
    ASSERT_EQ(57,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getG()));
    ASSERT_EQ(57,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getB()));

    ASSERT_EQ(107,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getR()));
    ASSERT_EQ(107,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getG()));
    ASSERT_EQ(107,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getB())); //5a colonna


    delete filtro;
}

TEST_F(ClassDeclaration, matrice_predefinita_e_emboss_gray){
    PGM grayImage(w, h);
    int p = 1;
    Filter *filtro = new Emboss;// qui c'è la prova
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            GrayPixel u(static_cast<unsigned char>(p));
            grayImage.pgmImage.setPixel(i, j, u);
            p++;
        }
    }
    cout << "La matrice creata è: " << endl; //stampa
    for (int i = 0; i < h; i++) {
        cout << " " << endl;
        for (int j = 0; j < w; j++) {
            cout << (static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray())) << " ";
        }
    }
    grayImage.matrixConvolutionPGM(*filtro); //ho levato l'eccezione tanto ci pensano i test agli errori
    cout << endl << "\nL'immagine filtrata e': " << endl;
    for (int i = 0; i < h; i++) {
        cout << endl;
        for (int j = 0; j < w; j++) {
            cout << (static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray())) << " ";
        }
    }
    cout << endl;
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[0].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[1].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[2].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[3].getGray()));
    ASSERT_EQ(15,static_cast<int> (grayImage.pgmImage.getBuffer()[4].getGray()));  //1a colonna

    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[5].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[6].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[7].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[8].getGray()));
    ASSERT_EQ(69,static_cast<int> (grayImage.pgmImage.getBuffer()[9].getGray()));  //2a colonna

    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[10].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[11].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[12].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[13].getGray()));
    ASSERT_EQ(73,static_cast<int> (grayImage.pgmImage.getBuffer()[14].getGray())); //3a colonna

    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[15].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[16].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[17].getGray()));
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[18].getGray()));
    ASSERT_EQ(77,static_cast<int> (grayImage.pgmImage.getBuffer()[19].getGray())); //4a colonna

    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[20].getGray()));
    ASSERT_EQ(17,static_cast<int> (grayImage.pgmImage.getBuffer()[21].getGray()));
    ASSERT_EQ(37,static_cast<int> (grayImage.pgmImage.getBuffer()[22].getGray()));
    ASSERT_EQ(57,static_cast<int> (grayImage.pgmImage.getBuffer()[23].getGray()));
    ASSERT_EQ(107,static_cast<int> (grayImage.pgmImage.getBuffer()[24].getGray()));//5a colonna


    delete filtro;
}

TEST_F(ClassDeclaration, matrice_predefinita_e_sharpen_RGB) {
    PPM coloredImage(w, h);
    int q = 1;
    Filter *filtro = new Sharpen;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            RGBPixel u(static_cast<unsigned char>(q),
                       static_cast<unsigned char>(q),
                       static_cast<unsigned char>(q));
            coloredImage.ppmImage.setPixel(i, j, u);
            q++;
        }
    }
    cout << "La matrice creata è: " << endl; //stampa
    for (int i = 0; i < h; i++) {
        cout << " " << endl;
        for (int j = 0; j < w; j++) {
            cout << "(" << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB())) << ") ";
        }
    }
    coloredImage.matrixConvolutionPPM(*filtro); //ho levato l'eccezione tanto ci pensano i test agli errori
    cout << endl << "\nLa matrice filtrata e': " << endl;
    for (int i = 0; i < h; i++) {
        cout << endl;
        for (int j = 0; j < w; j++) {
            cout << "(" << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getR())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getG())) << ", ";
            cout << (static_cast<int> (coloredImage.ppmImage.getBuffer()[j * h + i].getB())) << ") ";
        }
    }
    cout << endl;
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[0].getB()));

    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getR()));
    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getG()));
    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[1].getB()));

    ASSERT_EQ(21,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getR()));
    ASSERT_EQ(21,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getG()));
    ASSERT_EQ(21,static_cast<int> (coloredImage.ppmImage.getBuffer()[2].getB()));

    ASSERT_EQ(31,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getR()));
    ASSERT_EQ(31,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getG()));
    ASSERT_EQ(31,static_cast<int> (coloredImage.ppmImage.getBuffer()[3].getB()));

    ASSERT_EQ(67,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getR()));
    ASSERT_EQ(67,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getG()));
    ASSERT_EQ(67,static_cast<int> (coloredImage.ppmImage.getBuffer()[4].getB())); //1a colonna


    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getR()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getG()));
    ASSERT_EQ(0,static_cast<int> (coloredImage.ppmImage.getBuffer()[5].getB()));

    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getR()));
    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getG()));
    ASSERT_EQ(7,static_cast<int> (coloredImage.ppmImage.getBuffer()[6].getB()));

    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getR()));
    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getG()));
    ASSERT_EQ(12,static_cast<int> (coloredImage.ppmImage.getBuffer()[7].getB()));

    ASSERT_EQ(17,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getR()));
    ASSERT_EQ(17,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getG()));
    ASSERT_EQ(17,static_cast<int> (coloredImage.ppmImage.getBuffer()[8].getB()));

    ASSERT_EQ(49,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getR()));
    ASSERT_EQ(49,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getG()));
    ASSERT_EQ(49,static_cast<int> (coloredImage.ppmImage.getBuffer()[9].getB()));   //2a colonna


    ASSERT_EQ(1,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getR()));
    ASSERT_EQ(1,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getG()));
    ASSERT_EQ(1,static_cast<int> (coloredImage.ppmImage.getBuffer()[10].getB()));

    ASSERT_EQ(8,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getR()));
    ASSERT_EQ(8,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getG()));
    ASSERT_EQ(8,static_cast<int> (coloredImage.ppmImage.getBuffer()[11].getB()));

    ASSERT_EQ(13,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getR()));
    ASSERT_EQ(13,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getG()));
    ASSERT_EQ(13,static_cast<int> (coloredImage.ppmImage.getBuffer()[12].getB()));

    ASSERT_EQ(18,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getR()));
    ASSERT_EQ(18,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getG()));
    ASSERT_EQ(18,static_cast<int> (coloredImage.ppmImage.getBuffer()[13].getB()));

    ASSERT_EQ(51,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getR()));
    ASSERT_EQ(51,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getG()));
    ASSERT_EQ(51,static_cast<int> (coloredImage.ppmImage.getBuffer()[14].getB())); //3a colonna


    ASSERT_EQ(3,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getR()));
    ASSERT_EQ(3,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getG()));
    ASSERT_EQ(3,static_cast<int> (coloredImage.ppmImage.getBuffer()[15].getB()));

    ASSERT_EQ(9,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getR()));
    ASSERT_EQ(9,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getG()));
    ASSERT_EQ(9,static_cast<int> (coloredImage.ppmImage.getBuffer()[16].getB()));

    ASSERT_EQ(14,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getR()));
    ASSERT_EQ(14,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getG()));
    ASSERT_EQ(14,static_cast<int> (coloredImage.ppmImage.getBuffer()[17].getB()));

    ASSERT_EQ(19,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getR()));
    ASSERT_EQ(19,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getG()));
    ASSERT_EQ(19,static_cast<int> (coloredImage.ppmImage.getBuffer()[18].getB()));

    ASSERT_EQ(53,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getR()));
    ASSERT_EQ(53,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getG()));
    ASSERT_EQ(53,static_cast<int> (coloredImage.ppmImage.getBuffer()[19].getB())); //4a colonna


    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getR()));
    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getG()));
    ASSERT_EQ(11,static_cast<int> (coloredImage.ppmImage.getBuffer()[20].getB()));

    ASSERT_EQ(21,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getR()));
    ASSERT_EQ(21,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getG()));
    ASSERT_EQ(21,static_cast<int> (coloredImage.ppmImage.getBuffer()[21].getB()));

    ASSERT_EQ(31,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getR()));
    ASSERT_EQ(31,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getG()));
    ASSERT_EQ(31,static_cast<int> (coloredImage.ppmImage.getBuffer()[22].getB()));

    ASSERT_EQ(41,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getR()));
    ASSERT_EQ(41,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getG()));
    ASSERT_EQ(41,static_cast<int> (coloredImage.ppmImage.getBuffer()[23].getB()));

    ASSERT_EQ(81,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getR()));
    ASSERT_EQ(81,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getG()));
    ASSERT_EQ(81,static_cast<int> (coloredImage.ppmImage.getBuffer()[24].getB())); //5a colonna


    delete filtro;
}

TEST_F(ClassDeclaration, matrice_predefinita_e_sharpen_gray){
    PGM grayImage(w, h);
    int p = 1;
    Filter *filtro = new Sharpen;// qui c'è la prova
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            GrayPixel u(static_cast<unsigned char>(p));
            grayImage.pgmImage.setPixel(i, j, u);
            p++;
        }
    }
    cout << "La matrice creata è: " << endl; //stampa
    for (int i = 0; i < h; i++) {
        cout << " " << endl;
        for (int j = 0; j < w; j++) {
            cout << (static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray())) << " ";
        }
    }
    grayImage.matrixConvolutionPGM(*filtro); //ho levato l'eccezione tanto ci pensano i test agli errori
    cout << endl << "\nL'immagine filtrata e': " << endl;
    for (int i = 0; i < h; i++) {
        cout << endl;
        for (int j = 0; j < w; j++) {
            cout << (static_cast<int> (grayImage.pgmImage.getBuffer()[j * h + i].getGray())) << " ";
        }
    }
    cout << endl;
    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[0].getGray()));
    ASSERT_EQ(11,static_cast<int> (grayImage.pgmImage.getBuffer()[1].getGray()));
    ASSERT_EQ(21,static_cast<int> (grayImage.pgmImage.getBuffer()[2].getGray()));
    ASSERT_EQ(31,static_cast<int> (grayImage.pgmImage.getBuffer()[3].getGray()));
    ASSERT_EQ(67,static_cast<int> (grayImage.pgmImage.getBuffer()[4].getGray()));  //1a colonna

    ASSERT_EQ(0,static_cast<int> (grayImage.pgmImage.getBuffer()[5].getGray()));
    ASSERT_EQ(7,static_cast<int> (grayImage.pgmImage.getBuffer()[6].getGray()));
    ASSERT_EQ(12,static_cast<int> (grayImage.pgmImage.getBuffer()[7].getGray()));
    ASSERT_EQ(17,static_cast<int> (grayImage.pgmImage.getBuffer()[8].getGray()));
    ASSERT_EQ(49,static_cast<int> (grayImage.pgmImage.getBuffer()[9].getGray()));  //2a colonna

    ASSERT_EQ(1,static_cast<int> (grayImage.pgmImage.getBuffer()[10].getGray()));
    ASSERT_EQ(8,static_cast<int> (grayImage.pgmImage.getBuffer()[11].getGray()));
    ASSERT_EQ(13,static_cast<int> (grayImage.pgmImage.getBuffer()[12].getGray()));
    ASSERT_EQ(18,static_cast<int> (grayImage.pgmImage.getBuffer()[13].getGray()));
    ASSERT_EQ(51,static_cast<int> (grayImage.pgmImage.getBuffer()[14].getGray())); //3a colonna

    ASSERT_EQ(3,static_cast<int> (grayImage.pgmImage.getBuffer()[15].getGray()));
    ASSERT_EQ(9,static_cast<int> (grayImage.pgmImage.getBuffer()[16].getGray()));
    ASSERT_EQ(14,static_cast<int> (grayImage.pgmImage.getBuffer()[17].getGray()));
    ASSERT_EQ(19,static_cast<int> (grayImage.pgmImage.getBuffer()[18].getGray()));
    ASSERT_EQ(53,static_cast<int> (grayImage.pgmImage.getBuffer()[19].getGray())); //4a colonna

    ASSERT_EQ(11,static_cast<int> (grayImage.pgmImage.getBuffer()[20].getGray()));
    ASSERT_EQ(21,static_cast<int> (grayImage.pgmImage.getBuffer()[21].getGray()));
    ASSERT_EQ(31,static_cast<int> (grayImage.pgmImage.getBuffer()[22].getGray()));
    ASSERT_EQ(41,static_cast<int> (grayImage.pgmImage.getBuffer()[23].getGray()));
    ASSERT_EQ(81,static_cast<int> (grayImage.pgmImage.getBuffer()[24].getGray()));//5a colonna


    delete filtro;
}