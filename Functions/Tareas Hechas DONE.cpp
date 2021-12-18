#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main ()
{
    ifstream g;
    string leertarea;
    
    g.open("TH.txt");
    
    if (!g)
    {
        cout << "No se ha podido abrir el archivo de escritura";
    }
    else
    {
        while (getline (g,leertarea))
        {
            cout << leertarea << endl;
        }
    }
    g.close();
}
