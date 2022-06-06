#include <iostream>
#include <cmath>
#include <vector>
#include "main.h"

void Encryption::promptUser()
{
    std::cout << "Message to encrypt (lowercase only): ";
    std::string message{};
    getline(std::cin >> std::ws, message);
    setMessage(message);
}

int Encryption::mapKey(const std::string& c)
{
    std::string alphabet{ " abcdefghijklmnopqrstuvwxyz" };
    for(int i = 0; i <= alphabet.length(); ++i)
    {
        if(c == alphabet.substr(i, 1))
        {
            return i;
        }
    }
    return -1;
}
void Encryption::setUncodedMatrix()
{
    for(int i = 0; i < m_message.length(); ++i)
    {
        m_uncodedMatrix.push_back(mapKey(m_message.substr(i, 1)));
    }
    while(m_uncodedMatrix.size() % 3 != 0)
    {
        m_uncodedMatrix.push_back(0);
    }
}

void Encryption::setEncodingMatrix()
{
    for(int r = 0; r < 3; ++r)
    {
        for(int c = 0; c < 3; ++c)
        {
            m_encodingMatrix[r][c] = 1 + (rand() % 9);
        }
    }
}

void Encryption::setCodedMatrix()
{
    for(int i = 0; i < m_uncodedMatrix.size() / 3; ++i) // iterations determined by # of elements / 3
    {
        for (int c = 0; c < 3; ++c) // start off matrix multiplication col first then row
        {
            int element{};
            int j{ i * 3 }; // uncoded index position based on set iteration
            for (int r = 0; r < 3; ++r)
            {
//                std::cout << m_uncodedMatrix[j] << " ";
//                std::cout << m_encodingMatrix[r][c] << ' ';
//                std::cout << '\n';
                element += m_uncodedMatrix[j] * m_encodingMatrix[r][c];
                ++j;
            }
            m_codedMatrix.push_back(element);
        }
    }
}

int main()
{
    srand(time(0));
    std::cout << "Hill Cipher by Matthew Lim\n";
    std::cout << "e.g. hello transcribes to '8 5 12 12 15 0'\n";
    Encryption encryption;

    encryption.promptUser();
    // int length{ static_cast<int>(std::ceil((double) encryption.getMessage().length() / 3)) };
    encryption.setUncodedMatrix();
    encryption.setEncodingMatrix();
    encryption.setCodedMatrix();
    std::cout << "Message received: " << encryption.getMessage() << '\n';
    std::cout << "Uncoded message matrices: \n";
    encryption.printUncodedMatrix();
    std::cout << "Encoding matrix: \n";
    encryption.printEncodingMatrix();
    std::cout << "Coded message matrices: \n";
    encryption.printCodedMatrices();
    std::cout << "Coded preprocessed message: ";
    encryption.printCodedMessage();
    return 0;
}