#include <iostream>
#include <string>

class Prova
{
	private:
		std::string _name;
	public:
		Prova();
		~Prova();
		void		setName(std::string name);
		std::string	getName();
};

Prova::Prova() : _name("") {}

Prova::~Prova() {}

void	Prova::setName(std::string name)
{
	_name = name;
}

std::string Prova::getName()
{
	return (_name);
}

int main(int argc, char const *argv[])
{
	Prova prova;

	prova.setName("Gabriele");
	std::cout << prova.getName() << std::endl;

	return 0;
}

