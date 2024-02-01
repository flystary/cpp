#include <iostream>
#include <fstream>

#include <yaml-cpp/yaml.h>

using namespace std;


int main(int argc, char** argv)
{
    YAML::Node config;
    try{
        config = YAML::LoadFile("./config.yaml");
    } catch(YAML::BADFile &e) {
        cout << "read error!" << endl;
        return -1;
    }

    cout << "Node type: " << config.Type() << endl;
    cout << "skills type: " << config["skills"].Type() << endl;

    string age = "age";
    cout << "age when string is label:" << config[age].as<int>() << endl;
 
    cout << "name:" << config["name"].as<string>() << endl;
    cout << "sex:" << config["sex"].as<string>() << endl;
    cout << "age:" << config["age"].as<int>() << endl;

    try{
        string label = config["label"].as<string>();
    }catch(YAML::TypedBadConversion<string> &e){
        std::cout<<"label node is NULL"<<std::endl;
    }

}

