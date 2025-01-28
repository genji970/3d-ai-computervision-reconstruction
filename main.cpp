#include "function.hpp"
#include <vector>
#include <tuple>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string video_filename = "gaussian_splatting.avi";
    // TXT 파일 읽기
    string input_file = "data.txt";
    vector<tuple<float, float, float, float, float, float>> points = read_txt_file(input_file);

    apply_gaussian_splatting(points, video_filename);

    return 0;
}