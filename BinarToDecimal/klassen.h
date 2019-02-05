#ifndef KLASSEN_H
#define KLASSEN_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QGridLayout>
#include <QApplication>



class BinarToDecimal  : public QWidget
{
    Q_OBJECT
private:
    int countBits = 32;
     QLabel *lblBinary, *lblDecimal;
     QLineEdit *txtDecimal;
     QCheckBox *cbBinary[32];
     QHBoxLayout *bxLayout;
public:
    BinarToDecimal(QWidget * parent = 0, Qt::WindowFlags f = 0) :  QWidget(parent, f)
    {
        this->lblBinary = new QLabel("Binär (Bit "+ QString::number(countBits) + " - 0):", this);
        this->lblDecimal = new QLabel("Dezimal:", this);

        this->txtDecimal = new QLineEdit(this);

        this->bxLayout = new QHBoxLayout(this);

        bxLayout->addSpacing(10);

        bxLayout->addWidget(lblBinary);
        for (int i = countBits -1; i >= 0; i--)
        {
            cbBinary[i] = new QCheckBox(this);
            QObject::connect(this->cbBinary[i], SIGNAL(clicked()), this, SLOT(calcBinaryToDec()));
            bxLayout->addWidget(cbBinary[i]);
        }
        bxLayout->addWidget(lblDecimal);
        bxLayout->addWidget(txtDecimal);

        QObject::connect(this->txtDecimal, SIGNAL(textChanged(QString) ), this, SLOT(calcDecToBinary(QString)));

        this->setLayout(bxLayout);
    }
    ~BinarToDecimal()
    {
    }
public slots:
    void calcBinaryToDec();
    void calcDecToBinary(QString text);
};

#endif // KLASSEN_H
