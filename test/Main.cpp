#include "pch.hpp"
#include "UAV/uavOS.hpp"

namespace Test{
	class InputString : public UNL::UAV::Event::Event{
	private:
		std::string _input;
	public:
		InputString(const std::string& input) : _input(input){};
		std::string getLine() const { return _input;};
	};

	class EnterListener : public UNL::UAV::Event::Listener{
	public:
		void onEvent(UNL::UAV::Event::Event* event) override{
			InputString* is = static_cast<InputString*>(event);
			std::cout << "Received Event: " << is->getLine() << std::endl;
		};
	};
};
int main(int argc, char** argv){
	UNL::UAV::Log::init();

	for(int i = 0; i < argc; i++){
		std::cout << argv[i] << " ";
	}
	std::cout << std::endl;

	std::string line;

	UNL::UAV::Event::Dispatcher dispatcher;

	dispatcher.addListener(new Test::EnterListener());
	dispatcher.addListener(new Test::EnterListener());
	while(true){
		std::getline(std::cin, line);

		Test::InputString* input = new Test::InputString(line);
		dispatcher.dispatch(input);
	}
	return 0;
}