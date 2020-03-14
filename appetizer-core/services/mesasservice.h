#ifndef MESASSERVICE_H
#define MESASSERVICE_H
#include <QList>

struct MesaData
{
    int id_mesa = -1;
    int numero_personas;
    int piso = 0;
    int id_mesero = 0;
    int x;
    int y;
    int grupo = 0;
    int id_mesa_maestra = 0;
    int estado =  -1;
};

class QSqlDatabase;

class MesasService
{
public:
    MesasService();
    int lastMesaID() const;
    bool savePosition(int id, int x, int y);
    bool saveNumPersonas(int id, int numPersonas);
    bool saveMesa(MesaData mesa);
    MesaData createMesa(int numPersonas, int x, int y);
    MesaData getMesa(int id);
    bool deleteMesa(int id);    
    QList<MesaData> getMesas();
private:
    QSqlDatabase &db;
};

#endif // MESASSERVICE_H
