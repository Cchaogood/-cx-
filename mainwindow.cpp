#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mycompiler.h"
#pragma execution_character_set("utf-8")



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("MyCompiler");
  //修改
//
    connect(ui->open_action, &QAction::triggered, this, &MainWindow::openActionSlot);
    connect(ui->save_action, &QAction::triggered, this, &MainWindow::saveActionSlot);
//修改
}

MainWindow::~MainWindow()
{
    delete ui;
}

//修改
void MainWindow::openActionSlot()
{


    QString fileName= QFileDialog::getOpenFileName(this, "选择一个文件",
                            QCoreApplication::applicationFilePath(), "*.txt");

    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"警告","请选择一个文件");


    }

    else
    {
        //qDebug() <<fileName;
        QFile file(fileName);      //创建文件对象
        file.open(QIODevice::ReadOnly);
        QByteArray ba = file.readAll();
        ui->CxCode->setText(QString(ba));
        file.close();


    }

}


//修改

void MainWindow::saveActionSlot()
{
    QString fileName = QFileDialog::getSaveFileName(this, "选择一个文件",
                                        QCoreApplication::applicationFilePath());


    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"waring","please choose a file");
    }
    else {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        //ui->CxCode-toPlaintext();
        QByteArray ba;
        ba.append(ui->CxCode->toPlainText());
        file.write(ba);
        file.close();



        }




}



void MainWindow::savefilein(QString path){
    QString data;
    QFile file(path);

    //以文本方式打开
    if( file.open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        QTextStream out(&file); //IO设备对象的地址对其进行初始化

        out << ui->CxCode->toPlainText() << endl; //输出
        file.close();
    }
}

void MainWindow::savefileinput(QString path){
    QString data;
    QFile file(path);

    //以文本方式打开
    if( file.open(QIODevice::WriteOnly | QIODevice::Text) )
    {
        QTextStream out(&file); //IO设备对象的地址对其进行初始化

        out << ui->InputEdit->toPlainText() << endl; //输出
        file.close();
    }
}

void MainWindow::openfilein(QString path){
    QString data;
    QFile file(path); //path是文件的路径
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"文件未打开！";
    }
    while(!file.atEnd())
    {
        QByteArray array = file.readLine();
        QString str(array);
        // qDebug()<< str;
        data.append(str);
    }
    ui->CxCode->setText(data);
}

void MainWindow::openfileout(QString path){
    QString data;
    QFile file(path); //path是文件的路径
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"文件未打开！";
    }
    while(!file.atEnd())
    {
        QByteArray array = file.readLine();
        QString str(array);
        // qDebug()<< str;
        data.append(str);
    }
    ui->OutputEdit->setText(data);
}

void MainWindow::openfilecode(QString path){
    QString data;
    QFile file(path); //path是文件的路径
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"文件未打开！";
    }
    while(!file.atEnd())
    {
        QByteArray array = file.readLine();
        QString str(array);
        // qDebug()<< str;
        data.append(str);
    }
    ui->PcodeEdit->setText(data);
}

void MainWindow::openfiletable(QString path){
    QString data;
    QFile file(path); //path是文件的路径
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"文件未打开！";
    }
    while(!file.atEnd())
    {
        QByteArray array = file.readLine();
        QString str(array);
        // qDebug()<< str;
        data.append(str);
    }
    ui->TableEdit->setText(data);
}

void MainWindow::openfileinput(QString path){
    QString data;
    QFile file(path); //path是文件的路径
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"文件未打开！";
    }
    while(!file.atEnd())
    {
        QByteArray array = file.readLine();
        QString str(array);
        // qDebug()<< str;
        data.append(str);
    }
    ui->InputEdit->setText(data);
}

void MainWindow::openfileres(QString path){
    QString data;
    QFile file(path); //path是文件的路径
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"文件未打开！";
    }
    while(!file.atEnd())
    {
        QByteArray array = file.readLine();
        QString str(array);
        // qDebug()<< str;
        data.append(str);
    }
    ui->ResultEdit->setText(data);
}

void MainWindow::resload()
{
    QLatin1String qsres("fresult.txt");
    QString ffres(qsres);
    this->openfileres(ffres);
}

void MainWindow::load()
{
    QLatin1String qsin("test.txt");
    QString ffin(qsin);
    QLatin1String qsout("foutput.txt");
    QString ffout(qsout);
    QLatin1String qscode("fcode.txt");
    QString ffcode(qscode);
    QLatin1String qstable("ftable.txt");
    QString fftable(qstable);
    QLatin1String qsinput("finput.txt");
    QString ffinput(qsinput);

    this->openfilein(ffin);
    this->openfileout(ffout);
    this->openfilecode(ffcode);
    this->openfiletable(fftable);
    this->openfileinput(ffinput);

}

//运行
void MainWindow::on_BuildButton_clicked()
{
    //char path[100] = "test.txt";

    build("test.txt");

    load();
    resload();

}


//保存
void MainWindow::on_SaveButton_clicked()
{
    QLatin1String qsin("test.txt");
    QString ffin(qsin);
    this->savefilein(ffin);

    QLatin1String qsinput("finput.txt");
    QString ffinput(qsinput);
    this->savefileinput(ffinput);

    //load();
}
