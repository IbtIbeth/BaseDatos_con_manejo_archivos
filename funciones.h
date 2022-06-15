#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

string nombre, auxnombre, puesto, CURP;
float salario;
int id = 0;
int auxid = 0;
int opcion;
int continuar = 2;
bool encontrado = false;

void altas()
{
    ofstream escribir;
    ifstream leer;

    do{
    escribir.open("empleados.txt", ios::out | ios::app);
    leer.open("empleados.txt", ios::in);

    if (escribir.is_open() && leer.is_open()){


            bool existente=false;

            cout<<"\nA continuación ingresa los datos que se te pide del empleado "<<endl;
            cout<<"\nID: ";
            cin>>auxid;

            leer >> id;
            while (!leer.eof()){
                leer >> nombre >> puesto >> CURP >> salario;
                if (auxid == id){
                    cout<< "***Ya existe la ID del empleado***";
                    existente = true;
                    break;
                }
                leer >> id;
            }

            if (existente == false){
                cout << "Nombre completo: ";
                cin >> nombre;
                cout << "Puesto/cargo: ";
                cin >> puesto;
                cout << "CURP: ";
                cin >> CURP;
                cout << "Salario: ";
                cin >> salario;

                escribir<<auxid<<" "<<nombre<<" "<<puesto<<" "<<CURP<<" "<<salario<<endl;
                cout<<"***Registro agregado***"<<endl;
            }

            do{
              cout<<"\n¿Deseas ingresar otro empleado?\n(1) Sí \n(0) No\n";
              cin>>continuar;
              if(continuar == 1){
                opcion = continuar;
              }
              else if(continuar == 0){
                opcion = continuar;
                break;
              }
            }while(continuar != 1 && continuar != 0);


          continuar = 0;

    }else{
        cout<<"El archivo no se pudo abrir \n";
    }

    escribir.close();
    leer.close();

  }while (opcion == 1 );

}

void bajas()
{
    ofstream aux;
    ifstream lectura;

    encontrado=false;

    aux.open("auxiliar.txt", ios::out);
    lectura.open("empleados.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){

        cout<<"\nIngresa la id del empleado que deseas eliminar: ";
        cin>>auxid;

            lectura>>id;
            while (!lectura.eof()){
                lectura >> nombre >> puesto >> CURP >> salario;
                if (auxid==id){
                        encontrado=true;
                        cout<<"\nid:    "<<id<<endl;
                        cout<<"Nombre:   "<<nombre<<endl;
                        cout<<"puesto: "<<puesto<<endl;
                        cout<<"CURP:    "<<CURP<<endl;
                        cout<<"salario:     "<<salario<<endl;

                        do{
                          cout<<"\nRealmente deseas eliminar el registro actual\n(1) Sí \n(0) No\n";
                          cin>>continuar;
                          if(continuar == 1){
                            opcion = continuar;
                            cout<<"***Registro eliminado***"<<endl;
                          }
                          else if(continuar == 0){
                            opcion = continuar;
                            aux<<id<<" "<<nombre<<" "<<puesto<<" "<<CURP<<" "<<salario<<endl;
                            break;
                          }
                        }while(continuar != 1 && continuar != 0);


                      continuar = 0;

                    }else{
                        aux<<id<<" "<<nombre<<" "<<puesto<<" "<<CURP<<" "<<salario<<endl;
                    }
                lectura>>id;
            }
    }else{
        cout<<"El archivo no se pudo abrir \n";
    }

    if (encontrado==false){
                cout<<"\n***No se encontro ningun registro con la id: "<<auxid<<"***\n";
            }

    aux.close();
    lectura.close();
    remove ("empleados.txt");
    rename("auxiliar.txt", "empleados.txt");
}


void consultar()
{

    ifstream lectura;
    lectura.open("empleados.txt", ios::out | ios::in);
    if (lectura.is_open()){
       lectura>>id;
       while (!lectura.eof()){
            lectura >> nombre >> puesto >> CURP >> salario;
            cout<<"\nid:    "<<id<<endl;
            cout<<"Nombre:   "<<nombre<<endl;
            cout<<"puesto: "<<puesto<<endl;
            cout<<"CURP:    "<<CURP<<endl;
            cout<<"salario:     "<<salario<<endl;
            lectura>>id;
       }

    }else{
        cout<<"El archivo no se pudo abrir \n";
    }
    lectura.close();
}


void buscar()
{
    ifstream lectura;
    lectura.open("empleados.txt", ios::out | ios::in);

    encontrado=false;

    if (lectura.is_open()){
        cout<<"\n\tIngresa la id del empleado que deseas buscar: ";
        cin>>auxid;

        lectura>>id;
        while(!lectura.eof()){
            lectura >> nombre >> puesto >> CURP >> salario;

        if(auxid == id){
            cout<<"\n";
            cout<<"id:    "<<id<<endl;
            cout<<"Nombre:   "<<nombre<<endl;
            cout<<"puesto: "<<puesto<<endl;
            cout<<"CURP:    "<<CURP<<endl;
            cout<<"salario:     "<<salario<<endl;
            encontrado=true;

            break;
        }

        lectura>>id;
        }
        if (encontrado==false){
            cout<<"***No hay registros con la id: "<<auxid<<"***\n"<<endl;
        }
    }else{
        cout<<"***No se pudo abrir el archivo***"<<endl;
    }

    lectura.close();
}

void modificar()
{
    ofstream aux;
    ifstream lectura;

    encontrado = false;

    aux.open("auxiliar.txt", ios::out);
    lectura.open("empleados.txt", ios::in);

    if (aux.is_open() && lectura.is_open()){

        cout<<"\nIngresa la id del empleado que deseas modificar: ";
        cin>>auxid;

            lectura>>id;
            while (!lectura.eof()){
                lectura >> nombre >> puesto >> CURP >> salario;
                if (auxid==id){
                    encontrado=true;
                    cout<<"\n";
                    cout<<"id:    "<<id<<endl;
                    cout<<"Nombre:   "<<nombre<<endl;
                    cout<<"puesto: "<<puesto<<endl;
                    cout<<"CURP:    "<<CURP<<endl;
                    cout<<"salario:     "<<salario<<endl;
                    cout<<"Ingresa el nuevo nombre del empleado con la id: "<<auxid<<"\n\n";
                    cin>>auxnombre;

                    aux<<id<<" "<<auxnombre<<" "<<puesto<<" "<<CURP<<" "<<salario<<endl;
                    cout<<"Registro modificado";
                    }else{
                    aux<<id<<" "<<nombre<<" "<<puesto<<" "<<CURP<<" "<<salario<<endl;
                    }
                lectura>>id;
            }
    }else{
        cout<<"***El archivo no se pudo abrir***"<<endl;
    }

    if (encontrado==false){
                cout<<"\nNo se encontro ningun registro con la id: "<<auxid<<endl;
            }

    aux.close();
    lectura.close();
    remove ("empleados.txt");
    rename("auxiliar.txt", "empleados.txt");
}
