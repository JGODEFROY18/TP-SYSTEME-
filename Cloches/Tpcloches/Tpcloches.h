//*********************************************************************************************
//* Programme : Tpcloche.h date : 15/11/2022
//*---------------------------------------------------------------------------------------------------------
//* dernière mise a jour : 15/11/2022
//*
//*Programmeur(s) : Cesar Alexis - Godefroy Jules Classe : BTSSN2
//*
//*--------------------------------------------------------------------------------------------------------
//* BUT : Contrôler cloches
//*Programmes associés : AUCUN
//*********************************************************************************************

#include <QtWidgets/QMainWindow>
#include "Tpcloches.ui"
// Librairie 
#include <qtcpsocket.h>

class Tpcloches : public QMainWindow
{
    Q_OBJECT

public:
    Tpcloches(QWidget *parent = nullptr);
    ~Tpcloches();

public slots:
	void onConnectButtonClicked();
	void onDisconnectButtonClicked();
	void onSocketConnected(); // Statut connexion
	void onSocketDisconnected(); // Statut deconnexion
	void BtnCloche1Clicked(); 
	void BtnCloche2Clicked();
	void BtnCloche3Clicked();
	void BtnCloche4Clicked();

private:
    Ui::TpclochesClass ui;
	QTcpSocket * socket;
};
