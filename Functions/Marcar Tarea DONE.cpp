#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main ()
{
    string leertarea;
    fstream f;
    fstream g;
    f.open ("TH.txt",ios::app);
    g.open ("TP.txt");
    
    if (!f || !g)
        cout << "No se ha podido abrir alguno de los dos archivos.";
    else
    {
        cout << "Escribe que linea quieres llevar al otro archivo:\n";
        while (getline (g,leertarea))
        {
            cout << leertarea << endl;
        }
    
    }   
}

