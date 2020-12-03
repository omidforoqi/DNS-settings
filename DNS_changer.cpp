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
  // a if for reset dns setting
  if (id_of_command == 1){
    string reset_setting;
    reset_setting = "netsh interface ip set dns \"Ethernet\" dhcp";
    const char *command1 = reset_setting.c_str();
    system(command1);
    cout << "Done !!\nPress a key for exit...";
    _getch();
    return 0;
  }
  // print menu of available DNS
  cout << "Select your DNS Server" << '\n';
  cout << "1. Shecan\n2. begzar\n3. OpenDNS\n4. Cloudflare\n"\
  "5. Google Public DNS\n6. Comodo Secure DNS\n7. Quad9\n8. Verisign DNS\n"\
  "9. Custom DNS\n=>";
  int id_of_dns; // Get the selected DNS number
  cin >> id_of_dns;
  // Start of dns ip data //
  string first_dns_ip[9] = {"185.51.200.2",
  "185.55.226.26",
  "208.67.222.222",
  "1.1.1.1",
  "8.8.8.8",
  "8.26.56.26",
  "8.20.247.20",
  "64.6.64.6",
  };
  string second_dns_ip[9] = {"178.22.122.100",
  "185.55.225.25",
  "208.67.220.220",
  "1.0.0.1",
  "8.8.4.4",
  "8.20.247.20",
  "149.112.112.112",
  "64.6.65.6",
  };
  // End of dns ip data //
  if (id_of_dns == 9){
      cout << "First Ip: ";
      string custom_dns_first, custom_dns_second;
      cin >> custom_dns_first;
      first_dns_ip[8] = custom_dns_first;
      cout << "Second Ip: ";
      cin >> custom_dns_second;
      second_dns_ip[8] = custom_dns_second;
  }
  id_of_dns --;
  string str1, str2;
  str1 = "netsh interface ip set dns \"Ethernet\" static " + first_dns_ip[id_of_dns];
  const char *command1 = str1.c_str();
  str2 = "netsh interface ip add dns \"Ethernet\" " + second_dns_ip[id_of_dns] + " index=2";
  const char *command2 = str2.c_str();

  system(command1);
  cout << "Set first DNS";
  Sleep(50);
  system(command2);
  cout << "Set second DNS\n";
  cout << "Done !!\nPress a key for exit...";

  _getch();
  return 0;
}
