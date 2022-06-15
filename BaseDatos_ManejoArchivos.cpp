#include <string>
#include "funciones.h"

using namespace std;

int main()
{
    int op, salir;

    do{

    cout<<"\n\tBase de datos de empleados de ECOMODA\n\n"<<endl;
    cout<<"(1) Altas"<<endl;
    cout<<"(2) Bajas"<<endl;
    cout<<"(3) Consultas"<<endl;
    cout<<"(4) Buscar un registro"<<endl;
    cout<<"(5) Modificaciones"<<endl;
    cout<<"(6) Salir"<<endl;
    cout<<"\nElige una opción:  ";
    cin >> op;
    switch (op)
    {
case 1:{
    altas();
    cout<<"\n\t\t";
    break;
}
case 2:{

    bajas();
    cout<<"\n\t\t";
    break;
}

case 3:{
    consultar();
    cout<<"\n\t\t";
    break;
}
case 4:{
    buscar();
    cout<<"\n\t\t";
    break;
}
case 5:{
    modificar();
    cout<<"\n\t\t";

    break;
}
case 6:{
    cout<<"\n¿Seguro que quieres salir?\n(1) Sí \n(0) No\n"<<endl;
    cin>>salir;

    if(salir == 1){
      break;
    }else{
      op = 1;
      break;
    }

}
default:{
    cout<<"Ha elegido una opion inexistente";
    break;
}
    }

    }while (op!=6);

    return 0;
}
