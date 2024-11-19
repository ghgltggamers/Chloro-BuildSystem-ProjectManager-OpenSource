// This is the project specific file and the entire runtime of Chloro-cc
/*
 * Copyright (c) Chloro Runtime 2024 for Chloro cc 1
 * Written by ghgltggamer
 * Licensed under the same license used for Chloro cc 1
*/
#ifndef CHLORO_CC_RUNTIME
#define CHLORO_CC_RUNTIME 111000

#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::cout<<"Chloro Runtime for Chloro cc 1\n"
               "Chloro Runtime checks...\n";
    std::ifstream chloro_info_file_i("chloro-info"); // Chloro info file as input
    if (chloro_info_file_i.is_open()){ // checking if file can be opened
        std::cout<<"Chloro Runtime checks done\n"
                   "Parsing the project...\n";
        std::string temp, prepare_commands;
        std::string _compiler_, _compile_flags, _main_file_, _output_binary_, _compile_files_;bool _make_binary_; // Tokens
        while (std::getline(chloro_info_file_i, temp)){ // Read the entire file line by line to parse the project with storing each line in temp (Temporary)
            if (temp.find("#") != std::string::npos){
                continue;
            }
            else if (temp.find("chloro-project-name") != std::string::npos){
                continue;
            }
            else if (temp.find("chloro-project-version") != std::string::npos){
                continue;
            }
            else if (temp.find("chloro-project-compiler=") != std::string::npos){
                std::string keyword = "chloro-project-compiler=";
                std::string compiler = temp.substr(temp.find(keyword) + keyword.length());
                if (compiler == "gcc" || compiler == "g++"){
                    _compiler_ = "g++";
                }
                else if (compiler == "clang" || compiler == "llvm" || compiler == "clang++"){
                    _compiler_ = "clang++";
                }
                else {
                    std::cout<<"Chloro Runtime -> Parser -> Error (Can't find a valid compiler make sure that compiler is gcc/g++ or clang/llvm/clang++)\n";
                    break;
                }
            }
            else if (temp.find("chloro-main-file=") != std::string::npos){
                std::string keyword = "chloro-main-file=";
                std::string main_file = temp.substr(temp.find(keyword) + keyword.length());
                _main_file_ = main_file;
            }
            else if (temp.find("chloro-make-binary=") != std::string::npos){
                std::string keyword = "chloro-make-binary=";
                std::string make_binary = temp.substr(temp.find(keyword) + keyword.length());
                if (make_binary == "true"){
                    _make_binary_ = true;
                }
                else if (make_binary == "false"){
                    _make_binary_ = false;
                }
                else {
                    std::cout<<"Chloro Runtime -> Parser -> Error (Can't parse an invalid type into bool tokens)";
                }
            }
            else if (temp.find("chloro-output-binary=") != std::string::npos){
                std::string keyword = "chloro-output-binary=";
                std::string output_binary = temp.substr(temp.find(keyword) + keyword.length());
                _output_binary_ = output_binary;
            }
            else if (temp.find("chloro-compile-flags") != std::string::npos){
                std::string keyword = "chloro-compile-flags";
                std::string compile_flags = temp.substr(temp.find(keyword)+keyword.length());
                _compile_flags = compile_flags;
            }
            else if (temp.find("chloro-compile=") != std::string::npos){
                std::string keyword = "chloro-compile=";
                std::string compile_file_all = temp.substr(temp.find(keyword) + keyword.length());
                std::string file_name = compile_file_all.substr(0, compile_file_all.find(","));
                std::string ofile_name = compile_file_all.substr(compile_file_all.find(",")+1);
                // chloro-compile
                _compile_files_ += _compiler_+ " " + file_name + " -o " + ofile_name + "\n";
                // _main_file_ = compile_file_all;
            }
            else {
                std::cout<<"Chloro Runtime -> Parser -> Error (Unknown key value pairs are in chloro-info)\n";
                break;
            }
        }
        // Finalising the build command now
        std::string build_Command = "echo [Program Started]\n"
                                    "echo \"\"\n"
                                    +_compiler_+" "+_main_file_+" -o " + _output_binary_ + _compile_flags +"\n"
                                    +_compile_files_+"\n"
                                    +"./"+_output_binary_+"\n";
        if (_make_binary_){
            build_Command += "\n";
        }
        else {
            build_Command += "rm -rf " + _output_binary_ + "\n";
        }
        build_Command += "echo \"\"\necho [Program finished]\necho \"\"\n";
        std::system(build_Command.c_str());
        exit (3);
    }
    else {
        std::cout<<"Chloro Runtime -> Error (chloro-info file doesnot exist and without that Chloro Runtime can't parse your project)\n"
                   "Chloro Runtime -> Options\n"
                   " 1.) Create a new file instead\n"
                   " 2.) Leave without creating a new file\n\n"
                   "Your option ? (1/2 only) ";
        int option_input = 1;
        std::cin>>option_input;
        std::cout<<"Validating your selection...\n";
        if (option_input == 1){
            std::ofstream chloro_config_file("chloro-info");
            chloro_config_file<<"# This is the config file generated by chloro-cc for the chloro-runtime for this project please only modify settings according to the project don't rewrite this file unless you perfectly knew how to write this file\n"
                              "chloro-project-name=demo_project\n"
                              "chloro-project-version=1.0\n"
                              "chloro-make-binary=false\n"
                              "chloro-main-file=cc/main.cc\n"
                              "chloro-project-compiler=gcc\n"
                              "chloro-output-binary=bin/main\n"
                              "# Uncomment the line bellow if also want to compile additional C++ files also\n"
                              "# chloro-compile=yourfile.cc,output-bin\n"
                              "# Uncomment the line bellow if want to parse any flage during ccompilation\n"
                              "# chloro-compile-flags=your flags for compiler\n";
            std::cout<<"Chloro Runtime successfully created the chloro-info file, Please restart the Runtime for compiling the project.\n";
        }
        else if (option_input == 2){
            std::cout<<"Chloro Runtime exit with status 3\n";
            exit (3);
        }
        else {
            std::cout<<"Chloro Runtime -> Error (Invalid request)\n";
        }
    }
}

#endif