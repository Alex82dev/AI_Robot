#include <iostream>
#include <string>
#include <voice_engine.h> // Подключение голосового движка

class Robot {
public:
    void moveForward() {
        // Код для перемещения робота вперед
    }

    void moveBackward() {
        // Код для перемещения робота назад
    }

    void turnLeft() {
        // Код для поворота робота влево
    }

    void turnRight() {
        // Код для поворота робота вправо
    }

    // Другие методы робота

    // Метод для выполнения команды, полученной от голосового движка
    void executeCommand(const std::string& command) {
        if (command == "вперед") {
            moveForward();
        } else if (command == "назад") {
            moveBackward();
        } else if (command == "влево") {
            turnLeft();
        } else if (command == "вправо") {
            turnRight();
        } else {
            std::cout << "Неизвестная команда" << std::endl;
        }
    }
};

// Функция обратного вызова для обработки распознанных команд от голосового движка
void handleVoiceCommand(const std::string& command) {
    Robot robot;
    robot.executeCommand(command);
}

int main() {
    // Инициализация голосового движка
    VoiceEngine voiceEngine;
    voiceEngine.init();
    
    // Регистрация функции обратного вызова для обработки распознанных команд
    voiceEngine.registerCallback(handleVoiceCommand);

    // Ожидание команды от голосового движка
    std::string command;
    while (true) {
        command = voiceEngine.getCommand(); // Получение распознанной команды от голосового движка
        
        // Выход из цикла, если получена команда завершения работы
        if (command == "выключиться") {
            break;
        }
    }

    // Остановка голосового движка
    voiceEngine.stop();

    return 0;
}
