#include "../inc/files_handler.hpp"

static void	copying_and_correcting(std::ifstream *input, std::ofstream *output, Helper *helper);
static std::string make_the_name(const char *av);

void	handle_files(char **av, Helper *helper)
{
	std::ofstream	file;

	std::ifstream input(av[1], std::ios_base::binary); // av[1] == file que vamos abrir
	if (!input.is_open())
	{
		std::cerr << "Error: an \"" << av[1] << "\" file does not exist\n";
		exit(1);
	}
	std::string output_name = make_the_name(av[1]);
	std::ofstream output(output_name.c_str(), std::ios::binary);
	if (!output.is_open())
	{
		std::cerr << "Error: Could not create a copy\n";
		exit(1);
	}
	if (!input || !output)
	{
		std::cerr << "Error opening or creating files\n";
		exit(1);
	}
	copying_and_correcting(&input, &output, helper);
}

static std::string make_the_name(const char *av)
{
	return std::string(av) + ".replace";
}



static void	copying_and_correcting(std::ifstream *input, std::ofstream *output, Helper *helper)
{
	std::string line;
	size_t position;

	while (std::getline((*input), line))
	{
		position = 0;
		while ((position = line.find(helper->erase, position)) != std::string::npos) // std::string::npos == is a constant static member value with the highest possible value for an element of type size_t.
		{
			line.erase(position, helper->erase.length());
			line.insert(position, helper->replace);
			position += helper->replace.length();
		}
		(*output) << line << std::endl;
	}
}
