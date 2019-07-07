#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    presenter = new ReceivePresenter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete presenter;
}


void MainWindow::on_startButton_clicked()
{
    presenter->onStartButtonPressed();
}

void MainWindow::on_clearButton_clicked()
{
    presenter->onClearButtonPressed();
}

void MainWindow::setStartButtonLabel(QString str)
{
    ui->startButton->setText(str);
}

void MainWindow::setStatusBarMessage(QString message)
{
    ui->statusBar->showMessage(message,STATUS_BAR_DEFAULT_TIMEOUT);
}

void MainWindow::lightOnLed()
{
    ui->led->turnOn();
}

void MainWindow::lightOffLed()
{
    ui->led->turnOff();
}

void MainWindow::setListModel(QStringListModel *model)
{
    ui->listView->setModel(model);
}

void MainWindow::scrollListToBottom()
{
    ui->listView->scrollToBottom();
}
