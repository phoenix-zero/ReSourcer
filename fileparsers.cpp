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
  outp.flush();
  inp.close();
  outp.close();
}

std::string readFile(std::string path)
{
  std::fstream ifs(path,std::ios_base::in|std::ios_base::binary);
  std::string s((std::istreambuf_iterator<char>(ifs)),(std::istreambuf_iterator<char>()));
  ifs.close();
  std::stringstream ss;
  for(size_t i=0; i<s.length(); ++i)
      ss << std::hex << "0x" <<int(s[i]) << ",";
  s = ss.str();
  return s;
}

std::string parseFile(std::fstream& input)
{
  boost::property_tree::ptree pt;
  read_xml(input, pt);
  std::string key, value, ans, data;

  ans = "#include<vector>\n#include<string>\n#include<map>\nstd::vector<unsigned> __RCC__data__store__(std::string id)"
      "{\nstatic std::map<std::string,std::vector<unsigned>> _m_map({";

  for( boost::property_tree::ptree::value_type const& v: pt.get_child("RCC") )
  {
    if( v.first == "data" )
    {
      value = v.second.data().data();
      key = v.second.get("<xmlattr>.path", "string");
      if(value=="") continue;
      if(key=="") key = value;
      data=readFile(value);
      ans += "{\"" + key + "\",{" + data + "}},";
    }
  }
  ans +="}); return _m_map[id]; }";

/* basic template for the resource */
//  std::map<std::string, std::vector<int>> map({
//    {"hello",{3,4,6,7,}},
//  });

  return ans;
}
