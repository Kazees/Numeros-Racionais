#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditNumeradorNumero1->setFocus();

    ui->lineEditNumeradorNumero1->setValidator(new QIntValidator(-999,999));
    ui->lineEditDenominadorNumero1->setValidator(new QIntValidator(-999,999));
    ui->lineEditNumeradorNumero2->setValidator(new QIntValidator(-999,999));
    ui->lineEditDenominadorNumero2->setValidator(new QIntValidator(-999,999));

    if((ui->lineEditNumeradorNumero1->text()==""||ui->lineEditDenominadorNumero1->text()=="")||(ui->lineEditNumeradorNumero2->text()==""||ui->lineEditDenominadorNumero2->text()==""))
    {
        ui->pushButtonMostrar->setEnabled(false);
        ui->pushButtonSoma->setEnabled(false);
        ui->pushButtonSubtra->setEnabled(false);
        ui->pushButtonMultiplica->setEnabled(false);
        ui->pushButtonDivisao->setEnabled(false);
        ui->pushButtonSaoIguais->setEnabled(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonNovosNumeros_clicked()
{
    try
    {
        if((ui->lineEditNumeradorNumero1->text()==""||ui->lineEditDenominadorNumero1->text()=="")||(ui->lineEditNumeradorNumero2->text()==""||ui->lineEditDenominadorNumero2->text()==""))
        {
            throw QString("Vazio.");
        }

        ui->lineEditNumeradorNumero1->clear();
        ui->lineEditNumeradorNumero2->clear();
        ui->lineEditDenominadorNumero1->clear();
        ui->lineEditDenominadorNumero2->clear();
        ui->lineEditNumeradorNumero1->setFocus();

        ui->lineEditNumeradorNumero1->setEnabled(true);
        ui->lineEditNumeradorNumero2->setEnabled(true);
        ui->lineEditDenominadorNumero1->setEnabled(true);
        ui->lineEditDenominadorNumero2->setEnabled(true);

        ui->pushButtonMostrar->setEnabled(false);
        ui->pushButtonSoma->setEnabled(false);
        ui->pushButtonSubtra->setEnabled(false);
        ui->pushButtonMultiplica->setEnabled(false);
        ui->pushButtonDivisao->setEnabled(false);
        ui->pushButtonSaoIguais->setEnabled(false);

        ui->textEditResultado->clear();
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->pushButtonMostrar->setEnabled(false);
        ui->pushButtonSoma->setEnabled(false);
        ui->pushButtonSubtra->setEnabled(false);
        ui->pushButtonMultiplica->setEnabled(false);
        ui->pushButtonDivisao->setEnabled(false);
        ui->pushButtonSaoIguais->setEnabled(false);
        ui->lineEditNumeradorNumero1->setFocus();
    }
}

void MainWindow::on_pushButtonMostrar_clicked()
{
    QString saida;

    saida="Numero 1: "+QString::fromStdString(n1->obterRacional())+"\n"+"Numero 2: "+QString::fromStdString(n2->obterRacional());

    ui->textEditResultado->setText(saida);
}


void MainWindow::on_pushButtonArmazenar_clicked()
{
    n1=new Racional();
    n2=new Racional();

    try
    {
        if((ui->lineEditNumeradorNumero1->text()==""||ui->lineEditDenominadorNumero1->text()=="")||(ui->lineEditNumeradorNumero2->text()==""||ui->lineEditDenominadorNumero2->text()==""))
        {
            throw QString("Vazio.");
        }

        ui->pushButtonMostrar->setEnabled(true);
        ui->pushButtonSoma->setEnabled(true);
        ui->pushButtonSubtra->setEnabled(true);
        ui->pushButtonMultiplica->setEnabled(true);
        ui->pushButtonDivisao->setEnabled(true);
        ui->pushButtonSaoIguais->setEnabled(true);

        n1->setNumerador(ui->lineEditNumeradorNumero1->text().toInt());
        n1->setDenominador(ui->lineEditDenominadorNumero1->text().toInt());

        n2->setNumerador(ui->lineEditNumeradorNumero2->text().toInt());
        n2->setDenominador(ui->lineEditDenominadorNumero2->text().toInt());

        ui->lineEditDenominadorNumero1->setEnabled(false);
        ui->lineEditNumeradorNumero1->setEnabled(false);

        ui->lineEditNumeradorNumero2->setEnabled(false);
        ui->lineEditDenominadorNumero2->setEnabled(false);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);

        ui->lineEditDenominadorNumero1->clear();
        ui->lineEditDenominadorNumero2->clear();
        ui->lineEditNumeradorNumero1->setFocus();

        ui->pushButtonMostrar->setEnabled(false);
        ui->pushButtonSoma->setEnabled(false);
        ui->pushButtonSubtra->setEnabled(false);
        ui->pushButtonMultiplica->setEnabled(false);
        ui->pushButtonDivisao->setEnabled(false);
        ui->pushButtonSaoIguais->setEnabled(false);
    }
}


void MainWindow::on_pushButtonSoma_clicked()
{
    QString saida;

    saida="Soma: "+QString::fromStdString(n1->soma(n2).obterRacional());

    ui->textEditResultado->setText(saida);
}


void MainWindow::on_pushButtonSubtra_clicked()
{
    QString saida;

    saida="Subtração: "+QString::fromStdString(n1->subtracao(n2).obterRacional());

    ui->textEditResultado->setText(saida);
}


void MainWindow::on_pushButtonMultiplica_clicked()
{
    QString saida;

    saida="Multiplicação: "+QString::fromStdString(n1->multiplica(n2).obterRacional());

    ui->textEditResultado->setText(saida);
}


void MainWindow::on_pushButtonDivisao_clicked()
{
    QString saida;

    try
    {
        saida="Divisão: "+QString::fromStdString(n1->divisao(n2).obterRacional());

        ui->textEditResultado->setText(saida);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);

        ui->textEditResultado->clear();
    }
}


void MainWindow::on_pushButtonSaoIguais_clicked()
{
    QString saida;

    saida=QString::number(n1->igual(n2));

    if(saida=='1')
    {
        saida="Verdadeiro.";
    }

    else //saida==0
    {
        saida="Falso.";
    }

    ui->textEditResultado->setText(saida);
}
