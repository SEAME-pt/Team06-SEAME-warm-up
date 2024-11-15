#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QAction>
#include <QListWidget>
#include <QHash>
#include "ContactList.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void addContact();
    void editContact();
    void openFile();
    void saveFile();
    void saveFileAs();
    void exitApp();
    void onItemDoubleClicked(QListWidgetItem *item);

private:
    void createMenu();
    void createToolbar();
    void createActions();

    QListWidget *m_contactListWidget;
    ContactList m_contactList;

private:
    Ui::MainWindow *ui;
    QString m_fileName;
    QHash<QString, QAction*> m_actions;

    bool m_hasFile = false; //se nao temos file desativamos o save button
    void updateSaveAction();

private:
    void saveToBinaryFile(const QString &fileName);
    void loadFromBinaryFile(const QString &fileName) ;



};
#endif // MAINWINDOW_H
