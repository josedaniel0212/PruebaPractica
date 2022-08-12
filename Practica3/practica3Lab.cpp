#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

int main()
{
    string str3,str;
    ifstream fin;
    fin.open("texto.txt");

    while(fin.good()){
        getline(fin,str3);
        cout<<"Texto encontrado en el archivo: "<<str3<<endl;
        str+=str3;
    }
    fin.close();

    string binario="";
    for (int i = 0; i < str.length(); ++i) {
            bitset<8> bs4(str[i]);
            binario += bs4.to_string();
    }

    char opcion1;
    cout<<"Seleccione el metodo de encriptacion: "<<endl;
    cout<<"1. Metodo 1"<<endl;
    cout<<"2. Metodo 2"<<endl;
    cin>>opcion1;
    switch(opcion1){
        case '1':
            {
            cout<<"Texto en binario: "<<endl<<binario<<endl;
            int semilla;
            cout<<endl<<"Ingrese el numero de semilla: "<<endl;
            cin>>semilla;

            string part1,part2,part3="";
            part1 = binario.substr(0,semilla);
            for (int i=0; i<semilla; i++){
                if (part1[i]=='0'){
                    part3 += '1';
                }
                else if (part1[i]=='1'){
                        part3 += '0';
                }
            }

            string partTotal=part3;

            int ceros=0;
            int unos=0;
            int temp=(str.length());

            for (int x=0; x<temp;x++){
                part2 = binario.substr(semilla*(x+1),semilla);
                for (int i=0; i<semilla; i++){
                    if (part2[i]=='0'){
                        ceros++;
                    }
                    else if (part2[i]=='1'){
                            unos++;
                    }
                }
                if (ceros==unos){
                    for (int i=0; i<semilla; i++){
                        if (part2[i]=='0'){
                            part2[i] = '1';
                        }
                        else if (part2[i]=='1'){
                                part2[i] = '0';
                        }
                    }
                partTotal+=part2;
                }
                else if (ceros>unos){
                    for (int i=1; i<=semilla; i+=2){
                        if (part2[i]=='0'){
                            part2[i]= '1';
                        }
                        else if (part2[i]=='1'){
                                part2[i] = '0';
                        }

                    }
                partTotal+=part2;
                }
                else if (ceros<unos){
                    for (int i=2; i<=semilla; i+=3){
                        if (part2[i]=='0'){
                            part2[i]= '1';
                        }
                        else if (part2[i]=='1'){
                                part2[i] = '0';
                        }
                    }
                partTotal+=part2;
                }
                ceros=0;
                unos=0;
            }
            cout<<endl<<"El texto encriptado es: "<<endl<<partTotal<<endl;
            ofstream fout;
            fout.open("textosalida1.txt");
            fout<<partTotal;
            fout.close();

            char opcion;
            cout<<endl<<"¿Desea desencriptar el texto? (Presione 1 o 2)"<<endl;
            cout<<"1. Si"<<endl<<"2. No"<<endl;
            cin>>opcion;

            if (opcion =='1'){
                part3="";
                part2="";
                part1 = partTotal.substr(0,semilla);

                for (int i=0; i<semilla; i++){
                    if (part1[i]=='0'){
                        part3 += '1';
                    }
                    else if (part1[i]=='1'){
                            part3 += '0';
                    }
                }
                string partTotal2=part3;
                int ceros=0;
                int unos=0;
                int temp=(str.length());
                for (int x=0; x<temp;x++){
                    part2 = partTotal.substr(semilla*(x+1),semilla);
                    for (int i=0; i<semilla; i++){
                        if (part2[i]=='0'){
                            ceros++;
                        }
                        else if (part2[i]=='1'){
                                unos++;
                        }
                    }
                    if (ceros==unos){
                        for (int i=0; i<semilla; i++){
                            if (part2[i]=='0'){
                                part2[i] = '1';
                            }
                            else if (part2[i]=='1'){
                                    part2[i] = '0';
                            }
                        }
                    partTotal2+=part2;
                    }
                    else if (ceros<unos){
                        for (int i=1; i<=semilla; i+=2){
                            if (part2[i]=='0'){
                                part2[i]= '1';
                            }
                            else if (part2[i]=='1'){
                                    part2[i] = '0';
                            }

                        }
                    partTotal2+=part2;
                    }
                    else if (ceros>unos){
                        for (int i=2; i<=semilla; i+=3){
                            if (part2[i]=='0'){
                                part2[i]= '1';
                            }
                            else if (part2[i]=='1'){
                                    part2[i] = '0';
                            }
                        }
                    partTotal2+=part2;
                    }
                    ceros=0;
                    unos=0;
                }
            cout<<"El texto desencriptado es: "<<endl<<partTotal2<<endl;
            }
            else if (opcion=='2'){
                cout<<"Programa Finalizado"<<endl;
            }
            break;
            }
        case '2':
            {
            cout<<endl<<"El texto encontrado en binario es: "<<endl;
            cout<<endl<<binario<<endl;
            int tempo=int(binario.length());
            string binario2=binario;
            binario[0]=binario[tempo-1];

            for (int i=1;i<tempo+1;i++){
                binario[i]=binario2[(i-1)];
            }
            cout<<endl<<"El texto encriptado es: "<<endl;
            cout<<endl<<binario<<endl;
            ofstream fout;
            fout.open("textosalida.txt");
            fout<<binario;
            fout.close();
            char opcionl;
            cout<<endl<<"¿Desea desencriptar el texto? (Presione 1 o 2)"<<endl;
            cout<<"1. Si"<<endl<<"2. No"<<endl;
            cin>>opcionl;

            if (opcionl=='1'){
                binario2[tempo]=binario[0];
                for (int i=tempo;i>0;i--){
                    binario[i]=binario2[(i-1)];
                }
            cout<<"El texto desencriptado es: "<<endl;
            cout<<endl<<binario2<<endl;
            }
            else if (opcionl=='2'){
                    cout<<"Programa finalizado"<<endl;
            }
            break;
            }
    default:
        {
        cout<<"Programa Finalizado"<<endl;
        break;
        }
}
}
