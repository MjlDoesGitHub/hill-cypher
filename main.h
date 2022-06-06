#ifndef HILL_CIPHER_MAIN_H
#define HILL_CIPHER_MAIN_H

class Encryption
{
private:
    std::string m_message{};
    std::vector<int> m_uncodedMatrix;
    int m_encodingMatrix[3][3];
    std::vector<int> m_codedMatrix;

public:

    void promptUser();
    static int mapKey(const std::string& c);

    void setMessage(std::string message)
    {
        m_message = message;
    }

    void setUncodedMatrix();
    void setEncodingMatrix();
    void setCodedMatrix();

    void printUncodedMatrix()
    {
        for(int i = 0; i < m_uncodedMatrix.size(); ++i)
        {
            if(i == 0 || i % 3 == 0)
            {
                std::cout << "[ ";
            }
            std::cout << m_uncodedMatrix[i] << ' ';
            if((i + 1) % 3 == 0)
            {
                std::cout << "]\n";
            }
        }
    }
    void printEncodingMatrix()
    {
        for(int r = 0; r < 3; ++r)
        {
            for(int c = 0; c < 3; ++c)
            {
                std::cout << m_encodingMatrix[r][c] << " ";
            }
            std::cout << "\n";
        }

    }
    void printCodedMatrices()
    {
        for(int i = 0; i < m_codedMatrix.size(); ++i)
        {
            if(i == 0 || i % 3 == 0)
            {
                std::cout << "[ ";
            }
            std::cout << m_codedMatrix[i] << ' ';
            if((i + 1) % 3 == 0)
            {
                std::cout << "]\n";
            }
        }
    }
    void printCodedMessage()
    {
        for(int i = 0; i < m_codedMatrix.size(); ++i)
        {
            std::cout << m_codedMatrix[i] << ' ';
        }
        std::cout << '\n';
    }
    std::string getMessage() { return m_message; }

};
#endif