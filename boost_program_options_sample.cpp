#include <iostream>
#include <string>
#include <boost/program_options.hpp>

using namespace std;

namespace po = boost::program_options;


int main(int argc,char* argv[])
{
  po::options_description desc("Program options");
  
  desc.add_options()
    ("help","print info")
    ("filename" , po::value<string>()->default_value("default.txt"),"file to process");
  
  po::variables_map vm;
  auto parsed = po::parse_command_line(argc,argv,desc);
  
  po::store(parsed,vm);
  
  po::notify(vm);
  
  if(vm.count("help"))
  {
   cout << desc <<endl;
    getchar();
    return 1;
    
  }
  
  string filename = "default.txt"
    
    if(vm.count("filename"))
    {
     filename = vm["filename"].as<string>(); 
    }
  
  cout << "processing file " << filename <<endl;
  
  getchar();
 return 0; 
}

//second example
int customized(int argc,char* argv[])
{
  po::options_description desc("my file processor options");
  int value;
  desc.add_options()
    ("value,v" , po::value<int>(&value)->default_value(55),"input value to process")
    ("files",po::value<vector<string>>()->multitoken(),"filenames");
  
  po::positional_options_description pos;
  pos.add("files",-1);
  
  po::variables_map vm;
  po::command_line_parser parser(argc,argv);
  auto parsed_options = parser.options(desc).positional(pos).run();
  //auto parsed = po::parse_command_line(argc,argv,desc);
  
  //po::store(parsed,vm);
  po::store(parsed_options,vm);
  po::notify(vm);
  

  cout << "Value is " << value <<endl;

  if(vm.count("files"))
  {
   int i =0;
    
    auto files = vm["files"].as<vector<string>>();
    for(auto f:files)
    {
      cout << ++i << " : " << f << endl; 
    }
  }
 
  getchar();
 return 0; 
}
