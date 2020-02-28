#include "cuentas.h"
#include "ui_cuentas.h"
#include<QStringListModel>

cuentas::cuentas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cuentas)
{
    ui->setupUi(this);

    filas=0;
  ordenes=new QList<QList<QString>*>();
    ui->listcuentas->setDragEnabled(true);
    ui->listcuentas->setAcceptDrops(true);
    ui->listcuentas->setDropIndicatorShown(true);
    ui->listcuentas->setDefaultDropAction(Qt::MoveAction);


    ui->listordenes->setDragEnabled(true);
    ui->listordenes->setAcceptDrops(true);
    ui->listordenes->setDropIndicatorShown(true);
    ui->listordenes->setDefaultDropAction(Qt::MoveAction);



    ui->listcuentas->setStyleSheet
            ("QListWidget { font-size: 14pt; font-weight: bold; }"
             "QListWidget::item { padding: 10%;"
             "border: 1px solid gray; }"
             "QListWidget::item::hover {}");


    ui->listordenes->setStyleSheet
            ("QListWidget { font-size: 14pt; font-weight: bold; }"
             "QListWidget::item { padding: 10%;"
             "border: 1px solid gray; }"
             "QListWidget::item::hover {  }");


    ui->listordenes->setIconSize(QSize(40,40));
    ui->listcuentas->setIconSize(QSize(40,40));



            ui->listcuentas->setIconSize(QSize(50,50));

            QListWidgetItem *b=new QListWidgetItem();
            b->setIcon(QIcon(":/Img/logoordenes.png"));

            QListWidgetItem *c=new QListWidgetItem();
            c->setText("Orden de papas fritas");
            c->setIcon(QIcon(":/Img/logoordenes.png"));



            b->setText("Malteada de chocolate");
            ui->listordenes->addItem(b);
            ui->listordenes->addItem(c);


            int j=0;
             while (j<2) {

                 QList<QString> *lista=new QList<QString>;

                 ordenes->insert(j,lista);



                 j++;
             }


}

cuentas::~cuentas()
{
    delete ui;
}


void cuentas::imprimirCuenta(QList<QString>* lista){
    auto nombreArchivo=QFileDialog::getSaveFileName(this,"Guardar archivo",QDir::rootPath(),"Archivos (*.pdf);;");


    QPdfWriter pdf(nombreArchivo);

    QPainter painter(&pdf);
    painter.setRenderHint(QPainter::Antialiasing);


    QFont font("Arial",18,QFont::Bold);
    QFont subtitulo("Arial",14,QFont::Bold);
    QFont texto("Arial",12);


    painter.setPen(Qt::black);
    painter.setFont(font);
    painter.drawPixmap(QRect(300,1400,1600,1600),QPixmap("/Users/carlossalazar/Desktop/logo.png"));
    painter.drawText(2800,2200,"Ticket de compra");
    painter.setPen(Qt::gray);
    painter.drawLine(300,3200,9100,3200);
    painter.setPen(Qt::black);
    painter.setFont(subtitulo);

    painter.drawText(300,4000,"Fecha de importe");
    painter.drawText(7200,4000,"Hora");
    QTime hora=QTime::currentTime();
    QString hour=hora.toString("h:m a");


    painter.setFont(texto);
    QDate fecha=QDate::currentDate();
    QString date=fecha.toString("dd-MM-yyyy");

    painter.drawText(400,4500,date);
    painter.drawText(7200,4500,hour);

    painter.setFont(subtitulo);


    painter.drawText(300,5400,"Personal que atendió");
    painter.drawText(7200,5400,"Mesa atendida");

    painter.setFont(texto);
    painter.drawText(7600,5800,"6");

    painter.drawText(400,5800,"Jose Mendez Castro");
    painter.setPen(Qt::gray);
    painter.drawLine(300,6200,9100,6200);

    painter.setPen(Qt::black);
    painter.setFont(subtitulo);

    painter.drawText(500,6600,"Cantidad");
    painter.drawText(3300,6600,"Producto ordenado");
    painter.drawText(7200,6600,"Precio");
    painter.setFont(texto);
    int j=0,x=7000;
    while (j<lista->size()) {
        QString platillo=lista->at(j);
        painter.drawText(900,x,"1");
        painter.drawText(3300,x,platillo);
        painter.drawText(7300,x,"$100.00");

        x +=300;
        j++;
    }

/*
    painter.drawText(900,7000,"1");
    painter.drawText(3300,7000,"Hamburguesa con papas");
    painter.drawText(7300,7000,"$75.00");

    painter.drawText(900,7300,"1");
    painter.drawText(3300,7300,"Malteada de chocolate");
    painter.drawText(7300,7300,"$35.00");
*/
    painter.setPen(Qt::gray);
    painter.drawLine(300,x+400,9100,x+400);
    x+=400;
    painter.setPen(Qt::black);
    painter.setFont(subtitulo);

    painter.drawText(7300,x+500,"Subtotal: $94.82");
    painter.drawText(7300,x+900,"IVA: $15.18");
    painter.drawText(7300,x+1300,"Total: $110.00");





    painter.end();





}

void cuentas::on_pbimprimir_clicked()
{
    int i=0;
    if(ordenes->size()>1){
        while (i<ordenes->size()) {
            QList<QString>* orden=ordenes->at(i);
            imprimirCuenta(orden);

            i++;
        }

    }


}

void cuentas::on_listcuentas_itemChanged(QListWidgetItem *item)
{

    ui->listordenes->setStyleSheet
            ("QListWidget { font-size: 14pt; font-weight: bold; }"
             "QListWidget::item { padding: 10%;"
             "border: 1px solid gray; }"
             "QListWidget::item::hover {}");

    if(ui->listcuentas->model()->rowCount()>filas){
        qDebug()<<"Se disparo el evento";
        filas=ui->listcuentas->model()->rowCount();
        QList<QString> *lista=ordenes->at(ui->comboBox->currentIndex());
        lista->append(item->text());
qDebug()<<"El tam es "<<ordenes->size();
    }

}

void cuentas::on_comboBox_currentIndexChanged(int index)
{



    QList<QString> *lista=ordenes->at(index);

    int i=0,j=0;

    while(j<ui->listcuentas->model()->rowCount()){

        ui->listcuentas->takeItem(j);
        filas=0;
        j++;
    }

    while(i<lista->size()){
        QListWidgetItem *b=new QListWidgetItem();
        b->setText(lista->at(i));
        b->setIcon(QIcon(":/Img/logoordenes.png"));
        ui->listcuentas->addItem(b);
        filas=ui->listcuentas->model()->rowCount();
        i++;
    }

}

void cuentas::on_pbcancelar_clicked()
{
    close();
}
