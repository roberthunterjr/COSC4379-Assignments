#include <QApplication>
#include <QLabel>
#include <QtGui>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QLabel *label = new QLabel("Hello QT!");
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QWidget *window = new QWidget;
    QWidget *lcdPanel = new QWidget(window);
    QWidget *btnPanel = new QWidget(window);
    QSpinBox *box_1 = new QSpinBox;

    QHBoxLayout *layout_LCDPanel = new QHBoxLayout(window);
  
    QVBoxLayout *layout_LCDChannel_1 = new QVBoxLayout;
    QVBoxLayout *layout_LCDChannel_2 = new QVBoxLayout;
    QVBoxLayout *layout_LCDChannel_3 = new QVBoxLayout;
    QVBoxLayout *layout_LCDChannel_4 = new QVBoxLayout;

    layout_LCDPanel -> addLayout(layout_LCDChannel_1);
    layout_LCDPanel -> addLayout(layout_LCDChannel_2);
    layout_LCDPanel -> addLayout(layout_LCDChannel_3);
    layout_LCDPanel -> addLayout(layout_LCDChannel_4);
    

    QLCDNumber *lcd_Instances = new QLCDNumber;
    QLabel *label_Instances = new QLabel("Instances");

    QLCDNumber *lcd_HitRatio = new QLCDNumber;
    QLabel *label_HitRatio = new QLabel("Hit Ratio");

    QLCDNumber *lcd_ComMiss = new QLCDNumber;
    QLabel *label_ComMiss = new QLabel("Compulsary Miss");

    QLCDNumber *lcd_MissRatio = new QLCDNumber;
    QLabel *label_MissRatio = new QLabel("Miss Ratio");

    //group_Instances -> addWidget(lcd_Instances);
    //group_Instances -> addWidget(label_Instances);
    layout_LCDChannel_1 -> addWidget(lcd_Instances);
    layout_LCDChannel_1 -> addWidget(label_Instances);
    layout_LCDChannel_2 -> addWidget(lcd_HitRatio);
    layout_LCDChannel_2 -> addWidget(label_HitRatio);
    layout_LCDChannel_3 -> addWidget(lcd_ComMiss);
    layout_LCDChannel_3 -> addWidget(label_ComMiss);
    layout_LCDChannel_4 -> addWidget(lcd_MissRatio);
    layout_LCDChannel_4 -> addWidget(label_MissRatio);

    QWidget *controlPanel = new QWidget(window);
    QHBoxLayout *layout_CPanel = new QHBoxLayout;
    QVBoxLayout *layout_Sets = new QVBoxLayout;
    QVBoxLayout *layout_Ways = new QVBoxLayout;
    QVBoxLayout *layout_BB = new QVBoxLayout;

    layout_CPanel -> addLayout(layout_Sets);
    layout_CPanel -> addLayout(layout_Ways);
    layout_CPanel -> addLayout(layout_BB);

    QSlider *slider_Sets = new QSlider(Qt::Horizontal);
    QLabel *label_Sets = new QLabel("# Sets");
    layout_Sets -> addWidget(slider_Sets);
    layout_Sets ->addWidget(label_Sets);

    QSlider *slider_Ways = new QSlider(Qt::Vertical);
    QLabel *label_Ways = new QLabel("# Ways");
    layout_Ways -> addWidget(slider_Ways);
    layout_Ways ->addWidget(label_Ways);

    QDial *dial_BB = new QDial;
    QLabel *label_BB = new QLabel("Bytes/Block");
    layout_BB -> addWidget(dial_BB);
    layout_BB ->addWidget(label_BB);

    controlPanel -> setLayout(layout_CPanel);
    lcdPanel -> setLayout(layout_LCDPanel);

    QPushButton *button_Go = new QPushButton("Go");
    QPushButton *button_Break = new QPushButton("Break");
    QPushButton *button_Step = new QPushButton("Step");
    QPushButton *button_Start = new QPushButton("Start");

    QHBoxLayout *layout_buttons = new QHBoxLayout(window);
    layout_buttons -> addWidget(button_Go);
    layout_buttons -> addWidget(button_Break);
    layout_buttons -> addWidget(button_Step);
    layout_buttons -> addWidget(button_Start);

    btnPanel -> setLayout(layout_buttons);

    mainLayout -> addWidget(box_1);
    mainLayout -> addWidget(label);
    mainLayout -> addWidget(lcdPanel);
    mainLayout -> addWidget(controlPanel);
    mainLayout -> addWidget(btnPanel);
    //mainLayout -> addWidget(layout_buttons);
    window -> setLayout(mainLayout);
    //window -> setLayout(layout_buttons);
    //lcdPanel -> show();
    window -> show();
    //btnPanel -> show();
    return app.exec();
}
