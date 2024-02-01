#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>

using namespace std;


int main(void)
{
    char c;
    static struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;

    newt.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    system("stty -echo");
    while((c=getchar()) != 'e') {
        char d = c + 'A' - 'a';
        cout << d << endl;
    }

    system("stty echo");
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return 0;
}
