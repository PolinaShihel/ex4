#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <ostream>

class DeckFileNotFound : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public std::exception
{
public:
    DeckFileFormatError(const int line):
    m_line(line),
    m_error("Deck File Error: File format error in line " + std::to_string(m_line))
    {
    }

    virtual const char* what() const noexcept override
    {
        return m_error.c_str();
    }

private:
    int m_line;
    std::string m_error;
};

class DeckFileInvalidSize : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};

#endif //EXCEPTION_H