#include "Racional.h"

Racional::Racional()
{
    numerador=0;
    denominador=1;
}

Racional::Racional(int numerador,int denominador)
{
    setNumerador(numerador);
    setDenominador(denominador);
}

void Racional::setDenominador(int denominador)
{
    if(denominador==0)
    {
        throw QString("Invalido.");
    }

    this->denominador=denominador;
}

string Racional::obterRacional()const
{
    string frac;

    if(numerador==denominador)
    {
        return to_string(numerador);
    }

    else if(numerador==0)
    {
        return to_string(numerador);
    }

    frac=to_string(numerador)+'/'+to_string(denominador);

    return frac;
}

Racional Racional::soma(Racional *numero)const
{
    int mmc_denominador=mmc(denominador,numero->denominador);
    int novo_racional;

    novo_racional=(mmc_denominador/denominador)*numerador+(mmc_denominador/numero->denominador)*numero->numerador;

    Racional resultado(novo_racional,mmc_denominador);
    resultado.reduzRacional();

    return resultado;
}

Racional Racional::subtracao(Racional *numero)const
{
    int mmc_denominador=mmc(denominador,numero->denominador);
    int novo_racional;

    novo_racional=(mmc_denominador/denominador)*numerador-(mmc_denominador/numero->denominador)*numero->numerador;

    Racional resultado(novo_racional,mmc_denominador);
    resultado.reduzRacional();

    return resultado;
}

Racional Racional::multiplica(Racional *numero)const
{
    int novo_numerador,novo_denomidador;

    novo_numerador=numerador*numero->numerador;
    novo_denomidador=denominador*numero->denominador;

    Racional resultado(novo_numerador,novo_denomidador);
    resultado.reduzRacional();

    return resultado;
}

Racional Racional::divisao(Racional *numero)const
{
    int novo_numerador,novo_denomidador;

    novo_numerador=numerador*numero->denominador;
    novo_denomidador=denominador*numero->numerador;

    if(novo_numerador==0 && novo_denomidador==0)
    {
        throw QString("Valor indefinido.");
    }

    Racional resultado(novo_numerador,novo_denomidador);
    resultado.reduzRacional();

    return resultado;
}

bool Racional::igual(const Racional *numero)const
{
    Racional racional1=*this; // cria uma cópia do objeto atual
    Racional racional2=*numero; // cria uma cópia do objeto do parametro

    racional1.reduzRacional(); // Número 1
    racional2.reduzRacional(); // Número 2

    return racional1.numerador==racional2.numerador && racional1.denominador==racional2.denominador;
}
