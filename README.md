# Car-Parking-Reservation-System
# Description
The Car Parking Reservation System is a C++ console-based application that allows users to manage parking reservations efficiently. The system records car arrivals, calculates parking charges, and handles car departures. It provides an easy-to-use menu for users to interact with various functionalities.

# Features

 1) **User Authentication:** Secure login system to access the parking system.

2) **Car Arrival**: Users can register a car's arrival by entering driver details, car number, parking time, and time slot.

3) **View Parking Records**: Display all parked cars with relevant details.

4) **Parking Charges Calculation**: Determine parking fees based on duration and VIP status.

5) **Car Departure**: Remove a car's record from the system upon departure.

6) **View Total Parking Charges**: Display a summary of parking fees collected.

7) **Exit Program**: Safely exit the application.

# Installation

### **Clone this repository**:
         git clone https://github.com/yourusername/car-parking-system.git

### **Navigate to the project directory**:
          cd car-parking-system

### **Compile the C++ program using g++**:
         g++ parking_system.cpp -o parking_system

### **Run the executable**:
      ./parking_system

### **File Structure**
     CarParkingSystem/
     │── parking_system.cpp  # Main C++ source file
     │── parking3.csv        # Parking records (binary file, created during runtime)
     │── README.md           # Documentation
     
### **Usage**
          Enter the password (default: pass).
          Select an option from the main menu:
          1: Register a car arrival.
          
          2: View all parked cars.
          
          3: Calculate parking charges for a specific car.
          
          4: Display total parking charges for all cars.
          
          5: Remove a car record upon departure.
          
          6: Exit the program.
          
          Follow the on-screen instructions for each option.


### Dependencies
       C++ Compiler (g++ recommended)
       Standard C++ libraries (iostream, fstream, string)

# Future Enhancements

Implement a GUI for better user experience.

Add database integration for persistent storage.

Improve security by encrypting stored data
