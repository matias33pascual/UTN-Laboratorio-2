#include <iostream>

using namespace std;

class Persona
{
private:
    int edad;
    char nombre[30];

public:
    Persona()
    {
        cout << "soy un constructor! =)" << endl;
        edad = 0;
    }
    ~Persona()
    {
        cout << "estoy destruyendome =(" << endl;
    }

    saludar()
    {
        cout << "hola!" << endl;
    }
};

int main()
{
    Persona* persona = new Persona();
    delete persona;
}
