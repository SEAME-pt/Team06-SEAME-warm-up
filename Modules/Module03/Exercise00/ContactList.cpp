// ContactList.cpp
#include "ContactList.h"

// Busca um contato pelo nome e retorna o primeiro contato encontrado
Contact ContactList::searchContact(const QString& name) const
{
    for (const Contact& contact : m_contacts)
    {
        if (contact.name().compare(name, Qt::CaseInsensitive) == 0)
        {
            return contact; // Retorna o contato se encontrado
        }
    }
    // Retorna um contato vazio se nenhum contato for encontrado
    return Contact("", "", "");
}

// Adiciona um contato à lista
void ContactList::addContact(const Contact& contact)
{
    m_contacts.append(contact);
}

// Remove um contato da lista com base no índice
void ContactList::removeContact(int index)
{
    if (index >= 0 && index < m_contacts.size())
    {
        m_contacts.removeAt(index);
    }
}


void ContactList::clear()
{
    m_contacts.clear();
}
