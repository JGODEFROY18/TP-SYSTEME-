//*********************************************************************************************
//* Programme : main.cpp date : 15/11/2022
//*---------------------------------------------------------------------------------------------------------
//* dernière mise a jour : 15/11/2022
//*
//* Programmeur(s) : Cesar Alexis - Godefroy Jules Classe : BTSSN2
//*
//*--------------------------------------------------------------------------------------------------------
//* BUT : Contrôler cloches
//* Programmes associés : AUCUN
//*********************************************************************************************

#include "Tpcloches.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tpcloches w;
    w.show();
    return a.exec();
}
