#ifndef FUNCTION_H
#define FUNCTION_H
#include <vector>
#include <string>

//3d gaussian function declaration
float gaussian_3d(float x, float y, float z, float mean[3], float sigma[3]);
//visualization
void apply_gaussian_splatting(const std::vector<std::tuple<float, float, float, float, float, float>> &points,
                              const std::string &output_filename);
//read cloud point data
std::vector<std::tuple<float, float, float, float, float, float>> read_txt_file(const std::string &filename);

#endif