#include <iostream>
#include <windows.h>
#include <string>

#include <fstream>

using namespace std;


int main() {
    char exeFullPath[MAX_PATH];
    string strPath;
    GetModuleFileName(NULL,exeFullPath,MAX_PATH);
    strPath=(std::string)exeFullPath;
    int pos = strPath.find_last_of('\\', strPath.length());
    string strPath_without_file = strPath.substr(0, pos);
    cout << strPath_without_file << endl;


    ofstream ofs;
    ofs.open("cmd.reg",ios::trunc);
    ofs << "Windows Registry Editor Version 5.00\n"
           "\n"
           "[HKEY_CLASSES_ROOT\\telnet120]\n"
           "@=\"URL:cmd Protocol\"\n"
           "\"URL Protocol\"=\"\"\n"
           "\n"
           "[HKEY_CLASSES_ROOT\\telnet120\\DefaultIcon]\n"
           "@=\"cmd.exe,1\"\n"
           "\n"
           "[HKEY_CLASSES_ROOT\\telnet120\\shell]\n"
           "@=\"\"\n"
           "\n"
           "[HKEY_CLASSES_ROOT\\telnet120\\shell\\open]\n"
           "@=\"\"\n"
           "\n"
           "[HKEY_CLASSES_ROOT\\telnet120\\shell\\open\\command]\n"
           "@=\"cmd /c && telnet 192.168.1.10\"\n"
           "\n"
           "\n"
           "[HKEY_CLASSES_ROOT\\bat120]\n"
           "@=\"URL:cmd Protocol\"\n"
           "\"URL Protocol\"=\"\"\n"
           "\n"
           "[HKEY_CLASSES_ROOT\\bat120\\DefaultIcon]\n"
           "@=\"cmd.exe,1\"\n"
           "\n"
           "[HKEY_CLASSES_ROOT\\bat120\\shell]\n"
           "@=\"\"\n"
           "\n"
           "[HKEY_CLASSES_ROOT\\bat120\\shell\\open]\n"
           "@=\"\"\n"
           "\n"
           "[HKEY_CLASSES_ROOT\\bat120\\shell\\open\\command]\n"
           "@=\"cmd /c && cd /d "
           << strPath_without_file <<
           "\\autostart && start_sias.bat stop && start_sias.bat run\""
           << endl;

    ofs.close();


    return 0;
}
