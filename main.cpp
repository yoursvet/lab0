#include <iostream>


class RemoteControlDevice {
public:
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
};


class TV : public RemoteControlDevice {
public:
    void powerOn() override {
        std::cout << "телевизор включен" << std::endl;
    }
    void powerOff() override {
        std::cout << "телевизор выключен" << std::endl;
    }
    void changeChannel(int channel) {
        std::cout << "канал изменен " << channel << std::endl;
    }
};


class RemoteControl {
private:
    RemoteControlDevice* device_;
public:
    RemoteControl(RemoteControlDevice* device) : device_(device) {}

    void powerOn() {
        device_->powerOn();
    }
    void powerOff() {
        device_->powerOff();
    }
};

int main() {
    TV tv;
    RemoteControl remoteControl(&tv);
    remoteControl.powerOn();
    tv.changeChannel(5);
    remoteControl.powerOff();
    return 0;
}