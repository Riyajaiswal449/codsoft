#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Load the Haar cascade for face detection
    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load(cv::samples::findFile("haarcascade_frontalface_default.xml"))) {
        std::cerr << "Error loading Haar cascade for face detection!" << std::endl;
        return -1;
    }

    // Open video capture
    cv::VideoCapture capture(0); // Use 0 for default camera, or replace with video file path
    if (!capture.isOpened()) {
        std::cerr << "Error opening video capture!" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (capture.read(frame)) {
        std::vector<cv::Rect> faces;
        cv::Mat gray;
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        face_cascade.detectMultiScale(gray, faces);

        for (const auto &face : faces) {
            cv::rectangle(frame, face, cv::Scalar(255, 0, 0), 2);
        }

        cv::imshow("Face Detection", frame);
        if (cv::waitKey(30) >= 0) break;
    }

    return 0;
}

