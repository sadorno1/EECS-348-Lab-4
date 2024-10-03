#include <stdio.h>
#include <stdlib.h>

//function prototypes
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temperature(float celsius);

int main() {
    float temp_input, temp_converted;
    int input_scale, output_scale;
    
    //prompt for temperature
    printf("Enter the temperature: ");
    scanf("%f", &temp_input);
    
    //choose the current scale
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &input_scale);
    
    //choose the conversion scale
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &output_scale);
    
    //input validation
    if (input_scale == output_scale) {
        printf("Invalid conversion: Input scale and output scale cannot be the same.\n");
        exit(1);
    }

    //invalid Kelvin input check
    if (input_scale == 3 && temp_input < 0) {
        printf("Invalid temperature: Kelvin cannot be negative.\n");
        exit(1);
    }

    //convert based on input and output scale
    switch (input_scale) {
        case 1: //Celsius input
            if (output_scale == 2)
                temp_converted = celsius_to_fahrenheit(temp_input);
            else if (output_scale == 3)
                temp_converted = celsius_to_kelvin(temp_input);
            break;
        case 2: //Fahrenheit input
            if (output_scale == 1)
                temp_converted = fahrenheit_to_celsius(temp_input);
            else if (output_scale == 3)
                temp_converted = fahrenheit_to_kelvin(temp_input);
            break;
        case 3: //Kelvin input
            if (output_scale == 1)
                temp_converted = kelvin_to_celsius(temp_input);
            else if (output_scale == 2)
                temp_converted = kelvin_to_fahrenheit(temp_input);
            break;
        default:
            printf("Invalid scale choice.\n");
            exit(1);
    }
    
    //show converted temperature
    switch (output_scale) {
        case 1:
            printf("Converted temperature: %.2f°C\n", temp_converted);
            break;
        case 2:
            printf("Converted temperature: %.2f°F\n", temp_converted);
            break;
        case 3:
            printf("Converted temperature: %.2fK\n", temp_converted);
            break;
    }

    //categorize the temperature (convert to Celsius for consistency)
    if (output_scale == 1) {
        categorize_temperature(temp_converted);
    } else if (output_scale == 2) {
        categorize_temperature(fahrenheit_to_celsius(temp_converted));
    } else if (output_scale == 3) {
        categorize_temperature(kelvin_to_celsius(temp_converted));
    }
    
    return 0;
}

//conversion functions
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

//function to categorize the temperature and provide a weather advisory
void categorize_temperature(float celsius) {
    if (celsius < 0.0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay inside, it's too cold.\n");
    } else if (celsius >= 0.0 && celsius < 10.0) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10.0 && celsius < 25.0) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25.0 && celsius <= 35.0) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay inside, it's too hot.\n");
    }
}
