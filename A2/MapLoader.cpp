#include <fstream>
#include <string>
#include "MapLoader.h"
#include "Map.h"

//default constructor
MapLoader::MapLoader() {
    inputFileName = "none";
}

//copy constructor
MapLoader::MapLoader(const MapLoader* ml) {
    inputFileName = ml->inputFileName;
}

//two parameters constructor
MapLoader::MapLoader(string fileName, int arraySize) {
    this->inputFileName = fileName;
    territoryArray = new string[arraySize];
    generateTerritoryArray(arraySize);
}

//assignment operator
MapLoader& MapLoader::operator = (const MapLoader& ml) {
    this->inputFileName = ml.inputFileName;
    return *this;
}

//destructor
MapLoader::~MapLoader() {
    inputFileName.clear();
    territoryArray->clear();
    territoryArray = NULL;
}

//accessor
string MapLoader::getInputFileName() {
    return inputFileName;
}

//mutator
void MapLoader::setInputFileName(string s) {
    inputFileName = s;
}

//collect territory names from valid input file, exit(0) if invalid input file
void MapLoader::generateTerritoryArray(int size) {
    int a, b, c, d;
    bool valid = false;
    string s;
    ifstream input(inputFileName);
    getline(input, s);
    while (!input.eof()) {
        if ((a = s.find("countries") != string::npos)) {
            valid = true;
            for (int i = 0; i < size; i++) {
                input >> a >> territoryArray[i] >> b >> c >> d;
            }
            cout << "Index     Territory" << endl;
            for (int i = 0; i < size; i++) {
                cout << "  " << i << "   :   " << territoryArray[i] << endl;
            }
        }
        if (input.eof()) {
        }

        else
            getline(input, s);

    }

    if (!valid) {
        cout << "Initialization failed! Invalid input map file! Program terminated!" << endl;
        exit(0);
    }

    input.close();

}
