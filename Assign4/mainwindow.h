#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtOpenGL>
class QAction;
class QListWidget;
class QMenu;
class QTextEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void newTraceText();
    void help();
    void calculate();
    void saveTraceText();

private:
    void createActions();
    void createMenus();
    void createStatusBar();
    void createDockWindows();

    QTextEdit *textEdit;

    QMenu *fileMenu;
    QMenu *helpMenu;
    QAction *newTraceAct;
    QAction *helpAct;
    QAction *exitAct;
    
    QLCDNumber *lcd_Instances;
    QLCDNumber *lcd_HitRatio;
    QLCDNumber *lcd_ComMiss;
    QLCDNumber *lcd_MissRatio;
    
    QSlider *slider_Sets;
    QSpinBox *spin_Sets;
    QSlider *slider_Ways;
    QSpinBox *spin_Ways;
    QDial *dial_BB;
    QSpinBox *spin_BB;
};

#endif