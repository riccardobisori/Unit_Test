//
// Created by Utente on 24/09/2017.
//

// TODO si fa una classe template perchè almeno gli algoritmi vanno bene per più filtri(qualcuno andrà fatto ma ci sono su wikipedia)
// TODO va fatto l' overload del * perchè la convulazione non è il classico prodotto tra matrici
// QUESTA CLASSE PRENDE IN INGRESSO I FILTRI E LI APPLICA ALL'IMMAGINE, ANZI NO SI FA DAL MAIN SENNÒ È UNO SMATTO CON GLI ATTRIBUTI PRIVATI


#ifndef IMAGE_CONVOLUTION_FILTER_H
#define IMAGE_CONVOLUTION_FILTER_H


//#include <stdexcept>


class Filter {
public:
    // virtual Filter();//le matrici di convulazione devono avere dimensione dispari
    virtual ~Filter() = 0;
    int getRows() const;
    int getColumns() const;
    void setRows(int rows);
    void setColumns(int columns);

    float *getBuffer() const;

    void setBuffer(float *buffer);

protected:
    int rows;
    int columns;
    float* buffer;

};

//if((rows * columns)%2 == 0)
//throw (std::out_of_range("La dimensione della matrice deve essere dispari"));
//TODO questa condizione serve se i filtri che si passano non sono predefiniti tipo identity, edgedetection,ecc


#endif //IMAGE_CONVOLUTION_FILTER_H
