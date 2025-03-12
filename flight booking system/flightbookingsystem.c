#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 3
#define MAX_BOOKINGS 10

// Structure to store flight details
typedef struct {
    int flight_id;
    char airline[30];
    char source[30];
    char destination[30];
    int available_seats;
} Flight;

// Structure to store booking details
typedef struct {
    int booking_id;
    int flight_id;
    char passenger_name[30];
} Booking;

// Global variables
Flight flights[MAX_FLIGHTS] = {
    {1, "Air India", "New York", "London", 5},
    {2, "Emirates", "Dubai", "Paris", 4},
    {3, "Qatar Airways", "Doha", "Tokyo", 6}
};

Booking bookings[MAX_BOOKINGS];
int booking_count = 0;

// Function prototypes
void displayFlights();
void bookTicket();
void viewBookings();

int main() {
    int choice;
    while (1) {
        printf("\n===== Flight Booking System =====\n");
        printf("1. View Flights\n");
        printf("2. Book a Ticket\n");
        printf("3. View Bookings\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFlights();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                viewBookings();
                break;
            case 4:
                printf("Exiting... Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Function to display available flights
void displayFlights() {
    printf("\nAvailable Flights:\n");
    printf("ID\tAirline\t\tSource\t\tDestination\tSeats\n");
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        printf("%d\t%s\t%s\t%s\t\t%d\n", flights[i].flight_id, flights[i].airline, flights[i].source, flights[i].destination, flights[i].available_seats);
    }
}

// Function to book a ticket
void bookTicket() {
    int flight_id;
    char name[30];

    if (booking_count >= MAX_BOOKINGS) {
        printf("Booking limit reached!\n");
        return;
    }

    displayFlights();
    printf("\nEnter Flight ID to book: ");
    scanf("%d", &flight_id);

    // Find the flight
    for (int i = 0; i < MAX_FLIGHTS; i++) {
        if (flights[i].flight_id == flight_id && flights[i].available_seats > 0) {
            printf("Enter Passenger Name: ");
            scanf("%s", name);

            // Store booking
            bookings[booking_count].booking_id = booking_count + 1;
            bookings[booking_count].flight_id = flight_id;
            strcpy(bookings[booking_count].passenger_name, name);
            booking_count++;

            flights[i].available_seats--; // Reduce available seats

            printf("Booking successful! Your Booking ID is %d\n", booking_count);
            return;
        }
    }
    printf("Invalid Flight ID or no seats available.\n");
}

// Function to view bookings
void viewBookings() {
    if (booking_count == 0) {
        printf("\nNo bookings found.\n");
        return;
    }

    printf("\nBooked Tickets:\n");
    printf("Booking ID\tFlight ID\tPassenger Name\n");
    for (int i = 0; i < booking_count; i++) {
        printf("%d\t\t%d\t\t%s\n", bookings[i].booking_id, bookings[i].flight_id, bookings[i].passenger_name);
    }
}