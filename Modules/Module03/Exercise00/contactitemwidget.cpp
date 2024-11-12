#include "contactitemwidget.h"

ContactItemWidget::ContactItemWidget(const Contact &contact, QWidget *parent)
    : QWidget(parent),
    m_nameLabel(new QLabel(this)),
    m_phoneLabel(new QLabel(this)),
    m_emailLabel(new QLabel(this))
{
    // Configuração inicial do layout e dos labels
    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(m_nameLabel);
    layout->addWidget(m_phoneLabel);
    layout->addWidget(m_emailLabel);

    setLayout(layout);

    // Define os valores iniciais do contato
    setContact(contact);
}

void ContactItemWidget::setContact(const Contact &contact) {
    m_nameLabel->setText("Name: " + contact.name());
    m_phoneLabel->setText("Phone: " + contact.phone());
    m_emailLabel->setText("Email: " + contact.email());
}
