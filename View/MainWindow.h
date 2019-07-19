#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Presenter/ReceivePresenter.h>
#include "Contract/ReceiverContractView.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public ReceiverContractView
{
    Q_OBJECT
private slots:
    void on_startButton_clicked();
    void on_clearButton_clicked();
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    ReceivePresenter* presenter;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setStartButtonLabel(QString str);
    void lightOnLed();
    void lightOffLed();
    void setListModel(QStringListModel *model);
    void scrollListToBottom();
    void disableComboBox();
    void enableComboBox();
    void addItemToComboBox(QString value);
};

#endif // MAINWINDOW_H
