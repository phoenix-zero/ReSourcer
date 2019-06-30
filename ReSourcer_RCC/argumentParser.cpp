#include <boost/program_options.hpp>
#include <iostream>

std::pair<std::string,std::string> optionParser(int argc, char** argv)
{
    namespace proptions = boost::program_options;
    if(argc==1) exit(-1);
    std::string in, out;
    try
    {
        proptions::options_description desc{"Options"};
        desc.add_options()
                ("help,h", "Help screen")
                ("output,o", proptions::value<std::string>()->default_value("resource"), "Output file name")
                ("input,i", proptions::value<std::string>()->default_value("resource.rcc"), "Input file name");
        proptions::positional_options_description pos_desc;
        pos_desc.add("input", 1);
        proptions::command_line_parser parser{argc, argv};
        parser.options(desc).positional(pos_desc).allow_unregistered();
        proptions::parsed_options parsed_options = parser.run();
        proptions::variables_map vm;
        store(parsed_options, vm);
        notify(vm);
        if (vm.count("help"))
        {
            std::cout << desc << '\n';
            exit(0);
        }
        in = vm["input"].as<std::string>();
        out = vm["output"].as<std::string>();
    }
    catch (const proptions::error &ex)
    {
        std::cerr << ex.what() << '\n';
    }
    return  {in,out};
}
