#ifndef RACIONAL_H
#define RACIONAL_H
#include <string>
#include <QString>

using namespace std;

class Racional
{
private:
    int numerador;
    int denominador;
    void reduzRacional()
    {
        int maxdiv=mdc(numerador,denominador);

        numerador=numerador/maxdiv;
        denominador=denominador/maxdiv;
    }
    int mdc(int n1,int n2)const //Algoritmo de Euclides (divisões sucessivas até o numero se tornar 0)
    {
        while(n2!=0)
        {
            int aux;
            aux=n2;
            n2=n1%n2;
            n1=aux;
        }

        return n1;
    }
    int mmc(int n1,int n2)const
    {
        return n1*n2/mdc(n1,n2);
    }

public:
    Racional();
    Racional(int numerador,int denominador);

    void setNumerador(int numerador) {this->numerador=numerador;}
    void setDenominador(int denominador);

    int getNumerador()const {return numerador;}
    int getDenominador()const {return denominador;}

    string obterRacional()const;
    Racional soma(Racional *numero)const;
    Racional subtracao(Racional *numero)const;
    Racional multiplica(Racional *numero)const;
    Racional divisao(Racional *numero)const;
    bool igual(const Racional *numero)const;
};

#endif // RACIONAL_H
