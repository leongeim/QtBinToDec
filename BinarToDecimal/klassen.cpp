#include "klassen.h"
#include <math.h>

void BinarToDecimal::calcBinaryToDec()
{
    uint sum = 0;
    for(int i = 0; i < countBits; i++)
    {
        sum += (cbBinary[i]->checkState() == Qt::Checked ? 1 : 0)  * pow(2, i);
    }

    txtDecimal->setText(QString::number(sum));
}

void BinarToDecimal::calcDecToBinary( QString text)
{
    int bin[32], i;
    int zahl = text.toInt();

    for(i=0; zahl>0; i++)
    {
        bin[i]=zahl%2;
        zahl= zahl/2;
    }

    for (int j = 0; j < i; j++)
    {
        cbBinary[j]->setCheckState(bin[j]== 1 ? Qt::Checked : Qt::Unchecked);
    }
}
