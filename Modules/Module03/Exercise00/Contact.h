#ifndef CONTACT_H
#define CONTACT_H

/*

2. Create a contact class: Create a C++ class that represents a contact in the phonebook.
This class should have member variables for the contact's name, phone number, email address, and any other relevant information.
You should also provide member functions to access and modify these variables.
*/

#include <QString>

class Contact {
public:
    Contact(const QString& name, const QString& phone, const QString& email)
        : m_name(name), m_phone(phone), m_email(email) {}

    QString name() const { return m_name; }
    QString phone() const { return m_phone; }
    QString email() const { return m_email; }

    void setName(const QString& name) { m_name = name; }
    void setPhone(const QString& phone) { m_phone = phone; }
    void setEmail(const QString& email) { m_email = email; }

private:
    QString m_name;
    QString m_phone;
    QString m_email;
};

#endif // CONTACT_H
