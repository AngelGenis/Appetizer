#ifndef MESASSERVICE_H
#define MESASSERVICE_H
#include <QList>

struct MesaDataSet
{
    int id_mesa = -1;
    int numero_personas;
    int piso;
    int id_mesero;
    int x;
    int y;
};

class QSqlDatabase;

class MesasService
{
public:
    MesasService();
    bool savePosition(int id, int x, int y);
    bool saveMesa(MesaDataSet mesa);
    MesaDataSet createMesa(int numPersonas, int x, int y);
    bool deleteMesa(int id);    
    QList<MesaDataSet> getMesas();
private:
    QSqlDatabase &db;
};

#endif // MESASSERVICE_H
