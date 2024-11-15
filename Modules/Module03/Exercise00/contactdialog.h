#ifndef CONTACTDIALOG_H
#define CONTACTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include "Contact.h"

class ContactDialog : public QDialog {
    Q_OBJECT

public:
    explicit ContactDialog(QWidget *parent = nullptr);
    Contact getContact() const; // Retorna o contato criado/editado
    void setContact(const Contact &contact); // Define os dados do contato a serem editados

private slots:
    void accept() override; // Slot que salva o contato e fecha o diálogo

private:
    QLineEdit *m_nameLineEdit;
    QLineEdit *m_phoneLineEdit;
    QLineEdit *m_emailLineEdit;
};

#endif // CONTACTDIALOG_H
