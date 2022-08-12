/*#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <bitset>
#include <string.h>

using namespace std;
void Saldo();
void IngresoUsuario();
void Retiro();
int main()
{
    string clave;
    string str3,str,binfinal;
    ifstream fin;
    ofstream fout;
    fin.open("clave.txt");
    while(fin.good()){
        getline(fin,str3);
        str+=str3;
    }
    fin.close();
    cout<<"Ingrese la clave del Administrador: ";
    cin>>clave;

    string binario="";
    for (int i = 0; i < clave.length(); ++i) {
            bitset<8> bs4(clave[i]);
            binario += bs4.to_string();
    }

    int tempo=int(binario.length());
    string binario2=binario;
    binario[0]=binario[tempo-1];

    for (int i=1;i<tempo+1;i++){
        binario[i]=binario2[(i-1)];
    }

    if (str==binario){
        char opc;
        cout<<"Acceso permitido"<<endl<<endl;
        label:
        cout<<"¿Que desea hacer?"<<endl;
        cout<<"1. Ingresar usuarios"<<endl;
        cout<<"2. Consultar o retirar dinero"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>opc;

        switch(opc){
            case'1':
            {
                IngresoUsuario();
                goto label;
            }
            case '2':
           {
               char opc2;
               label3:
               cout<<"¿Que desea hacer?"<<endl;
               cout<<"1. Consultar saldo"<<endl;
               cout<<"2. Retirar dinero"<<endl;
               cout<<"3. Salir"<<endl;
               cin>>opc2;

               switch (opc2){

               case '1':                //consulta de saldo
               {
                   Saldo();
                   goto label3;
                }
               case '2':
               {
                   Retiro();
                   goto label3;
               }
               case '3':
               {
                   goto label4;
               }
           }
        }
        label4:
        case '3':
        {
            cout<<"Programa finalizado"<<endl;
            break;
        }
        }
    }
    else{
        cout<<"Clave incorrecta"<<endl;
        cout<<"Programa Finalizado"<<endl;
    }
    return 0;

}

void Saldo(){
    string ced,cedulaarc,datos,clavearc,saldoarc,copia,str,str2,k,copia2,copia3;
    ifstream fin,fan;
    ofstream fout;
    int x=0,c=0,bits=0;
    cout<<"Ingrese numero de cedula: "<<endl;
    cin>>ced;
    fin.open("cajeroauto.txt");
    while(fin.good()){
       getline(fin,k);
       copia2+=k+'\n';
    }
    fin.close();
    fout.open("cajeroautotempo.txt");
    fout<<copia2;
    fout.close();

    fin.open("cajeroauto.txt");
    while(fin.good()){                                   //Lectura del archivo hasta el final
        getline(fin,datos);                               //Lee una linea del archivo y la guarda en datos
        int count = 0;
        int temp = 0;

        for(int i = 0; i<int(datos.length()); i++){
            if(datos.at(i)==';' && (count==0)){
                cedulaarc = datos.substr(temp,i);
                temp = i+1;
                break;
            }
        }
        x++;
        if (ced==cedulaarc){                          //comparación con la cedula ingresada y la linea del archivo
            fan.open("cajeroautotempo.txt");
            string p,d;
            d="";
            while(fan.good()){
               getline(fan,p);
               if (p!=datos && p!=d){
                   copia3+=p+'\n';
               }
            }
            fan.close();
            string clave;
            int h=0;
            int f=3;
            label5:
            cout<<"Ingrese clave del ususario: "<<endl;
            cin>>clave;
            clavearc = datos.substr(temp,4);
            if (clave==clavearc){
                string saldoarc = datos.substr(temp+5);
                cout<<"El saldo es: $ "<<saldoarc<<" Pesos"<<endl<<endl;
                int num = stoi(saldoarc);
                num=num-1000;
                string num2 = to_string(num);
                str2=ced+';'+clave+';'+num2;
                copia3+=str2;
                fout.open("cajeroauto.txt");
                fout<<copia3;
                fout.close();

                break;
            }
            else {
                cout<<"Clave incorrecta"<<endl;
                h++;
                f--;
                cout<<"Le quedan "<<f<<" intentos"<<endl;
                if (h==3){
                    cout<<endl;
                    break;
                }
                goto label5;
                break;
            }
         fin.close();
         }
}
}

void IngresoUsuario(){
    string copia,cedula,clave,saldo,sumadatos,str3;
    ifstream fin;
    ofstream fout;
    fin.open("cajeroauto.txt");
    while(fin.good()){
        getline(fin,str3);
        copia+=str3+"\n";
    }
    fin.close();
    cout<<"Ingrese cedula: "<<endl;
    cin>>cedula;
    cout<<"Ingrese clave: "<<endl;
    cin>>clave;
    cout<<"Ingrese saldo: "<<endl;
    cin>>saldo;
    sumadatos+=cedula+";"+clave+";"+saldo;
    copia+=sumadatos;
    fout.open("cajeroauto.txt");
    fout<<copia;
    fout.close();
}

void Retiro(){
    string ced,cedulaarc,datos,clavearc,saldoarc,copia,str,str2,k,copia2,copia3;
    ifstream fin,fan;
    ofstream fout;
    int x=0,c=0,bits=0;
    cout<<"Ingrese numero de cedula: "<<endl;
    cin>>ced;
    fin.open("cajeroauto.txt");
    while(fin.good()){
       getline(fin,k);
       copia2+=k+'\n';
    }
    fin.close();
    fout.open("cajeroautotempo.txt");
    fout<<copia2;
    fout.close();

    fin.open("cajeroauto.txt");
    while(fin.good()){                                   //Lectura del archivo hasta el final
        getline(fin,datos);                               //Lee una linea del archivo y la guarda en datos
        int count = 0;
        int temp = 0;

        for(int i = 0; i<int(datos.length()); i++){
            if(datos.at(i)==';' && (count==0)){
                cedulaarc = datos.substr(temp,i);
                temp = i+1;
                break;
            }
        }
        x++;
        if (ced==cedulaarc){                          //comparación con la cedula ingresada y la linea del archivo
            fan.open("cajeroautotempo.txt");
            string p,d;
            d="";
            while(fan.good()){
               getline(fan,p);
               if (p!=datos && p!=d){
                   copia3+=p+'\n';
               }
            }
            fan.close();
            string clave;
            int h=0;
            int f=3;
            int retiro;
            label5:
            cout<<"Ingrese clave del ususario: "<<endl;
            cin>>clave;
            clavearc = datos.substr(temp,4);
            if (clave==clavearc){
                string saldoarc = datos.substr(temp+5);

                //cout<<"El saldo es: $ "<<saldoarc<<" Pesos"<<endl<<endl;
                label8:
                cout<<"Ingrese saldo a retirar: "<<endl;
                cin>>retiro;

                int num = stoi(saldoarc);

                num=num-retiro-1000;

                if (num<retiro){
                    cout<<"Saldo insuficiente"<<endl;
                    goto label8;
                }

                string num2 = to_string(num);
                str2=ced+';'+clave+';'+num2;
                copia3+=str2;
                fout.open("cajeroauto.txt");
                fout<<copia3;
                fout.close();
                cout<<"Su nuevo saldo es: $"<<num2<<" Pesos"<<endl;
                break;
            }
            else {
                cout<<"Clave incorrecta"<<endl;
                h++;
                f--;
                cout<<"Le quedan "<<f<<" intentos"<<endl;
                if (h==3){
                    cout<<endl;
                    break;
                }
                goto label5;
                break;
            }
         fin.close();
         }
}
}*/
