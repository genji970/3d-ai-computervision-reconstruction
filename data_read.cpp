#include "function.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>
#include <iostream>

// TXT 파일에서 데이터 읽기
std::vector<std::tuple<float, float, float, float, float, float>> read_txt_file(const std::string &filename) {
    std::vector<std::tuple<float, float, float, float, float, float>> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        float x, y, z, mean_x, mean_y, mean_z;

        ss >> x >> y >> z >> mean_x >> mean_y >> mean_z;
        data.emplace_back(x, y, z, mean_x, mean_y, mean_z);
    }

    file.close();
    return data;
}
