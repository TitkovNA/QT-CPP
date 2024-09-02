#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer;
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&QWidget::update));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QTime time = QTime::currentTime();

    QPainter painter;
    painter.begin(this);

    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(width()/2,height()/2);

    size_t R = 0.8*qMin(width()/2,height()/2);

    for (int i = 0 ; i < 60 ; ++i)
    {
        if (i % 5 == 0)
        {
            painter.drawLine(0,R,0,R-15);
        }
        else
        {
            painter.drawLine(0,R,0,R-5);
        }
        painter.rotate(6.0);
    }
    painter.setPen(Qt::NoPen);

    painter.save();
    QPolygon polygon_hour;
    polygon_hour << QPoint(-0.04*R,0) <<  QPoint(0.04*R,0)<<  QPoint(0, -0.4*R);
    painter.setBrush(QColor(0,0,255));
    painter.rotate(30*(time.hour()+time.minute()/60));
    painter.drawPolygon(polygon_hour);
    painter.restore();

    painter.save();
    QPolygon polygon_minute;
    polygon_minute << QPoint(-0.03*R,0) <<  QPoint(0.03*R,0)<<  QPoint(0, -0.6*R);
    painter.setBrush(QColor(0,0,200,150));
    painter.rotate(6.0*(time.minute()+time.second()/60));
    painter.drawPolygon(polygon_minute);
    painter.restore();

    painter.save();
    QPolygon polygon_second;
    polygon_second << QPoint(-0.03*R,0) <<  QPoint(0.03*R,0)<<  QPoint(0, -0.8*R);
    painter.setBrush(QColor(0,0,150,100));
    painter.rotate(6.0*(time.second()));
    painter.drawPolygon(polygon_second);
    painter.restore();


    painter.end();
}
