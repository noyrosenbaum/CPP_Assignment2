#include <string>
#include <iostream>
using namespace std;

namespace ariel
{
    class card
    {
    private:
        string sign;
        int value;

    public:
        card(string sign, int value);
        int getValue()
        {
            return value;
        }
        string getSign()
        {
            return sign;
        }
    };
}
