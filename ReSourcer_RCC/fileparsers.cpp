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
      if(!ifs)
      {
          std::cerr << "Error opening " << path << std::endl;
          exit(0);
      }
      std::string s((std::istreambuf_iterator<char>(ifs)),(std::istreambuf_iterator<char>()));
      ifs.close();
      std::stringstream ss;
      for(size_t i=0; i<s.length(); ++i)
          ss << std::hex << "0x" <<int(uint8_t(s[i])) << ",";
      s = ss.str();
      return s;
}

std::string parseFile(std::fstream& input)
{
    boost::property_tree::ptree pt;
    read_xml(input, pt);
    std::string key, value, ans, data;

    ans = "/*Don't read this file. This file is cursed*/\n"
          "#include<vector>\n#include<string>\n#include<map>\nstd::map<std::string,std::vector<unsigned char>> "
          "__RCC__DATA__STORE__({";

    for( boost::property_tree::ptree::value_type const& v: pt.get_child("RCC") )
    {
        if( v.first == "file" )
        {
            value = v.second.data().data();
            key = v.second.get("<xmlattr>.id", "string");
            if(value=="") continue;
            if(key=="") key = value;
            data=readFile(value);
            ans += "{\"" + key + "\",{" + data + "}},";
        }
        else if( v.first == "data")
        {
            value = v.second.data().data();
            key = v.second.get("<xmlattr>.id", "string");
            if(key=="") continue;
            std::stringstream ss;
            for(size_t i=0; i<value.length(); ++i)
                ss << std::hex << "0x" <<int(uint8_t(value[i])) << ",";
            data = ss.str();
            ans += "{\"" + key + "\",{" + data + "}},";
        }
    }
    ans +="});";

    /* basic template for the resource */
    //  std::map<std::string, std::vector<int>> map({
    //    {"hello",{3,4,6,7,}},
    //  });

    return ans;
}
