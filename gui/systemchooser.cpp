#include "systemchooser.h"
#include "ui_systemchooser.h"

SystemChooser::SystemChooser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemChooser)
{
    ui->setupUi(this);

    setMaximumSize(size());
    setMinimumSize(size());
    typeGroup.addButton(ui->rectBtn);
    typeGroup.addButton(ui->radialBtn);

    QStringList yPosStrs;
    yPosStrs.append(tr("Up"));
    yPosStrs.append(tr("Middle"));
    yPosStrs.append(tr("Down"));

    QStringList xPosStrs;
    xPosStrs.append(tr("Left"));
    xPosStrs.append(tr("Middle"));
    xPosStrs.append(tr("Right"));

    for(int y=0;y<3;y++)
        for(int x=0;x<3;x++){
            QString str1=yPosStrs.at(y);
            QString str2=xPosStrs.at(x);

            QString str;
            if(str1==str2){
                str=str1;
            }else str=str1+"-"+str2;

            ui->centerBox->addItem(str);
        }

    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(close()));
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(okClicked()));
}

void SystemChooser::init(System system){
    int xpos=system.xPos();
    int ypos=system.yPos();

    int index=ypos*3+xpos;
    ui->centerBox->setCurrentIndex(index);

    if(system.yOrientation()==System::ToDown)ui->toDownBtn->setChecked(true);
    else ui->toUpBtn->setChecked(true);

    if(system.type()==System::Rectangle)ui->rectBtn->setChecked(true);
    else ui->radialBtn->setChecked(true);

    ui->shiftXSpin->setValue(system.getShiftX());
    ui->shiftYSpin->setValue(system.getShiftY());
}

SystemChooser::~SystemChooser()
{
    delete ui;
}

void SystemChooser::okClicked(){
    System system;

    System::SystemType type=(ui->rectBtn->isChecked())? System::Rectangle : System::Radial;

    int pos=ui->centerBox->currentIndex();
    System::XPosition posx=(System::XPosition)(pos%3);
    System::YPosition posy=(System::YPosition)(pos/3);
    int dx=ui->shiftXSpin->value();
    int dy=ui->shiftYSpin->value();


    System::YOrientation orient;
    if(ui->toDownBtn->isChecked()){
        orient=System::ToDown;
    }else orient=System::ToUp;

    system.setPos(posx,posy);
    system.setYOrientation(orient);
    system.setType(type);

    system.setShiftX(dx);
    system.setShiftY(dy);

    emit systemSelected(system);
    close();
}
