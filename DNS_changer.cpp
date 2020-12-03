#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int main() {
  int id_of_command;
  cout << "Enter 1\t\t\tEnter 2\nReset to default DNS\tSet two DNS addresses\n=> ";
  cin >> id_of_command;

  if (id_of_command == 1){
    string reset_setting;
    reset_setting = "netsh interface ip set dns \"Ethernet\" dhcp";
    const char *command1 = reset_setting.c_str();
    system(command1);
    cout << "Done !!\nPress a key for exit...";
    _getch();
    return 0;
  }
  int id_of_dns;
  cout << "Select your DNS Server" << '\n';
  cout << "1. Shecan\n2. begzar\n3. OpenDNS\n4. Cloudflare\n"\
  "5. Google Public DNS\n6. Comodo Secure DNS\n7. Quad9\n8. Verisign DNS\n"\
  "9. Custom DNS\n=>";
  cin >> id_of_dns;
  string first_dns_ip, second_dns_ip;
  switch (id_of_dns) {
    case 1:
      first_dns_ip = "185.51.200.2"; second_dns_ip = "178.22.122.100";
      break;
    case 2:
      first_dns_ip = "185.55.226.26"; second_dns_ip = "185.55.225.25";
      break;
    case 3:
      first_dns_ip = "208.67.222.222"; second_dns_ip = "208.67.220.220";
      break;
    case 4:
      first_dns_ip = "1.1.1.1"; second_dns_ip = "1.0.0.1";
      break;
    case 5:
      first_dns_ip = "8.8.8.8"; second_dns_ip = "8.8.4.4";
      break;
    case 6:
      first_dns_ip = "8.26.56.26"; second_dns_ip = "8.20.247.20";
      break;
    case 7:
      first_dns_ip = "8.20.247.20"; second_dns_ip = "149.112.112.112";
      break;
    case 8:
      first_dns_ip = "64.6.64.6"; second_dns_ip = "64.6.65.6";
      break;
    case 9:
      cout << "First Ip: ";
      cin >> first_dns_ip;
      cout << "Second Ip: ";
      cin >> second_dns_ip;
      break;
  }
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
  cout << "Done !!\nPress a key for exit...";

  _getch();
  return 0;
}
