/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:10:05 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/12 07:02:19 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <algorithm>

void createHeaderFile(std::string name)
{
	std::ofstream file(name + ".hpp", std::ios::out);
	if (!file)
		throw std::invalid_argument("Error creating file");
	std::string nameUpper = name;
	std::transform(nameUpper.begin(), nameUpper.end(), nameUpper.begin(), 
               [](unsigned char c){ return std::toupper(c); });

	file << "#ifndef " << nameUpper << "_HPP" << std::endl;
	file << "# define " << nameUpper << "_HPP" << std::endl;
	file << std::endl;
	file << "class " << name << std::endl;
	file << "{" << std::endl;
	file << "\tpublic:" << std::endl;
	file << "\t\t" << name << "();" << std::endl;
	file << "\t\t" << name << "(const " << name << " &src);" << std::endl;
	file << "\t\t~" << name << "();" << std::endl;
	file << std::endl;
	file << "\t\t" << name << " &operator=(const " << name << " &rhs);" << std::endl;
	file << std::endl;
	file << "\tprivate:" << std::endl;
	file << "};" << std::endl;
	file << std::endl;
	file << "#endif" << std::endl;
	file.close();
}

void createSourceFile(std::string name)
{
	std::ofstream file(name + ".cpp", std::ios::out);
	if (!file)
		throw std::invalid_argument("Error creating file");
	file << "#include \"" << name << ".hpp\"" << std::endl;
	file << std::endl;
	file << name << "::" << name << "()" << std::endl;
	file << "{" << std::endl;
	file << "}" << std::endl;
	file << std::endl;
	file << name << "::~" << name << "()" << std::endl;
	file << "{" << std::endl;
	file << "}" << std::endl;
	file << std::endl;
	file << name << "::" << name << "(const " << name << " &src)" << std::endl;
	file << "{" << std::endl;
	file << "}" << std::endl;
	file << std::endl;
	file << name << " &" << name << "::operator=(const " << name << " &rhs)" << std::endl;
	file << "{" << std::endl;
	file << "\tif (this == &rhs)" << std::endl;
	file << "\t\treturn (*this);" << std::endl;
	file << "\treturn (*this);" << std::endl;
	file << "}" << std::endl;
	file.close();
}

void nameHandler(std::string name)
{
	if (name.data()[0] == 'A' && std::isupper(name.data()[1]) && std::islower(name.data()[2]))
	{
		createHeaderFile(name);
		createSourceFile(name);
	}	
	else if (name.data()[0] == 'I' && (name.data()[1] >= 'A' && name.data()[1] <= 'Z') && (name.data()[2] >= 'a' && name.data()[2] <= 'z'))
		createHeaderFile(name);
	else if (name.data()[0] == 'T' && (name.data()[1] >= 'A' && name.data()[1] <= 'Z') && (name.data()[2] >= 'a' && name.data()[2] <= 'z'))
		createHeaderFile(name);
	else if (std::isupper(name.data()[0]) && std::islower(name.data()[1]))
	{
		createHeaderFile(name);
		createSourceFile(name);
	}
	else
		throw std::invalid_argument("Invalid class name, please check the naming convention.");
}

int main (int argc, char *argv[])
{
	std::vector<std::string> v;
	
	if (argc < 2)
	{
		std::cout << "Usage: ./42classes file1 file2...." << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++)
		v.push_back(argv[i]);
	for (int i = 0; i < v.size(); i++)
	{
		try {
				nameHandler(v[i]);
			}
		catch (std::invalid_argument &e) 
			{
				std::cout << e.what() << std::endl;
			}		
	}
}