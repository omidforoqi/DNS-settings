#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int main() {
  int id_of_command;
  cout << "Enter 1\t\t\tEnter 2\nSet DNS automaticlly\tSet two DNS addresses\n=> ";
  cin >> id_of_command;
  
  if (id_of_command == 1){
    string reset_setting;
    reset_setting = "netsh interface ip set dns \"Ethernet\" dhcp";
    const char *command1 = reset_setting.c_str();
    system(command1);
    cout << "Done !! \n Press a key for exit...";
    _getch();
    return 0;
  }
  string first_dns_ip, second_dns_ip;
  cout << "First Ip: ";
  cin >> first_dns_ip;
  cout << "Second Ip: ";
  cin >> second_dns_ip;

  string str1, str2;
  str1 = "netsh interface ip set dns \"Ethernet\" static " + first_dns_ip;
  const char *command1 = str1.c_str();
  str2 = "netsh interface ip add dns \"Ethernet\" " + second_dns_ip + " index=2";
  const char *command2 = str2.c_str();
  
  system(command1);
  cout << "Set first DNS ";
  Sleep(50);
  system(command2);
  cout << "Set second DNS \n";
  cout << "Done !! \n Press a key for exit...";
  
  _getch();
  return 0;
}
