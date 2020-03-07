#include "UAV/Serial.hpp"
namespace UNL::UAV{
Serial::Serial(std::string& name, int baudrate) : _uartName(name), _baudrate(baudrate){
	this->_fd = -1;
	this->_status = 0;

	int result = pthread_mutex_init(&_lock, NULL);
	if (result != 0 ){
		std::cout << "Failed to create Mutex" << std::endl;
		throw 1;
	}
};
Serial::~Serial(){
	pthread_mutex_destroy(&_lock);
}
void Serial::start(){
	{ //Open Port
		this->_fd = open(this->_uartName.data(), O_RDWR | O_NOCTTY | O_NDELAY);
		if(this->_fd == -1){
			std::cout << "Could not open port!" << std::endl;
			std::exit(-1);
		}
		fcntl(this->_fd, F_SETFL, 0);
	}
	{ // Setup the port
		if(!isatty(this->_fd)){
			std::cout << this->_uartName << " is not Serial Port!" << std::endl;
			std::exit(-1);
		}

		// Read file descritor configuration
		struct termios  config;
		if(tcgetattr(this->_fd, &config) < 0){
			std::cout << "ERROR: could not read configuration" << std::endl;
			std::exit(-1);
		}

		// Input flags - Turn off input processing
		// convert break to null byte, no CR to NL translation,
		// no NL to CR translation, don't mark parity errors or breaks
		// no input parity check, don't strip high bit off,
		// no XON/XOFF software flow control
		config.c_iflag &= ~(IGNBRK | BRKINT | ICRNL |
							INLCR | PARMRK | INPCK | ISTRIP | IXON);

		// Output flags - Turn off output processing
		// no CR to NL translation, no NL to CR-NL translation,
		// no NL to CR translation, no column 0 CR suppression,
		// no Ctrl-D suppression, no fill characters, no case mapping,
		// no local output processing
		config.c_oflag &= ~(OCRNL | ONLCR | ONLRET |
							 ONOCR | OFILL | OPOST);

		#ifdef OLCUC
			config.c_oflag &= ~OLCUC;
		#endif

		#ifdef ONOEOT
			config.c_oflag &= ~ONOEOT;
		#endif

		// No line processing:
		// echo off, echo newline off, canonical mode off,
		// extended input processing off, signal chars off
		config.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);

		// Turn off character processing
		// clear current char size mask, no parity checking,
		// no output processing, force 8 bit input
		config.c_cflag &= ~(CSIZE | PARENB);
		config.c_cflag |= CS8;

		// One input byte is enough to return from read()
		// Inter-character timer off
		config.c_cc[VMIN]  = 1;
		config.c_cc[VTIME] = 10; // was 0

		// Get the current options for the port
		////struct termios options;
		////tcgetattr(fd, &options);

		// Apply baudrate
		switch (this->_baudrate){
			case 1200:
				if (cfsetispeed(&config, B1200) < 0 || cfsetospeed(&config, B1200) < 0){
					std::cout << "Could not set desired baudrate!" << std::endl;
					std::exit(-1);
				}
				break;
			case 1800:
				cfsetispeed(&config, 1800);
				cfsetospeed(&config, 1800);
				break;
			case 9600:
				cfsetispeed(&config, 9600);
				cfsetospeed(&config, 9600);
				break;
			case 19200:
				cfsetispeed(&config, 19200);
				cfsetospeed(&config, 19200);
				break;
			case 38400:
				if (cfsetispeed(&config, 38400) < 0 || cfsetospeed(&config, 38400) < 0){
					std::cout << "Could not set desired baudrate!" << std::endl;
					std::exit(-1);
				}
				break;
			case 57600:
				if (cfsetispeed(&config, 57600) < 0 || cfsetospeed(&config, 57600) < 0){
					std::cout << "Could not set desired baudrate!" << std::endl;
					std::exit(-1);
				}
				break;
			case 115200:
				if (cfsetispeed(&config, 115200) < 0 || cfsetospeed(&config, 115200) < 0){
					std::cout << "Could not set desired baudrate!" << std::endl;
					std::exit(-1);
				}
				break;

			// These two non-standard (by the 70'ties ) rates are fully supported on
			// current Debian and Mac OS versions (tested since 2010).
			case 460800:
				if (cfsetispeed(&config, 460800) < 0 || cfsetospeed(&config, 460800) < 0){
					std::cout << "Could not set desired baudrate!" << std::endl;
					std::exit(-1);
				}
				break;
			case 921600:
				if (cfsetispeed(&config, 921600) < 0 || cfsetospeed(&config, 921600) < 0){
					std::cout << "Could not set desired baudrate!" << std::endl;
					std::exit(-1);
				}
				break;
			default:
				std::cout << "Could not set desired baudrate!" << std::endl;
				std::exit(-1);

				break;
		}

		// Finally, apply the configuration
		if(tcsetattr(this->_fd, TCSAFLUSH, &config) < 0){
			std::cout << "Could not set configuration!" << std::endl;
			std::exit(-1);
		}
	}
};

void Serial::stop(){
	int result = close(this->_fd);
	if(result){
		std::cout << "Unable to close port "<< std::endl;
	}
}

int Serial::read(uint8_t& cp){
	pthread_mutex_lock(&this->_lock);
	int result = ::read(this->_fd, &cp, 1);
	pthread_mutex_unlock(&this->_lock);

	return result;
};

void Serial::write(int length, char* buffer){
	pthread_mutex_lock(&this->_lock);
	::write(this->_fd, buffer, length);
	tcdrain(this->_fd);
	pthread_mutex_unlock(&this->_lock);
};
};