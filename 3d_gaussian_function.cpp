#include "function.hpp"
#include <iostream>
#include <cmath>
// #include <vector>
#include <opencv2/opencv.hpp>

// 3D Gaussian 함수
float gaussian_3d(float x, float y, float z, float mean[3], float sigma[3]) {
    float mx = mean[0], my = mean[1], mz = mean[2];
    float sx = sigma[0], sy = sigma[1], sz = sigma[2];
    return std::exp(-(
        ((x - mx) * (x - mx)) / (2 * sx * sx) +
        ((y - my) * (y - my)) / (2 * sy * sy) +
        ((z - mz) * (z - mz)) / (2 * sz * sz)
    ));
}

// Gaussian Splatting 및 비디오 저장
void apply_gaussian_splatting(const std::vector<std::tuple<float, float, float, float, float, float>> &points,
                              const std::string &output_filename) {
    int frame_width = 800;
    int frame_height = 800;
    int total_frames = 100;
    float sigma[3] = {0.5f, 0.5f, 0.5f};

    // OpenCV VideoWriter 설정
    cv::VideoWriter writer(
        output_filename,
        cv::VideoWriter::fourcc('X', 'V', 'I', 'D'),  // XVID 코덱 사용
        30,
        cv::Size(frame_width, frame_height)
    );

    if (!writer.isOpened()) {
        std::cerr << "Error: Could not open the video writer." << std::endl;
        return;
    }

    for (int frame = 0; frame < total_frames; ++frame) {
        cv::Mat img(frame_height, frame_width, CV_8UC3, cv::Scalar(0, 0, 0));

        for (const auto &[x, y, z, mean_x, mean_y, mean_z] : points) {
            float mean[3] = {mean_x, mean_y, mean_z};
            float value = gaussian_3d(x, y, z, mean, sigma);

            if (value > 0.0001) {
                int px = static_cast<int>((x + 2.0f) / 4.0f * (frame_width - 1));
                int py = static_cast<int>((y + 2.0f) / 4.0f * (frame_height - 1));
                cv::circle(img, cv::Point(px, py), 2, cv::Scalar(0, 255, 255), -1);
            }
        }

        // 디버깅용: 프레임 확인
        cv::imshow("Frame", img);
        cv::waitKey(1);

        writer.write(img);
    }

    writer.release();
    std::cout << "Video written to " << output_filename << std::endl;
}