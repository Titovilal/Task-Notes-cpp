/********* Task Notes **************************************************/ /**
 *
 * Este programa es una agenda de tareas que permite: añadir tareas, eliminar 
 * tareas, marcarlas como completadas, puedes ver las tareas pendientes y las 
 * completadas.
 *
 * @version 1.0 Funciona.
 * @version 1.10 Parches y 
 * @version 2.0 Cambio total al codigo interno
 *
 * @author Salva Castells
 * @date 05/12/2019
 *
 ***************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Variables globales
const int MAX = 100;

//Registros y vectores
typedef string vTareas [MAX];
struct Tareas
{
    vTareas info;
    int num;
};

//Prototipo funciones
int Presentacion ();                                                                //Presentar programa y seleccionar opcion
bool LeerFicheros (string fich_p,string fich_h,Tareas & tp,Tareas & th);            //Leer ficheros y rellenar los registros
void MostrarTareas (Tareas);                                                        //Mostrar todas las tareas del registro seleccionado
void AgregarTarea (string,string tarea,Tareas &);                                   //Agegar tarea a un vector
bool EliminarTarea (string tarea,Tareas &);                                         //Eliminar tarea de un vector
bool ReescribirFichero (string,Tareas);                                             //Funcion reescribir un fichero con un vector
int main ()
{
    //Variables
    Tareas tp,th,t;
    string fich_p = "TP.txt",fich_h = "TH.txt",fich;
    int op;
    string tarea;

    //Menu
    do
    {
        if (!LeerFicheros (fich_p,fich_h,tp,th))                                    //Rellenar registros desde los ficheros
        {
            cout << "No se han podido encontrar los archivos";
            system ("pause");
            op = 0;
        }
        else
        {
            op = Presentacion ();                                                   //Presentacion del programa + seleccion menu

            switch (op)
            {
                case 1:                                                             //Agregar tarea en tareas pendientes
                    cout << "Escribe la nueva tarea: ";
                    getline (cin,tarea);
                    AgregarTarea (fich_p,tarea,tp);
                    break;

                case 2:                                                             //Marcar tarea como completada
                    MostrarTareas (tp);
                    cout << "Escribe la tarea que quieres tachar: ";
                    getline (cin,tarea);
                    if (EliminarTarea (tarea,tp))
                    {
                        if (ReescribirFichero (fich_p,tp))
                        {
                            AgregarTarea (fich_h,tarea,th);
                            cout << "Se ha movido la tarea correctamente." << endl;
                        }
                        else
                            cout << "Ha habido un problema con los ficheros" << endl;
                    }
                    else 
                        cout << "La tarea escrita no existe." << endl;
                    break;

                case 3:                                                             //Mostrar tareas pendientes
                    cout << "Tareas pendientes ("<<tp.num<<"): \n";
                    MostrarTareas (tp);
                    break;
                    
                case 4:                                                             //Eliminar tarea
                    MostrarTareas (tp);
                    cout << "Escribe la tarea que quieres eliminar: ";
                    getline (cin,tarea);
                    if (EliminarTarea (tarea,tp))
                    {
                        if (ReescribirFichero (fich_p,tp))
                            cout << "Se ha eliminado la tarea correctamente." << endl;
                        else
                            cout << "Ha habido un problema con los ficheros" << endl;
                    }
                    else
                        cout << "La tarea escrita no existe." << endl;
                    break;

                case 5:                                                             //Mostrar tareas hechas
                    cout << "Tareas hechas ("<<th.num<<"): \n";
                    MostrarTareas (th);
                    break;
                    
                default:                                                            //Error numero equivocado
                    if (op != 0)
                        cout << "Error, no es una opcion del menu . . .\n";
                    break;
            }
            if (op != 0)
            {
                system ("pause");
                system ("cls");
            }
        }
    }
    while (op != 0);
    
    return 0;
}
//Funcion presentar programa y seleccionar opcion
int Presentacion ()
{
    int op;
    cout << "******************************  TASK NOTES  ******************************\n";
    cout << "****  Elige una opcion (0 para cerrar el programa):  *********************\n";
    cout << "****  1 Agregar Tarea  ***************************************************\n";
    cout << "****  2 Marcar tarea como completada  ************************************\n";
    cout << "****  3 Ver tareas pendientes  *******************************************\n";
    cout << "****  4 Eliminar Tarea  **************************************************\n";
    cout << "****  5 Ver tareas hechas  ***********************************************\n";
    cout << "************************************************************************ ";
    cin >> op;
    cin.ignore();
    
    return op;
}
//Funcion leer ficheros y rellenar los registros
bool LeerFicheros (string fich_p,string fich_h,Tareas & tp,Tareas & th)
{
    //Variables
    bool ok;
    string tarea;
    ifstream g,d;
    tp.num = 0;
    th.num = 0;
    
    //Procesamiento y salida de datos
    g.open(fich_p);
    d.open(fich_h);

    if (!g || !d)
        ok = false;

    else
    {
        ok = true;

        while (getline (g,tp.info[tp.num]))                                         //Rellenar registro tareas pendientes
            tp.num++;

        while (getline (d,th.info[th.num]))                                         //Rellenar registro tareas pendientes
            th.num++;

        g.close();
        d.close();
    }
    return ok;
}
//Funcion mostrar todas las tareas del registro seleccionado
void MostrarTareas (Tareas t)
{
    int i;

    for (i = 0;i <t.num;i++)                                                        //Bucle mostrar tareas
        cout << t.info[i] << endl;
        
    cout << "**************************************************************************\n";

    return;
}
//Fucnion agregar tarea a tareas pendientes
void AgregarTarea (string fich,string tarea,Tareas & t)
{
    ofstream f;

    t.num++;
    t.info[t.num] = tarea;

    f.open(fich,ios::app);
    f << tarea << endl;
    f.close();

    return;
}
//Funcion eliminar tarea de vector
bool EliminarTarea (string tarea,Tareas & t)
{
    int i,j;
    bool deleted = false;

    for (i = 0;i < t.num;i++)
    {
        if (t.info[i] == tarea)                                                     //Si la tarea existe borrar tarea
        {
            deleted = true;
            for (j = i;j < t.num;j++)
            {
                t.info[j] = t.info[j+1];
            }
            t.num--;
        }
    }
    return deleted;
}
//Funcion reescribir un fichero con un vector
bool ReescribirFichero (string fich,Tareas t)
{
    bool ok;
    ofstream f;
    int i;
    
    f.open(fich);
    
    if (!f)
        ok = false;
    else
    {
        ok = true;

        for (i = 0;i < t.num;i++)
        {
            f << t.info[i] << endl;
        }
    f.close();
    }
    return ok;
}
