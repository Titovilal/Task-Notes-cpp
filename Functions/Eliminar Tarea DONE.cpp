#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int MAX = 1000;                       

string Tarea [MAX];

int main ()
{
    int num,i;
    num = 0;
    ofstream f;
    ifstream g;
    string t_eliminar;
    
    g.open("TP.txt",ios::out);
    if (!g)
    {
        cout << "No se ha podido abrir el archivo de escritura";
    }
    else
    {
        while (getline(g,Tarea [num]))
        {
            num ++;
        }
    g.close();
    }
    
    f.open("TP.txt");
    if (!f)
    {
        cout << "No se ha podido abrir el archivo de escritura";
    }
    else
    {
        cout << "Escribe el nombre de la tarea a eliminar: "; 
        getline (cin,t_eliminar);
        
        for (i = 0; i < num; i++)
        {
            if (Tarea[i].compare (t_eliminar)!=0)
            {
                f << Tarea [i] << endl; 
                cout << "Se ha eliminado la tarea correctamente";
            }
        }
        f.close ();
    }
}

