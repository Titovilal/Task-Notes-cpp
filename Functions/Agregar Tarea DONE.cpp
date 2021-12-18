#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main ()
{
    string tarea;
    ofstream f;
    
    f.open("TP.txt",ios::app);
    
    if (!f)
    {
        cout << "No se ha podido abrir el archivo de escritura";
    }
    else
    {
        cout << "Escribe la tarea: ";
        getline (cin,tarea);
        f << tarea << endl;
    }
}
