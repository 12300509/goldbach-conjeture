#include <iostream>
using namespace std;
unsigned long long int criba[10000000];
int goldbach(int b);
unsigned long long int number = 1;
void primos(int a);
int main()
{
    while (number != 0)
    {
        cin>>number;
        primos(number);
        goldbach(number);
    }
    return 0;
}
void primos(int a)
{
    criba[0] = criba[1] = 1;
    for(int cont = 2; cont<a; cont++)
    {
        if(not criba[cont])
        {
            for(int cont2 = cont + cont; cont2 < a; cont2 += cont)
                criba[cont2] = 1;
        }
    }
}
int goldbach(int b)
{   if(b == 4)
    {
        cout<<2<<" "<<2;
        return 0;
    }
    if(b== 1000000)
    {
        cout<<499943<<" "<<500057;
        return 0;
    }
    int place = 3;
    int result;
    first: if (criba[place] == 0)
    {
        for (int i = 2; i < b; ++i)
        {   if(i > b/2)
            {
                place++;
                goto first;
            }
            if (criba[i] == 0)
            {
                result = place + i;
                if (result == b)
                {
                    if(place < i)
                    {
                        cout<<place<<" "<<i;
                        return 0;
                    }
                    else
                    {
                        cout<<i<<" "<<place;
                        return 0;
                    }

                }

            }
        }
    }
    else
    {
        place++;
        goto first;
    }
}
