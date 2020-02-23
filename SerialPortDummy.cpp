//
// Created by trifecta on 2/23/20.
//

#include "SerialPortDummy.h"
#include <string>
namespace mn {
    namespace CppLinuxSerial {
        /// \brief		Default constructor. You must specify at least the device before calling Open().
        SerialPort::SerialPort() {

        };

        /// \brief		Constructor that sets up serial port with the basic (required) parameters.
        SerialPort::SerialPort(const std::string &device, BaudRate baudRate) {

        };

        //! @brief		Destructor. Closes serial port if still open.
        SerialPort::~SerialPort() {

        };

        /// \brief		Sets the device to use for serial port communications.
        /// \details    Method can be called when serial port is in any state.
        void SerialPort::SetDevice(const std::string &device){};

        void SerialPort::SetBaudRate(BaudRate baudRate){};

        /// \brief      Sets the read timeout (in milliseconds)/blocking mode.
        /// \details    Only call when state != OPEN. This method manupulates VMIN and VTIME.
        /// \param      timeout_ms  Set to -1 to infinite timeout, 0 to return immediately with any data (non
        ///             blocking, or >0 to wait for data for a specified number of milliseconds). Timeout will
        ///             be rounded to the nearest 100ms (a Linux API restriction). Maximum value limited to
        ///             25500ms (another Linux API restriction).
        void SerialPort::SetTimeout(int32_t timeout_ms){};

        /// \brief		Enables/disables echo.
        /// \param		value		Pass in true to enable echo, false to disable echo.
        void SerialPort::SetEcho(bool value){};

        /// \brief		Opens the COM port for use.
        /// \throws		CppLinuxSerial::Exception if device cannot be opened.
        /// \note		Must call this before you can configure the COM port.
        void SerialPort::Open(){};

        /// \brief		Closes the COM port.
        void SerialPort::Close(){};

        /// \brief		Sends a message over the com port.
        /// \param		data		The data that will be written to the COM port.
        /// \throws		CppLinuxSerial::Exception if state != OPEN.
        void SerialPort::Write(const std::string &data){};

        /// \brief		Use to read from the COM port.
        /// \param		data		The object the read characters from the COM port will be saved to.
        /// \param      wait_ms     The amount of time to wait for data. Set to 0 for non-blocking mode. Set to -1
        ///                 to wait indefinitely for new data.
        /// \throws		CppLinuxSerial::Exception if state != OPEN.
        void SerialPort::Read(std::string &data){};

        std::string SerialPort::recvWithStartEndMarkers(){
            return "1";
        };

        /// \brief		Returns a populated termios structure for the passed in file descriptor.
        int SerialPort::GetTermios(){
            return 0;
        };

        /// \brief		Configures the tty device as a serial port.
        /// \warning    Device must be open (valid file descriptor) when this is called.
        void SerialPort::ConfigureTermios(){};

        void SerialPort::SetTermios(int myTermios){};

        /// \brief      Keeps track of the serial port's state.
        State state_;

        /// \brief      The file path to the serial port device (e.g. "/dev/ttyUSB0").
        std::string device_;

        /// \brief      The current baud rate.
        BaudRate baudRate_;

        /// \brief		The file descriptor for the open file. This gets written to when Open() is called.
        int fileDesc_;

        bool echo_;

        int32_t timeout_ms_;

        std::vector<char> readBuffer_;
        unsigned char readBufferSize_B_;

        static constexpr BaudRate defaultBaudRate_ = BaudRate::B_57600;
        static constexpr int32_t defaultTimeout_ms_ = -1;
        static constexpr unsigned char defaultReadBufferSize_B_ = 255;

    }
}
