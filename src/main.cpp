#include"application.hpp"

#include<iostream>
#include<stdexcept>

int main() {
	try {
		Application app{1280, 720};
		run(app);
	}
	catch(std::exception& e) {
		std::cerr << "fatal error: " << e.what() << std::endl;
		return -1;
	}
	catch(...) {
		std::cerr << "unexpected fatal error" << std::endl;
		return -1;
	}

	return 0;
}
