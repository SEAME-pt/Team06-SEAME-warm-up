
#include <QMenuBar>
#include <QToolBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "contactdialog.h"
#include "contactitemwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),m_contactListWidget(new QListWidget(this))
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_fileName ="";

    setCentralWidget(m_contactListWidget);

    // Criação do menu e da barra de ferramentas
    createActions();
    createMenu();
    createToolbar();

    connect(m_contactListWidget, &QListWidget::itemDoubleClicked, this, &MainWindow::onItemDoubleClicked);

   // connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::searchContact);






}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::createActions()
{
    m_actions["Open"] = new QAction(style()->standardIcon(QStyle::SP_DialogOpenButton), "Open", this);
    connect(m_actions["Open"], &QAction::triggered, this, &MainWindow::openFile);

    m_actions["Save"] = new QAction(style()->standardIcon(QStyle::SP_DialogSaveButton), "Save", this);
    connect(m_actions["Save"], &QAction::triggered, this, &MainWindow::saveFile);
    m_actions["Save"]->setEnabled(false); // Desativa o Save como default


    m_actions["Save As"] = new QAction(style()->standardIcon(QStyle::SP_FileIcon), "Save As", this);
    connect(m_actions["Save As"], &QAction::triggered, this, &MainWindow::saveFileAs);

    m_actions["Exit"] = new QAction(style()->standardIcon(QStyle::SP_TrashIcon), "Exit", this);
    connect(m_actions["Exit"], &QAction::triggered, this, &MainWindow::exitApp);

    m_actions["Add"] = new QAction(style()->standardIcon(QStyle::SP_FileIcon), "Add", this);
    connect(m_actions["Add"], &QAction::triggered, this, &MainWindow::addContact);

    m_actions["Edit"] = new QAction(style()->standardIcon(QStyle::SP_BrowserReload), "Edit", this);
    connect(m_actions["Edit"], &QAction::triggered, this, &MainWindow::editContact);
}
void MainWindow::createMenu()
{
    QMenu *fileMenu = menuBar()->addMenu("File");


    fileMenu->addAction(m_actions["Open"]);
    fileMenu->addAction(m_actions["Save"]);
    fileMenu->addAction(m_actions["Save As"]);
    fileMenu->addSeparator();
    fileMenu->addAction(m_actions["Exit"]);

    QMenu *editMenu = menuBar()->addMenu("Edit");

    //  ações de edição ao menu
    editMenu->addAction(m_actions["Add"]);
    editMenu->addAction(m_actions["Edit"]);
}

void MainWindow::createToolbar()
{
    QToolBar *toolbar = addToolBar("Main Toolbar");

    toolbar->addAction(m_actions["Save"]);
    toolbar->addSeparator();

    // Adiciona as ações à barra de ferramentas
    toolbar->addAction(m_actions["Add"]);
    toolbar->addAction(m_actions["Edit"]);

}

// Slot para adicionar contato
void MainWindow::addContact()
{
    ContactDialog dialog(this);
    dialog.setWindowTitle("Add Contact");


    if (dialog.exec() == QDialog::Accepted)
    {
        Contact newContact = dialog.getContact();
        m_contactList.addContact(newContact);


        QListWidgetItem *item = new QListWidgetItem(m_contactListWidget);
        ContactItemWidget *contactWidget = new ContactItemWidget(newContact);
        item->setSizeHint(contactWidget->sizeHint()); // Ajusta o tamanho do item para caber o widget
        m_contactListWidget->setItemWidget(item, contactWidget);
    }


}

// Slot para editar contato
void MainWindow::editContact()
{

    QListWidgetItem *selectedItem = m_contactListWidget->currentItem();
    if (!selectedItem)
    {
        QMessageBox::warning(this, "Edit Contact", "No contact selected");
        return;
    }



    int index = m_contactListWidget->row(selectedItem);
    Contact contact = m_contactList.contacts().at(index);



    ContactDialog dialog(this);
    dialog.setWindowTitle("Edit Contact");
    dialog.setContact(contact);



    if (dialog.exec() == QDialog::Accepted)
    {
        Contact updatedContact = dialog.getContact();
        m_contactList.removeContact(index);
        m_contactList.addContact(updatedContact);



        ContactItemWidget *contactWidget = new ContactItemWidget(updatedContact);
        selectedItem->setSizeHint(contactWidget->sizeHint());
        m_contactListWidget->setItemWidget(selectedItem, contactWidget);
    }
}

// Slot para abrir arquivo
void MainWindow::openFile()
{
    m_fileName = QFileDialog::getOpenFileName(this, "Open Contact List", "", "Seame Files (*.me)");
    if (!m_fileName.isEmpty())
    {
        loadFromBinaryFile(m_fileName);
        m_hasFile = true;
        updateSaveAction();
    }
}

// Slot para salvar arquivo
void MainWindow::saveFile()
{

    if (!m_fileName.isEmpty() && m_hasFile)
    {
        saveToBinaryFile(m_fileName);
    }

}

// Slot para salvar como
void MainWindow::saveFileAs()
{
    m_fileName = QFileDialog::getSaveFileName(this, "Save Contact List As", "", "Seame Files (*.me)");
    if (!m_fileName.isEmpty())
    {
        saveToBinaryFile(m_fileName);
        m_hasFile = true;
        updateSaveAction();
    }
}

void MainWindow::onItemDoubleClicked(QListWidgetItem *item)
{
    int index = m_contactListWidget->row(item);
    Contact contact = m_contactList.contacts().at(index);

    ContactDialog dialog(this);
    dialog.setWindowTitle("Edit Contact");
    dialog.setContact(contact);

    if (dialog.exec() == QDialog::Accepted)
    {
        Contact updatedContact = dialog.getContact();
        m_contactList.removeContact(index);
        m_contactList.addContact(updatedContact);

        // Atualizar o widget do item de lista
        ContactItemWidget *contactWidget = new ContactItemWidget(updatedContact);
        item->setSizeHint(contactWidget->sizeHint());
        m_contactListWidget->setItemWidget(item, contactWidget);
    }
}


void MainWindow::exitApp()
{
    QApplication::quit();
}



void MainWindow::saveToBinaryFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, "Save Error", "Could not open file for writing.");
        return;
    }

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_15); // Define a versão do QDataStream

    // Escreve o header do arquivo
    double version = 0.01;  // Versão do formato
    out << version;

    int contactCount = m_contactList.contacts().size();
    out << contactCount;

    // Escreve cada contato em binário
    for (const Contact &contact : m_contactList.contacts())
    {
        out << contact.name();
        out << contact.phone();
        out << contact.email();
    }

    file.close();
}

void MainWindow::loadFromBinaryFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, "Load Error", "Could not open file for reading.");
        return;
    }

    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_5_15); // Define a versão do QDataStream

    // Lê o header do arquivo
    double version;
    in >> version;
    if (version != 0.01)
    {
        QMessageBox::warning(this, "Load Error", "Unsupported file version.");
        return;
    }

    int contactCount;
    in >> contactCount;

    m_contactListWidget->clear();
    m_contactList.clear();



    for (int i = 0; i < contactCount; ++i)
    {
        QString name, phone, email;
        in >> name >> phone >> email;

        Contact contact(name, phone, email);
        m_contactList.addContact(contact);

        // Adiciona o widget personalizado à lista
        QListWidgetItem *item = new QListWidgetItem(m_contactListWidget);
        ContactItemWidget *contactWidget = new ContactItemWidget(contact);
        item->setSizeHint(contactWidget->sizeHint());
        m_contactListWidget->setItemWidget(item, contactWidget);
    }

    file.close();
}

void MainWindow::updateSaveAction()
{
    m_actions["Save"]->setEnabled(m_hasFile);
}
