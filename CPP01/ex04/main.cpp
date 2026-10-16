#include <fstream>
#include <iostream>

std::string replace(std::string tmp, const std::string to_replace, const std::string replacement)
{
    std::string::size_type pos = tmp.find(to_replace);

    if (pos == std::string::npos || to_replace.empty())
        return (tmp);

    else
    {
        std::string             result = "";
        std::string::iterator   index = tmp.begin();
        int                     i = 0;
       
        while (pos != std::string::npos)
        {
            while (i < pos)
            {
                result += *index;
                index++;
                i++;
            }
            result += replacement;
            i += to_replace.size();
            index += to_replace.size();
            pos = tmp.find(to_replace, index - tmp.begin());
        }

        while (i < tmp.size())
        {
            result += *index;
            index++;
            i++;
        }

        return (result);
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong number of argments" << "\n";
        return (1);
    }

    std::ifstream infile(argv[1]);
  
    if (!infile.is_open())
    {
        std::cout << "No such file" << "\n";
        return (1);
    }

    std::string name(argv[1]);
    std::string to_replace(argv[2]);
    std::string replacement(argv[3]);
    name += ".replace";

    std::ofstream outfile(name);
  
    std::string tmp;
    while (std::getline(infile, tmp)) 
    {
        tmp = replace(tmp, to_replace, replacement);
        outfile << tmp << "\n";
    }

    return 0;
}