#include <iostream>

using namespace std;

int cant_deDigitos(int n)
{
    int i;
    for(i=0; n>0; n=n/10)
    {
        i=i+1;
    }
    return i;
}

int elevado(int x, int y)
{
    if (y==0)
    {
        return 1;
    }
    return x*elevado(x,y-1);
}


int invertir(int n)
{
    int cant=cant_deDigitos(n);
    int cant1 = cant;
    int nuevo=0;
    int dig;
    for (int i=0; cant>0; cant--)
    {
        dig=n/elevado(10,cant-1);
        n=n-dig*elevado(10,cant-1);
        nuevo=nuevo + dig*elevado(10,i);
        i=i+1;
    }
    return nuevo;
}


int powerbase(int x, int y)
{
    if (y==1)
    {
        return x;
    }
    return x* powerbase(x,y-1);
}


int fiboRecursivo(int n)
{
    if (n==1 || n==0)
    {
        return 1;
    }
    return fiboRecursivo(n-1) + fiboRecursivo(n-2);
}


int fiboIterativo(int n)
{
    long long m_1= 1;
    long long m_2= 1;
    long long fibo;
    long long gm_2;
    if (n==0 || n==1)
    {
        return 1;
    }
    while (n>1)
    {
        gm_2=m_2;
        fibo = m_1 + m_2;
        m_2=m_1+m_2;
        m_1=gm_2;
        n=n-1;
    }
    return fibo;

}


int main()
{
    //1
//    Problem 1. [5 puntos] [Fuente: Projecteuler.net. Problem 1] Si se imprimiera todos los
//    n ́umeros naturales menores que 10, los cuales sean multiplos de 3 o 5, obtendr ́ıamos: 3, 5, 6, 9.
//    La suma de estos m ́ultiplos es 23.
//    Encontrar la suma de todos los m ́ultiplos de 3 o 5 menores a 1000000.


    long long suma = 0;
    long long divisor = 0;
    for (divisor = 0; divisor<1000000; divisor = divisor + 1)
    {
        if (divisor%3 == 0 || divisor%5 == 0)
        {
            suma = suma + divisor;
        }
    }

    cout << suma << endl;

    //2
//    Problem 2. [5 puntos] Escribir una funcio´n que recibe un entero y retorna el entero invertido.
//    Por ejemplo, dado el nu´mero 7631, la funci´on debe retornar 1367.




    cout <<"implemente un numero para voltearlo: ";
    int n;
    cin>>n;
    int nuevo = invertir(n);
    cout << nuevo << endl;

//    3
//    Problem 3. [5 puntos] Escribir una funci´on recursiva power( base, exponent ) la cual,
//    cuando se invoque, debe retornar baseexponent. Por ejemplo, power( 3, 4 ) = 3 * 3 * 3 * 3.
//    Asuma que exponent es un entero mayor o igual que 1.

    cout<<"coloque su base: ";
    int b;
    cin>>b;
    cout<<endl;
    cout<<"coloque el exponente: ";
    int e;
    cin>>e;
    cout << powerbase(b,e)<<endl;

    //4.
//    Problem 4. [5 puntos] Implemente dos funciones que encuentre el ﬁbonacci de un nu´mero,
//    una de la forma iterativa o otra de la forma recursiva.

    cout << "(Recursiva) coloque la posición que quiere en la sucesión Fibonacci: ";
    cin>>n;
    e=fiboRecursivo(n);
    cout<<e<<endl;

    cout << "(Iterativo) coloque la posición que quiere en la sucesión Fibonacci: ";
    cin>>n;
    e=fiboIterativo(n);
    cout<<e<<endl;


    return 0;
}
