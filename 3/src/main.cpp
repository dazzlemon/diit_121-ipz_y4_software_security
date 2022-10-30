#include <iostream>
#include <sys/utsname.h>
#include <unistd.h>

int main() {
	utsname buf;
	int res = uname(&buf);

	std::cout << "sysname:  " << buf.sysname << '\n'
	          << "nodename: " << buf.nodename << '\n'
	          << "release:  " << buf.release << '\n'
	          << "version:  " << buf.version << '\n'
	          << "machine:  " << buf.machine << '\n'
						<< "username: " << getlogin() << '\n'
						;

	char line[500]; // Read with fgets().
	char ip_address[500]; // Obviously more space than necessary, just illustrating here.
	int hw_type;
	int flags;
	char mac_address[500];
	char mask[500];
	char device[500];

	FILE *fp = fopen("/proc/net/arp", "r");
	fgets(line, sizeof(line), fp);    // Skip the first line (column headers).
	while(fgets(line, sizeof(line), fp))
	{
			// Read the data.
			sscanf(line, "%s 0x%x 0x%x %s %s %s\n",
						ip_address,
						&hw_type,
						&flags,
						mac_address,
						mask,
						device);

			// Do stuff with it.
	}

	fclose(fp);

	std::cout << mac_address << '\n';
}