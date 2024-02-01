#include <tcl.h>
#include <expect.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <expect_tcl.h>

using namespace std;

int main()
{
    extern int exp_timeout;
    exp_timeout = 100;
    Tcl_Interp  *tcl;
    tcl = Tcl_CreateInterp();

    if(Expect_Init(tcl) != TCL_OK)
    {
        puts("failure");
        return 1;
    }

    int fd = exp_spawnl("ssh", "ssh", "-p 7722", "root@10.168.1.133", "echo start;ls ~;", (char *)0);
    if(fd < 0)
    {
        cout << "Fail to ssh" << endl;
        return -1;
    }
    int loop = 1;
    int result;
    
    while(loop)
    {
    result = exp_expectl(fd, exp_glob, "*assword: ", 1, exp_exact, "Permission denied, please try again.", 2, exp_regexp, "(The authenticity of host)(.)*(Are you sure you want to continue connecting (yes/no)?)", 3, exp_end);
    char pas[] = "Xnetworks.c0M\n";
    
    cout << endl;
    cout << "result: " <<  result << endl;

    switch(result)
    {
        case 1:
            write(fd, pas, sizeof(pas) - 1);
            break;       
        case 2:
            cout << "wrong password" << endl;
            break;
        case 3:
            cout << "connect security" << endl;
            write(fd, "yes\n", 4);
            break;
        
        case EXP_EOF:
            cout << "EOF\n";
            loop = 0;
            break;
        case EXP_TIMEOUT:
            cout<<"Time out\n";
            loop = 0;
            break;
        default:
            cout<<"logged in "<<result<<endl;
            loop = 0;
            break;
      }

    }
    exp_interactive();
    Tcl_DeleteInterp(tcl);
}
