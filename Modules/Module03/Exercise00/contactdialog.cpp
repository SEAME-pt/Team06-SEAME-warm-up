#include "contactdialog.h"


#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

ContactDialog::ContactDialog(QWidget *parent)
    : QDialog(parent),
    m_nameLineEdit(new QLineEdit(this)),
    m_phoneLineEdit(new QLineEdit(this)),
    m_emailLineEdit(new QLineEdit(this))
{
    setWindowTitle("Contact  Sea:Me  Pithons");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Nome
    QHBoxLayout *nameLayout = new QHBoxLayout;
    nameLayout->addWidget(new QLabel("Name:"));
    nameLayout->addWidget(m_nameLineEdit);
    mainLayout->addLayout(nameLayout);

    // Telefone
    QHBoxLayout *phoneLayout = new QHBoxLayout;
    phoneLayout->addWidget(new QLabel("Phone:"));
    phoneLayout->addWidget(m_phoneLineEdit);
    mainLayout->addLayout(phoneLayout);

    // Email
    QHBoxLayout *emailLayout = new QHBoxLayout;
    emailLayout->addWidget(new QLabel("Email:"));
    emailLayout->addWidget(m_emailLineEdit);
    mainLayout->addLayout(emailLayout);

    // Botões
    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    QPushButton *saveButton = new QPushButton("Save", this);
    QPushButton *cancelButton = new QPushButton("Cancel", this);

    connect(saveButton, &QPushButton::clicked, this, &ContactDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &ContactDialog::reject);

    buttonsLayout->addWidget(saveButton);
    buttonsLayout->addWidget(cancelButton);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);
}

Contact ContactDialog::getContact() const
{
    return Contact(m_nameLineEdit->text(), m_phoneLineEdit->text(), m_emailLineEdit->text());
}

void ContactDialog::setContact(const Contact &contact) {
    m_nameLineEdit->setText(contact.name());
    m_phoneLineEdit->setText(contact.phone());
    m_emailLineEdit->setText(contact.email());
}

void ContactDialog::accept() {
    // Aqui podemos validar os dados

    if (m_nameLineEdit->text().isEmpty() || m_phoneLineEdit->text().isEmpty())
    {


        return;
    }
    QDialog::accept();
}
