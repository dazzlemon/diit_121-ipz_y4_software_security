#include <iostream>
#include <unistd.h>
#include <fstream>

#define BIOS_VERSION "1.80\n"
#define USERNAME "dazzlemon"

std::string getBiosVersion() {
  std::ifstream ifs("/sys/class/dmi/id/bios_version");
  return std::string( (std::istreambuf_iterator<char>(ifs))
                    , (std::istreambuf_iterator<char>())
										);
}

int main() {
	if (getBiosVersion() != BIOS_VERSION) {
		std::cout << "wrong bios version\n";
		return -1;
	}

	if (std::string(getlogin()) != USERNAME) {
		std::cout << "wrong bios version\n";
		return -1;
	}

	std::cout << "OK\n";

	return 0;
}