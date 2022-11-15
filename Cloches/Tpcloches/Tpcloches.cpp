//*********************************************************************************************
//* Programme : Tpcloche.cpp date : 15/11/2022
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

Tpcloches::Tpcloches(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	socket = new QTcpSocket(this);
	QObject::connect(socket, SIGNAL(connected()), this, SLOT(onSocketConnected()));
	QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(onSocketDisconnected()));
}

// Vérification appuie sur bouton connexion
void Tpcloches::onConnectButtonClicked() {
	QString ip = ui.IPEdit->text();
	QString port = ui.PortEdit->text();

	bool ok;
	int portasint = port.toInt(&ok);

	// Si tout est le bon, la connexion au socket s'effectue
	if (ok) {
		socket->connectToHost(ip, portasint);
	}
}

// Vérification appuie sur bouton déconnexion
void Tpcloches::onDisconnectButtonClicked() {
	socket->disconnectFromHost(); // Si le bouton deconnexion est appuyé on se déconnecter du socket
}

// Fonction vérification du statu de connexion
void Tpcloches::onSocketConnected() {
	// Affiche connexion si on est connecté
	ui.AffConnexion->setText("Connexion");
}

// Fonction vérification du statu de déconnexion
void Tpcloches::onSocketDisconnected() {
	// Affiche deconnexion si on est deconnecté (par défault déconnecter)
	ui.AffConnexion->setText("Deconnexion");
}

void Tpcloches::BtnCloche1Clicked() {
	if (socket->state() == QAbstractSocket::ConnectedState) {
		char trameClocheMarche[12];
		char trameClocheArret[12];

		// en-tête MODBUS/TCP
		trameClocheMarche[0] = 0x00; // numero de transaction modbus
		trameClocheMarche[1] = 0x00;
		trameClocheMarche[2] = 0x00; // numero de protocole (0 pour MODBUS/TCP)
		trameClocheMarche[3] = 0x00;
		trameClocheMarche[4] = 0x00; // longueur du message
		trameClocheMarche[5] = 0x06;
		trameClocheMarche[6] = 0x00; // adresse xvay

		// suite de la trame classique modbus
		trameClocheMarche[7] = 0x06; // code fonction (fonction 6 : écriture)
		trameClocheMarche[8] = 0x00; // mot 00 22 (mot 2 de l'automate)
		trameClocheMarche[9] = 0x02;
		trameClocheMarche[10] = 0x00; // valeur mot (18 en base 10 en l'occurence)
		trameClocheMarche[11] = 0x12;

		trameClocheMarche[12] = 0x01; // CRC
		trameClocheMarche[13] = 0x01;

		QByteArray donneesMarche(trameClocheMarche, 14);
		socket->write(donneesMarche);

		// en-tête MODBUS/TCP
		trameClocheArret[0] = 0x00;
		trameClocheArret[1] = 0x00;
		trameClocheArret[2] = 0x00;
		trameClocheArret[3] = 0x00;
		trameClocheArret[4] = 0x00;
		trameClocheArret[5] = 0x06;
		trameClocheArret[6] = 0x00;

		// suite de la trame classique modbus
		trameClocheArret[7] = 0x06;
		trameClocheArret[8] = 0x00;
		trameClocheArret[9] = 0x02;
		trameClocheArret[10] = 0x00;
		trameClocheArret[11] = 0x12;

		trameClocheMarche[12] = 0x01; // CRC
		trameClocheMarche[13] = 0x01;

		QByteArray donneesArret(trameClocheArret, 14);
		socket->write(donneesArret);

		ui.StatusCo->setText("La grosse cloche (1) sonne");
	}
	else ui.StatusCo->setText("Erreur de connexion");
}

void Tpcloches::BtnCloche2Clicked() {
	if (socket->state() == QAbstractSocket::ConnectedState) {
		char trameClocheMarche[12];
		char trameClocheArret[12];

		// en-tête MODBUS/TCP
		trameClocheMarche[0] = 0x00; // numero de transaction modbus
		trameClocheMarche[1] = 0x00;
		trameClocheMarche[2] = 0x00; // numero de protocole (0 pour MODBUS/TCP)
		trameClocheMarche[3] = 0x00;
		trameClocheMarche[4] = 0x00; // longueur du message
		trameClocheMarche[5] = 0x06;
		trameClocheMarche[6] = 0x00; // adresse xvay

		// suite de la trame classique modbus
		trameClocheMarche[7] = 0x06; // code fonction (fonction 6 : écriture)
		trameClocheMarche[8] = 0x00; // mot 00 22 (mot 2 de l'automate)
		trameClocheMarche[9] = 0x02;
		trameClocheMarche[10] = 0x00; // valeur mot (18 en base 10 en l'occurence)
		trameClocheMarche[11] = 0x12;

		trameClocheMarche[12] = 0x01; // CRC
		trameClocheMarche[13] = 0x01;

		QByteArray donneesMarche(trameClocheMarche, 14);
		socket->write(donneesMarche);

		// en-tête MODBUS/TCP
		trameClocheArret[0] = 0x00;
		trameClocheArret[1] = 0x00;
		trameClocheArret[2] = 0x00;
		trameClocheArret[3] = 0x00;
		trameClocheArret[4] = 0x00;
		trameClocheArret[5] = 0x06;
		trameClocheArret[6] = 0x00;

		// suite de la trame classique modbus
		trameClocheArret[7] = 0x06;
		trameClocheArret[8] = 0x00;
		trameClocheArret[9] = 0x02;
		trameClocheArret[10] = 0x00;
		trameClocheArret[11] = 0x12;

		trameClocheMarche[12] = 0x01; // CRC
		trameClocheMarche[13] = 0x01;

		QByteArray donneesArret(trameClocheArret, 14);
		socket->write(donneesArret);

		ui.StatusCo->setText("La cloche (2) sonne");
	}
	else ui.StatusCo->setText("Erreur de connexion");
}

void Tpcloches::BtnCloche3Clicked() {
	if (socket->state() == QAbstractSocket::ConnectedState) {
		char trameClocheMarche[12];
		char trameClocheArret[12];

		// en-tête MODBUS/TCP
		trameClocheMarche[0] = 0x00; // numero de transaction modbus
		trameClocheMarche[1] = 0x00;
		trameClocheMarche[2] = 0x00; // numero de protocole (0 pour MODBUS/TCP)
		trameClocheMarche[3] = 0x00;
		trameClocheMarche[4] = 0x00; // longueur du message
		trameClocheMarche[5] = 0x06;
		trameClocheMarche[6] = 0x00; // adresse xvay

		// suite de la trame classique modbus
		trameClocheMarche[7] = 0x06; // code fonction (fonction 6 : écriture)
		trameClocheMarche[8] = 0x00; // mot 00 22 (mot 2 de l'automate)
		trameClocheMarche[9] = 0x02;
		trameClocheMarche[10] = 0x00; // valeur mot (18 en base 10 en l'occurence)
		trameClocheMarche[11] = 0x12;

		trameClocheMarche[12] = 0x01; // CRC
		trameClocheMarche[13] = 0x01;

		QByteArray donneesMarche(trameClocheMarche, 12);
		socket->write(donneesMarche);

		// en-tête MODBUS/TCP
		trameClocheArret[0] = 0x00;
		trameClocheArret[1] = 0x00;
		trameClocheArret[2] = 0x00;
		trameClocheArret[3] = 0x00;
		trameClocheArret[4] = 0x00;
		trameClocheArret[5] = 0x06;
		trameClocheArret[6] = 0x00;

		// suite de la trame classique modbus
		trameClocheArret[7] = 0x06;
		trameClocheArret[8] = 0x00;
		trameClocheArret[9] = 0x02;
		trameClocheArret[10] = 0x00;
		trameClocheArret[11] = 0x12;

		trameClocheMarche[12] = 0x01; // CRC
		trameClocheMarche[13] = 0x01;

		QByteArray donneesArret(trameClocheArret, 12);
		socket->write(donneesArret);

		ui.StatusCo->setText("La cloche (3) sonne");
	}
	else ui.StatusCo->setText("Erreur de connexion");
}

void Tpcloches::BtnCloche4Clicked() {
	if (socket->state() == QAbstractSocket::ConnectedState) {
		char trameClocheMarche[12];
		char trameClocheArret[12];

		// en-tête MODBUS/TCP
		trameClocheMarche[0] = 0x00; // numero de transaction modbus
		trameClocheMarche[1] = 0x00;
		trameClocheMarche[2] = 0x00; // numero de protocole (0 pour MODBUS/TCP)
		trameClocheMarche[3] = 0x00;
		trameClocheMarche[4] = 0x00; // longueur du message
		trameClocheMarche[5] = 0x06;
		trameClocheMarche[6] = 0x00; // adresse xvay

		// suite de la trame classique modbus
		trameClocheMarche[7] = 0x06; // code fonction (fonction 6 : écriture)
		trameClocheMarche[8] = 0x00; // mot 00 22 (mot 2 de l'automate)
		trameClocheMarche[9] = 0x02;
		trameClocheMarche[10] = 0x00; // valeur mot (18 en base 10 en l'occurence)
		trameClocheMarche[11] = 0x12;

		trameClocheMarche[12] = 0x01; // CRC
		trameClocheMarche[13] = 0x01;

		QByteArray donneesMarche(trameClocheMarche, 12);
		socket->write(donneesMarche);

		// en-tête MODBUS/TCP
		trameClocheArret[0] = 0x00;
		trameClocheArret[1] = 0x00;
		trameClocheArret[2] = 0x00;
		trameClocheArret[3] = 0x00;
		trameClocheArret[4] = 0x00;
		trameClocheArret[5] = 0x06;
		trameClocheArret[6] = 0x00;

		// suite de la trame classique modbus
		trameClocheArret[7] = 0x06;
		trameClocheArret[8] = 0x00;
		trameClocheArret[9] = 0x02;
		trameClocheArret[10] = 0x00;
		trameClocheArret[11] = 0x12;

		trameClocheMarche[12] = 0x01; // CRC
		trameClocheMarche[13] = 0x01;

		QByteArray donneesArret(trameClocheArret, 12);
		socket->write(donneesArret);

		ui.StatusCo->setText("La cloche (4) sonne");
	}
	else ui.StatusCo->setText("Erreur de connexion");
}

// Destructeur de la class
Tpcloches::~Tpcloches()
{}