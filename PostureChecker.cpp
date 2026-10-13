#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Пробуем открыть главную веб-камеру (индекс 0)
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cerr << "Ошибка: Не удалось открыть веб-камеру!" << std::endl;
        return -1;
    }

    std::cout << "Камера успешно подключена! Нажмите ESC в окне видео для выхода." << std::endl;

    cv::Mat frame;
    while (true) {
        cap >> frame; // Считываем новый кадр

        if (frame.empty()) {
            std::cerr << "Ошибка: Пустой кадр!" << std::endl;
            break;
        }

        // Рисуем простой зеленый текст прямо на видео
        cv::putText(frame, "Test Camera: OK", cv::Point(30, 50),
            cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0, 255, 0), 2);

        // Показываем кадр в окне
        cv::imshow("Posture Checker Test", frame);

        // Завершаем работу при нажатии клавиши Esc (код 27)
        if (cv::waitKey(30) == 27) {
            break;
        }
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}