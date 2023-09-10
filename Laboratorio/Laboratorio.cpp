#include <iostream>
#include <mysql.h>
#include <string>

void signo();
int ingopcion();
void menu();
void listardatos();
void ingresardatos();
void consultarvin();
void Modificardatos();
void Eliminardatos();
void menu2();
int ingopcion2();


MYSQL_ROW f;
MYSQL_RES* resultado;
MYSQL* conectar;

using namespace std;

int main()
{
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "tecnologo", "tecnologo", "vehiculo", 3306, NULL, 0);
    if (conectar) {
        int op;
        menu();
        op = ingopcion();
        while (op != 6)
        {
            switch (op)
            {
            case 1:
                //listar
                listardatos();      
                break;
            case 2:
                //ingresar
                ingresardatos();
                break;
            case 3:
                //modificar
               Modificardatos();
                break;
            case 4:
                //eliminar
               Eliminardatos();
                break;
            case 5:
                //consultar
                consultarvin();
                break;
            }
            menu();
            op = ingopcion();
        }

    }
    
}

void Eliminardatos()
{
    bool longvin = false;
    int vf;
    string v;
    system("cls");
    cout << ("====================\n");
    cout << ("   Eliminar auto\n");
    cout << ("====================\n\n");

    while (not longvin) {
        cout << "Ingrese vin: ";
        cin >> v;
        string select = "select * from auto where vin = ( '" + v + "')";
        const char* c = select.c_str();
        vf = mysql_query(conectar, c);
        resultado = mysql_store_result(conectar);
        if (mysql_num_rows(resultado) != 0)
        {
            longvin = true;
            cout << "" << endl;
            cout << "El Vin que usted ingreso Existe, Eliminacion existosa..." << endl;
            cout << "" << endl;
            
            cout << "" << endl;
            string deletear = "delete from auto where vin = ('" + v + "')";
            const char* del = deletear.c_str();
            vf = mysql_query(conectar, del);
            system("pause");
        }
        else {
            cout << "El vin que usted ingreso no existe, por favor verifique e intentelo de nuevo..." << endl;

        }
    }
}

void Modificardatos()
{
    bool longvin = false;
    int vf;
    string v;
    string m;
    string mo;
    string fe;
    string pr;
    int m_a;
    system("cls");
    cout << ("=============================\n");
    cout << ("   Actualizar dato de auto\n");
    cout << ("=============================\n\n");

    while (not longvin) {

        cout << "Ingrese vin: ";
        cin >> v;
        string select = "select * from auto where vin = ( '" + v + "')";
        const char* c = select.c_str();
        vf = mysql_query(conectar, c);
        resultado = mysql_store_result(conectar);
        if (mysql_num_rows(resultado) != 0)
        {
            cout << "" << endl;
            cout << "El Vin que usted ingreso existe..." << endl; 
            longvin = true;
            int op;
            cout << "" << endl;
            menu2();
            op = ingopcion2();
            while (op != 5)
            {
                switch (op)
                {
                case 1:
                    //Modificar marca
                {
                    cout << "" << endl;
                    cout << "Ingrese Marca: ";
                    cin >> m;
                    string select = "update auto set marca = ( '" + m + "') where vin = ( '" + v + "')";
                    const char* c = select.c_str();
                    m_a = mysql_query(conectar, c);
                    if (!m_a)
                    {
                        cout << ("=================================\n");
                        cout << "La modificacion ha sido exitosa" << endl;
                        cout << ("=================================\n");
                        cout << "" << endl;
                        mysql_close(conectar);
                        system("pause");
                        exit(0);
                    }
                    else {
                        cout << "" << endl;
                        cout << "La modificacion ha fallado" << endl;
                        cout << "" << endl;
                    }
                    break;
                }
                case 2:
                    //Modificar modelo
                {

                    cout << "" << endl;
                    cout << "Ingrese Modelo: ";
                    cin >> mo;
                    string select = "update auto set modelo = ( '" + mo + "') where vin = ( '" + v + "')";
                    const char* c = select.c_str();
                    m_a = mysql_query(conectar, c);
                    if (!m_a)
                    {
                        cout << ("=================================\n");
                        cout << "La modificacion ha sido exitosa" << endl;
                        cout << ("=================================\n");
                        cout << "" << endl;
                        mysql_close(conectar);
                        system("pause");
                        exit(0);
                    }
                    else {
                        cout << "" << endl;
                        cout << "La modificacion ha fallado" << endl;
                        cout << "" << endl;
                    }
                    
                }
                    break;
                case 3:
                    //Modificar fecha
                {
                    cout << "" << endl;
                    cout << ("==============================\n");
                    cout << "   Formato Fecha Anio/Mes/Dia" << endl;
                    cout << ("==============================\n");
                    cout << "" << endl;
                    cout << "Ingrese Fecha: ";
                    cin >> fe;
                    string select = "update auto set fecha_fab = ( '" + fe + "') where vin = ( '" + v + "')";
                    const char* c = select.c_str();
                    m_a = mysql_query(conectar, c);
                    if (!m_a)
                    {
                        cout << ("=================================\n");
                        cout << "La modificacion ha sido exitosa" << endl;
                        cout << ("=================================\n");
                        cout << "" << endl;
                        mysql_close(conectar);
                        system("pause");
                        exit(0);
                    }
                    else {
                        cout << "" << endl;
                        cout << "La modificacion ha fallado" << endl;
                        cout << "" << endl;
                    }
                    break;
                }
                    break;
                case 4:
                    //Modificar precio
                {
                    cout << "" << endl;
                    cout << "Ingrese Precio: ";
                    cin >> pr;
                    string select = "update auto set precio = ( '" + pr + "') where vin = ( '" + v + "')";
                    const char* c = select.c_str();
                    m_a = mysql_query(conectar, c);
                    if (!m_a)
                    {
                        cout << ("=================================\n");
                        cout << "La modificacion ha sido exitosa" << endl;
                        cout << ("=================================\n");
                        cout << "" << endl;
                        mysql_close(conectar);
                        system("pause");
                        exit(0);
                    }
                    else {
                        cout << "" << endl;
                        cout << "La modificacion ha fallado" << endl;
                        cout << "" << endl;
                    }
                    break;
                }
                    break;
                }
                menu();
                op = ingopcion();
            }

        }
        else
        {
            cout << "Vin no existe" << endl;
        }   break;
    }
}

void consultarvin()
{
    system("cls");
    cout << ("====================\n");
    cout << ("   Consultar VIN\n");
    cout << ("====================\n\n");
    int c_v;
    bool longvin = false;
    string v;
    while (not longvin) {
        cout << "Ingrese vin: ";
        cin >> v;
        string select = "select * from auto where vin = ( '" + v + "')";
        const char* c = select.c_str();
        c_v = mysql_query(conectar, c);
        resultado = mysql_store_result(conectar);
        if (mysql_num_rows(resultado) != 0)
        {     
                    longvin = true;
                    cout << "" << endl;
                    signo();
                    cout << "Vin existe" << endl;
                    while (f = mysql_fetch_row(resultado))
                    {
                        signo();
                        cout << "" << endl;
                        cout << "Vin: " << f[0] << endl;
                        cout << "Marca: " << f[1] << endl;
                        cout << "Modelo: " << f[2] << endl;
                        cout << "Fecha Fabricacion : " << f[3] << endl;
                        cout << "Precio: " << f[4] << endl;
                        cout << "" << endl;
                        signo();
                    }
        }
        else
        {
            cout << "Vin no existe" << endl;
        }   break;
    }
    system("pause");

}

void listardatos()
{
    int l_a;
    string consulta = "Select * from auto order by vin asc";
    const char* c = consulta.c_str();
    l_a = mysql_query(conectar, c);
    if (!l_a) {
        resultado = mysql_store_result(conectar);

        cout << "\n" << endl;
        while (f = mysql_fetch_row(resultado))
        {
            signo();
            cout <<""<< endl;
            cout << "Vin: " << f[0] << endl;
            cout << "Marca: " << f[1] << endl;
            cout << "Modelo:  " << f[2] << endl;
            cout << "Fecha Fabricacion : " << f[3] << endl; 
            cout << "Precio:  " << f[4] << endl;
            cout << "" << endl;
            signo();
        }
    }

    system("pause");
}

void ingresardatos()
{

    system("cls");
    cout << ("====================\n");
    cout << ("   Ingresar auto\n");
    cout << ("====================\n\n");
    cout << "" << endl;
    cout << "Formato Fecha Anio/Mes/Dia" << endl;
    cout << "" << endl;
    cout << "" << endl;
    int i_d;
    bool longvin = false;
    int long1;
    string vin;
    string marca;
    string modelo;
    string fecha;
    string precio;
    int vf;

    while (not longvin) {
        cout << "Ingrese vin: ";
        cin >> vin;
        long1 = size(vin);
        if (long1 <= 25 && long1 > 0) {
            longvin = true;
            string select = "select * from auto where vin = ( '" + vin + "')";
            const char* c = select.c_str();
            vf = mysql_query(conectar, c);
            resultado = mysql_store_result(conectar);
            if (mysql_num_rows(resultado) != 1) {

                cout << "Ingrese Marca: ";
                cin >> marca;

                cout << "Ingrese Modelo: ";
                cin >> modelo;

                cout << "Ingrese fecha fabricacion: ";
                cin >> fecha;

                cout << "Ingrese precio: ";
                cin >> precio;

                string insert = "insert into auto(vin,marca,modelo,fecha_fab,precio) values ('" + vin + "','" + marca + "','" + modelo + "','" + fecha + "','" + precio + "')";
                const char* i = insert.c_str();
                i_d = mysql_query(conectar, i);
                if (!i_d) {
                    cout << "" << endl;
                    cout << "El ingreso ha sido exitoso" << endl;
                    cout << "" << endl;
                    mysql_close(conectar);

                }

                else {
                    cout << "" << endl;
                    cout << "El ingreso ha fallado" << endl;
                    cout << "" << endl;
                    mysql_close(conectar);

                }
                system("pause");
            }
            else {
                cout << "" << endl;
                cout << "El vin ingresado ya existe" << endl;
                cout << "" << endl;
                system("pause");

            }

        }
    }

}



void menu()
{

    system("cls");
    cout << "Agustin Sosa 3er Laboratorio BD" << endl;
    cout << "" << endl;
    cout << "==========" << endl;
    cout << "   MENU   " << endl;
    cout << "==========" << endl;
    cout << "" << endl;
    cout << "1-Listar" << endl;
    cout << "2-Ingresar" << endl;
    cout << "3-Modificar" << endl;
    cout << "4-Eliminar " << endl;
    cout << "5-Consultar" << endl;
    cout << "6-Fin del Programa" << endl;
    cout << "" << endl;
}

int ingopcion()
{
    int opcion = NULL;
    do
    {
        cout << ("Ingrese Opcion (1-6): ");
        cin >> (opcion);
    } while ((opcion < 1) || (opcion > 6));
    getchar();
    return (opcion);
}

int ingopcion2()
{
    int opcion = NULL;
    do
    {
        cout << ("Ingrese Opcion (1-6): ");
        cin >> (opcion);
    } while ((opcion < 1) || (opcion > 5));
    getchar();
    return (opcion);
}

void signo()
{

    int i = 0;
    for (i = 1; i < 30; i++)
    {
        cout << "=";

    }
    cout << endl;
}

void menu2()
{
    cout << "====================================" << endl;
    cout << "   Posibles datos para actualizar   " << endl;
    cout << "====================================" << endl;
    cout << "" << endl;
    cout << "1-Marca" << endl;
    cout << "2-Modelo" << endl;
    cout << "3-Fecha" << endl;
    cout << "4-Precio" << endl;
    cout << "5-No modificar mas nada" << endl;
    cout << "" << endl;

}