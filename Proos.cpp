#include <iostream>
using namespace std;
#include <stdlib.h>
#include <fstream>
#include <chrono>
#include <ctime>

struct Horario{ // estructura para guadar Fecha 
    int dia;
    int mes;
    int anio;
};

Horario entregrar_fecha(){ // funcion de tipo struct para obtener la fecha y guardarla en el struct
    
    Horario Fecha_exacta;
    // Obtener el tiempo actual en el sistema
    auto ahora = chrono::system_clock::now();
    
    // Convertir el tiempo actual a un tipo de tiempo basado en el tiempo UTC
    time_t tiempo = chrono::system_clock::to_time_t(ahora);
    
    // Convertir el tiempo UTC en una estructura de tiempo local
    tm* tiempo_local = localtime(&tiempo);

    Fecha_exacta.dia= tiempo_local->tm_mday;
    Fecha_exacta.mes= tiempo_local->tm_mon + 1;
    Fecha_exacta.anio= tiempo_local->tm_year + 1900;

    return Fecha_exacta;
}


void agregar(int huevos){    // Aqui se abre el archivo y posteriormente se le agrega la cantidad de huevos y fecha
    ofstream archivo;
    Horario Fecha=entregrar_fecha();
    archivo.open("registro.txt",ios::app);
    if(archivo.is_open()){   
        cout<<"Se abrio "<<endl;
        archivo <<"Vendiste "<<huevos<<" Huevos   "<< Fecha.dia<< "/"<< Fecha.mes << "/"<< Fecha.anio<<endl;
    archivo.close();
    }
    else {
        cout<<"No se abrio el archivo"<<endl;
    }
}

void Calculadora(int huevos){
    cout<< "Se vendieron: "<<huevos<<" Huevos"<<endl;
    cout<< "Se recaudo un total de :"<< huevos*200 <<" pesos"<<endl;
}



int main()
{
    
    int var,cajas_h=0,cajas=0, valor=0;
    int huevos=0;
    int seguir;
    do{
    do{
    cout<<"[1] Huevos individuales"<<endl;
    cout<<"[2] Cajas de huevo"<<endl;
    cin>>var; 
    if (var==1) {
        cout<<"Ingrese la cantidad de huevos"<<endl;
        cin>> valor;
        huevos= huevos+valor;
        
    }
    else if (var==2) {
        cout<<"Ingrese la cantidad de cajas de huevos"<<endl;
        cin>> cajas_h;
        cajas= cajas_h+cajas;
        huevos= huevos + (30*cajas_h);
    }
    else{
        cout<<"Ingrese una valor valido"<<endl;
    }

    }while(var!=1 && var!=2);

    cout<<"Desea continuar"<<endl;
    cout<<"[1] SI"<<endl;
    cout<<"[2] NO"<<endl;
    cin>> seguir;
     
    }while(seguir==1);

    agregar(huevos);
    Calculadora(huevos);

    return 0;
}


