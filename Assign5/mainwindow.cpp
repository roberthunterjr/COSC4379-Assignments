#include <QtGui>
#include "mainwindow.h"
#include "myglwidget.h"
#include "myglgraph.h"

MainWindow::MainWindow()
{
    textEdit = new QTextEdit;
    setCentralWidget(textEdit);

    createActions();
    createMenus();
    createStatusBar();
    createDockWindows();

    setWindowTitle(tr("Assignment I3: Robert Hunter"));

    newTraceText();
    saveTraceText();
    setUnifiedTitleAndToolBarOnMac(true);
    
    
    ////////Attempt to merge
    
    
}

void MainWindow::newTraceText()
{
    textEdit->clear();

    QTextCursor cursor(textEdit->textCursor());
    cursor.movePosition(QTextCursor::Start);
    QTextFrame *topFrame = cursor.currentFrame();
    QTextFrameFormat topFrameFormat = topFrame->frameFormat();
    topFrameFormat.setPadding(16);
    topFrame->setFrameFormat(topFrameFormat);

    QTextCharFormat textFormat;
    QTextCharFormat boldFormat;
    boldFormat.setFontWeight(QFont::Bold);
    QTextCharFormat italicFormat;
    italicFormat.setFontItalic(true);
    
    //cursor.insertText("0x00000000");
    QFile inputFile("trace.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          cursor.insertText("0x");
          cursor.insertText(line);
          cursor.insertBlock();
       }
       inputFile.close();
    }
    

    //cursor.insertText("0x00000000");
    
}

void MainWindow::help()
{
   QMessageBox::about(this, tr("Help"),tr("Help Information"));
}



void MainWindow::createActions()
{
    newTraceAct = new QAction(tr("&New Trace File"),this);
    newTraceAct->setShortcuts(QKeySequence::New);
    newTraceAct->setStatusTip(tr("Open a new trace file"));
    connect(newTraceAct, SIGNAL(triggered()), this, SLOT(newTraceText()));

    exitAct = new QAction(tr("&Exit Application"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exits from the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    
    helpAct = new QAction(tr("&Help"), this);
    helpAct->setStatusTip(tr("Show the application's help dialogue"));
    connect(helpAct, SIGNAL(triggered()), this, SLOT(help()));

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newTraceAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(helpAct);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createDockWindows()
{
    
    //////
    
    QLabel *label = new QLabel("Hello QT!");
    QVBoxLayout *controlLayout = new QVBoxLayout;
    QWidget *window = new QWidget;
    QWidget *lcdPanel = new QWidget(window);
    QWidget *btnPanel = new QWidget(window);
    QSpinBox *box_1 = new QSpinBox;
    MyGLWidget *glview = new MyGLWidget;
    MyGLGraph *glgview = new MyGLGraph;
    
    QLineEdit *edit_memorySize = new QLineEdit();
    QLabel *label_memorySize = new QLabel("Memory Size");

        	QHBoxLayout *layout_LCDPanel = new QHBoxLayout(window);
        	
        	QVBoxLayout *layout_LCDChannel_1 = new QVBoxLayout;
        	QVBoxLayout *layout_LCDChannel_2 = new QVBoxLayout;
        	QVBoxLayout *layout_LCDChannel_3 = new QVBoxLayout;
        	QVBoxLayout *layout_LCDChannel_4 = new QVBoxLayout;

        	layout_LCDPanel -> addLayout(layout_LCDChannel_1);
        	layout_LCDPanel -> addLayout(layout_LCDChannel_2);
        	layout_LCDPanel -> addLayout(layout_LCDChannel_3);
        	layout_LCDPanel -> addLayout(layout_LCDChannel_4);
        	    

        	lcd_Instances = new QLCDNumber;
        	QLabel *label_Instances = new QLabel("Instances");
        	lcd_HitRatio = new QLCDNumber;
        	QLabel *label_HitRatio = new QLabel("Hit Ratio");
        	
        	lcd_ComMiss = new QLCDNumber;
        	QLabel *label_ComMiss = new QLabel("Compulsary Miss");
        	
        	lcd_MissRatio = new QLCDNumber;
        	QLabel *label_MissRatio = new QLabel("Miss Ratio");
        	
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
        	QVBoxLayout *layout_Mem = new QVBoxLayout;
        	
        	layout_CPanel -> addLayout(layout_Sets);
        	layout_CPanel -> addLayout(layout_Ways);
        	layout_CPanel -> addLayout(layout_BB);
        	
        	slider_Sets = new QSlider(Qt::Horizontal);
        	QLabel *label_Sets = new QLabel("# Sets");
        	spin_Sets = new QSpinBox;
        	layout_Sets -> addWidget(slider_Sets);
        	layout_Sets ->addWidget(label_Sets);
        	layout_Sets -> addWidget(spin_Sets);
        	spin_Sets -> setRange(0,16);
        	slider_Sets -> setRange(0,16);
        	connect(spin_Sets, SIGNAL(valueChanged(int)), slider_Sets, SLOT(setValue(int)));
        	connect(slider_Sets, SIGNAL(valueChanged(int)), spin_Sets, SLOT(setValue(int)));
        	
        	slider_Ways = new QSlider(Qt::Vertical);
        	QLabel *label_Ways = new QLabel("# Ways");
        	spin_Ways = new QSpinBox;
        	layout_Ways -> addWidget(slider_Ways);
        	layout_Ways ->addWidget(label_Ways);
        	layout_Ways -> addWidget(spin_Ways);
        	spin_Ways -> setRange(0,16);
        	slider_Ways -> setRange(0,16);
        	connect(spin_Ways, SIGNAL(valueChanged(int)), slider_Ways, SLOT(setValue(int)));
        	connect(slider_Ways, SIGNAL(valueChanged(int)), spin_Ways, SLOT(setValue(int)));

        	dial_BB = new QDial;
        	QLabel *label_BB = new QLabel("Bytes/Block");
        	spin_BB = new QSpinBox;
        	layout_BB -> addWidget(dial_BB);
        	layout_BB ->addWidget(label_BB);
        	layout_BB -> addWidget(spin_BB);
        	spin_BB -> setRange(0,16);
        	dial_BB -> setRange(0,16);
        	connect(spin_BB, SIGNAL(valueChanged(int)), dial_BB, SLOT(setValue(int)));
        	connect(dial_BB, SIGNAL(valueChanged(int)), spin_BB, SLOT(setValue(int)));
        	
        	QWidget *memoryPanel = new QWidget;
        	
        	layout_Mem -> addWidget(label_memorySize);
        	layout_Mem -> addWidget(edit_memorySize);
        	memoryPanel ->setLayout(layout_Mem);

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
        	connect(button_Start,SIGNAL(clicked()), this, SLOT(calculate()));
        	connect(button_Go,SIGNAL(clicked()), this, SLOT(calculate()));
        	connect(button_Step,SIGNAL(clicked()), this, SLOT(calculate()));
        	connect(button_Break,SIGNAL(clicked()), this, SLOT(calculate()));
        	
        	//controlLayout -> addWidget(lcdPanel);
        	//controlLayout -> addWidget(controlPanel);
        	//controlLayout -> addWidget(btnPanel);
        	
        	//window->setLayout(controlLayout);
        	//window->show();
    
    ////////
        	
    //QDockWidget *dock = new QDockWidget(tr("Intro"), this);
    //dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    //QLabel *tlabel = new QLabel("Label Area");
    //dock->setWidget(tlabel);
    //addDockWidget(Qt::RightDockWidgetArea, dock);
    
//    dock = new QDockWidget(tr("Memory Size"), this);
//    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
//    dock->setWidget(memoryPanel);
//    addDockWidget(Qt::RightDockWidgetArea, dock);
//    
//    
//    dock = new QDockWidget(tr("Output"), this);
//    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
//    dock->setWidget(lcdPanel);
//    addDockWidget(Qt::RightDockWidgetArea, dock);
//    
//    dock = new QDockWidget(tr("Parameters"), this);
//    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
//    dock->setWidget(controlPanel);
//    addDockWidget(Qt::RightDockWidgetArea, dock);
//    
//    dock = new QDockWidget(tr("Controls"), this);
//    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
//    dock->setWidget(btnPanel);
//    addDockWidget(Qt::LeftDockWidgetArea, dock);
        	
    QDockWidget *dock = new QDockWidget(tr("Graphic I"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setWidget(glview);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    
    dock = new QDockWidget(tr("Graphic II"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setWidget(glgview);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    
    
}

void MainWindow::calculate(){
	lcd_Instances -> display(spin_Sets->value());
	lcd_HitRatio -> display(5);
	lcd_ComMiss -> display(5);
	lcd_MissRatio -> display(5);
}

void MainWindow::saveTraceText(){
	QFile outputFile("tracehex.txt");
	    if (outputFile.open(QIODevice::WriteOnly))
	    {
	       QTextStream out(&outputFile);
	       out << textEdit->toPlainText();
	       outputFile.close();
	    }
}