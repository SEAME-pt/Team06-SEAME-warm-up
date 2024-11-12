#ifndef CONTACTITEMWIDGET_H
#define CONTACTITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include "Contact.h"

class ContactItemWidget : public QWidget {
    Q_OBJECT

public:
    explicit ContactItemWidget(const Contact &contact, QWidget *parent = nullptr);

    void setContact(const Contact &contact); // Para atualizar o contato exibido

private:
    QLabel *m_nameLabel;
    QLabel *m_phoneLabel;
    QLabel *m_emailLabel;
    
};

#endif // CONTACTITEMWIDGET_H
