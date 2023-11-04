#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QValidator>
#include <Racional.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonNovosNumeros_clicked();

    void on_pushButtonMostrar_clicked();

    void on_pushButtonArmazenar_clicked();

    void on_pushButtonSoma_clicked();

    void on_pushButtonSubtra_clicked();

    void on_pushButtonMultiplica_clicked();

    void on_pushButtonDivisao_clicked();

    void on_pushButtonSaoIguais_clicked();


private:
    Ui::MainWindow *ui;
    Racional *n1;
    Racional *n2;
};
#endif // MAINWINDOW_H
