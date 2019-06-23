#include <iostream>
#include <fstream>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>

std::string parseFile(std::fstream& input);

void fileParser(std::string input, std::string output)
{
  std::fstream inp(input,std::ios_base::in),
      outp(output,std::ios_base::out);

  outp.seekp(0);
  outp << parseFile(inp);
  //outp.flush();
  inp.close();
  outp.close();
}

std::string parseFile(std::fstream& input)
{
  using boost::property_tree::ptree;
  ptree pt;
  read_xml(input, pt);
  std::string ans;

  for( ptree::value_type const& v: pt.get_child("RCC") )
  {
    if( v.first == "data" )
    {
      std::cout << v.second.data().data();
      std::cout << v.second.get("<xmlattr>.path", "string");
    }
  }
  return "";
}
