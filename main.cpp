/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:10:05 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/12 04:22:06 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <string>
#include <cctype>

void nameHandler(std::string name)
{
	if (name.data()[0] == 'A' && std::isupper(name.data()[1]) && std::islower(name.data()[2]))
		std::cout << "Abstract class detected" << std::endl;
	else if (name.data()[0] == 'I' && (name.data()[1] >= 'A' && name.data()[1] <= 'Z') && (name.data()[2] >= 'a' && name.data()[2] <= 'z'))
		std::cout << "Interface detected" << std::endl;
	else if (name.data()[0] == 'T' && (name.data()[1] >= 'A' && name.data()[1] <= 'Z') && (name.data()[2] >= 'a' && name.data()[2] <= 'z'))
		std::cout << "Template detected" << std::endl;
	else if 
		std::cout << "Class detected" << std::endl;
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
		nameHandler(v[i]);
}