#include "Phonebook.hpp"
#include "Contact.hpp"
#include "gtest/gtest.h"

class MockContact : public Contact {
public:
    MockContact(const std::string &name, const std::string &number, const std::string &nickname, bool bookmarked) {
        setName(name);
        setNumber(number);
        setNickname(nickname);
        setBookmarked(bookmarked);
    }
};

class PhonebookTest : public ::testing::Test {
protected:
    Phonebook phonebook;

    void SetUp() override {
        phonebook._contacts.push_back(MockContact("Alice", "12345", "Ally", false));
        phonebook._contacts.push_back(MockContact("Bob", "67890", "Bobby", true));
    }
};

TEST_F(PhonebookTest, AddContact) {
    size_t initialSize = phonebook._contacts.size();
    phonebook._contacts.push_back(MockContact("Charlie", "112233", "Chuck", false));
    EXPECT_EQ(phonebook._contacts.size(), initialSize + 1);
    EXPECT_EQ(phonebook._contacts.back().getName(), "Charlie");
}

TEST_F(PhonebookTest, RemoveContactByIndex) {
    size_t initialSize = phonebook._contacts.size();
    ASSERT_NO_THROW(phonebook._contacts.erase(phonebook._contacts.begin() + 1)); // Remove Bob
    EXPECT_EQ(phonebook._contacts.size(), initialSize - 1);
    EXPECT_EQ(phonebook._contacts[0].getName(), "Alice");
}

TEST_F(PhonebookTest, EmptyPhonebookThrows) {
    Phonebook emptyPhonebook;
    EXPECT_THROW(emptyPhonebook.hasContacts(), std::invalid_argument);
}
