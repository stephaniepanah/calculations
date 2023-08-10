/***********************************************
     program: calculations.cpp
     author : Stephanie Ezat-Panah
     mod log: 02/08/2018 version 1.0

     use: https://www.onlinegdb.com/online_c++_compiler
     copy, paste, run

***********************************************/

/***********************************************
     directives
***********************************************/

#include <iostream>
#include <iomanip>
#include <istream>
#include <locale>
#include <string>
#include <sstream>
#include <ctype.h>
#include <math.h>

using namespace std;

/***********************************************
     macros
***********************************************/

constexpr auto QUIT = 'Q';
constexpr auto PI = 3.1416;
constexpr auto OUT_OF_BOUNDS = -500;
constexpr auto HIGHTEMP = 2000;
constexpr auto MIN_FAHRENHEIT = -459;
constexpr auto ABSZERO = -273;
constexpr auto ZERO_KELVIN = 0;

/***********************************************
     prototypes
***********************************************/

int  processData();
void findArea();
void findVolume();
void findTemp();
int  validateCelsius();
int  validateFahrenheit();
int  validateKelvin();
bool validateInteger(string str);

/***********************************************
     main
***********************************************/

int  main()
{
    processData();
    return 0;
}

/***********************************************
    processData
***********************************************/

int processData()
{
    char instr[20];

    cout << "\n\n";
    cout << "\nPlease select from the following: ";
    cout << "\n 1 - area of a circle             ";
    cout << "\n 2 - volume of a sphere           ";
    cout << "\n 3 - compute temperature          ";
    cout << "\n or Q to quit                     ";
    cout << "\n\n";

    do
    {
        cin >> instr;

        switch (instr[0])
        {
        case '1': findArea();   break;
        case '2': findVolume(); break;
        case '3': findTemp();   break;
        case 'Q': case 'q':     break;
        default: cout << "\n you entered: " << instr << " please reenter \n"; break;
        }

        if (instr[0] != 'Q' && instr[0] != 'q')
            cout << "\n enter 1, 2, 3 or Q \n";

    } while (toupper(instr[0]) != QUIT);

    return 0;
}

/***********************************************
  find the area of a circle using the radius
***********************************************/

class AreaCircle
{
    double area;

public:
    double get_area(int);
};

double AreaCircle::get_area(int r)
{
    return area = (PI * pow(r, 2));
}

void findArea()
{
    int  r = 0; // radius
    int  i = 0;
    char input[20];
    bool isinteger = true;

    AreaCircle areaCircle{};

    cout << "\n enter an integer value for the radius: ";
    cin >> input;
    string str = input;

    cout << "\n you entered, " << str;

    for (i = 0; str[i] != '\0'; ++i)
    {
        if (!isdigit(str[i]))
        {
            cout << "\n the value, " << str << ", is not an integer \n";
            isinteger = false;
            break;
        }
    }

    if (isinteger == true)
    {
        r = atoi(str.c_str());
        cout << "\n the area is: " << areaCircle.get_area(r) << "\n";
    }
}

/***********************************************
  find the volume of a sphere using the radius
***********************************************/

class VolumeSphere
{
    double volume;

public:
    double get_volume(int);
};

double VolumeSphere::get_volume(int r)
{
    return volume = (static_cast<double>(4) / 3 * (PI * pow(r, 3)));
}

void findVolume()
{
    int  r = 0; // radius
    int  i = 0;
    char input[20];
    bool isinteger = true;

    VolumeSphere volumeSphere{};

    cout << "\n enter an integer value for the radius: ";
    cin >> input;
    string str = input;

    cout << "\n you entered, " << str;

    for (i = 0; str[i] != '\0'; ++i)
    {
        if (!isdigit(str[i]))
        {
            cout << "\n the value, " << str << ", is not an integer \n";
            isinteger = false;
            break;
        }
    }

    if (isinteger == true)
    {
        r = atoi(str.c_str());
        cout << "\n the volume is: " << volumeSphere.get_volume(r) << "\n";
    }
}

/***********************************************
  find the temperature in Celsius, Fahrenheit
  and Kelvin using any scale
***********************************************/

class Temperature
{
    double calc_temp = 0;

public:
    double celsiusToFahrenheit(int temperature);
    double fahrenheitToCelsius(int temperature);
    double celsiusToKelvin(int temperature);
    double celsiusToKelvin(double celsius);
    double kelvinToCelsius(int temperature);
};

double Temperature::celsiusToFahrenheit(int temperature)
{
    return (temperature * static_cast<double>(9) / 5) + 32;
}

double Temperature::fahrenheitToCelsius(int temperature)
{
    return (temperature - static_cast<double>(32)) * 5 / 9;
}

double Temperature::celsiusToKelvin(int temperature)
{
    return temperature + 273;
}

double Temperature::celsiusToKelvin(double celsius)
{
    return celsius + 273;
}

double Temperature::kelvinToCelsius(int temperature)
{
    return temperature - 273;
}

/***********************************************
     findTemp
***********************************************/

void findTemp()
{
    char   scale;
    char   instring[200];
    int    temperature = 0;
    double celsius = 0;
    double fahrenheit = 0;
    double kelvin = 0;

    Temperature temp; // an instance of Class Temperature

    do
    {
        cout << "\n enter C(elsius) F(ahrenheit) or K(elvin): ";
        cin >> instring;
        scale = toupper(instring[0]);
        cout << "\n you entered, " << scale << "\n";
        if (scale != 'C' && scale != 'F' && scale != 'K')
            cout << "\n enter C, F or K \n";
    } while (scale != 'C' && scale != 'F' && scale != 'K');

    switch (scale)
    {
    case 'C':
        cout << "\n Celsius scale \n";
        temperature = validateCelsius();
        break;

    case 'F':
        cout << "\n Fahrenheit scale \n";
        temperature = validateFahrenheit();
        break;

    case 'K':
        cout << "\n Kelvin scale \n";
        temperature = validateKelvin();
        break;
    }

    if (temperature == OUT_OF_BOUNDS)
        return;

    switch (scale)
    {
    case 'C':
        celsius = temperature;
        fahrenheit = temp.celsiusToFahrenheit(temperature);
        kelvin = temp.celsiusToKelvin(temperature);
        break;

    case 'F':
        fahrenheit = temperature;
        celsius = temp.fahrenheitToCelsius(temperature);
        kelvin = temp.celsiusToKelvin(celsius);
        break;

    case 'K':
        kelvin = temperature;
        celsius = temp.kelvinToCelsius(temperature);
        fahrenheit = temp.celsiusToFahrenheit(celsius);
        break;
    }

    cout << "\n Celsius   : " << celsius;
    cout << "\n Fahrenheit: " << fahrenheit;
    cout << "\n Kelvin    : " << kelvin;
    cout << "\n";

    return;
}

/***********************************************
     validateCelsius
***********************************************/

int  validateCelsius()
{
    char   instring[6];
    string str;
    int    temperature = 0;
    bool   isinteger = false;

    do
    {
        cout << "\n enter an integer value between " << ABSZERO << " and " << HIGHTEMP << " for the celsius temperature: ";
        cin >> instring;
        str = instring;
        cout << "\n you entered, " << str << "\n";
        isinteger = validateInteger(str);
    } while (isinteger == false);

    temperature = atoi(str.c_str());

    if ((temperature >= ABSZERO) && (temperature <= HIGHTEMP))
    {
        return temperature;
    }
    else
    {
        cout << "\n the temperature, " << temperature << ", is out of bounds \n";
        return OUT_OF_BOUNDS;
    }
}

/***********************************************
     validateFahrenheit
***********************************************/

int  validateFahrenheit()
{
    char   instring[6];
    string str;
    int    temperature = 0;
    bool   isinteger = false;

    do
    {
        cout << "\n enter an integer value between " << MIN_FAHRENHEIT << " and " << HIGHTEMP << " for the Fahrenheit temperature: ";
        cin >> instring;

        str = instring;

        cout << "\n you entered, " << str << "\n";
        isinteger = validateInteger(str);
    } while (isinteger == false);

    temperature = atoi(str.c_str());

    if ((temperature >= MIN_FAHRENHEIT) && (temperature <= HIGHTEMP))
    {
        return temperature;
    }
    else
    {
        cout << "\n the temperature, " << temperature << ", is out of bounds \n";
        return OUT_OF_BOUNDS;
    }
}

/***********************************************
     validateKelvin
***********************************************/

int  validateKelvin()
{
    char   instring[6];
    string str;
    int    temperature = 0;
    bool   isinteger = false;

    do
    {
        cout << "\n enter an integer value between " << ZERO_KELVIN << " and " << HIGHTEMP << " for the Kelvin temperature: ";
        cin >> instring;
        str = instring;
        cout << "\n you entered, " << str << "\n";
        isinteger = validateInteger(str);
    } while (isinteger == false);

    temperature = atoi(str.c_str());

    if ((temperature >= ZERO_KELVIN) && (temperature <= HIGHTEMP))
    {
        return temperature;
    }
    else
    {
        cout << "\n the temperature, " << temperature << ", is out of bounds \n";
        return OUT_OF_BOUNDS;
    }
}

/***********************************************
     validateInteger
***********************************************/

bool validateInteger(string str)
{

    if (str[0] != '+' && str[0] != '-' && !isdigit(str[0]))
        return false;

    for (int i = 1; str[i] != '\0'; ++i)
    {
        if (!isdigit(str[i]))
        {
            cout << "\n the value, " << str << ", is not an integer \n";
            return false;
        }
    }

    return true;
}

/***********************************************
     end of program
***********************************************/