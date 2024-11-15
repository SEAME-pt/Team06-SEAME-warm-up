// ContactList.h
#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"
#include <QList>

class ContactList {
public:
    void addContact(const Contact& contact);
    void removeContact(int index);
    Contact searchContact(const QString& name) const;

    QList<Contact> contacts() const { return m_contacts; }

    void clear();

private:
    QList<Contact> m_contacts;
};

#endif // CONTACTLIST_H
