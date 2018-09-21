#include <iostream>
#include <functional>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

int main(int argc, char** argv) {

    cv::VideoCapture stream = cv::VideoCapture("http://192.168.42.1:8080/stream/video.mjpeg");
    // cv::VideoCapture stream = cv::VideoCapture("udp://192.168.42.1:8080");
    if (!stream.isOpened()) return -1;

    cv::namedWindow("rpi_stream", CV_WINDOW_AUTOSIZE);
    cv::Mat frame;

    while (true) {
        if (!stream.read(frame)) return -1;

        cv::imshow("rpi_stream", frame);
        cv::waitKey(15);
    }

    return 1;
}