#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H

#include <iostream>
#include <string>

class addressType {
private:
    std::string streetAddress;
    std::string city;
    std::string state;
    int zipCode;

    // Helper function to validate state
    bool isValidState(const std::string& st) {
        return st.length() == 2;
    }

    // Helper function to validate ZIP code
    bool isValidZip(int zip) {
        return zip >= 11111 && zip <= 99999;
    }

public:
    // Default constructor
    addressType()
        : streetAddress(""), city(""), state("XX"), zipCode(10000) {}

    // Parameterized constructor
    addressType(const std::string& street, const std::string& cityName, const std::string& st, int zip)
        : streetAddress(street), city(cityName) {
        state = isValidState(st) ? st : "XX";
        zipCode = isValidZip(zip) ? zip : 10000;
    }

    // Function to set street address
    void setAddress(const std::string& street) {
        streetAddress = street;
    }

    // Function to set city
    void setCity(const std::string& cityName) {
        city = cityName;
    }

    // Function to set state with validation
    void setState(const std::string& st) {
        state = isValidState(st) ? st : "XX";
    }

    // Function to set ZIP code with validation
    void setZipcode(int zip) {
        zipCode = isValidZip(zip) ? zip : 10000;
    }

    // Function to print the address in standard format
    void print() const {
        if (!streetAddress.empty()) {
            std::cout << streetAddress << std::endl;
        }
        std::cout << city << " " << state << ", " << zipCode << std::endl;
    }

    // Getters
    std::string getStreetAddress() const { return streetAddress; }
    std::string getCity() const { return city; }
    std::string getState() const { return state; }
    int getZipCode() const { return zipCode; }
};

#endif // ADDRESSTYPE_H