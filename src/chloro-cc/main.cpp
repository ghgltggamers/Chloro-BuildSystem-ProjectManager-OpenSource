/*
 * Copyright (c) Chloro 2024
 * Written by ghgltggamer
 * Chloro is a project manager which can be used to run any C++ project with a lot of ease.alignas
 * Chloro can be used better with complex project who requires a project manager to manage them
 * Chloro is fully open source and free to use
 * You are viewing the source code of Chloro-cc which is a part of project SCNN and Chloro
 * You are yourself relaiable for any compilation issues while using Chloro
 * Licensed under MIT License
 * No one owns Chloro it's indpendent from any author, Go ahead and contribute for project and be a contributer instead
 * Chloro is owned by everyone including you if you uses Chloro.
*/


// Source
#ifndef CHLORO_CC
#define CHLORO_CC 111000111
#define CHLORO_CC_VERSION 1
// headerfiles
#include <iostream>
#include  <fstream>
#include   <string>

// main function for running the program
int main(int argc, char*argv[]){
    std::string appName = argv[0];// casting the CLI 0 of c style into std::string of C++
    if (appName.find("chloro") != std::string::npos){

    }
    else {
        std::cout<<"Chloro Runtime Manager -> Error (The program name is invalid must include chloro in name of the program)\n";
        exit(3);
    }

    if (argc > 0){
        std::string first_Cli_Argument = argv[1];// Casting c_style array of index 1 to C++ std::string
        if (first_Cli_Argument == "--version"){
            std::cout<<"Chloro cc "<<CHLORO_CC_VERSION<<"\n";
        }
        else if (first_Cli_Argument == "--help"){
            std::cout<<"\n                             Chloro cc - Help\n\nUse the following commands with chloro cc:-\n 1.) --version : This command is used to check your chloro cc version\n 2.) --help : this command will show you the documentation of CLI\n";
        }
        else if (first_Cli_Argument == "--new"){
            std::string second_Cli_Argument = argv[2];// Converting c style array into C++ std::string for index 2
            if (second_Cli_Argument.empty()){
                std::cout<<"Chloro -> Error (Project name must not be empty please give a project name when using '--new')\n";
            }
            else {
                std::string third_Cli_Argument = argv[3];// Converting c style array into C++ std::string for index 3
                std::string mkdir_Command_For_Config = "mkdir "+third_Cli_Argument+"/"+second_Cli_Argument;
                std::system(mkdir_Command_For_Config.c_str());
                std::string project_Path = third_Cli_Argument+"/"+second_Cli_Argument;
                std::ofstream config_OFile(project_Path+"/chloro-info");// Config output file
                config_OFile<<"# This is the config file generated by chloro-cc for the chloro-runtime for this project please only modify settings according to the project don't rewrite this file unless you perfectly knew how to write this file\n"
                              "chloro-project-name="+second_Cli_Argument+"\n"
                              "chloro-project-version=1.0\n"
                              "chloro-make-binary=false\n"
                              "chloro-main-file=cc/main.cc\n"
                              "chloro-project-compiler=gcc\n"
                              "chloro-output-binary=bin/main\n"
                              "# Uncomment the line bellow if also want to compile additional C++ files also\n"
                              "# chloro-compile=yourfile.cc,output-bin\n"
                              "# Uncomment the line bellow if want to parse any flaage during ccompilation\n"
                              "# chloro-compile-flags=your flags for compiler\n";
                std::string mkdir_Command_For_Runtime = "mkdir "+third_Cli_Argument+"/"+second_Cli_Argument+"/chloro/";
                std::system(mkdir_Command_For_Runtime.c_str());
                std::ofstream runtime_OFile(project_Path+"/chloro/chloro-runtime.cc");
                std::string temp;
                std::ifstream runtime_IFile("chloro-runtime.cc");
                while (std::getline(runtime_IFile,temp)){
                    runtime_OFile<<temp<<"\n";
                }
                std::string mkdir_Command_For_Cc = "mkdir "+project_Path + "/cc/";
                std::system(mkdir_Command_For_Cc.c_str());
                // main.cc
                std::ofstream main_Cc(project_Path+"/cc/main.cc");
                main_Cc<<"/*\n"
                         " * Copyright (c) "+second_Cli_Argument+" 2024\n"
                         " * Licensed under LICENSE file, Checkout the license file for more information\n"
                         " * Checkout README.md for documentation of this project\n"
                         " * Checkout CHANGELOGS.md file for changelogs related to version\n"
                         "*/\n"
                         "\n"
                         "#ifndef MAIN\n"
                         "#define MAIN 11110101\n"
                         "\n"
                         "// header files \n"
                         "#include \""+second_Cli_Argument+".hpp\"\n"
                         "\n\n"
                         "int main(int argc, char* argv[]){\n"
                         "  // Source of your application starts from here\nstd::cout<<\"Your project is live...\";\n// Source of your application ends here\n}\n\n #endif";
                std::ofstream project_HeaderFile(project_Path+"/cc/"+second_Cli_Argument+".hpp");
                project_HeaderFile<<"// This is the headerfile of your project\n"
                                    "#include <iostream>\n"
                                    "#include  <fstream>\n"
                                    "#include   <string>\n"
                                    "#include    <cmath>\n"
                                    "\n\n\n"
                                    "// start writing your header from here\n\n// end your header here";
                std::ofstream readme_file(project_Path+"/cc/README.md");
                readme_file<<"# "+second_Cli_Argument+"\nDefine your project here! May be a documentation or an overview.";
                std::ofstream license_file(project_Path+"/cc/LICENSE");
                license_file<<"Please replace the content of this file with actual LICENSE, Better grab a license from https://choosealicense.com, No promotion just providing a resource preferred by many developers.";
                std::ofstream changelogs(project_Path+"/cc/CHANGELOGS.md");
                changelogs<<"# Define changelogs for current version of your project.";
                std::string mkdir_Command_For_Bin = "mkdir "+project_Path+"/bin";
                std::system(mkdir_Command_For_Bin.c_str());
                std::ofstream build_file(project_Path+"/configure-chloro-runtime.sh");
                build_file<<"g++ chloro/chloro-runtime.cc -o chloro-rt";
                std::cout<<"The project was successfully initalised! You are fully ready to start working with it!\n";
            }
        }
        else {
            std::cout<<"Chloro -> Error (Need a valid argument please use '--help' for more information)\n";
        }
    }
    else {
        std::cout<<"Chloro -> Error (Need at the least 1 argument from Command Line to work use '--help' with chloro)\n";
    }
}

#endif